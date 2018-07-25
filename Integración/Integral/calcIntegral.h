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
		long double formTrapecio(vector<long double> vectInterpolado, long double intervaloMenor, long double intervaloMayor);
		long double formSimpson(vector<long double> vectInterpolado, long double intervaloMenor, long double intervaloMayor);
		long double errorRelativo(long double valorMedido, long double valorReal);
};
