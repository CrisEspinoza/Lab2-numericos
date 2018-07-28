
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

%Funcion 2
matriz_f2_x_0_5_minimos = load("MinCuadrados/Func2_0_5.txt");
matriz_f2_x_1_minimos = load("MinCuadrados/Func2_1.txt");
matriz_f2_x_5_minimos = load("MinCuadrados/Func2_5.txt");
matriz_f2_x_10_minimos = load("MinCuadrados/Func2_10.txt");

    %DIFERENCIAS DIVIDIDAS
%Funcion 1
matriz_f1_x_0_5_divididas = load("DifDivididas/Func1_0_5.txt");
matriz_f1_x_1_divididas = load("DifDivididas/Func1_1.txt");
matriz_f1_x_5_divididas = load("DifDivididas/Func1_5.txt");
matriz_f1_x_10_divididas = load("DifDivididas/Func1_10.txt");

%Funcion 2
matriz_f2_x_0_5_divididas = load("DifDivididas/Func2_0_5.txt");
matriz_f2_x_1_divididas = load("DifDivididas/Func2_1.txt");
matriz_f2_x_5_divididas = load("DifDivididas/Func2_5.txt");
matriz_f2_x_10_divididas = load("DifDivididas/Func2_10.txt");

    %DIFERENCIAS FINITAS
%Funcion 1
matriz_f1_x_0_5_finitas = load("DifFinitas/Func1_0_5.txt");
matriz_f1_x_1_finitas = load("DifFinitas/Func1_1.txt");
matriz_f1_x_5_finitas = load("DifFinitas/Func1_5.txt");
matriz_f1_x_10_finitas = load("DifFinitas/Func1_10.txt");

%Funcion 2
matriz_f2_x_0_5_finitas = load("DifFinitas/Func2_0_5.txt");
matriz_f2_x_1_finitas = load("DifFinitas/Func2_1.txt");
matriz_f2_x_5_finitas = load("DifFinitas/Func2_5.txt");
matriz_f2_x_10_finitas = load("DifFinitas/Func2_10.txt");

    %SPLINE CUBICO
    
%Funcion 1
matriz_f1_x_0_5_spline = load("SplineCubico/Func1_0_5.txt");
matriz_f1_x_1_spline = load("SplineCubico/Func1_1.txt");
matriz_f1_x_5_spline = load("SplineCubico/Func1_5.txt");
matriz_f1_x_10_spline = load("SplineCubico/Func1_10.txt");

%Funcion 2
matriz_f2_x_0_5_spline = load("SplineCubico/Func2_0_5.txt");
matriz_f2_x_1_spline = load("SplineCubico/Func2_1.txt");
matriz_f2_x_5_spline = load("SplineCubico/Func2_5.txt");
matriz_f2_x_10_spline = load("SplineCubico/Func2_10.txt");

% %Ingresamos a la carpeta para guardar las imagenes

cd 
cd 'Fotos graficos'/;

%Menu

opcion = input (' \n              * Menu * \n -------------------- \n    Graficar funcion I \n 1. Metodo Diferencias dividias \n 2. Metodo Diferencias finitas \n 3. Metodo Minimos cuadrados \n 4. Metodo Spline cubico \n  Graficar funcion II \n 5. Metodo Diferencias dividias \n 6. Metodo Diferencias finitas \n 7. Metodo Minimos cuadrados \n 8. Metodo Spline cubico \n        *-*-*-*-*-*-*-* \n 9. Terminar programa \n  -------> Ingrese opción:  ');

while (opcion ~= 9) 
   
    switch opcion
        
        case 1
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F1_div(matrizReal_f1_x0_05,matriz_f1_x_0_5_divididas,matriz_f1_x_1_divididas,matriz_f1_x_5_divididas,matriz_f1_x_10_divididas);
            h = figure(1);
            saveas(h, 'Func1_DD.png');
            %break;
        case 2
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F1_fin(matrizReal_f1_x0_05,matriz_f1_x_0_5_finitas,matriz_f1_x_1_finitas,matriz_f1_x_5_finitas,matriz_f1_x_10_finitas);
            h1 = figure(1);
            saveas(h1, 'Func1_DF.png');
            %break;
        case 3
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F1_min(matrizReal_f1_x0_05,matriz_f1_x_0_5_minimos,matriz_f1_x_1_minimos,matriz_f1_x_5_minimos,matriz_f1_x_10_minimos);
            h3 = figure(1);
            saveas(h3, 'Func1_MC.png');
            %break;
        case 4
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F1_spli(matrizReal_f1_x0_05,matriz_f1_x_0_5_spline,matriz_f1_x_1_spline,matriz_f1_x_5_spline,matriz_f1_x_10_spline);
            h = figure(1);
            saveas(h, 'Func1_SC.png');
            %break;
        case 5
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F2_div(matriz_f2_x_0_5_divididas,matriz_f2_x_1_divididas,matriz_f2_x_5_divididas,matriz_f2_x_10_divididas);
            h = figure(1);
            saveas(h, 'Func2_DD.png');
            %break;
        case 6
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F2_fin(matrizReal_f2_x0_05,matriz_f2_x_0_5_finitas,matriz_f2_x_1_finitas,matriz_f2_x_5_finitas,matriz_f2_x_10_finitas);
            h = figure(1);
            saveas(h, 'Func2_DF.png');
            %break;
        case 7
            %Para cerrar los graficos que queden abiertos
            close all
            graficar_F2_min(matrizReal_f2_x0_05,matriz_f2_x_0_5_minimos,matriz_f2_x_1_minimos,matriz_f2_x_5_minimos,matriz_f2_x_10_minimos);
            h = figure(1);
            saveas(h, 'Func2_MC.png');
            %break;
        case 8
            %Para cerrar los graficos que queden abiertos
            close all 
            graficar_F2_spli(matrizReal_f2_x0_05,matriz_f2_x_0_5_spline,matriz_f2_x_1_spline,matriz_f2_x_5_spline,matriz_f2_x_10_spline);
            h = figure(1);
            saveas(h, 'Func2_SC.png');
            %break;
    end
    opcion = input (' \n *             Menu: Ingrese opcion * \n -------------------- \n    Graficar funcion I \n 1. Metodo Diferencias dividias \n 2. Metodo Diferencias finitas \n 3. Metodo Minimos cuadrados \n 4. Metodo Spline cubico \n  Graficar funcion II \n 5. Metodo Diferencias dividias \n 6. Metodo Diferencias finitas \n 7. Metodo Minimos cuadrados \n 8. Metodo Spline cubico \n        *-*-*-*-*-*-*-* \n 9. Terminar programa \n  -------> Ingrese opción:  ');
end
%Para cerrar los graficos que queden abiertos
close all
disp('El programa ha terminado ! ')
