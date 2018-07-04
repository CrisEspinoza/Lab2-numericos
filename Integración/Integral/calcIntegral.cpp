#include "calcIntegral.h"

calcIntegral::calcIntegral(){
}

double calcIntegral::formTrapecio(vector<double> vectInterpolado, double intervaloMenor, double intervaloMayor)
{
	int largo = vectInterpolado.size();
	double valorIntegral = 0.0;
	double inicio = vectInterpolado[0];
	double final = vectInterpolado[largo-1];
	double valor = 0.0;

	for(int i = 1; i < (largo-1); i++)
	{
		valor = valor + (2.0*vectInterpolado[i]);
	}

	valorIntegral = ((intervaloMayor-intervaloMenor) / (2*(largo-1)))*(inicio+valor+final);
	
	return valorIntegral;
}

double calcIntegral::formSimpson(int tamano, vector<double> vectInterpolado, double intervaloMenor, double intervaloMayor)
{
	double valoresImpares = 0.0;
	double valoresPares = 0.0;
	int largo = vectInterpolado.size();
	double inicial = vectInterpolado[0];
	double final = vectInterpolado[tamano];
	double valorIntegral = 0.0;

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

double calcIntegral::errorRelativo(double valorMedido, double valorReal)
{
	double error;
	double absoluto;
	
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;

	return error;
}