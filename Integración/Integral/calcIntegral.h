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
		double formTrapecio(vector<double> vectInterpolado, double intervaloMenor, double intervaloMayor);
		double formSimpson(int tamano, vector<double> vectInterpolado, double intervaloMenor, double intervaloMayor);
		double errorRelativo(double valorMedido, double valorReal);
};
