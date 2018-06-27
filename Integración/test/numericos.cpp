#include "../interpolacion/interpolacion.h"

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#include <cstdlib>


#define  ARMA_DONT_USE_WRAPPER
#define  ARMA_USE_LAPACK
#include <armadillo>

using namespace std;
using namespace arma; 

void escribirArchivo(char* archivo,vector<double> vectorX, vector<double> vectorY)
{
  ofstream archivoSalida;
  archivoSalida.open(archivo,ios::out);

  for(int i = 0; i<vectorX.size(); i++)
  {
    archivoSalida<<vectorX[i]<<" "<<vectorY[i]<<endl;
  }
  
  archivoSalida.close();
}

void escribirArchivoDatos(ofstream &archivoDatos , char* archivo,vector<double> vectorX, vector<double> vectorY)
{

  for(int i = 0; i<vectorX.size(); i++)
  {
    archivoDatos<<vectorX[i]<<" "<<vectorY[i]<<endl;
  }
  
}

int main()
{
  int opcion;

  Interpolacion inter;
  double valor1;
  double valor2;
  char func1[256] = "e^x+x-2";
  char func2[256] = "x^3+4*x^2-5*x+2";

  // Declaranco variables de archivos de salida.
  ofstream archivoSalidaParte1,archivoSalidaParte2;
  archivoSalidaParte1.open("ErroresRMSEParte1.txt");
  ofstream archivoaux("Datos.txt");

  //Vector x interpolado en 0.5, 1, 5, 10
  vector<double> vectorX_0_5, vectorX_1, vectorX_5, vectorX_10; 

  //Vector f(x) donde x son los x interpolados antes. (Función 1)
  vector<double> vector1_Y_0_5, vector1_Y_1, vector1_Y_5, vector1_Y_10;
  
  //Vector f(x) donde x son los x interpolados antes. (Función 2)
  vector<double> vector2_Y_0_5, vector2_Y_1, vector2_Y_5, vector2_Y_10;

  //Vector para graficar escala logaritmica 
  vector<double> vectorXInterpolado_0_05, vector1_Y_Interpolado_0_05, vector2_Y_Interpolado_0_05;
  
  //Variables a utilizar Funcion 1:
  vector<double> difFinitas1_0_5,difFinitas1_1,difFinitas1_5,difFinitas1_10;
  double errorFinito1_0_5,errorFinito1_1,errorFinito1_5,errorFinito1_10;

  //Variables a utilizar Funcion 2:
  vector<double> difFinitas2_0_5,difFinitas2_1,difFinitas2_5,difFinitas2_10;
  double errorFinito2_0_5,errorFinito2_1,errorFinito2_5,errorFinito2_10;

  // Menu (UX)
  do
  {
    cout <<"\n   1. Comenzar parte 1 del laboratorio" << endl;
    cout <<"\n   2. Comenzar parte 2 del laboratorio" << endl;
    cout <<"\n   3. Creditos" << endl;
    cout <<"\n   4. Salir" << endl;
    cout <<"\n   Introduzca opcion (1-4): "; 

    scanf( "%d", &opcion );

    /* Inicio del anidamiento */

    switch ( opcion )
       {
       case 1: 
              //Vector x interpolado en 0.5, 1, 5, 10 (Asignando valores)
              vectorX_0_5 = inter.vectorX(0.5);
              vectorX_1 = inter.vectorX(1);
              vectorX_5 = inter.vectorX(5);
              vectorX_10 = inter.vectorX(10);
              //Vector f(x) donde x son los x interpolados antes. (Función 1) (Asignando valores)
              vector1_Y_0_5 = inter.vectorY(vectorX_0_5,1);
              vector1_Y_1 = inter.vectorY(vectorX_1,1);
              vector1_Y_5 = inter.vectorY(vectorX_5,1);
              vector1_Y_10 = inter.vectorY(vectorX_10,1);

              //Vector f(x) donde x son los x interpolados antes. (Función 2) (Asignando valores)
              vector2_Y_0_5 = inter.vectorY(vectorX_0_5,2);
              vector2_Y_1 = inter.vectorY(vectorX_1,2);
              vector2_Y_5 = inter.vectorY(vectorX_5,2);
              vector2_Y_10 = inter.vectorY(vectorX_10,2);

              //Vector para graficar escala logaritmica (Asignando valores)
              vectorXInterpolado_0_05 = inter.vectorX(0.05);
              vector1_Y_Interpolado_0_05 = inter.vectorY(vectorXInterpolado_0_05,1);
              vector2_Y_Interpolado_0_05 = inter.vectorY(vectorXInterpolado_0_05,2);

              // METODOS DE INTERPOLACION 

              //Metodo 1 : DIFERENCIAS FINITAS
              archivoSalidaParte1 << "METODOS DE INTERPOLACION:" << endl;
              
              archivoSalidaParte1 << ""<< endl;
              archivoSalidaParte1 << "Diferencias finitias:" << endl;
              archivoSalidaParte1 << ""<< endl;
              archivoSalidaParte1 << "Funcion 1 :" << func1 << endl;
              archivoSalidaParte1 << ""<< endl;

              // Funciones con x = 0.5
              difFinitas1_0_5 = inter.diferenciasFinitas(vectorX_0_5,vector1_Y_0_5,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC1_X=0_5.txt",vectorXInterpolado_0_05,difFinitas1_0_5);
              archivoaux<<" Comienza Metodo 1 : Diferencias divididas - FUNCION 1 : " << func1 <<endl;
              archivoaux<<" -------------------- Con X = 0.5 ----------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas1_0_5);
              errorFinito1_0_5 = inter.RMSE(difFinitas1_0_5,vector1_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con X = 0.5: "<<errorFinito1_0_5<<endl;

              // Funciones con x = 1
              difFinitas1_1 = inter.diferenciasFinitas(vectorX_1,vector1_Y_1,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC1_X=1.txt",vectorXInterpolado_0_05,difFinitas1_1);
              archivoaux<<" -----------------****************** Termino ******************------------------ "<<endl;
              archivoaux<<" ---------------- Con X = 1 --------------------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas1_1);
              errorFinito1_1 = inter.RMSE(difFinitas1_1,vector1_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con x = 1: "<<errorFinito1_1<<endl;

              // Funciones con x = 5
              difFinitas1_5 = inter.diferenciasFinitas(vectorX_5,vector1_Y_5,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC1_X=5.txt",vectorXInterpolado_0_05,difFinitas1_5);
              archivoaux<<" -----------------****************** Termino *******************------------------ "<<endl;
              archivoaux<<" ------------------ Con X = 5 -----------------------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas1_5);
              errorFinito1_5 = inter.RMSE(difFinitas1_5,vector1_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con x = 5: "<<errorFinito1_5<<endl;

              // Funciones con x = 10
              difFinitas1_10 = inter.diferenciasFinitas(vectorX_10,vector1_Y_10,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC1_X=10.txt",vectorXInterpolado_0_05,difFinitas1_10);
              archivoaux<<" -----------------****************** Termino ******************------------------ "<<endl;
              archivoaux<<" ------------------------- Con X = 10 -----------------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas1_10);
              errorFinito1_10 = inter.RMSE(difFinitas1_10,vector1_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con x = 10: "<<errorFinito1_10<<endl;
              archivoaux<<" -----------------****************** Termino ******************------------------ "<<endl;

              // Colocando salto de linea al archivo 
              archivoSalidaParte1<<endl;

              // Comnezamos el proceso para la funcion 2
              archivoSalidaParte1 << "Funcion 2 :" << func2 << endl;
              archivoSalidaParte1 << ""<< endl;

              // Funciones con x = 0.5
              difFinitas2_0_5 = inter.diferenciasFinitas(vectorX_0_5,vector2_Y_0_5,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC2_X=0_5.txt",vectorXInterpolado_0_05,difFinitas2_0_5);
              archivoaux<<" Comienza Metodo 1 : Diferencias divididas - FUNCION 2: " << func2 <<endl;
              archivoaux<<" -------------------- Con X = 0.5 ----------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas2_0_5);
              errorFinito2_0_5 = inter.RMSE(difFinitas2_0_5,vector2_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con X = 0.5: "<<errorFinito2_0_5<<endl;

              // Funciones con x = 1
              difFinitas2_1 = inter.diferenciasFinitas(vectorX_1,vector2_Y_1,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC2_X=1.txt",vectorXInterpolado_0_05,difFinitas2_1);
              archivoaux<<" -----------------****************** Termino ******************------------------ "<<endl;
              archivoaux<<" ---------------- Con X = 1 --------------------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas2_1);
              errorFinito2_1 = inter.RMSE(difFinitas2_1,vector2_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con x = 1: "<<errorFinito2_1<<endl;

              // Funciones con x = 5
              difFinitas2_5 = inter.diferenciasFinitas(vectorX_5,vector2_Y_5,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC2_X=5.txt",vectorXInterpolado_0_05,difFinitas2_5);
              archivoaux<<" -----------------****************** Termino *******************------------------ "<<endl;
              archivoaux<<" ------------------ Con X = 5 -----------------------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas2_5);
              errorFinito2_5 = inter.RMSE(difFinitas2_5,vector2_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con x = 5: "<<errorFinito2_5<<endl;

              // Funciones con x = 10
              difFinitas2_10 = inter.diferenciasFinitas(vectorX_10,vector2_Y_10,vectorXInterpolado_0_05);
              escribirArchivo((char*)"../Resultados/DIFERENCIASFINITAS_FUNC2_X=10.txt",vectorXInterpolado_0_05,difFinitas2_10);
              archivoaux<<" -----------------****************** Termino ******************------------------ "<<endl;
              archivoaux<<" ------------------------- Con X = 10 -----------------------------"<<endl;
              escribirArchivoDatos(archivoaux,(char*)"Datos.txt",vectorXInterpolado_0_05,difFinitas2_10);
              errorFinito2_10 = inter.RMSE(difFinitas2_10,vector2_Y_Interpolado_0_05);
              archivoSalidaParte1<<"Error con x = 10: "<<errorFinito2_10<<endl;
              archivoaux<<" -----------------****************** Termino ******************------------------ "<<endl;

              // Colocando salto de linea al archivo 
              archivoSalidaParte1<<endl;  

              //Metodo 2 : DIFERENCIAS DIVIDIDAS

              //Metodo 3 : MINIMOS CUADRADROS

              //Metodo 4 : SPLINE CÚBICOS

              break;

       case 2: //Parte 2
               break;

       case 3: cout <<" * Autor: Cristian Espinoza \n "<< endl;
               cout <<" * Universidad santiago de chile \n"<< endl;
               break;
       default:
               if(opcion != 4)
               cout <<"Esta opcion no esta permitida.\n"<< endl;
               break;
      }

    }while(opcion!=4);

  archivoSalidaParte1.close();
  archivoaux.close();

  return 0;
}

// Ejemplo clases

  //cout << "Armadillo version: " << arma_version::as_string() << endl;
    // Se declaran las matrices a utilizar: 
  
  /*A.load("289x289/A289.dat",raw_ascii);
    B.load("289x289/b289.dat",raw_ascii);
    A.load("289x289/A289.dat",raw_ascii);
    B.load("289x289/b289.dat",raw_ascii);
   */
  
   /* Codigo que realiza el metodo de LU      
   clock_gettime(CLOCK_MONOTONIC,&strart);
    
   A.load("4225x4225/A4225.dat",raw_ascii);
   B.load("4225x4225/b4225.dat",raw_ascii);
   mat L, U;
   lu(L,U,B,A);
   mat X = B.t()*L*U;
  
   clock_gettime(CLOCK_MONOTONIC,&end);
  
   diff = end.tv_nsec - strart.tv_nsec;
  
   cout << X << endl; 
   cout << diff << endl;
   */