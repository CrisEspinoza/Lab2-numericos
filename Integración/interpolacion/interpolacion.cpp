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

//Método de Interpolacion: Diferencias divididas
vector<double> Interpolacion::diferenciaDivididas(vector<double> vectorX, vector<double> vectorY, vector<double> vectorXInterpolado_0_05)
{
	int tamano = vectorX.size();
	double tablaDif[tamano][tamano];
	double xt;
	double yi;
	int i,j;

	//inicializa la tabla de diferencias
	for (i = 0; i < tamano; ++i)
	{
		tablaDif[i][0] = vectorY[i];
	}

	//calcula la tabla de diferencias
	for(j = 1 ; j < tamano ; j++)
	{
		for(i = 0 ; i < tamano-j ; i++)
		{
			tablaDif[i][j] = (tablaDif[i+1][j-1] - tablaDif[i][j-1])/(vectorX[i+j]-vectorX[i]);
		}
	}

	//interpola con el polinomio
	vector<double> vectorResultante;
	int contador = vectorXInterpolado_0_05.size();

	for(i = 0; i < contador; i++)
	{
		xt = 1;
		yi = tablaDif[0][0];

		for(j = 0 ;j < tamano-1 ;j++)
		{
			xt = xt * (vectorXInterpolado_0_05[i]-vectorX[j]);
			yi = yi + tablaDif[0][j+1] * xt;

		}

		vectorResultante.push_back(yi);
	}
	
	return vectorResultante;
}

//Método de Interpolacion de los Minimos Cuadrados
vector<double> Interpolacion::minimosCuadrados(vector<double> vectorX, vector<double> vectorY, vector<double> vectorXInterpolado_0_05)
{
    int tamano = vectorX.size();
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0;
    double yx0 = 0, yx1 = 0, yx2 = 0, yx3 = 0, yx4 = 0;

    //Calculamos todos los elementos que contiene la matriz
    for (int i = 0; i < tamano; ++i)
    {
        x1 = x1 + pow(vectorX[i],1.0);
        x2 = x2 + pow(vectorX[i],2.0);
        x3 = x3 + pow(vectorX[i],3.0);
        x4 = x4 + pow(vectorX[i],4.0);
        x5 = x5 + pow(vectorX[i],5.0);
        x6 = x6 + pow(vectorX[i],6.0);
        x7 = x7 + pow(vectorX[i],7.0);
        x8 = x8 + pow(vectorX[i],8.0);


        yx0 = yx0 + vectorY[i] * pow(vectorX[i],0.0);
        yx1 = yx1 + vectorY[i] * pow(vectorX[i],1.0);
        yx2 = yx2 + vectorY[i] * pow(vectorX[i],2.0);
        yx3 = yx3 + vectorY[i] * pow(vectorX[i],3.0);
        yx4 = yx4 + vectorY[i] * pow(vectorX[i],4.0);
    }

    mat A = mat(4,4);

    //relleno fila 1
    A(0,0) = tamano;
    A(0,1) = x1;
    A(0,2) = x2;
    A(0,3) = x3;
    
    //relleno fila 2
    A(1,0) = x1;
    A(1,1) = x2;
    A(1,2) = x3;
    A(1,3) = x4;  
    
    //relleno fila 3
    A(2,0) = x2;
    A(2,1) = x3;
    A(2,2) = x4;
    A(2,3) = x5;
    
    //relleno fila 4
    A(3,0) = x3;
    A(3,1) = x4;
    A(3,2) = x5;
    A(3,3) = x6;

    mat b = mat(1,4);
    b(0,0) = yx0;
    b(0,1) = yx1;
    b(0,2) = yx2;
    b(0,3) = yx3;

    mat B = b.t();

    vec C = solve(A,B);
    int count = vectorXInterpolado_0_05.size();
    vector<double> FXresultante; 

    for (int i = 0; i < count; ++i)
    {
        double yResultante = C(0) + C(1)*vectorXInterpolado_0_05[i] + C(2)* pow(vectorXInterpolado_0_05[i],2.0) + C(3) * pow(vectorXInterpolado_0_05[i],3.0);
        FXresultante.push_back(yResultante);
    }
    
    return FXresultante;

}

