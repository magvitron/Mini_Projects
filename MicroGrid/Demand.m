function [f] = DEMAND_function(t_hours,P_demand)
f =1;
%% VoltageLL_pu_abc
% Initialize: 
    E_demand=(P_demand+t_hours*0);
    % Calculate the beak demand
        [minBeak im] = min(P_demand);
        [maxBeak iM] = max(P_demand);
        
% Grafic DEMAND
    figure(111); hold on; %grid on;
    f111 = stem(t_hours,E_demand,'k:','o','linewidth',1);   
    hold on; 
    h=0.00001; Xi = 1:h:24; 
    yint = interp1(t_hours,P_demand,Xi,'spline'); z=0; c=0;
    f112 = plot(Xi,yint,'b-',z,c,'linewidth',1.2); 
  
% Max y Min
    f113 = plot (iM, maxBeak,'r:O','LineWidth',2.5); % Max demand
    f114 = plot (im, minBeak,'g:O','LineWidth',2.5); % min demand
 
ylim([0 3.5]);
xlim([1 24]);

% Titles     
     title('Demand curve','fontname','times new roman','fontsize',13);
     xlabel('Time (hour)','fontname','times new roman','fontsize',13); 
     ylabel('Power (MVA)','fontname','times new roman','fontsize',13);
     leyenda=legend([f113, f114],'Max demand','Min demand','Location','SE');
     set(leyenda,'FontName','Times New Roman','FontUnits','points','FontSize',11,'FontWeight','normal','FontAngle','normal');
     set(leyenda.BoxFace,'ColorType', 'truecoloralpha', 'ColorData',uint8([255;255;255;0.85*255]));
     ax = gca; 
     ax.XAxis.TickLabelFormat = '%,.0fh00';
     p=get(0,'ScreenSize'); 
     set(gcf,'Position',p +[0 0 0 0]);
print -dpng -r600 Demand; 
hold off;
return;
