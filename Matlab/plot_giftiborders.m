function p = plot_giftiborders(gii,cdata)

% adds to current plot a set of points on borders between integer labelled
% vertices


F = gii.faces;
V = gii.vertices;

gcf;
hold on;
u = unique(cdata);
for i = 1:length(u)
    b = double(cdata==u(i));
    b = surfdat_smooth(F,b,1);
    b = rem(b,1); % find border vertices by smoothing and find remainder
    b = find(b>0);
    b = find(all(ismember(F,b),2));
    for n = 1:length(b)
        v(n,:) = mean(V(F(b(n),:),:));
    end
    p(i) = scatter3(v(:,1),v(:,2),v(:,3),'.','k');
end