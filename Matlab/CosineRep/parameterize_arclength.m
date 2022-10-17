function [arc_length  para]=parameterize_arclength(tract)
%
% function [length  para]=parameterize_arclength(tract)
%
% Computes the arc length and perform the unit length parameterization of a
% curve.
%
% tract : 3 x n_vertex or 2 x n_vertex
% length: total arc length
% para  : number between 0 and 1 that maps the track to a unit interval.
%
%
% (C) Moo K. Chung & Nagesh Adluru 2008
%     mkchung@wisc.edu
%     University of Wisconsin-Madison
%
% update history
% 2008 created by M.K. Chung
% 2009 optimized by N. Adluru
% 2010 comments added


n_vertex=size(tract,2);
% n_vertex >=2 in order for this function to work.

p0=tract(:,1:(n_vertex-1));
p1=tract(:,2:n_vertex);
disp=p1-p0;
%January 22, 2009.
%Nagesh Adluru.
%Now computes directly: no function call overhead.
%L2=L2norm(disp');
L2=sqrt(sum(disp'.^2,2));

arc_length=sum(L2);
%length=0; % length up to the i-th vertex.
%para=zeros(1,n_vertex);
% for i=1:(n_vertex-1)
%     length=length + L2(i);
%     para(i+1)=  length/arc_length;
% end;

%January 21, 2009.
%Nagesh Adluru.
%Removing the above for-loop.
cum_len=cumsum(L2)/arc_length;
para=zeros(1,n_vertex);
para(2:end)=cum_len';
%----------------------------

return

