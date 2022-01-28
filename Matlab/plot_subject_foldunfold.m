function plot_subject_foldunfold(dir,subject,mod)

% testing
% dir = 'hcp1200_hippunfold_vp1.0.0';
% subject = '100206';
% mod = 'gyrification';

window = true;
smooth = 0;

g = [];
g.XLim = [0 1];
figure; hold on;

% subfield colormap
subfs = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-hipp_subfields.label.gii']);

% rotate surface to corobl
try
    try
        rot = importdata([dir '/hippunfold/sub-' subject '/warps/sub-' subject '_desc-affine_from-T1w_to-corobl_type-ras_xfm.txt']);
    catch
        system(['tar -zxf ' dir '/work/sub-' subject '_work.tar.gz work/sub-' subject '/warps/sub-' subject '_desc-affine_from-T1w_to-corobl_type-ras_xfm.txt']);
        rot = importdata(['work/sub-' subject '/warps/sub-' subject '_desc-affine_from-T1w_to-corobl_type-ras_xfm.txt']);
        system(['rm -r work']);
    end
catch
    warning('could not find rotation to corobl');
    rot = eye(4);
end


% surface left hipp
try
    slh = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-hipp_midthickness.surf.gii']);
    v = [slh.vertices, zeros(length(slh.vertices),1)];
    v = rot'*v';
    slh.vertices = v(1:3,:)';
    tuplh = mean(slh.vertices(:,2));
    slh.vertices(:,2) = slh.vertices(:,2) -tuplh; % align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-hipp_' mod '.shape.gii']);
        lh = plot_gifti(slh,c.cdata,window,smooth);
        p = plot_giftiborders(slh,subfs.cdata);
    else
        lh = plot_gifti(slh,subfs.cdata);
        colormap(subfs.labels.rgba(2:end,1:3))
    end
catch
    warning([subject ' hemi-L ' mod ' hipp not found']);
end

% surface left dentate
try
    sld = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-dentate_midthickness.surf.gii']);
    v = [sld.vertices, zeros(length(sld.vertices),1)];
    v = rot'*v';
    sld.vertices = v(1:3,:)';
    sld.vertices(:,2) = sld.vertices(:,2) -tuplh; % align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-dentate_' mod '.shape.gii']);
        ld = plot_gifti(sld,c.cdata,window,smooth);
    else
        ld = plot_gifti(sld);
        ld.FaceColor = 'y';
    end
catch
    warning([subject ' hemi-L ' mod ' dentate not found']);
end

% surface left unfolded hipp
try
    sluh = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-unfolded_den-0p5mm_label-hipp_midthickness.surf.gii']);
    sluh.vertices(:,[1 2 3]) = sluh.vertices(:,[2 1 3]);
    sluh.vertices(:,1) = -sluh.vertices(:,1); % flip left
    g = gca;
    sluh.vertices(:,1) = sluh.vertices(:,1) + (g.XLim(1)-max(sluh.vertices(:,1))) -1; % translate to left edge
    sluh.vertices(:,2) = sluh.vertices(:,2) -mean(sluh.vertices(:,2)); % align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-hipp_' mod '.shape.gii']);
        luh = plot_gifti(sluh,c.cdata,window,smooth);
        p = plot_giftiborders(sluh,subfs.cdata);
    else
        luh = plot_gifti(sluh,subfs.cdata);
    end
catch
    warning([subject ' hemi-L ' mod ' unfolded hipp not found']);
end

% surface left unfolded dentate
try
    slud = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-unfolded_den-0p5mm_label-dentate_midthickness.surf.gii']);
    slud.vertices(:,[1 2 3]) = slud.vertices(:,[2 1 3]);
    slud.vertices(:,1) = -slud.vertices(:,1); % flip left
    g = gca;
    slud.vertices(:,1) = slud.vertices(:,1) + (g.XLim(1)-max(slud.vertices(:,1))) -1; % translate to left edge
    slud.vertices(:,2) = slud.vertices(:,2) -mean(slud.vertices(:,2)); % align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-L_space-T1w_den-0p5mm_label-dentate_' mod '.shape.gii']);
        lud = plot_gifti(slud,c.cdata,window,smooth);
    else
        lud = plot_gifti(slud);
        lud.FaceColor = 'y';
    end
