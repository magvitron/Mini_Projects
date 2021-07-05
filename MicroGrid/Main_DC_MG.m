%% System Simulation of DC Microgrid: 
% From: Hybrid AC/DC microgrid test system simulation: grid-connected mode.% Heliyon - 2019.
%       https://www.sciencedirect.com/science/article/pii/S2405844019365211
% Autor: PhD (c). Leony Ortiz and author collectives. 
close all; clearvars; clc; 
   
%% Initialize: 
% ****** SIMULINK - POWERGUI and Microgrid ******
    Fnom = 60;
    Ts_Power=1/(33*Fnom)/100; Ts = Ts_Power; 
    Vnom_DC = 300; 
% ****** POWER AND ELECTRONIC PV SYSTEM ******
    Ts_Control=10*Ts_Power; 
% DC LOADs: 
        P_Load_DC = 2e3; 
        R_Load_DC = Vnom_DC^2/ P_Load_DC; 
 
 %% RUN SIMULATION 
model = 'Model_DC_MG'; load_system(model); 
set_param('Model_DC_MG','IgnoredZcDiagnostic','none'); 
% sim(model);
