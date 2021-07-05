%% Simulation and Model of Microgrid AC/DC (Model 14 Bus)
% Autor: PhD (c). Leony Ortiz Matos; Msc. Rogelio Orizondo; PhD (c). Alexander
% Aguila at al

%% VoltageLL_pu_abc
% Reading of data
    VoltageLL_pu_abc_data = VoltageLL_pu_abc.Data;
    Time_Sim = VoltageLL_pu_abc.time;
    VoltageLL_pu_microgrid = VoltageLL_pu_abc_data (end,:); 
    Vdc_bus = VoltageLL_pu_microgrid (1,end); 
    m_bus = (length(VoltageLL_pu_microgrid)-1)/Phase; bus = 1:1:m_bus+1;
     
    cont = 1;
        for j = 1 : m_bus 
           for i = 1 : Phase 
               VoltageLL_pu_microgrid_plot (j,i) = VoltageLL_pu_microgrid (1,cont);  
               cont = cont + 1;
           end
        end
    VoltageLL_pu_AC_bus = VoltageLL_pu_microgrid_plot;    
    VoltageLL_pu_microgrid_plot (m_bus+1,:) = [0 Vdc_bus 0];
    
% DPVS & DPVS max 
	u = ones (length (VoltageLL_pu_AC_bus), Phase);
    DPVSabc = abs( u -  VoltageLL_pu_AC_bus);
	DPVS = sum (DPVSabc)/length (DPVSabc); 
    DVmax = max (DPVSabc) % 
    
% VoltageLL_pu_abc "HISTOGRAM"
    figure(2); hold on; grid minor;
    x = [0 m_bus+1.5];
    line(x,[1 1],'Color','green','LineStyle','-');
    f2 = stem(bus,VoltageLL_pu_microgrid_plot,'^','linewidth',1.3);

% Graphic DPVS abc and DVmax point
    f23 = line(x,[1-DPVS(1,1) 1-DPVS(1,1)],'Color','b','LineStyle','-.') % DVPS phase a
    f24 = line(x,[1-DPVS(1,2) 1-DPVS(1,2)],'Color','r','LineStyle','-.') % DVPS phase b
    f25 = line(x,[1-DPVS(1,3) 1-DPVS(1,3)],'Color','y','LineStyle','-.') % DVPS phase c
%  Interpolation
    h=0.00001; Xi = 1:h:15; 
    y11 = interp1(bus,VoltageLL_pu_microgrid_plot (:,2),Xi,'spline'); z=0; c=0;
    
    f22 = plot(Xi,y11,'b:',z,c,'linewidth',1.2);
    title(['Voltage L-L (pu) per Bus  /  ADVS (abc) = ',num2str(DPVS)],'fontname','times new roman','fontsize',13);
    xlabel('Bus number','fontname','times new roman','fontsize',13); 
    ylabel('Voltage abc L-L (pu) and ADVS (pu)','fontname','times new roman','fontsize',13);  
    leyenda=legend([f2 f23 f24 f25],'V phase a','V phase b','V phase c', 'ADVS phase a', 'ADVS phase b', 'ADVS phase c','Location','SE');
    set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
    axis([0.5 15.5 0.65 1.2]); 
    ax = gca; 
    ax.XAxis.TickLabelFormat = 'Bus%,.0fAC';
    p=get(0,'ScreenSize'); 
    set(gcf,'Position',p +[0 0 0 0])
    hold off;
    print -dpng -r600 VoltageLL_pu_abc;  
 
	%% Active_Power_abc
    P_abc_data = P_abc.Data; 
    P_abc_microgrid = P_abc_data (end,:); 
    Pdc_bus = P_abc_microgrid (1,end);
    cont = 1;
        for j = 1 : m_bus
           for i = 1 : Phase
               P_abc_microgrid_plot (j,i) = P_abc_microgrid (1,cont);  
               cont = cont + 1;
           end
        end
    P_abc_microgrid_plot (m_bus+1,:) = [0 Pdc_bus 0];
% Graphic VoltageLL_pu_abc "HISTOGRAM"
    figure(3); hold on;
    Pa =  (P_abc_microgrid_plot (:,Phase-2)); Pb =  (P_abc_microgrid_plot (:,Phase-1) );Pc =  (P_abc_microgrid_plot (:,Phase));
    f3 = bar(bus, [Pa Pb Pc], 0.5, 'stack');  grid minor;
    title('Active Power abc per Bus','fontname','times new roman','fontsize',13);
    xlabel('Bus number','fontname','times new roman','fontsize',13);
    ylabel('Active Power abc (AC:kVA and DC:kW )','fontname','times new roman','fontsize',13);
    leyenda=legend([f3],'Phase a','Phase b','Phase c','Location','SW');
    set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
    ax = gca; 
    ax.XAxis.TickLabelFormat = 'Bus%,.0fAC';
    p=get(0,'ScreenSize');  
    set(gcf,'Position',p +[0 0 0 0]) 
    hold off;
    print -dpng -r600 ActivePower_abc;
    
