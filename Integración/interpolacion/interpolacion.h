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
		double func1(double x);
		double func2(double x);	
		double RMSE(vector<double> vectorYInterpolado, vector<double> vectorYReal);
		double factorial(int numero, double valor);
		vector<double> vectorX(double distancia);
		vector<double> vectorY(vector<double> vectorInterX, int i);
		vector<double> diferenciasFinitas(vector<double> vectorX, vector<double> vectorY,vector<double> vectorXInterpolado_0_05);
		vector<double> diferenciaDivididas(vector<double> vectorX, vector<double> vectorY, vector<double> vectorXInterpolado_0_05);
		vector<double> splineCubico(vector<double> t, vector<double> y, vector<double> x);
		vector<double> minimosCuadrados(vector<double> vectorX, vector<double> vectorY, vector<double> vectorXInterpolado_0_05);
};

#endif