import numpy as np
import nibabel as nib
import copy
import glob
from brainspace.mesh.mesh_io import read_surface
from brainspace.plotting import plot_hemispheres, plot_surf, build_plotter
from brainspace.mesh import mesh_creation as mc


try:
    from hippunfold_toolbox import utils
except:
    import utils
from pathlib import Path

resourcesdir=str(Path(utils.__file__).parents[1]) + '/resources'


def surfplot_canonical_foldunfold(cdata, den='0p5mm', excludeDG=False, excludeR=False, tighten_cwindow=False, resourcesdir=resourcesdir, size=[400,200], **qwargs):
    '''
    Plots canonical folded and unfolded surfaces (hipp/dentate; folded/unfolded). This is good for cdata that isn't specific to one subject (eg. maybe it has been averaged across many subjects).
    
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
    if len(cdata.shape)<3: cdata = np.reshape(cdata,[cdata.shape[0],2-excludeR,1])
    if tighten_cwindow>0: 
        for i in range(0,cdata.shape[2]):
            cdata[:,:,i] = utils.bound_cdata(cdata[:,:,i])
    size[1] = size[1]*(cdata.shape[2])
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

    p = plot_surf(surfDict,surfList, array_name=arrName, size=size, nan_color=(0,0,0,0), **qwargs)
    return p



def surfplot_sub_foldunfold(hippunfold_dir, sub, ses, features, hemis=['L','R'], labels=['hipp','dentate'], den='den-0p5mm', modality='T1w', tighten_cwindow=True, rotate=True,  resourcesdir=resourcesdir, size=[400,200], cmap='viridis', **qwargs):
    '''
    Plots subject-specific folded and unfolded surfaces (hipp/dentate; folded/unfolded). 
    
    Inputs are path/filenames, with their specifier present (eg. sub='sub-01', ses='ses-01') 
        if ses doesn't exist, simply set it to ''. 
    features: list of strings. Can include 'thickness', 'curvature', 'gyrification', 'subfields', or any added data that follows the same naming convention
    kwargs: see hhttps://brainspace.readthedocs.io/en/latest/generated/brainspace.plotting.surface_plotting.plot_surf.html#brainspace.plotting.surface_plotting.plot_surf
    '''

    if len(ses)>0: 
        uses = '_'+ses 
    else: 
        uses = ''
    size[0] = size[0]*len(hemis)
    size[1] = size[1]*len(features)

    # load surfaces
    surf = []
    n=0
    for hemi in hemis:
        for space in [modality,'unfold']:
            for label in labels:
                fn1 = f'{hippunfold_dir}/{sub}/{ses}/surf/{sub}{uses}_hemi-{hemi}_space-{space}_{den}_label-{label}_midthickness.surf.gii'
                try:
                    s = read_surface(fn1)
                    if label=='hipp':
                        nptsHipp = s.n_points
                    if space=='unfold':
                        s.Points = s.Points[:,[1,0,2]] # reorient unfold
                        if label=='dentate':
                            s.Points = s.Points + [22,0,0] # translate DG
                    if label=='dentate': # concatenate dentate to hipp
                        s = mc.build_polydata(np.concatenate((oldsurf.Points.copy(), s.Points.copy())),
                                        cells=np.concatenate((oldsurf.GetCells2D().copy(), s.GetCells2D().copy()+nptsHipp)))
                        if hemi=="L" and space=='unfold': # flip L unfolded
                            s.Points[:,0] = -s.Points[:,0]
                    oldsurf = s
                except:
                    print(fn1 + ' failed')
            surf.append(s)
    npts = len(surf[0].Points)

    # rotate surfaces to approx coronal-oblique
    if rotate:
        aff = np.loadtxt(f'{resourcesdir}/xfms/corobl-20deg_xfm.txt')
        for i,h in enumerate(hemis):
            p = np.hstack((surf[i*2].Points, np.ones((npts,1))))
            p = p @ aff
            surf[i*2].Points = p[:,:3]

    # load features data
    ind = [range(nptsHipp), range(nptsHipp,npts)]
    cdat = np.ones([npts,len(hemis),len(features)]) * np.nan
    for h,hemi in enumerate(hemis):
        for l,label in enumerate(labels):
            for f,feature in enumerate(features):
                fn2 = f'{hippunfold_dir}/{sub}/{ses}/surf/{sub}{uses}_hemi-{hemi}_space-{modality}_{den}_label-{label}_*{feature}*.*.gii'
                fn3 = glob.glob(fn2)
                try:
                    cdat[ind[l],h,f]= nib.load(fn3[0]).darrays[0].data
                except:
                    print(fn2 + ' failed')

    # options
    cmaps = np.ones((len(features),len(hemis)*2),dtype=object)
    cmaps[:] = cmap
    for f,feature in enumerate(features):
        if feature=='subfields':
            cdat[ind[1],:,f] = np.nanmax(cdat)+1
            cmaps[f,:] = ('tab10')
        else:
            if tighten_cwindow>0: 
                cdat[:,:,f] = utils.bound_cdata(cdat[:,:,f])

    # set up layout
    surfDict = {}
    surfList = np.ones((len(features),len(hemis)*2),dtype=object)
    arrName = np.ones((len(features),len(hemis)*2),dtype=object)
    for h,hemi in enumerate(hemis):
        surfDict.update({f"{hemi}f":surf[h*2]})
        surfDict.update({f"{hemi}u":surf[h*2 +1]})
        if hemi=='L':
            surfList[:,[0,1]] = np.array([f"{hemi}f",f"{hemi}u"])
        elif hemi=='R':
            surfList[:,[2,3]] = np.array([f"{hemi}u",f"{hemi}f"])
        for f,feature in enumerate(features):
            surf[h*2].append_array(cdat[:,h,f], name=feature, at='point')
            surf[h*2 +1].append_array(cdat[:,h,f], name=feature, at='point')
            arrName[f,:] = feature

    p = plot_surf(surfDict,surfList, array_name=arrName, nan_color=(0,0,0,0), size=size, cmap=cmaps, **qwargs)
    return p

