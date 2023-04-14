import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import art3d
import nibabel as nib
import copy
try:
    from hippunfold_toolbox import utils
except:
    import utils
from pathlib import Path

resourcesdir=str(Path(utils.__file__).parents[1]) + '/resources'


def set_axes_equal(ax):
    '''Make axes of 3D plot have equal scale.  This is one possible solution to Matplotlib's
    ax.set_aspect('equal') and ax.axis('equal') not working for 3D.
    Input
      ax: a matplotlib axis, e.g., as output from plt.gca().'''

    x_limits = ax.get_xlim3d()
    y_limits = ax.get_ylim3d()
    z_limits = ax.get_zlim3d()

    x_range = abs(x_limits[1] - x_limits[0])
    x_middle = np.mean(x_limits)
    y_range = abs(y_limits[1] - y_limits[0])
    y_middle = np.mean(y_limits)
    z_range = abs(z_limits[1] - z_limits[0])
    z_middle = np.mean(z_limits)

    # The plot bounding box is a sphere in the sense of the infinity
    # norm, hence I call half the max range the plot radius.
    plot_radius = 0.5*max([x_range, y_range, z_range])

    ax.set_xlim3d([x_middle - plot_radius, x_middle + plot_radius])
    ax.set_ylim3d([y_middle - plot_radius, y_middle + plot_radius])
    ax.set_zlim3d([z_middle - plot_radius, z_middle + plot_radius])
    return ax



def cdata_vertex_to_face(c,faces):
    '''Interpolates vertex data to the nearest face
    Input
      c: vertex data
      faces: face data'''
    if len(c.shape)>1:
        cf = np.zeros([len(faces),c.shape[1]])
        for f in range(len(faces)):
            cf[f,:] = np.mean(c[faces[f],:],axis=0)
    else:
        cf = np.zeros(len(faces))
        for f in range(len(faces)):
            cf[f] = np.mean(c[faces[f]])
    return cf



def window_cdata(cdata,cutoff=0.05):
    '''Returns upper and lower X percent interval values
    Input
      cdata: list of values
      cutoff: upper and lower percentile'''
    if not cutoff:
        return False
    l = np.sort(cdata.flatten())
    return l[[int(cutoff*len(l)), int((1-cutoff)*len(l))]]



def surfplot_cdata(ax,cdat,f,v,cwindow=False,cmap=False):
    '''create surface in existing axis
    Input
      ax: axis (of type subplot_kw={'projection': "3d"})
      cdata: color of surface
      f: faces
      v: vertices
      cwindow: whether to narrow the window of cdata [True,False, or Tuple for custom window]
      cmap: whether to use a custom colormap [Nx3 where N is the number of unique cdat values]'''
    cdata = cdata_vertex_to_face(cdat,f)
    # make window if needed
    if type(cwindow) == type(True):
        if not cwindow:
            norm = plt.Normalize(np.min(cdata), np.max(cdata)) 
        elif cwindow: # use default
            norm = plt.Normalize(window_cdata(cdata)[0],window_cdata(cdata)[1]) 
    else: # hard set window
        norm = plt.Normalize(cwindow[0],cwindow[1]) 
    # set colours if needed
    if type(cmap) == type(False):
        colors = plt.cm.viridis(norm(cdata))
    else:
        colors = np.zeros([len(cdat),cmap.shape[1]])
        u,i = np.unique(cdat,return_index=True)
        for ii in range(len(u)):
            colors[cdat==u[ii],:] = cmap[ii,:]
        colors = cdata_vertex_to_face(colors,f)
    
    pc = art3d.Poly3DCollection(v[f], facecolors=colors)
    ax.add_collection(pc)

    ax.set_xlim([np.min(v[:,0]),np.max(v[:,0])])
    ax.set_ylim([np.min(v[:,1]),np.max(v[:,1])])
    ax.set_zlim([np.min(v[:,2]),np.max(v[:,2])])
    ax.view_init(elev=90, azim=-90)
    ax = set_axes_equal(ax)
    ax.set_axis_off()
    return ax



