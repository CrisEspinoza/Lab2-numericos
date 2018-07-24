function graficar_F2_spli(real, F_0_5,F_1,F_5,F_10)
%CREATEFIGURE(Y1)
% Create figure
figure1 = figure;

% Create axes
axes1 = axes('Parent',figure1);
box(axes1,'on');
hold(axes1,'all');
hold on;
grid on;

plot(real(1:end,1),real(1:end,2),'-+','MarkerSize',1,'MarkerFaceColor','c');
plot(F_0_5(1:end,1),F_0_5(1:end,2),'-o','MarkerSize',1,'MarkerFaceColor','m');
plot(F_1(1:end,1),F_1(1:end,2),'-*','MarkerSize',1,'MarkerFaceColor','y');
plot(F_5(1:end,1),F_5(1:end,2),'-x','MarkerSize',1,'MarkerFaceColor','r');
plot(F_10(1:end,1),F_10(1:end,2),'-s','MarkerSize',1,'MarkerFaceColor','g');

title('Spline Cubico')
xlabel('X') % x-axis label
ylabel('Interpolacion');
legend('Funcion Real', 'X=0,5','X=1','X=5','X=10');
end