%% Reactive_Power_abc; Voltage abc and Voltahe angle abc 
    Q_abc_data = Q_abc.Data; 
    Q_abc_microgrid = Q_abc_data (end,:);
    m_bus = length(Q_abc_microgrid)/Phase; bus = 1:1:m_bus; 
     
    cont = 1;
        for j = 1 : m_bus 
           for i = 1 : Phase 
               Q_abc_microgrid_plot (j,i) = Q_abc_microgrid (1,cont);  
               cont = cont + 1;
           end
        end
% Graphic Q_abc "HISTOGRAM"
    figure(4); hold on;
    Qa =  (Q_abc_microgrid_plot (:,Phase-2)); Qb =  (Q_abc_microgrid_plot (:,Phase-1) );Qc =  (Q_abc_microgrid_plot (:,Phase));
    subplot(2, 2, [1 3]);
    f4 = bar(bus, [Qa Qb Qc], 0.5, 'stack');  grid on;
    title('Reactive Power abc per Bus','fontname','times new roman','fontsize',13);
    xlabel('Bus number','fontname','times new roman','fontsize',13);
    ylabel('Reactive Power abc (VA)','fontname','times new roman','fontsize',13);
    leyenda=legend([f4],'Phase a','Phase b','Phase c','Location','NW');
    set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
% VoltageLL_pu_abc
    bus = 1:1:m_bus+1;
% Graphic VoltageLL_pu_abc "HISTOGRAM"
    subplot(2, 2, 2); hold on;
    x = [0 m_bus+1];
    y = [1 1];
    line(x,y,'Color','green','LineStyle','--');
    f42 = stem(bus,VoltageLL_pu_microgrid_plot);
% Interpolation
    h=0.00001; Xi = 1:h:15; 
    y11 = interp1(bus,VoltageLL_pu_microgrid_plot (:,2),Xi,'spline'); z=0; c=0;
    plot(Xi,y11,'b:',z,c,'linewidth',1.2); 
% Titles 
    title('Voltage L-L (pu) per Bus','fontname','times new roman','fontsize',13);
    xlabel('Bus number','fontname','times new roman','fontsize',13);
    ylabel('Voltage abc L-L (pu)','fontname','times new roman','fontsize',13);
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
    axis([0.5 15.5 0.65 1.15]); % Change axis properties

    ang_abc_data = ang_abc.Data; 
    ang_abc_microgrid = ang_abc_data (end,:); 
    m_bus = length(ang_abc_microgrid)/Phase; bus = 1:1:m_bus; 
     
    cont = 1;
        for j = 1 : m_bus 
           for i = 1 : Phase 
               ang_abc_microgrid_plot (j,i) = ang_abc_microgrid (1,cont);  
               cont = cont + 1;
           end
        end
     ang_a_microgrid_plot = ang_abc_microgrid_plot (:,Phase-2); ang_a_microgrid_plot'; 
     ang_a_microgrid_plot = (ang_a_microgrid_plot + 360)*pi/180; % in rad
     ang_b_microgrid_plot = ang_abc_microgrid_plot (:,Phase-1); ang_a_microgrid_plot'; 
     ang_b_microgrid_plot = (ang_b_microgrid_plot)*pi/180; % in rad
     ang_c_microgrid_plot = ang_abc_microgrid_plot (:,Phase); ang_a_microgrid_plot'; 
     ang_c_microgrid_plot = (ang_c_microgrid_plot)*pi/180; % in rad
     
     subplot(2, 2, 4); 
     rose(ang_a_microgrid_plot,40);hold on;
     rose(ang_b_microgrid_plot,40);
     rose(ang_c_microgrid_plot,40);
     title('Voltage angle abc per Bus','fontname','times new roman','fontsize',13);
    
    p=get(0,'ScreenSize'); 
    set(gcf,'Position',p +[0 0 0 0]) 
    hold off;
    print -dpng -r600  Reactive_Power_angle;
        
%% Power_Losse_abc
    Power_Losse_abc_data = Power_Losse_abc.Data; 
    Power_Losse_microgrid = Power_Losse_abc_data (end,:);
    n_lines = length(Power_Losse_microgrid)/Phase; lines = 1:1:n_lines;
    cont = 1;
        for j = 1 : n_lines 
           for i = 1 : Phase
               Power_Losse_microgrid_plot (j,i) = Power_Losse_microgrid (1,cont);  
               cont = cont + 1;
           end
        end
