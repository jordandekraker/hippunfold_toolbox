%% automatically define PD gradient sink (i.e. approximates DGgcl)

% This portion of the code was used in the original publication, but future
% work will define the DGgcl separately

% The current section does fast marching from EC within each bin of AP gradient.
% this is used to define the sink (approximately the DG granule cell layer, or
% most distal ~10% of the fast march)

vertunc = zeros(sz);
vertunc(labelmap==4) = 1;


Laplace_AP_bin=zeros(sz);
Laplace_AP_bin(idxgm) = Laplace_AP;
Laplace_AP_bin = ceil(Laplace_AP_bin*25); % 25 discreet bins seems to work well

Geodist_PD = nan(sz);
Geodist_temp = nan(sz);

%run separately on each AP bin
for AP = 1:25
    fg = (Laplace_AP_bin == AP); %use grey matter of this bin
    vel = zeros(size(labelmap)); %initialize / clear previous
    vel(fg) = 0.5;
    vel(sourcePD) = 1;
    [r,c,v] = ind2sub(size(labelmap),sourcePD); %ind of start
    
    Geodist_temp = perform_fast_marching(vel,[r c v]');
    Geodist_temp(~fg) = nan;
    Geodist_temp(Geodist_temp>10000) = nan; %10000 step max
    Geodist_temp = Geodist_temp/max(Geodist_temp(:)); %rescale 0 to 1
    Geodist_PD(fg) = Geodist_temp(fg); %save results for this bin
end

% dilate dark band (or cyst) over distal parts of geodist_PD to get only
% approximate granule cell layer
se = ones(3,3,3);
SRLMorCyst = ismember(labelmap,2);
sink_main = (imdilate(SRLMorCyst,se) & Geodist_PD>=0.9); %last ~10% of geodist is DG


% now find where DG passes through the vertical component of the uncus.
% This will be the part of hippocampus where our heuristic 'SRLM on
% vertical component' label ends (i.e. where it borders clear label)
sf = zeros(3,3,3); sf(2,:,:) = 1; sf(:,2,:) = 1; sf (:,:,2) = 1;

sink_unc = false(sz);
sink_unc(imdilate(labelmap==0,se) & imdilate(vertunc,se) & Geodist_PD>0.5) = 1; % intersection of all 3 labels