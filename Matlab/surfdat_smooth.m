function cdata_smooth = surfdat_smooth(F,cdata,smoothiters)

% smooths surface data by averaging connected real values. Can be repeated
% smoothiters times. 

if ~exist('smoothiters','var')
    smoothiters = 1;
end

cdata_smooth = cdata;

for i = 1:smoothiters
    newV = cdata_smooth;
    for n = 1:length(newV)
        f = find(any(F==n,2));
        v = unique(F(f,:));
        newV(n) = nanmean(cdata_smooth(v));
    end
    cdata_smooth = newV;
end
