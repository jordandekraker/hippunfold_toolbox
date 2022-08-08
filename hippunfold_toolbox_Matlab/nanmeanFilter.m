function B = nanmeanFilter(A,r)

if ~exist('r','var')
    r=1;
end

se = strel('sphere',r);
se = se.Neighborhood./sum(se.Neighborhood(:));

insulate_correction = zeros(size(A)); 
insulate_correction(~isnan(A)) = 1;
insulate_correction = imfilter(insulate_correction,se,'replicate','conv');

A(isnan(A)) = 0;
A = imfilter(A,se,'replicate','conv');
B = A./insulate_correction;

% careful not to divide by 0
B(B>max(A(:))) = max(A(:));