% Graphic Power_Losse_abc "HISTOGRAM"
    figure(6); grid minor; hold on;
    f6 = bar(lines,Power_Losse_microgrid_plot);
    h=0.00001; Xi = 1:h:14; 
    y11 = interp1(lines,Power_Losse_microgrid_plot(:,2),Xi,'spline'); z=0; c=0;
    f62 = plot(Xi,y11,'r:',z,c,'linewidth',1.2); 
    title('Power Losses per Lines','fontname','times new roman','fontsize',13);
    xlabel('Line number','fontname','times new roman','fontsize',13);
    ylabel('Power Losses (kW)','fontname','times new roman','fontsize',13);
    leyenda=legend([f6],'Phase a','Phase b','Phase c','Location','NE');
    set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
    switch Demand_case
        case 1 % Max demand
            axis([0.5 14.5 0 10]); % Max demand
        otherwise % Min demand
            axis([0.5 14.5 0 2]); % Min demand
    end
    ax = gca;
    ax.XAxis.TickLabelFormat = 'Line%,.0fAC';
    p=get(0,'ScreenSize'); 
    set(gcf,'Position',p +[0 0 10 0])
    hold off;
    print -dpng -r600 FigPowerLosse;
    
%% Power factor
    PF_abc_data = PF_abc.Data;
    PF_abc_microgrid = PF_abc_data (end,:); 
    m_bus = length(PF_abc_microgrid)/Phase; bus = 1:1:m_bus;
    cont = 1;
        for j = 1 : m_bus 
           for i = 1 : Phase 
               PF_abc_microgrid_plot (j,i) = PF_abc_microgrid (1,cont);  
               cont = cont + 1;
           end
        end
 
 % Min Demand
    switch Demand_case
        case 1 % Max demand
        otherwise % Min demand
            PF_abc_microgrid_plot (1,:) = PF_abc_microgrid_plot(1,:) * -1;
            PF_abc_microgrid_plot (2,:) = PF_abc_microgrid_plot(2,:) * -1;
            PF_abc_microgrid_plot (14,:) = PF_abc_microgrid_plot(14,:) * -1;
    end   
        
% Graphic PF_abc_microgrid "HISTOGRAM"
    figure(7); hold on; grid minor;
    x = [0 m_bus+0.5];
    line(x,[1 1],'Color','green','LineStyle','-');
    f7 = stem(bus,PF_abc_microgrid_plot,'o','linewidth',1.3);
    h=0.00001; Xi = 1:h:14; 
    y11 = interp1(bus,PF_abc_microgrid_plot (:,2),Xi,'spline'); z=0; c=0;
    f72 = plot(Xi,y11,'r:',z,c,'linewidth',1.2); 
    title('Power factor','fontname','times new roman','fontsize',13);
    xlabel('Bus number','fontname','times new roman','fontsize',13); 
    ylabel('Power factor','fontname','times new roman','fontsize',13);  
    leyenda=legend([f7],'PF phase a','PF phase b','PF phase c','Location','SE');
    set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
    axis([0.4 14.5 0 1.1]);
    ax = gca; 
    ax.XAxis.TickLabelFormat = 'Bus%,.0fAC';
    p=get(0,'ScreenSize'); 
    set(gcf,'Position',p +[0 0 0 0]) 
    hold off;
    print -dpng -r600 PF_abc; 

 %% THD Voltage_abc
    THDv_abc_data = THDv_abc.Data; 
    THDv_abc_microgrid = THDv_abc_data (end,:);
    m_bus = length(THDv_abc_microgrid)/Phase; bus = 1:1:m_bus; 
      cont = 1;
        for j = 1 : m_bus 
           for i = 1 : Phase 
               THDv_abc_microgrid_plot (j,i) = THDv_abc_microgrid (1,cont);  
               cont = cont + 1;
           end
        end

% Graphic_INTERPOLACION THDv phase a
    figure(8); hold on; grid minor;
    h=0.00001; Xi = 1:h:14; 
    y12 = interp1(bus,THDv_abc_microgrid_plot (:,1),Xi,'spline'); z=0; c=0;
    f82 = plot(Xi,y12,'-','linewidth',1.2);
    
% Graphic_INTERPOLACION THDv phase b
    y13 = interp1(bus,THDv_abc_microgrid_plot (:,2),Xi,'spline'); z=0; c=0;
    f83 = plot(Xi,y13,'-','linewidth',1.2);
    
% Graphic_INTERPOLACION THDv phase c
    y14 = interp1(bus,THDv_abc_microgrid_plot (:,3),Xi,'spline'); z=0; c=0;
    f84 = plot(Xi,y14,'-','linewidth',1.2); 
    title('Voltage THD per Bus','fontname','times new roman','fontsize',13);
    xlabel('Bus number','fontname','times new roman','fontsize',13); 
    ylabel('THD (%)','fontname','times new roman','fontsize',13);  
    leyenda = legend([f82 f83 f84],'Phase a','Phase b','Phase c','Location','SE');
    set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
    set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
    axis([0.9 14.1 0 5]);
    ax = gca;
    ax.XAxis.TickLabelFormat = 'Bus%,.0fAC';
    p=get(0,'ScreenSize');  
    set(gcf,'Position',p +[0 0 0 0]) 
    hold off;
    print -dpng -r600 THDv_abc;  
    
%% Demand 
    [f] = Demand(t_hours,P_demand);
    
