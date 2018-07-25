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

	for(i = 1; i < largo-1; i++)
	{
		valor = valor + (vectInterpolado[i]*2.0);
	}

	valorIntegral = ((intervaloMayor-intervaloMenor) / (2*(largo-1)))*(inicio+valor+final);
	
	return valorIntegral;
}

long double calcIntegral::formSimpson(vector<long double> vectInterpolado, long double intervaloMenor, long double intervaloMayor)
{
	int largo = vectInterpolado.size() , i;
	long double valoresImpares = 0.0 , valoresPares = 0.0 , inicial = vectInterpolado[0] , final = vectInterpolado[largo-1] , valorIntegral = 0.0 , resultadoCompleto = 0.0;
	
	for (i = 1; i < (largo / 2) ; i++)
	{	
		valoresPares = valoresPares + (2.0*vectInterpolado[i*2]);
		valoresImpares = valoresImpares +  (4.0*vectInterpolado[(i*2)-1]);
	}

	resultadoCompleto = valoresImpares + valoresPares;

	if(largo % 2 != 0)
	{
		resultadoCompleto = resultadoCompleto + (4.0*vectInterpolado[largo-2]);
	}

	valorIntegral = ((intervaloMayor-intervaloMenor)/(3.0*largo))*(inicial + resultadoCompleto + final);

	return valorIntegral;

	/*int n = vectorInterpolado.size();
	long double result = vectorInterpolado[0] + vectorInterpolado[n-1];
	for (int i = 1; i < (n/2); i++)
	{	
		result += 2.0*vectorInterpolado[i*2];
		result += 4.0*vectorInterpolado[(i*2)-1];
	}
	if(n%2 != 0){
		result += 4.0*vectorInterpolado[n-2];
	}
	result *= ((b-a)/(3.0*n));
	return result;*/
}

long double calcIntegral::errorRelativo(long double valorMedido, long double valorReal)
{
	long double error;
	long double absoluto;
	
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;

	return error;
}