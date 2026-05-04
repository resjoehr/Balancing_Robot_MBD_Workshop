function [N,K,B] = SensorNoiseAnalysis(data, Fs)
% this function is adapted from: https://www.mathworks.com/help/fusion/ug/inertial-sensor-noise-analysis-using-allan-variance.html
    t0 = 1/Fs;
    theta = cumsum(data(:,2), 1)*t0;

    maxNumM = 100;
    L = size(theta, 1);
    maxM = 2.^floor(log2(L/2)); 
    m = logspace(log10(1), log10(maxM), maxNumM).';
    m = ceil(m); % m must be an integer.
    m = unique(m); % Remove duplicates.
    
    tau = m*t0;
    
    [avarFromFunc, tauFromFunc] = allanvar(data, m, Fs);
    adevFromFunc = sqrt(avarFromFunc);

%Velocity Random Walk/Angle Random Walk

    slope = -0.5;
    logtau = log10(tau);
    logadevFromFunc = log10(adevFromFunc);
    dlogadevFromFunc = diff(logadevFromFunc) ./ diff(logtau);
    [~, i] = min(abs(dlogadevFromFunc - slope));
    
    % Find the y-intercept of the line.
    for n=1:3
        b(n) = logadevFromFunc(i(n),n) - slope*logtau(i(n));
    end
    
    logN = slope*log(1) + b;
    N = 10.^logN;

%Acceleration Random Walk/Rate Random Walk

    slope = 0.5;
    logtau = log10(tau);
    logadevFromFunc = log10(adevFromFunc);
    dlogadevFromFunc = diff(logadevFromFunc) ./ diff(logtau);
    [~, i] = min(abs(dlogadevFromFunc - slope));
    
    % Find the y-intercept of the line.
    for n=1:3
        b(n) = logadevFromFunc(i(n),n) - slope*logtau(i(n));
    end
    
    % Determine the rate random walk coefficient from the line.
    logK = slope*log10(3) + b;
    K = 10.^logK;

%Bias Instability

    slope = 0;
    logtau = log10(tau);
    logadevFromFunc = log10(adevFromFunc);
    dlogadevFromFunc = diff(logadevFromFunc) ./ diff(logtau);
    %[~, i] = min(abs(dlogadevFromFunc - slope));
    [~, i] = min(abs(dlogadevFromFunc(2:end,:) - slope)); %quick and dirty fix to prevent that the first value is selected...
    i=i+1;
    
    % Find the y-intercept of the line.
    for n=1:3
        b(n) = logadevFromFunc(i(n),n) - slope*logtau(i(n));
    end
    % Determine the rate random walk coefficient from the line.
    scfB = sqrt(2*log(2)/pi);
    logB = b - log10(scfB);
    B = 10.^logB;

end