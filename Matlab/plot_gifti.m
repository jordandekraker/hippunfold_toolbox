function p = plot_gifti(gii,map,window,smooth)

% plots a gifti structure. can provide a custom map (or cdata), windowing
% of that map, and optional smoothing;

if ~exist('window','var')
    window = false;
end
if ~exist('smooth','var')
    smooth = 0;
end

p = patch('Faces',gii.faces,'Vertices',gii.vertices);
p.FaceColor = [17 17 17]/255; % default grey
p.LineStyle = 'none';
material dull;
axis equal tight off;
% colormap('jet');
% light;
material dull;

if exist('map','var')
    if smooth>=1
        map = surfdat_smooth(gii.faces,map(:),smooth);
    end
    if window==true % default. 95% window
        t = sort(map(:));
        t(isnan(t)) = [];
        window = [t(round(length(t)*.05)) t(round(length(t)*.95))];
        caxis(window);
    elseif window==false
    else % provide custom windowing
        caxis(window);
    end
    p.FaceVertexCData = map(:);
    p.FaceColor = 'flat';
%     colorbar;
end