catch
    warning([subject ' hemi-L ' mod ' unfolded dentate not found']);
end

% surface right hipp
try
    srh = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-T1w_den-0p5mm_label-hipp_midthickness.surf.gii']);
    v = [srh.vertices, zeros(length(srh.vertices),1)];
    v = rot'*v';
    srh.vertices = v(1:3,:)';
    g = gca;
    tright = (g.XLim(2)-min(srh.vertices(:,1))) +1;
    srh.vertices(:,1) = srh.vertices(:,1) + tright; % translate to right edge
    tuprh = mean(srh.vertices(:,2));
    srh.vertices(:,2) = srh.vertices(:,2) - tuprh;% align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-T1w_den-0p5mm_label-hipp_' mod '.shape.gii']);
        rh = plot_gifti(srh,c.cdata,window,smooth);
        p = plot_giftiborders(srh,subfs.cdata);
    else
        rh = plot_gifti(srh,subfs.cdata);
        colormap(subfs.labels.rgba(2:end,1:3))
    end
catch
    warning([subject ' hemi-R ' mod ' hipp not found']);
end

% surface right dentate
try
    srd = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-T1w_den-0p5mm_label-dentate_midthickness.surf.gii']);
    v = [srd.vertices, zeros(length(srd.vertices),1)];
    v = rot'*v';
    srd.vertices = v(1:3,:)';
    srd.vertices(:,1) = srd.vertices(:,1) + tright;
    srd.vertices(:,2) = srd.vertices(:,2) - tuprh;
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-T1w_den-0p5mm_label-dentate_' mod '.shape.gii']);
        rd = plot_gifti(srd,c.cdata,window,smooth);
    else
        rd = plot_gifti(srd);
        rd.FaceColor = 'y';
    end
catch
    warning([subject ' hemi-R ' mod ' dentate not found']);
end

% surface right unfolded hipp
try
    sruh = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-unfolded_den-0p5mm_label-hipp_midthickness.surf.gii']);
    sruh.vertices(:,[1 2 3]) = sruh.vertices(:,[2 1 3]);
    g = gca;
    sruh.vertices(:,1) = sruh.vertices(:,1) + (g.XLim(2)-min(sruh.vertices(:,1))) +1; % translate to right edge
    sruh.vertices(:,2) = sruh.vertices(:,2) -mean(sruh.vertices(:,2)); % align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-T1w_den-0p5mm_label-hipp_' mod '.shape.gii']);
        ruh = plot_gifti(sruh,c.cdata,window,smooth);
        p = plot_giftiborders(sruh,subfs.cdata);
    else
        ruh = plot_gifti(sruh,subfs.cdata);
    end
catch
    warning([subject ' hemi-R ' mod ' unfolded hipp not found']);
end

% surface right unfolded dentate
try
    srud = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-unfolded_den-0p5mm_label-dentate_midthickness.surf.gii']);
    srud.vertices(:,[1 2 3]) = srud.vertices(:,[2 1 3]);
    g = gca;
    srud.vertices(:,1) = srud.vertices(:,1) + (g.XLim(2)-min(srud.vertices(:,1))) +1; % translate to right edge
    srud.vertices(:,2) = srud.vertices(:,2) -mean(srud.vertices(:,2)); % align middle
    if ~strcmp(mod,'subfields')
        c = gifti([dir '/hippunfold/sub-' subject '/surf/sub-' subject '_hemi-R_space-T1w_den-0p5mm_label-dentate_' mod '.shape.gii']);
        rud = plot_gifti(srud,c.cdata,window,smooth);
    else
        rud = plot_gifti(srud);
        rud.FaceColor = 'y';
    end
catch
    warning([subject ' hemi-R ' mod ' unfolded dentate not found']);
end

if window && ~strcmp(mod,'subfields')
    cl = sort([lh.FaceVertexCData; rh.FaceVertexCData]);
    caxis([cl(round(0.05*length(cl))) cl(round(0.95*length(cl)))])
end

colorbar;
light;