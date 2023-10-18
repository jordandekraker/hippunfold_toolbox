import numpy as np
import glob
import os
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
import pygeodesic.geodesic as geodesic


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

def surfdat_smooth(F, cdata, iters=1, cores=8):
    '''Smoothes surface data across neighbouring vertices. This assumes that vertices are evenly spaced and evenly connected.
    TODO: convert to mm vis calibration curves in https://github.com/MELDProject/meld_classifier/blob/9d3d364de86dc207d3a1e5ec11dcab3ef012ebcb/meld_classifier/mesh_tools.py#L17'''
    cdat = copy.deepcopy(cdata)
    for i in range(iters):
        cdat = Parallel(n_jobs=cores)(delayed(avg_neighbours)((F,cdat,n)) for n in range(len(cdat)))
        cdata_smooth = np.array(cdat)
        cdat = copy.deepcopy(cdata_smooth)
    return cdata_smooth


def profile_align(P,V,F, patchdist=None, maxroll=5):
    '''Aligns microstructural profiles in the depth direction across a set of surfaces.
    inputs:
      P: a VxD matrix of intensities (vertices x depths)
      V: the midthickness surface vertices
      F: the midthickness surface faces
      patchdist: radius (in mm) of geodesic distance to compute the average profile. If None then all profiles are used
      maxroll: maximum shift
    Outputs:
      Paligned: a matrix the same size as P
    pads profiles by maxroll, then rolls them by +/- maxroll until maximum overlap with the patch average is achieved'''
    P = np.pad(P,((0,0),(maxroll,maxroll)),mode='edge')
    Paligned = np.ones(P.shape)*np.nan

    if patchdist==None:
        p_mean = np.nanmean(P,axis=0)
        # get R for all rolls
        rolls = np.arange(-maxroll,maxroll+1)
        R = np.zeros((len(P),len(rolls)))
        for o,offset in enumerate(rolls):
            p_mean_off = np.reshape(np.roll(p_mean,offset),(1,len(p_mean)))
            R[:,o] = np.corrcoef(p_mean_off,P)[1:,0]
        Rbest = np.argmax(R,axis=1)
        # keep only the best roll
        for v in range(len(V)):
            Paligned[v,:] = np.roll(P[v,:],-rolls[Rbest[v]])
    else:
        geoalg = geodesic.PyGeodesicAlgorithmExact(V, F)
        for v in range(len(V)):
            # use a patch around the given vertex as the averaged reference
            dist,_ = geoalg.geodesicDistances(np.array([v]), None)
            p_mean = np.nanmean(P[dist<patchdist,:],axis=0)
            rolls = np.arange(-maxroll,maxroll+1)
            R = np.zeros((len(rolls)))
            for o,offset in enumerate(rolls):
                p_mean_off = np.reshape(np.roll(p_mean,offset),(1,len(p_mean)))
                R[o] = np.corrcoef(p_mean_off,P[v,:])[0,1]
            Rbest = np.argmax(R)
            Paligned[v,:] = np.roll(P[v,:],-rolls[Rbest])
    return Paligned[:,maxroll:-maxroll]
      

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


def surface_to_volume(surf_data, indensity, hippunfold_dir, sub, ses, hemi, space='*', label='hipp', save_out_name=None, method='nearest'):
    # from https://github.com/khanlab/hippunfold/blob/master/hippunfold/workflow/scripts/label_subfields_from_vol_coords.py

    # this function labels voxels using data on a folded/unfolded surface (midthickness or any), and native space coords (ap, pd) images
    # TODO: consider trying to simplify inputs specifying the coords paths?

    if len(ses)>0: 
        ses = 'ses-'+ses
        uses = '_'+ses 
    else: 
        uses = ''

    nii_ap = glob.glob(f'{hippunfold_dir}/sub-{sub}/{ses}/coords/sub-{sub}{uses}_dir-AP_hemi-{hemi}_space-{space}_label-{label}_desc-laplace_coords.nii.gz')[0]
    nii_pd = glob.glob(f'{hippunfold_dir}/sub-{sub}/{ses}/coords/sub-{sub}{uses}_dir-PD_hemi-{hemi}_space-{space}_label-{label}_desc-laplace_coords.nii.gz')[0]
    nii_mask = glob.glob(f'{hippunfold_dir}/sub-{sub}/{ses}/anat/sub-{sub}{uses}_hemi-{hemi}_space-{space}_*_dseg.nii.gz')[0]

    # resample surface data into APxPD shape
    surf_data[np.isnan(surf_data)] = -999
    if indensity != 'unfildiso':
        surf_data_unfoldiso,_,_ = density_interp(indensity,'unfoldiso',surf_data, label, method=method)
    surf_data_unfoldiso = surf_data_unfoldiso.reshape(126,254).T
    surf_data_unfoldiso[surf_data_unfoldiso==-999] = np.nan

    # undo unfolded space warp
    warp = glob.glob(f'{hippunfold_dir}/../work/sub-{sub}/{ses}/warps/sub-{sub}{uses}_hemi-{hemi}_space-unfold_desc-SyN_from-*_to-subject_type-itk_xfm.nii.gz')
    if not warp: raise Warning("No unfolded space warp found. It may be that your HippUnfold output work dir is tarred, or you ran hippunfold without unfolded space registration. Proceeding without unfolded space registration")
    try:
        t = nib.load(warp[0])
        tmp_nib = nib.Nifti1Image(surf_data_unfoldiso, t.affine)
        nib.save(tmp_nib, "tmp.nii.gz")
        if method=="nearest": 
            meth = "NearestNeighbor" 
        elif method=="linear": 
            meth="Linear"
        t = os.system(f"antsApplyTransforms -i tmp.nii.gz -r tmp.nii.gz -o tmpWarped.nii.gz -t {warp[0]} -n {meth}")
        if t!=0: raise Error("ANTs not found")
        surf_data_unfoldiso = nib.load("tmpWarped.nii.gz").get_fdata()[:,:,0]
        os.system("rm tmp.nii.gz tmpWarped.nii.gz")
    except:
        raise Warning("error in unfolded space registration")

    # setup the interpolating grid
    spacing_ap = np.linspace(0, 1, 254)
    spacing_pd = np.linspace(0, 1, 126)
    points = (spacing_ap, spacing_pd)

    # load up the coords
    ap_nib = nib.load(nii_ap)
    pd_nib = nib.load(nii_pd)
    ap_img = ap_nib.get_fdata()
    pd_img = pd_nib.get_fdata()

    # get mask of coords
    mask_nib = nib.load(nii_mask)
    mask_img = mask_nib.get_fdata()
    if label=='hipp':
        mask = np.logical_and(mask_img > 0, mask_img < 6)
    elif label=='dentate':
        mask = mask_img==6
    else:
        mask = mask_img>0

    # interpolate
    query_points = np.vstack((ap_img[mask], pd_img[mask])).T
    labelled_points = interpn(points, surf_data_unfoldiso, query_points, method=method)

    # put back into image
    label_img = np.zeros(ap_img.shape, dtype="uint16")
    label_img[mask==1] = labelled_points
    
    if save_out_name:
        # save label img
        label_nib = nib.Nifti1Image(label_img, ap_nib.affine, ap_nib.header)
        nib.save(label_nib, save_out_name)
    return label_img


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

