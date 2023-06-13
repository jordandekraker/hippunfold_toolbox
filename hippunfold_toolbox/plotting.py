import numpy as np
import nibabel as nib
import copy
from brainspace.mesh.mesh_io import read_surface
from brainspace.plotting import plot_hemispheres, plot_surf, build_plotter
from brainspace.mesh import mesh_creation as mc


try:
    from hippunfold_toolbox import utils
except:
    import utils
from pathlib import Path

resourcesdir=str(Path(utils.__file__).parents[1]) + '/resources'


def surfplot_canonical_foldunfold(cdata, den='0p5mm', excludeDG=False, excludeR=False, tighten_cwindow=False, resourcesdir=resourcesdir, size=[800,200], **qwargs):
    '''
    cdata: array with the shape Vx2xF, where V is the number of vertices (including DG unless specified), 2 is the number of hemispheres (unless specified), and F is the number of rows/features
    kwargs: see hhttps://brainspace.readthedocs.io/en/latest/generated/brainspace.plotting.surface_plotting.plot_surf.html#brainspace.plotting.surface_plotting.plot_surf
    '''
    rh = read_surface(f'{resourcesdir}/canonical_surfs/tpl-avg_space-canonical_den-{den}_label-hipp_midthickness.surf.gii')
    ru = read_surface(f'{resourcesdir}/unfold_template_hipp/tpl-avg_space-unfold_den-{den}_midthickness.surf.gii')

    # reorient unfolded
    ru.Points = ru.Points[:,[1,0,2]]

    if not excludeDG:
        ud = read_surface(f'{resourcesdir}/unfold_template_dentate/tpl-avg_space-unfold_den-{den}_midthickness.surf.gii')
        hd = read_surface(f'{resourcesdir}/canonical_surfs/tpl-avg_space-canonical_den-{den}_label-dentate_midthickness.surf.gii')
        # reorient unfolded
        ud.Points = ud.Points[:,[1,0,2]]
        # translate unfolded dg
        ud.Points = ud.Points + [22, 0, 0]
        # add to original
        npts = rh.n_points
        rh = mc.build_polydata(np.concatenate((rh.Points.copy(), hd.Points.copy())),
                                    cells=np.concatenate((rh.GetCells2D().copy(), hd.GetCells2D().copy()+npts)))
        ru = mc.build_polydata(np.concatenate((ru.Points.copy(), ud.Points.copy())),
                                cells=np.concatenate((ru.GetCells2D().copy(), ud.GetCells2D().copy()+npts)))

    # flip to get left hemisphere
    lh = mc.build_polydata(rh.Points.copy(), cells=rh.GetCells2D().copy())
    lh.Points[:,0] = -lh.Points[:,0]
    lu = mc.build_polydata(ru.Points.copy(), cells=ru.GetCells2D().copy())
    lu.Points[:,0] = -lu.Points[:,0]

    # get some formatting
    if excludeR: cdata = np.reshape(cdata,[cdata.shape[0],1,-1])
    if tighten_cwindow>0: 
        for i in range(0,cdata.shape[2]):
            c = cdata[:,:,i]
            cwindow = utils.window_cdata(c)
            c[c<cwindow[0]] = cwindow[0]
            c[c>cwindow[1]] = cwindow[1]
            cdata[:,:,i] = c
    size[1] = size[1]*(cdata.shape[2]+1)
    surfDict = {"lh":lh, "lu":lu, "rh":rh, "ru": ru}

    # loop through F to add cdata features
    surfList = np.empty((0,2))
    arrName = np.empty((0,2))
    for i in range(0,cdata.shape[2]):
        lh.append_array(cdata[:,0,i], name=f'lh_array{i}', at='point')
        lu.append_array(cdata[:,0,i], name=f'lu_array{i}', at='point')
        surfList = np.vstack((surfList, np.array(['lh','lu'])))
        arrName = np.vstack((arrName, np.array([f'lh_array{i}',f'lu_array{i}'])))

    # consider adding hemi-R
    if not excludeR:
        surfList = np.hstack((surfList, np.flip(surfList,1)))
        arrName = np.hstack((arrName, np.flip(arrName,1)))
        for i in range(0,cdata.shape[2]):
            rh.append_array(cdata[:,1,i], name=f'rh_array{i}', at='point')
            ru.append_array(cdata[:,1,i], name=f'ru_array{i}', at='point')
            surfList[i,2] = surfList[i,2].replace('l','r')
            surfList[i,3] = surfList[i,3].replace('l','r')
            arrName[i,2] = arrName[i,2].replace('l','r')
            arrName[i,3] = arrName[i,3].replace('l','r')

    p = plot_surf(surfDict,surfList, array_name=arrName, embed_nb=True, size=size, **qwargs)
    return p



