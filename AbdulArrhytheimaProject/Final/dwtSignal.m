function ecgsigTransf = dwtSignal(ecgsig, scale)

% Maximal overlap discrete wavelet transform
wt = modwt(ecgsig,scale);
wtrec = zeros(size(wt));
wtrec(3:4,:) = wt(3:4,:);
% Inverse maximal overlap discrete wavelet transform
ecgsigTransf = imodwt(wtrec,'sym4');
    
end