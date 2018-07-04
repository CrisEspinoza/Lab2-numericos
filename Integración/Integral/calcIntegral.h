#include <iostream>
#include <cmath>
#include <math.h>
#include <armadillo>

using namespace std;
using namespace arma;

class calcIntegral
{
	public:
		calcIntegral();
		double formTrapecio(vector<double> vectorInterpolado, double a, double b);
		double formSimpson(int n, vector<double> vectorInterpolado, double a, double b);
		double errorRelativo(double valorMedido, double valorReal);
};
