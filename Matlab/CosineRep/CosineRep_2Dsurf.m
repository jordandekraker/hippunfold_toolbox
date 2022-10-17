function [Vrec,Erec,beta,DX] = CosineRep_2Dsurf(Vmid,k,sigma,DX)

% Inputs
% Vmid: input surface (sized [APres,PDres,3])
% k: numper of cosine basis functions
% sigma: smoothing factor
% DX (optional): design matrix (specify only if, eg., fitting
% multiple surfaces with the same design matrix)
% Outputs
% Vrec: reconstructed surface
% Erec: reconstruction error
% beta: cosine fits (Vmid = DX*beta = Vrec+Erec)
% DX: design matrix

[APres,PDres,~] = size(Vmid);
r = APres/PDres;
kAP = k; kPD = ceil(k/r); 

%% smoothing
s1 = sigma/kAP;
s2 = sigma/kPD;
w1=exp(-[0:(kAP -1)]'.^2*pi^2*s1);
w2=exp(-[0:(kPD -1)]'.^2*pi^2*s2);
weight = diag(reshape(w1*w2',[kAP*kPD,1]));

if exist('DX')==0
    %% parameterize DX by arc lengths

    xAP = nan([APres,PDres]); 
    xPD = nan([APres,PDres]);
    for PD = 1:PDres
        tract = squeeze(Vmid(:,PD,:));
        [~, xAP(:,PD)]=parameterize_arclength(tract');
    end
    for AP = 1:APres
        tract = squeeze(Vmid(AP,:,:));
        [~, xPD(AP,:)]=parameterize_arclength(tract');
    end
    % xAPm = mean(xAP,2);
    % xPDm = mean(xPD,1);
    % x = (xAP+xPD)./2;
    % x = xAPm*xPDm;
    % x = xAP.*xPD;
    % x = (xAP.^2 + xPD.^2).^0.5; x = x/max(x(:));

    %% make design matrix
    DX=[];
    % we want kAP*kPD predictors, not kAP + kPD!
    for AP=1:APres
        for PD=1:PDres
    %         DX1(AP,PD,:)=sqrt(2)*cos(pi.*[0:kAP-1].*xAP(AP,PD));
    %         DX2(AP,PD,:)=sqrt(2)*cos(pi.*[0:kPD-1].*xPD(AP,PD));
            DX(AP,PD,1:kAP,1:kPD) = sqrt(2)*cos(pi.*[0:kAP-1].*xAP(AP,PD))'...
                *sqrt(2)*cos(pi.*[0:kPD-1].*xPD(AP,PD));
        end
    end
    % DX1 = reshape(DX1,[APres*PDres,kAP]);
    % DX2 = reshape(DX2,[APres*PDres,kPD]);
    % DX = [DX1 DX2];
end
DX = reshape(DX,[APres*PDres,kAP*kPD]);

%% fit!
Vmid = reshape(Vmid,[APres*PDres,3]);
% beta1 = pinv(DX1'*DX1)*DX1'*Vmid;
% beta2 = pinv(DX2'*DX2)*DX2'*Vmid;
beta = pinv(DX'*DX)*DX'*Vmid;

%% reconstruct
% Vrec1 = DX1*beta1;
% Vrec2 = DX2*beta2;
% Vrec = Vrec1.*Vrec2;
Vrec = DX*(weight*beta);
Erec = norm(Vmid-Vrec);