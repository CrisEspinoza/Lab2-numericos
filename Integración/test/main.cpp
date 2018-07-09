#include "../interpolacion/interpolacion.h"
#include "../Integral/calcIntegral.h"

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

void escribirArchivo(char* archivo,vector<long double> vectorX, vector<long double> vectorY)
{
  ofstream archivoSalida;
  archivoSalida.open(archivo,ios::out);

  for(int i = 0; i<vectorX.size(); i++)
  {
    archivoSalida<<vectorX[i]<<" "<<vectorY[i]<<endl;
  }
  
  archivoSalida.close();
}

void escribirArchivoDatos(ofstream &archivoDatos,vector<long double> vectorX)
{

  for(int i = 0; i<vectorX.size(); i++)
  {
    archivoDatos<<vectorX[i]<<" "<<endl;
  }
  archivoDatos<< "-------------------------------------- TERMINO ----------------------------------------"<<endl;
}

int main()
{
  int opcion;
  int bandera = 0;
  Interpolacion inter;
  int intervaloMenor = -200 , intervaloMayor = 200;
  //calcIntegral calcIntegral;
  char func1[256] = "e^x+x-2";
  char func2[256] = "x^3+4*x^2-5*x+2";

  // Variables ocupadas para la parte 1 del enunciado;

  // Declaranco variables de archivos de salida.
  ofstream archivoSalidaParte1,archivoSalidaParte2,resultF1_0_05,resultF1_1,resultF1_5,resultF1_10, 
            resultF2_0_05,resultF2_1,resultF2_5,resultF2_10;
  archivoSalidaParte1.open("ErroresRMSEParte1.txt");
  ofstream archivoaux("Datos.txt");
  // Resultado de funciones reales
    //Funcion 1
  resultF1_0_05.open ("../ResultadosReales/real_0_05_F1.txt");
  resultF1_1.open("../ResultadosReales/real_1_F1.txt");
  resultF1_5.open("../ResultadosReales/real_5_F1.txt");
  resultF1_10.open("../ResultadosReales/real_10_F1.txt");
    //Funcion 2
  resultF2_0_05.open("../ResultadosReales/real_0_05_F2.txt");
  resultF2_1.open("../ResultadosReales/real_1_F2.txt");
  resultF2_5.open("../ResultadosReales/real_5_F2.txt");
  resultF2_10.open("../ResultadosReales/real_10_F2.txt");

  //Vector x interpolado en 0.5, 1, 5, 10
  vector<long double> vectorX_0_5, vectorX_1, vectorX_5, vectorX_10; 

  //Vector f(x) donde x son los x interpolados antes. (Función 1)
  vector<long double> vector1_Y_0_5, vector1_Y_1, vector1_Y_5, vector1_Y_10;
  
  //Vector f(x) donde x son los x interpolados antes. (Función 2)
  vector<long double> vector2_Y_0_5, vector2_Y_1, vector2_Y_5, vector2_Y_10;

  //Vector para graficar escala logaritmica 
  vector<long double> vectorXInterpolado_0_05, vector1_Y_Interpolado_0_05, vector2_Y_Interpolado_0_05;

  // Metodo 1:
    //Variables a utilizar Funcion 1:

    //Variables a utilizar Funcion 2:

  // Metodo 2:
    //Variables a utilizar Funcion 1:
    //Variables a utilizar Funcion 2:

  // Metodo 3:
    //Variables a utilizar Funcion 1:
  //Variables a utilizar Funcion 2:

  // Metodo 4:
    //Variables a utilizar Funcion 1:
    //Variables a utilizar Funcion 2:

  // Variables ocupadas para la parte 2 del enunciados:

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
       case 1://Vector x interpolado en 0.5, 1, 5, 10 (Asignando valores)
              vectorX_0_5 = inter.vectorX(0.5,intervaloMenor,intervaloMayor);
              vectorX_1 = inter.vectorX(1,intervaloMenor,intervaloMayor);
              vectorX_5 = inter.vectorX(5,intervaloMenor,intervaloMayor);
              vectorX_10 = inter.vectorX(10,intervaloMenor,intervaloMayor);
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
              vectorXInterpolado_0_05 = inter.vectorX(0.05,intervaloMenor,intervaloMayor);
              vector1_Y_Interpolado_0_05 = inter.vectorY(vectorXInterpolado_0_05,1);
              vector2_Y_Interpolado_0_05 = inter.vectorY(vectorXInterpolado_0_05,2);

              /* Probando separacion de verctores ...
              //escribirArchivoDatos(archivoaux,vectorXInterpolado_0_05);
              //escribirArchivoDatos(archivoaux,vectorX_0_5);
              //escribirArchivoDatos(archivoaux,vectorX_1);
              //escribirArchivoDatos(archivoaux,vectorX_5);
              //escribirArchivoDatos(archivoaux,vectorX_10);
              */

              /*
              // Valores reales de las funciones 
                // Funcion 1
              escribirArchivo( (char*)"../ResultadosReales/real_0_05_F1.txt",vectorX_0_5,vector1_Y_0_5);
              escribirArchivo( (char*)"../ResultadosReales/real_1_F1.txt",vectorX_1,vector1_Y_1);
              escribirArchivo( (char*)"../ResultadosReales/real_5_F1.txt",vectorX_5,vector1_Y_5);
              escribirArchivo( (char*)"../ResultadosReales/real_10_F1.txt",vectorX_10,vector1_Y_10);
                // Funcion 2
              escribirArchivo( (char*)"../ResultadosReales/real_0_05_F2.txt",vectorX_0_5,vector2_Y_0_5);
              escribirArchivo( (char*)"../ResultadosReales/real_1_F2.txt",vectorX_1,vector2_Y_1);
              escribirArchivo( (char*)"../ResultadosReales/real_5_F2.txt",vectorX_5,vector2_Y_5);
              escribirArchivo( (char*)"../ResultadosReales/real_10_F2.txt",vectorX_10,vector2_Y_10);
              */
              
              // Liberando opcion 2
              bandera = 1;

              break;

       case 2: 
              if(bandera == 0)
              {
                cout << "Primero tiene que realizar la opcion 1, para poder pasar a la segunda parte del laboratorio" ;
                break;
              }
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


  return 0;
}