import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D, art3d  # noqa: F401 unused import
import nibabel as nib
import copy
import utils

hippunfolddir = '/home/bic/jordand/graham/scratch/opt/hippunfold'


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



def surfplot_cdata(ax,cdata,f,v,cwindow=False):
    '''create surface in existing axis
    Input
      ax: axis (of type subplot_kw={'projection': "3d"})
      cdata: color of surface
      f: faces
      v: vertices
      window cdata [True,False, or Tuple for custom window]'''
    cdata = cdata_vertex_to_face(cdata,f)
    # make window if needed
    if type(cwindow) == type(True):
        if not cwindow:
            norm = plt.Normalize(np.min(cdata), np.max(cdata)) 
            colors = plt.cm.viridis(norm(cdata))
        elif cwindow: # use default
            norm = plt.Normalize(window_cdata(cdata)[0],window_cdata(cdata)[1]) 
            colors = plt.cm.viridis(norm(cdata))
    else: # hard set window
        norm = plt.Normalize(cwindow[0],cwindow[1]) 
        colors = plt.cm.viridis(norm(cdata))

    pc = art3d.Poly3DCollection(v[f], facecolors=colors)
    ax.add_collection(pc)

    ax.set_xlim([np.min(v[:,0]),np.max(v[:,0])])
    ax.set_ylim([np.min(v[:,1]),np.max(v[:,1])])
    ax.set_zlim([np.min(v[:,2]),np.max(v[:,2])])
    ax.view_init(elev=90, azim=-90)
    ax = set_axes_equal(ax)
    ax.set_axis_off()
    return ax



def plot_gifti(gii,map='fill',window=False,smooth=0):
    ''' plots a gifti structure. 
    Inputs
      gii: gfiti object as loaded by nibabel
      map: colour data [default all 1s]
      window: percentile to window colour axis around
      smooth: number of NN vertex smoothing iterations'''
    cdata = copy.deepcopy(map) # new variable rather than pointer
    vertices = gii.get_arrays_from_intent('NIFTI_INTENT_POINTSET')[0].data
    faces = gii.get_arrays_from_intent('NIFTI_INTENT_TRIANGLE')[0].data
    # if this doesn't exist, make ones
    if cdata=='fill':
        cdata = np.ones(vertices.shape[0])
    # smooth if needed
    if smooth>=1:
        cdata = utils.surfdat_smooth(faces,cdata,smooth);
    
    fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(36,12), subplot_kw={'projection': "3d"})
    surfplot_cdata(axes,cdata,faces,vertices,window) 
    return fig, axes