def plot_gifti(gii,map='fill',window=False,smooth=0,cmap=False):
    ''' plots a gifti structure. 
    Inputs
      gii: gfiti object as loaded by nibabel
      map: colour data [default all 1s]
      window: percentile to window colour axis around
      smooth: number of NN vertex smoothing iterations
      cmap: whether to use a custom colormap [Nx3 where N is the number of unique cdat values]'''
    cdata = copy.deepcopy(map) # new variable rather than pointer
    vertices = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    faces = gii.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data
    # if this doesn't exist, make ones
    if cdata=='fill':
        cdata = np.ones(vertices.shape[0])
    # smooth if needed
    if smooth>=1:
        cdata = utils.surfdat_smooth(faces,cdata,smooth,cmap=False);
    
    fig, ax = plt.subplots(nrows=1, ncols=1, figsize=(36,12), subplot_kw={'projection': "3d"})
    surfplot_cdata(ax,cdata,faces,vertices,window,cmap) 
    return fig, ax


def surfplot_canonical_foldunfold(ax,cdata,den='2mm',excludeDG=False,excludeR=False,resorcesdir=resourcesdir,cwindow=False,cmap=False):
    '''cdata order is always in order: Lhipp, Ldg, Rhipp, Rdg
      cwindow: whether to narrow the window of cdata [True,False, or Tuple for custom window]
      cmap: whether to use a custom colormap [Nx3 where N is the number of unique cdat values]'''

    # load canonical and unfolded surfaces
    gii = nib.load(f'{resorcesdir}/canonical_surfs/tpl-avg_space-canonical_den-{den}_label-hipp_midthickness.surf.gii')
    v = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    f = gii.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data
    gii = nib.load(f'{resorcesdir}/canonical_surfs/tpl-avg_space-canonical_den-{den}_label-dentate_midthickness.surf.gii')
    vdg = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    fdg = gii.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data
    gii = nib.load(f'{resorcesdir}/unfold_template_hipp/tpl-avg_space-unfold_den-{den}_midthickness.surf.gii')
    vu = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    gii = nib.load(f'{resorcesdir}/unfold_template_dentate/tpl-avg_space-unfold_den-{den}_midthickness.surf.gii')
    vudg = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data

    # reorient unfolded
    vu = vu[:,[1,0,2]]
    vudg = vudg[:,[1,0,2]]
    # translate unfolded dg
    vudg = vudg + [22, 0, 0]
    # translate folded
    translatx = np.max(vudg[:,0]) - np.min(v[:,0]) + 2
    translaty = np.mean(vudg[:,1]) - np.mean(v[:,1])
    v = v + [translatx, translaty, 0]
    vdg = vdg + [translatx, translaty, 0]

    if excludeDG:
        vall = np.concatenate((v, vu,))
        fall = np.concatenate((f, f+len(v)))
    else:
        vall = np.concatenate((v, vdg,        vu,                vudg))
        fall = np.concatenate((f, fdg+len(v), f+len(v)+len(vdg), fdg+len(v)+len(vdg)+len(vu)))


    vflip = np.ones(vall.shape)
    vflip[:,0] = -1
    vallL = vall*vflip

    if excludeR:
        vLR = vallL
        fLR = fall
        cdata = np.concatenate((cdata,cdata))
    else:
        # R translat
        translatx = np.max(vallL[:,0]) - np.min(vall[:,0]) + 2
        vallR = vall + [translatx, 0, 0]

        vLR = np.concatenate((vallL, vallR))
        fLR = np.concatenate((fall, fall+len(vall)))

        # replicate cdata for unfolded space
        cdata = np.concatenate((cdata[:int(len(cdata)/2)], cdata[:int(len(cdata)/2)],
                                cdata[int(len(cdata)/2):], cdata[int(len(cdata)/2):]))

    surfplot_cdata(ax,cdata,fLR,vLR,cwindow,cmap)
    return ax

def highlight_subfields(ax,gii,cdata):
    vertices = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    faces = gii.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data
    borders = cdata
    
    # edges = utils.surfdat_smooth(faces,borders)
    # edges = np.remainder(edges,1)>0
    # ax.scatter(vertices[edges,0],vertices[edges,1],vertices[edges,2],color=[0,0,0,1])
    
    for i in np.unique(borders):
        edges = utils.surfdat_smooth(faces,borders==i)
        edges = np.where(np.logical_and(np.remainder(edges,1)>0, borders==[i-1]))[0]
        ax.scatter(vertices[edges,0],vertices[edges,1],vertices[edges,2],color=[0,0,0,1])
    return ax
