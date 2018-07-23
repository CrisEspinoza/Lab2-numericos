#include "calcIntegral.h"

calcIntegral::calcIntegral(){
}

long double calcIntegral::formTrapecio(vector<long double> vectInterpolado, long double intervaloMenor, long double intervaloMayor)
{
	int largo = vectInterpolado.size();
	int i;
	long double valorIntegral = 0.0;
	long double inicio = vectInterpolado[0];
	long double final = vectInterpolado[largo-1];
	long double valor = 0.0;

	for(i = 1; i < (largo-1); i++)
	{
		valor = valor + (vectInterpolado[i]*2.0);
	}

	valorIntegral = ((intervaloMayor-intervaloMenor) / (2*(largo-1)))*(inicio+valor+final);
	
	return valorIntegral;
}

long double calcIntegral::formSimpson(int tamano, vector<long double> vectInterpolado, long double intervaloMenor, long double intervaloMayor)
{
	long double valoresImpares = 0.0;
	long double valoresPares = 0.0;
	int largo = vectInterpolado.size();
	long double inicial = vectInterpolado[0];
	long double final = vectInterpolado[tamano];
	long double valorIntegral = 0.0;

	for (int i = 1; i <= (tamano/2) - 1; i++)
	{	
		valoresPares += 2.0*vectInterpolado[i*2];

	}
	
	for (int i = 1; i <= (tamano/2) ; i++)
	{	
			valoresImpares += 4.0*vectInterpolado[(i*2)-1];	
	}

	valorIntegral = ((intervaloMayor-intervaloMenor)/(3.0*tamano))*(inicial + valoresImpares + valoresPares + final);

	return valorIntegral;
}

long double calcIntegral::errorRelativo(long double valorMedido, long double valorReal)
{
	long double error;
	long double absoluto;
	
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;

	return error;
}