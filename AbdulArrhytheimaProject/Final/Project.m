currentdirectory = pwd; 
disp(currentdirectory);
path = strcat( string(currentdirectory) + '\data\', fileName);
% arrhythmiaType = 'VT';
% fileName =  '215m';
outPutFileName = 'output';
% minPeakHeight = 0.5;
% minPeakDistance = 0.15;

% Load files---------------------------------------------------------------


infoName = strcat(path, '.info');
matName = strcat(path, '.mat');
load(matName);
ecgsig = val;
fid = fopen(infoName, 'rt');
fgetl(fid);
fgetl(fid);
fgetl(fid);
[freqint] = sscanf(fgetl(fid), 'Sampling frequency: %f Hz  Sampling interval: %f sec');
Fs = freqint(1);
interval = freqint(2);
fgetl(fid);

for i = 1:size(ecgsig, 1)
  [row(i), signal(i), gain(i), base(i), units(i)]=strread(fgetl(fid),'%d%s%f%f%s','delimiter','\t');
end

fclose(fid);
ecgsig(ecgsig==-32768) = NaN;

for i = 1:size(ecgsig, 1)
    ecgsig(i, :) = (ecgsig(i, :) - base(i)) / gain(i);
end

tm = (1:size(ecgsig, 2)) * interval;
sizeEcgSig = size(ecgsig, 2);
timeEcgSig = sizeEcgSig*interval;
% plot(x', val');

for i = 1:length(signal)
   labels{i} = strcat(signal{i}, ' (', units{i}, ')'); 
end

legend(labels);
xlabel('Time (sec)');
grid on

%--------------------------------------------------------------------------
arrhythmiaType = strcat('(', arrhythmiaType);
annotationsEcg = readAnnotations(path);
arrhythmiaPeriods = {};
for i = 1:size(annotationsEcg{1})
    % Force normal sinus rhythm label on empty labels when a '(N'
    % extraction case is demanded
    if(strcmp(annotationsEcg{1,4}(i),'') && strcmp(arrhythmiaType,'(N'))
        annotationsEcg{1,4}(i) = {arrhythmiaType};
    end
    
    if(strcmp(annotationsEcg{1,4}(i),arrhythmiaType))
        inst = {annotationsEcg{1,1}(i) annotationsEcg{1,2}(i) annotationsEcg{1,3}(i) annotationsEcg{1,4}(i)};
        arrhythmiaPeriods(end+1,:) = inst;
    end
end
%--------------------------------------------------------------------------
periodInterval = sizeEcgSig/timeEcgSig;

arrhythmiaMultipleQRS = {};
qrsScaleStart = 2;
qrsScaleEnd = 1;

% Increase the right period	in Ventricular bigeminy cases
if(arrhythmiaType == 'B')
    qrsScaleStart = 2;
    qrsScaleEnd = 2;
elseif(arrhythmiaType == 'T')
    qrsScaleStart = 1;
    qrsScaleEnd = 2.1;
end

for i = 1:size(arrhythmiaPeriods,1)-1
    period = arrhythmiaPeriods{i,3};
    if(period == -1)
        %tmPeriod = arrhythmiaPeriods{i,3} * interval;
        tmTotal = arrhythmiaPeriods{i,1} * 60;
        tmTotal = tmTotal + arrhythmiaPeriods{i,2};
        period = (tmTotal*sizeEcgSig)/timeEcgSig;
    end
    
    %i == size(arrhythmiaPeriods,1)
    % Arrhythmia detected in signal start
    if(period - periodInterval/2 <= 0)
        qrsExtracted = ecgsig(1:round(period + periodInterval));
        tmExtracted = tm(1:round(period + periodInterval)); 
    % Arrhythmia detected in signal end for arrhythmiaType normal
    elseif(~strcmp(arrhythmiaType,'N') && (i == size(arrhythmiaPeriods,1)))
        qrsExtracted = ecgsig(round(period - periodInterval/qrsScaleStart):size(arrhythmiaPeriods,1));
        tmExtracted = tm(round(period - periodInterval/qrsScaleStart):size(arrhythmiaPeriods,1)); 
    % Arrhythmia detected in signal end for arrhythmiaTypes
    elseif(strcmp(arrhythmiaType,'N') && i == size(arrhythmiaPeriods,1)-1)
        qrsExtracted = ecgsig(round(period - periodInterval/qrsScaleStart):size(arrhythmiaPeriods,1));
        tmExtracted = tm(round(period - periodInterval/qrsScaleStart):size(arrhythmiaPeriods,1)); 
    else
        qrsExtracted = ecgsig(round(period - periodInterval/qrsScaleStart):round(period + periodInterval*qrsScaleEnd));
        tmExtracted = tm(round(period - periodInterval/qrsScaleStart):round(period + periodInterval*qrsScaleEnd)); 
    end
    inst = {qrsExtracted tmExtracted arrhythmiaPeriods{i,4}};
    arrhythmiaMultipleQRS(end+1,:) = inst;
    
    %if(arrhythmiaType ~= 'N')
        % Plot QRS to check the waves
        figure
        plot(tmExtracted, qrsExtracted);
        xlabel('Time (sec)');
        ylabel('Amplitude (mV)');
        str = sprintf('Extracted QRS signal %d - %s %s', i, fileName, arrhythmiaType);
        title(str);
        strExport = sprintf('%s-example%d-%s', arrhythmiaType, i, fileName);
%         print(strExport,'-dpng');
    %end
end

%--------------------------------------------------------------------------
scale = 3;
DWTsignalPeaks = {};

for i = 1:size(arrhythmiaMultipleQRS,1)
    % Force minPeakDistance in normal waves
    %if(strcmp(arrhythmiaType,'N'))
    %    minPeakDistance = 0.13;
    %end
    if(i == 10)
        minPeakDistance = 0.13;
    else
        minPeakDistance = 0.15;
    end
    if(~isempty(arrhythmiaMultipleQRS{i,1}))
        ecgsigTransf = dwtSignal(arrhythmiaMultipleQRS{i,1}, scale);
        %ecgsigTransf = abs(ecgsigTransf).^2;
        [qrsPeaks,locs] = findpeaks(ecgsigTransf,arrhythmiaMultipleQRS{i,2},...
                                'MinPeakHeight',minPeakHeight,...
                                'MinPeakDistance',minPeakDistance);
        inst = {qrsPeaks locs arrhythmiaMultipleQRS{i,3}};
        DWTsignalPeaks(end+1,:) = inst;
        
        %if(arrhythmiaType ~= 'N')
            % Plot Peaks
            figure;
            plot(arrhythmiaMultipleQRS{i,2},ecgsigTransf)
            hold on
            plot(locs,qrsPeaks,'ro')
            xlabel('Time (sec)');
            ylabel('Amplitude (mV)');
            str = sprintf('R Peaks From Signal %d Localized by Wavelet Transform - %s %s', i, fileName, arrhythmiaType);
            title(str)
            strExport = sprintf('%s-peaks%d-%s', arrhythmiaType, i, fileName);
%             print(strExport,'-dpng');
        %end
    else
        continue;
    end
end

%--------------------------------------------------------------------------

% Read the file
info = strcat(path, '.hea');
fid = fopen(info, 'rt');

% Iterate through lines of the file, associating two lines:
% age/sex (line 2) and medicine prescribed (line 3)
line = fgetl(fid);
cont = 0;
while(ischar(line))
    line = fgetl(fid);
    if cont == 2
        fc1 = strrep(line,'# ','');
    end
    if cont == 3
        fc2 = strrep(line,'# ','');
    end
    cont = cont + 1;
end
fclose(fid);

% Get age, sex and medication prescription
data = textscan(fc1, '%d %c %d %d %s')
age = data{1};
sex = data{2};
if strcmp(fc2, 'None')
    medicine = 'No';
else
    medicine = 'Yes';
end


%--------------------------------------------------------------------------
features = {};

for i = 1:size(DWTsignalPeaks,1)
    % Check if peaks amplitude and locs aren't empty
    if(~isempty(DWTsignalPeaks{i,1}) && ~isempty(DWTsignalPeaks{i,2}))
        % Check if at least 2 peaks were found
        if(length(DWTsignalPeaks{i,1}) >= 2 && length(DWTsignalPeaks{i,2}) >= 2)
            % Extraction for VT and B arrhythmia
            %if(strcmp(DWTsignalPeaks{i,3},'(VT') || strcmp(DWTsignalPeaks{i,3},'(B') || strcmp(DWTsignalPeaks{i,3},'(T') || strcmp(DWTsignalPeaks{i,3},'(N'))
            if(strcmp(DWTsignalPeaks{i,3},'(VT'))
                peakAmpR = DWTsignalPeaks{i,1}(end);
                if(length(DWTsignalPeaks{i,1}) > 3)
                    peakIntervalRR = DWTsignalPeaks{i,2}(end-1) - DWTsignalPeaks{i,2}(1); 
                else 
                    peakIntervalRR = DWTsignalPeaks{i,2}(end) - DWTsignalPeaks{i,2}(1); 
                end
                inst = {peakAmpR peakIntervalRR peakAmpR/peakIntervalRR age sex medicine DWTsignalPeaks{i,3}};
                features(end+1,:) = inst;
                
            % Other types of arrhythmia
            else
                peakAmpR = DWTsignalPeaks{i,1}(end);
                if(length(DWTsignalPeaks{i,1}) > 3)
                    peakIntervalRR = DWTsignalPeaks{i,2}(end-1) - DWTsignalPeaks{i,2}(1); 
                else 
                    peakIntervalRR = DWTsignalPeaks{i,2}(end) - DWTsignalPeaks{i,2}(1); 
                end
                inst = {peakAmpR peakIntervalRR peakAmpR/peakIntervalRR age sex medicine DWTsignalPeaks{i,3}};
                features(end+1,:) = inst;
            end
        else
            continue;
        end
    else
        continue;
    end
end

featuresExtr = strcat(outPutFileName, '.csv');
global featuresTable;
features
featuresTable = cell2table(features, 'VariableNames',{'Amplitude','RR','Speed','Age','Sex','Medicine','Arrhythmia'});
featuresTable
writetable(featuresTable, featuresExtr);



% end