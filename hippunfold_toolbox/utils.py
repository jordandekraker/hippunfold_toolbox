import numpy as np
import copy
from joblib import Parallel, delayed
import warnings
from scipy.interpolate import griddata
from scipy.interpolate import NearestNDInterpolator
import nibabel as nib
from pathlib import Path
from scipy.ndimage.filters import gaussian_filter
from scipy.interpolate import interp1d
from scipy.interpolate import interpn
from numpy.matlib import repmat

resourcesdir=str(Path(__file__).parents[1]) + '/resources'

def avg_neighbours(invar):
    '''Averages vertex-wise data at vertex n with its neighbouring vertices. F, cdat, n should be passed as a tuple (for easier parallel).'''
    F,cdat,n = invar
    frows = np.where(F==n)[0]
    v = np.unique(F[frows,:])
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        out = np.nanmean(cdat[v])
    return out


def bound_cdata(cdata,cutoff=0.05):
    '''Returns upper and lower X percent interval values
    Input
      cdata: list of values
      cutoff: upper and lower percentile'''
    if not cutoff:
        return False
    shp = cdata.shape
    c = cdata.flatten()
    l = np.sort(c[~np.isnan(c)])
    try:
        bounds = l[[int(cutoff*len(l)), int((1-cutoff)*len(l))]]
        cdata[cdata<bounds[0]] = bounds[0]
        cdata[cdata>bounds[1]] = bounds[1]
    except:
        print('cdata all NaN')
    return np.reshape(cdata, shp)


def surf_dist(mask, F):
    '''Computes distance (in nodes) between a starting mask to all other vertices'''
    var = mask+0
    while np.any(var==0):
        frows = np.unique(np.where(np.isin(F,np.where(var>0)[0]))[0])
        v = np.unique(F[frows,:])
        var[v] = var[v] +1
    return np.max(var) - var


def surfdat_smooth(F,cdata,iters=1,cores=8):
    '''Smoothes surface data across neighbouring vertices. This assumes that vertices are evenly spaced and evenly connected.
    TODO: convert to mm vis calibration curves in https://github.com/MELDProject/meld_classifier/blob/9d3d364de86dc207d3a1e5ec11dcab3ef012ebcb/meld_classifier/mesh_tools.py#L17'''
    cdat = copy.deepcopy(cdata)
    for i in range(iters):
        cdat = Parallel(n_jobs=cores)(delayed(avg_neighbours)((F,cdat,n)) for n in range(len(cdat)))
        cdata_smooth = np.array(cdat)
        cdat = copy.deepcopy(cdata_smooth)
    return cdata_smooth


def Laplace_solver(faces,init,maxiters=1e4,conv=1e-6,cores=8):
    '''Solves Laplace equation along vertices of a surface.
      inputs:
        faces: faces of a surface mesh
        init: initial vertex-wise values. Source(s) should have a value of 0, Sink(s) should have a value of 1. NaN values will be masked. Time required scales with the number of unmasked vertices.
        maxiters: maximum iterations to run
        conv: convergence criterion
        cores: cores to use (per iteration)
      outputs:
        LP: Laplace solution (vertex-wise)
        change: sum of absolute changes per iteration (should converge towards 0)'''
    ind_start = np.where(init==0)[0]
    ind_end = np.where(init==1)[0]
    mask = np.where(np.isnan(init))[0]
    # optimize speed
    faces = np.delete(faces, np.where(np.isin(faces,mask))[0],0)
    change = []
    LP = copy.deepcopy(init)
    for iters in range(maxiters):
        LPup = surfdat_smooth(faces,LP,iters=1,cores=cores)
        LPup[ind_start] = 0
        LPup[ind_end] = 1
        LPup[mask] = np.nan
        c = np.nansum(np.abs(LP-LPup))
        change.append(c)
        LP = copy.deepcopy(LPup)
        if c < conv:
            break
    return LP,change


def fillnanvertices(F,V):
    '''Fills NaNs by iteratively nanmean nearest neighbours until no NaNs remain. Can be used to fill missing vertices OR missing vertex cdata.'''
    Vold = copy.deepcopy(V)
    Vnew = copy.deepcopy(V)
    while np.isnan(np.sum(Vnew)):
        # index of vertices containing nan
        vrows = np.unique(np.where(np.isnan(Vnew))[0])
        # replace with the nanmean of neighbouring vertices
        for n in vrows:
            frows = np.where(F == n)[0]
            neighbours = np.unique(F[frows,:])
            Vnew[n] = np.nanmean(Vnew[neighbours], 0)
        if sum(np.isnan(Vold)) == sum(np.isnan(Vnew)): # stop if no changes
            break
        else:
            Vold=Vnew
    return Vnew