//Método de Interpolacion: Spline Cubico
vector<double> Interpolacion::splineCubico(vector<double> t, vector<double> y, vector<double> x)
{
	if(t.size() != y.size()){
        printf("los vectores tienen distinto largo ");
    }

    int tamano = t.size();
    int i,j;
    
    vector<double> h;
	double hi;
	
	//damos valor al vector h(distancia entre los x)
    for(i = 0 ;i < tamano-1; i++)
    {
        hi = t[i+1] - t[i];
        h.push_back(hi);
    }
    
	//se inicializan las matrices
	mat A(tamano-2, tamano-2);
    mat B(tamano-2,1);
    
    for(i = 0; i < tamano-2; i++)
    {
		for(j = 0; j < tamano-2; j++)
		{
			A(i,j) = 0; 	
		}
	}
	
	//se llena la matriz A
	j = 0;
	A(0,0) = 2*(h[0] + h[1]);
	A(0,1) = h[1];
		
    for(i = 1; i < tamano-3;i++)
    {
		A(i,j) = h[i];
		A(i,j+1) = 2*(h[i] + h[i+1]);
		A(i,j+2) = h[i+1];
		j++; 
	}
	
	A(tamano-3,tamano-3) = 2*(h[tamano-3] + h[tamano-2]);
	A(tamano-3,tamano-4) = h[tamano-3];
	
	//se llena la matriz B
	for(i = 0 ; i < tamano-2; i++)
	{
		B(i,0) = 6*( ( (y[i+2] - y[i+1]) / (t[i+2] - t[i+1]) ) - ( (y[i+1] - y[i])/ (t[i+1] - t[i]) ) );	
	}
	
	//resolver sistema ecuaciones con la funcion de armadillo "solve":
	vec X1 = solve(A, B);

    vector<double> solucion;
    
    //interpolando
    i = 0;
    double a,b,c,d,e,Rj;
	
    while(i < x.size())
    {
		for(j = 0; j < tamano-1; j++)
		{
			if(x[i]>= t[j] && x[i] < t[j+1])
			{
				break;
			}
		}
		if(j == 0)
		{
			a = 0 * (t[j+1] - x[i])*(t[j+1] - x[i])*(t[j+1] - x[i]) / 6*h[j];
			b = (x[i] - t[j])*(x[i] - t[j])*(x[i] - t[j]) * X1[j] / 6*h[j];
			c = ( ( (y[j+1] - y[j]) / h[j]) - ((X1[j] - 0) * h[j] /6)) * x[i];
			d = ( (y[j]*t[j+1]) - (y[j+1]*t[j])) / h[j] ;
			e = h[j]*(( (t[j]*X1[j]) - (t[j+1]* 0 )) / 6);
		}

		if(j == tamano-2)
		{
			a = X1[j-1] * (t[j+1] - x[i])*(t[j+1] - x[i])*(t[j+1] - x[i]) / 6*h[j];
			b = (x[i] - t[j])*(x[i] - t[j])*(x[i] - t[j]) * 0 / 6*h[j];
			c = ( ( (y[j+1] - y[j]) / h[j]) - ((0 - X1[j-1]) * h[j] /6)) * x[i];
			d = ( (y[j]*t[j+1]) - (y[j+1]*t[j])) / h[j] ;
			e = h[j]*(( (t[j]*0) - (t[j+1]*X1[j-1])) / 6);
		}
		
		if(j != tamano-2 && j != 0)
		{
			a = X1[j-1] * (t[j+1] - x[i])*(t[j+1] - x[i])*(t[j+1] - x[i]) / 6*h[j];
			b = (x[i] - t[j])*(x[i] - t[j])*(x[i] - t[j]) * X1[j] / 6*h[j];
			c = ( ( (y[j+1] - y[j]) / h[j]) - ((X1[j] - X1[j-1]) * h[j] /6)) * x[i];
			d = ( (y[j]*t[j+1]) - (y[j+1]*t[j])) / h[j] ;
			e = h[j]*(( (t[j]*X1[j]) - (t[j+1]*X1[j-1])) / 6);
		}

		Rj = a+b+c+d+e;
		solucion.push_back(Rj);
		i++;
	}
    
    return solucion;
}