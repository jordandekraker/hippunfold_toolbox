import numpy as np
import copy
from joblib import Parallel, delayed
import warnings


def avg_neighbours(invar):
    '''Averages vertex-wise data at vertex n with its neighbouring vertices. F, cdat, n should be passed as a tuple (for easier parallel).'''
    F,cdat,n = invar
    f = np.where(F==n)[0]
    v = np.unique(F[f,:])
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
