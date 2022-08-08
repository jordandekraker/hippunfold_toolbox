function cdata_nonan = surfdat_fillnans(F,cdata)

% fills nan values by averaging connected real values iteratively until no
% nans remain

while isnan(sum(cdata))
    newV = cdata;
    i = find(isnan(newV)); % index of vertices==Nan
    for n = 1:length(i)
        f = find(any(F==i(n),2));
        v = unique(F(f,:));
        newV(i(n)) = nanmean(cdata(v));
    end
    cdata = newV;
end
cdata_nonan = cdata;