def density_interp(indensity, outdensity, cdata, label, method='linear', resourcesdir=resourcesdir):
    '''interpolates data from one surface density onto another via unfolded space
    Inputs:
      indensity: one of '0p5mm', '1mm', '2mm', or 'unfoldiso
      outdensity: one of '0p5mm', '1mm', '2mm', or 'unfoldiso
      cdata: data to be interpolated (same number of vertices, N, as indensity)
      label: 'hipp' or 'dentate'
      method: 'nearest', 'linear', or 'cubic'. 
      resourcesdir: path to hippunfold resources folder
    Outputs: 
      interp: interpolated data
      faces: face connectivity from new surface density'''
    
    VALID_STATUS = {'0p5mm', '1mm', '2mm', 'unfoldiso'}
    if indensity not in VALID_STATUS:
        raise ValueError("results: indensity must be one of %r." % VALID_STATUS)
    if outdensity not in VALID_STATUS:
        raise ValueError("results: outdensity must be one of %r." % VALID_STATUS)
    
    # load unfolded surfaces for topological matching
    startsurf = nib.load(f'{resourcesdir}/canonical_surfs/tpl-avg_space-unfold_den-{indensity}_label-{label}_midthickness.surf.gii')
    vertices_start = startsurf.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    targetsurf = nib.load(f'{resourcesdir}/canonical_surfs/tpl-avg_space-unfold_den-{outdensity}_label-{label}_midthickness.surf.gii')
    vertices_target = targetsurf.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    faces = targetsurf.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data

    # interpolate
    interp = griddata(vertices_start[:,:2], values=cdata, xi=vertices_target[:,:2], method=method)
    # fill any NaNs
    interp = fillnanvertices(faces,interp)
    return interp,faces,vertices_target


def area_rescale(vertices,den,label,APaxis=1):
    '''Most of the time, in unfolded space the anterior and psoterior are overrepresented. This function compresses these regions proportionally to the surface areas of a cononical example'''
    w = 126 if label=='hipp' else 30 # width of unfolded space
    s=15 # surf area smoothing (sigma)
    Pold = vertices[:,APaxis] 

    # compute rescaling from surface areas
    surfarea = nib.load(f'{resourcesdir}/canonical_surfs/tpl-avg_space-unfold_den-{den}_label-{label}_surfarea.shape.gii').darrays[0].data
    surfarea,_,_ = density_interp(den, 'unfoldiso', surfarea.flatten(), label)
    surfarea = np.reshape(surfarea,(w,254))
    surfarea = gaussian_filter(surfarea,sigma=s)

    avg_surfarea = np.mean(surfarea,axis=0)
    rescalefactor = np.cumsum(1/avg_surfarea)
    rescalefactor = rescalefactor - np.min(rescalefactor)
    rescalefactor = rescalefactor/np.max(rescalefactor)
    rescalefactor = rescalefactor+1 - np.linspace(0,1,len(rescalefactor))

    rescalefactor = repmat(rescalefactor,w,1)
    rescalefactor,_,_ = density_interp('unfoldiso', den, rescalefactor.flatten(), label)
    
    Pnew = Pold * rescalefactor
    vertices[:,APaxis] = Pnew
    return vertices


def surface_to_volume(surf_data, out_name, indensity, hippunfold_dir, sub, ses, hemi, space, label='hipp', method='nearest'):
    # from https://github.com/khanlab/hippunfold/blob/master/hippunfold/workflow/scripts/label_subfields_from_vol_coords.py

    # this function labels subfields using the labels in unfolded space, and native space coords (ap, pd) images

    if len(ses)>0: 
        ses = 'ses-'+ses
        uses = '_'+ses 
    else: 
        uses = ''

    nii_ap = f'{hippunfold_dir}/sub-{sub}/{ses}/coords/sub-{sub}{uses}_dir-AP_hemi-{hemi}_space-{space}_label-{label}_desc-laplace_coords.nii.gz'
    nii_pd = f'{hippunfold_dir}/sub-{sub}/{ses}/coords/sub-{sub}{uses}_dir-PD_hemi-{hemi}_space-{space}_label-{label}_desc-laplace_coords.nii.gz'

    # get labels from volumetric unfolded labels
    if indensity != 'unfildiso':
        surf_data_unfoldiso,_,_ = density_interp(indensity,'unfoldiso',surf_data, label, method=method)
    surf_data_unfoldiso = surf_data_unfoldiso.reshape(126,254).T

    # setup the interpolating grid
    spacing_ap = np.linspace(0, 1, surf_data_unfoldiso.shape[0])
    spacing_pd = np.linspace(0, 1, surf_data_unfoldiso.shape[1])
    points = (spacing_ap, spacing_pd)

    # load up the coords
    ap_nib = nib.load(nii_ap)
    pd_nib = nib.load(nii_pd)
    ap_img = ap_nib.get_fdata()
    pd_img = pd_nib.get_fdata()

    # get mask of coords
    mask = np.logical_or(ap_img > 0, pd_img > 0)

    # interpolate
    query_points = np.vstack((ap_img[mask], pd_img[mask])).T
    labelled_points = interpn(points, surf_data_unfoldiso, query_points, method=method)

    # put back into image
    label_img = np.zeros(ap_img.shape, dtype="uint16")
    label_img[mask] = labelled_points

    # save label img
    label_nib = nib.Nifti1Image(label_img, ap_nib.affine, ap_nib.header)
    nib.save(label_nib, out_name)
    return label_img
