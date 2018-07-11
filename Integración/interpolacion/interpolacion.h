#ifndef INTERPOLACION_H
#define INTERPOLACION_H

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>


#define  ARMA_DONT_USE_WRAPPER
#define  ARMA_USE_LAPACK
#include <armadillo>

using namespace std;
using namespace arma;


// Declaración de nuestra clase a utilizar
class Interpolacion
{
	public:	
		Interpolacion();
		long double func1(long double x);
		long double func2(long double x);	
		long double RMSE(vector<long double> vectorYInterpolado, vector<long double> vectorYReal);
		long double factorial(int numero, long double valor);
		long double** crearMatrizMet1y2(vector<long double> vectorX, vector<long double> vectorY);
		vector<long double> vectorX(long double distancia,int interMenor, int interMayor);
		vector<long double> vectorY(vector<long double> vectorInterX, int i);
		void diferenciasFinitas(vector<long double> vectorX, vector<long double> vectorY,vector<long double> vectorXInterpolado_0_05);
		vector<long double> diferenciaDivididas(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05);
		vector<long double> splineCubico(vector<long double> t, vector<long double> y, vector<long double> x);
		void minimosCuadrados(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05, int grado);
};

#endif