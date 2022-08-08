function [LP, iter_change] = laplace_iters(fg,source,sink,init,maxiters,sz,neighbourhoodradius)

change_threshold = 10^(-3);


% filter set-up 
hl = ones([(neighbourhoodradius*2 +1) (neighbourhoodradius*2 +1) (neighbourhoodradius*2 +1)]);
hl(neighbourhoodradius+1,neighbourhoodradius+1,neighbourhoodradius+1) = 0;
hl = hl/sum(hl(:)); 


%set up all requisite variables
vel = nan(sz);
vel(fg)=init;
vel(source)=0;
vel(sink)=1;
bg = find(isnan(vel)); 
vel(bg)=0; %must be insulated after filtering
iter_change = zeros(1,maxiters);
insulate_correction = zeros(sz); 
insulate_correction([fg;source;sink]) = 1;
insulate_correction = imfilter(insulate_correction,hl,'replicate','conv');

% apply filter
iters = 0;
while iters < maxiters %max iterations
    iters = iters+1;
    
    velup = imfilter(vel,hl,'replicate','conv'); %apply averaging filter
    
    %insulate the grey matter so gradient doesn't pass between folds -
    %inspired by ndnanfilter
    velup = velup./insulate_correction;
    velup(bg) = 0;
    velup(source) = 0;
    velup(sink) = 1;
    
    %stopping condition
    iter_change(iters) = nansum(abs(vel(fg)-velup(fg))); %compute change from last iteration
    vel = velup;
    if iter_change(iters)<change_threshold
        break
    end
end
vel = vel./max(vel(:));
vel(~fg) = nan;
LP = vel;
end