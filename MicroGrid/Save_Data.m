%% Simulation and Model of Microgrid AC/DC (Model 14 Bus)

 %% Save Data
switch Demand_case
    case 1 % Max demand
        save('Microgrid_Data_Max_demand.mat','VoltageLL_pu_abc','P_abc','Q_abc','Means_Bus8');
        save('Microgrid_Data1_Max_demand.mat','ang_abc','PF_abc','Power_Losse_abc','THDv_abc');
    otherwise % Min demand
        save('Microgrid_Data_Min_demand.mat','VoltageLL_pu_abc','P_abc','Q_abc','Means_Bus8');
        save('Microgrid_Data1_Min_demand.mat','ang_abc','PF_abc','Power_Losse_abc','THDv_abc');
end;