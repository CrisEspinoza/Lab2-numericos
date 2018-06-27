#include "interpolacion.h"

//Constructor
Interpolacion::Interpolacion(){
}

// Funciones que evalua la funcion 1 con el valor ingresado
double Interpolacion::func1 (double x)
{
	double valor = exp(x)+x-2;
	return valor;
}


// Funciones que evalua la funcion 2 con el valor ingresado
double Interpolacion::func2 (double x)
{
	double valor = pow(x,3)+4*pow(x,2)-5*x+2;
	return valor;
}

// Calcula el error
double Interpolacion::RMSE(vector<double> vectorYInterpolado, vector<double> vectorYReal)
{
	double largo = vectorYReal.size();
	double resultadoParcial = 0;
	double resultadoFinal;
	int i ;

	for(i = 0; i < largo; i++){
		resultadoParcial = resultadoParcial + pow(vectorYReal[i]-vectorYInterpolado[i],2.0);
	}

	resultadoFinal = sqrt(resultadoParcial/largo);
	
	return resultadoFinal;
}

//Calcula el factorial de un numero ingresado
double Interpolacion::factorial(int numero, double valor)
{
	if(numero == 0)
	{
		return valor;
	}
	else
	{
		valor = valor*numero;
		factorial(numero-1,valor);
	}
}

/*Funcion que retorna el vector que se forma para x, con la diferencia
que se ingresa como parametro*/
vector<double> Interpolacion::vectorX(double distancia)
{
	vector<double> vectorResultante;
	double i;
	
	// Intervalo fijo de [-200,200]
	for(i = -200; i <= 200; i = i + distancia){
		if(i == 0)
			break;
		vectorResultante.push_back(i);
	}
	
	return vectorResultante;
}


/*Funcion que retorna el vector que se forma para x, con la diferencia
que se ingresa como parametro*/
vector<double> Interpolacion::vectorY(vector<double> vectorInterX, int i)
{
	vector<double> vectorResultante;
	double valor;
	
	//para funcion1
	if(i == 1){
		for(int i = 0; i < vectorInterX.size(); i++){
			valor = func1(vectorInterX[i]);
			vectorResultante.push_back(valor);
		}
	}

	//para funcion2
	else if(i == 2){
		for(int i = 0; i < vectorInterX.size(); i++){
			
			valor = func2(vectorInterX[i]);
			vectorResultante.push_back(valor);
		}
	}

	return vectorResultante;
}

//Método de Interpolación: Diferencias finitas
vector<double> Interpolacion::diferenciasFinitas(vector<double> vectorX, vector<double> vectorY,vector<double> vectorXInterpolado_0_05)
{
	int i,j;
	int tamano = vectorX.size();
	double tablaDif[tamano][tamano]; //tabla de diferencias
	double tablaVal[tamano][tamano]; //tabla de valores
	double xt;
	double yi;

	//inicializa la tabla de diferencias y tabla de valores
	for (i = 0; i < tamano; ++i){
		tablaVal[i][0] = vectorY[i];
		tablaDif[i][0] = vectorY[i];
	}

	//calcula la tabla de diferencias
	for(j = 1; j < tamano; j++){
		for(i = 0; i < tamano - j ; i++){
			tablaDif[i][j] = tablaDif[i+1][j-1] - tablaDif[i][j-1];
		}
	}

	//calcula la tabla de valores 
	int h = vectorX[1]-vectorX[0];

	for(j = 1; j < tamano; j++){
		for(i = 0; i < tamano-j ; i++){
			tablaVal[i][j] = (tablaDif[i][j])/((pow(h,j))*factorial(j,1));
		}
	}

	//interpola con el polinomio
	vector<double> vectorResultante;
	int contador = vectorXInterpolado_0_05.size();

	for(i = 0; i < contador; i++){
		xt = 1;
		yi = tablaVal[0][0];
		
		for(j = 0; j < tamano - 1; j++){
			xt = xt * (vectorXInterpolado_0_05[i]-vectorX[j]);
			yi = yi + tablaVal[0][j+1] * xt;
		}

		vectorResultante.push_back(yi);
	}
	
	return vectorResultante;
}


