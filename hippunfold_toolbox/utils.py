import numpy as np
import copy
from joblib import Parallel, delayed
import warnings
from scipy.interpolate import griddata
from scipy.interpolate import NearestNDInterpolator
import nibabel as nib

def avg_neighbours(invar):
    '''Averages vertex-wise data at vertex n with its neighbouring vertices. F, cdat, n should be passed as a tuple (for easier parallel).'''
    F,cdat,n = invar
    frows = np.where(F==n)[0]
    v = np.unique(F[frows,:])
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        out = np.nanmean(cdat[v])
    return out



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
    Vnew = copy.deepcopy(V)
    while np.isnan(np.sum(Vnew)):
        # index of vertices containing nan
        vrows = np.unique(np.where(np.isnan(Vnew))[0])
        # replace with the nanmean of neighbouring vertices
        for n in vrows:
            frows = np.where(F == n)[0]
            neighbours = np.unique(F[frows,:])
            Vnew[n] = np.nanmean(Vnew[neighbours], 0)
    return Vnew



def density_interp(indensity, outdensity, cdata, method='linear', resources_dir='/data/mica3/opt/hippunfold/hippunfold/resources'):
    '''interpolates data from one surface density onto another via unfolded space
    Inputs:
      indensity: one of '0p5mm', '1mm', '2mm', or 'unfoldiso
      outdensity: one of '0p5mm', '1mm', '2mm', or 'unfoldiso
      cdata: data to be interpolated (same number of vertices, N, as indensity)
      method: 'nearest', 'linear', or 'cubic'. 
      resources_dir: path to hippunfold resources folder
    Outputs: 
      interp: interpolated data
      faces: face connectivity from new surface density'''
    
    VALID_STATUS = {'0p5mm', '1mm', '2mm', 'unfoldiso'}
    if indensity not in VALID_STATUS:
        raise ValueError("results: indensity must be one of %r." % VALID_STATUS)
    if outdensity not in VALID_STATUS:
        raise ValueError("results: outdensity must be one of %r." % VALID_STATUS)
    
    # load unfolded surfaces for topological matching
    startsurf = nib.load(f'{resources_dir}/unfold_template_hipp/tpl-avg_space-unfold_den-{indensity}_midthickness.surf.gii')
    vertices_start = startsurf.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    targetsurf = nib.load(f'{resources_dir}/unfold_template_hipp/tpl-avg_space-unfold_den-{outdensity}_midthickness.surf.gii')
    vertices_target = targetsurf.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    faces = targetsurf.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data

    # interpolate
    interp = griddata(vertices_start[:,:2], values=cdata, xi=vertices_target[:,:2], method=method)
    # fill any NaNs
    interp = fillnanvertices(faces,interp)
    return interp,faces,vertices_target
