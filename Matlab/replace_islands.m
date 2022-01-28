function out = replace_islands(labelmap)
% this function looks for islands (26NN) of any given label and replaces it
% with the mode of all immediately surrounding labels

labels = unique(labelmap(:));
se = ones([3,3,3]); %26 NN
% se = strel('sphere',1); % 6NN
out = labelmap;

for ll = 1:length(labels)
    l = labels(ll);
    islands = bwconncomp(labelmap==l,26);
    if islands.NumObjects >1
        % get island sizes
        isizes = [];
        for i = 1:islands.NumObjects
            isizes(i) = length(islands.PixelIdxList{i});
        end
        [~,islandorder] = sort(isizes,'descend');
        % replace smaller islands
        for ii = islandorder(2:end)
            tmp = zeros(size(labelmap));
            tmp(islands.PixelIdxList{ii}) = 1;
            tmp2 = imdilate(tmp,se);
            newval = mode(labelmap(tmp2 & ~tmp));
            for iii = 1:length(islands.PixelIdxList{ii})
                out(islands.PixelIdxList{ii}(iii)) = newval;
            end
        end
    end
end

nreplaced = length(find((out(:) - labelmap(:)) ~=0));
sprintf('replaced %d voxels', nreplaced)
