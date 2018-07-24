%Realizamos el llamado a toda las funciones 
 
        %MATRICES CON VALORES REALES

matrizReal_f1_x0_05 = load("ResultadosReales/real_0_05_F1.txt");
matrizReal_f2_x0_05 = load("ResultadosReales/real_0_05_F2.txt");

    %MINIMOS CUADRADOS
%Funcion 1
matriz_f1_x_0_5_minimos = load("MinCuadrados/Func1_0_5.txt");
matriz_f1_x_1_minimos = load("MinCuadrados/Func1_1.txt");
matriz_f1_x_5_minimos = load("MinCuadrados/Func1_5.txt");
matriz_f1_x_10_minimos = load("MinCuadrados/Func1_10.txt");

graficar_F1_min(matrizReal_f1_x0_05,matriz_f1_x_0_5_minimos,matriz_f1_x_1_minimos,matriz_f1_x_5_minimos,matriz_f1_x_10_minimos);

%Funcion 2
matriz_f2_x_0_5_minimos = load("MinCuadrados/Func2_0_5.txt");
matriz_f2_x_1_minimos = load("MinCuadrados/Func2_1.txt");
matriz_f2_x_5_minimos = load("MinCuadrados/Func2_5.txt");
matriz_f2_x_10_minimos = load("MinCuadrados/Func2_10.txt");

graficar_F2_min(matrizReal_f2_x0_05,matriz_f2_x_0_5_minimos,matriz_f2_x_1_minimos,matriz_f2_x_5_minimos,matriz_f2_x_10_minimos);

    %DIFERENCIAS DIVIDIDAS
%Funcion 1
matriz_f1_x_0_5_divididas = load("DifDivididas/Func1_0_5.txt");
matriz_f1_x_1_divididas = load("DifDivididas/Func1_1.txt");
matriz_f1_x_5_divididas = load("DifDivididas/Func1_5.txt");
matriz_f1_x_10_divididas = load("DifDivididas/Func1_10.txt");

graficar_F1_div(matrizReal_f1_x0_05,matriz_f1_x_0_5_divididas,matriz_f1_x_1_divididas,matriz_f1_x_5_divididas,matriz_f1_x_10_divididas);

%Funcion 2
matriz_f2_x_0_5_divididas = load("DifDivididas/Func2_0_5.txt");
matriz_f2_x_1_divididas = load("DifDivididas/Func2_1.txt");
matriz_f2_x_5_divididas = load("DifDivididas/Func2_5.txt");
matriz_f2_x_10_divididas = load("DifDivididas/Func2_10.txt");

graficar_F2_div(matriz_f2_x_0_5_divididas,matriz_f2_x_1_divididas,matriz_f2_x_5_divididas,matriz_f2_x_10_divididas);

    %DIFERENCIAS FINITAS
%Funcion 1
matriz_f1_x_0_5_finitas = load("DifFinitas/Func1_0_5.txt");
matriz_f1_x_1_finitas = load("DifFinitas/Func1_1.txt");
matriz_f1_x_5_finitas = load("DifFinitas/Func1_5.txt");
matriz_f1_x_10_finitas = load("DifFinitas/Func1_10.txt");

graficar_F1_fin(matrizReal_f1_x0_05,matriz_f1_x_0_5_finitas,matriz_f1_x_1_finitas,matriz_f1_x_5_finitas,matriz_f1_x_10_finitas);

%Funcion 2
matriz_f2_x_0_5_finitas = load("DifFinitas/Func2_0_5.txt");
matriz_f2_x_1_finitas = load("DifFinitas/Func2_1.txt");
matriz_f2_x_5_finitas = load("DifFinitas/Func2_5.txt");
matriz_f2_x_10_finitas = load("DifFinitas/Func2_10.txt");

graficar_F2_fin(matrizReal_f2_x0_05,matriz_f2_x_0_5_finitas,matriz_f2_x_1_finitas,matriz_f2_x_5_finitas,matriz_f2_x_10_finitas);

    %SPLINE CUBICO
    
%Funcion 1
matriz_f1_x_0_5_spline = load("SplineCubico/Func1_0_5.txt");
matriz_f1_x_1_spline = load("SplineCubico/Func1_1.txt");
matriz_f1_x_5_spline = load("SplineCubico/Func1_5.txt");
matriz_f1_x_10_spline = load("SplineCubico/Func1_10.txt");

graficar_F1_spli(matrizReal_f1_x0_05,matriz_f1_x_0_5_spline,matriz_f1_x_1_spline,matriz_f1_x_5_spline,matriz_f1_x_10_spline);

%Funcion 2
matriz_f2_x_0_5_spline = load("SplineCubico/Func2_0_5.txt");
matriz_f2_x_1_spline = load("SplineCubico/Func2_1.txt");
matriz_f2_x_5_spline = load("SplineCubico/Func2_5.txt");
matriz_f2_x_10_spline = load("SplineCubico/Func2_10.txt");

graficar_F2_spli(matrizReal_f2_x0_05,matriz_f2_x_0_5_spline,matriz_f2_x_1_spline,matriz_f2_x_5_spline,matriz_f2_x_10_spline);

%Ingresamos a la carpeta para guardar las imagenes
cd 
cd 'Fotos graficos'/;

%Guardamos los resultados del metodo minimos cuadrados
h = figure(1);
saveas(h, 'Func1_MC.png');
h = figure(2);
saveas(h, 'Func2_MC.png');
%Guardamos los resultados del metodo defirencia divididas
h = figure(3);
saveas(h, 'Func1_DD.png');
h = figure(4);
saveas(h, 'Func2_DD.png');
% Guardamos los resultados del metodo diferencia finitas
h = figure(5);
saveas(h, 'Func1_DF.png');
h = figure(6);
saveas(h, 'Func2_DF.png');
%Guardamos los resultados del metodo spline cubico
h = figure(7);
saveas(h, 'Func1_SC.png');
h = figure(8);
saveas(h, 'Func2_SC.png');
