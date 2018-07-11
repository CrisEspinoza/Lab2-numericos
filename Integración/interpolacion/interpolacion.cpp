#include "interpolacion.h"

//Constructor
Interpolacion::Interpolacion(){
}

// Funciones que evalua la funcion 1 con el valor ingresado
long double Interpolacion::func1 (long double x)
{
	long double valor = exp(x)+x-2;
	return valor;
}


// Funciones que evalua la funcion 2 con el valor ingresado
long double Interpolacion::func2 (long double x)
{
	long double valor = pow(x,3)+4*pow(x,2)-5*x+2;
	return valor;
}

// Calcula el error
long double Interpolacion::RMSE(vector<long double> vectorYInterpolado, vector<long double> vectorYReal)
{
	long double largo = vectorYReal.size();
	long double resultadoParcial = 0;
	long double resultadoFinal;
	int i ;

	for(i = 0; i < largo; i++)
	{
		resultadoParcial = resultadoParcial + pow(vectorYReal[i]-vectorYInterpolado[i],2.0);
	}

	resultadoFinal = sqrt(resultadoParcial/largo);
	
	return resultadoFinal;
}

//Calcula el factorial de un numero ingresado
long double Interpolacion::factorial(int numero, long double valor)
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
vector<long double> Interpolacion::vectorX(long double distancia,int interMenor, int interMayor)
{
	vector<long double> vectorResultante;
	double i;
	
	// Iteracion de valores de x e y, segun el intervalo ingresado
	for(i = interMenor; i <= interMayor; i = i + distancia)
	{
		//cout<< distancia <<endl;
		vectorResultante.push_back(i);
	}
	
	return vectorResultante;
}


/*Funcion que retorna el vector que se forma para x, con la diferencia
que se ingresa como parametro*/
vector<long double> Interpolacion::vectorY(vector<long double> vectorInterX, int i)
{
	vector<long double> vectorResultante;
	long double valor;
	
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

long double** Interpolacion::crearMatrizMet1y2(vector<long double> vectorX, vector<long double> vectorY)
{
	int tamano = vectorX.size();
	cout << "El numero del arreglo es de: " << tamano << endl;

	int i,j,descuento=0;
	long double **matriz;
	matriz = (long double**)calloc((tamano+1),sizeof(long double*));
   	for (i = 0 ; i <= tamano; ++i)
     	matriz[i] = (long double*)calloc(tamano,sizeof(long double));
	
	//inicializa la tabla de diferencias y tabla de valores
	for (i = 0; i < tamano; i++)
	{
		matriz[0][i] = vectorX[i];
		matriz[1][i] = vectorY[i];
	}

	// Me falta rellenar los demas :o ... 
	for (j = 2; j <= tamano; j++)
	{
		for (i = 0 ; i < tamano-descuento; i++)
		{
			cout<<matriz[j-1][i+1]<<endl;
			cout<< matriz[j-1][i]<<endl;
			cout<<matriz[0][i+1]<<endl;
			cout<<matriz[0][i]<<endl;

			matriz[j][i] = ( (matriz[j-1][i+1] - matriz[j-1][i]) / (matriz[0][i+1] - matriz[0][i]) );

			cout<<"El resultado es : "<<matriz[j][i]<<endl;
		}
		descuento++;
	}

	
	for (i = 2; i <= tamano ; i++)
	{
		for (j = 0; j < tamano; j++)
		{
			cout << "Matriz" <<"[" << i <<"]"<<"["<< j << "] : " << matriz[i][j] << endl;
		}
		cout<<endl;
		cout<<endl;
	}

	return matriz;
}

//Método de Interpolación: Diferencias finitas
void Interpolacion::diferenciasFinitas(vector<long double> vectorX, vector<long double> vectorY,vector<long double> vectorXInterpolado_0_05)
{
	long double **matriz;
	matriz = crearMatrizMet1y2(vectorX,vectorY);
	int tamano = vectorX.size();
	int i,j;

	/*
	// Comprobando la matriz que resulto
	for (i = 2; i <= tamano ; i++)
	{
		for (j = 0; j < tamano; j++)
		{
			cout << "Matriz" <<"[" << i <<"]"<<"["<< j << "] : " << matriz[i][j] << endl;
		}
		cout<<endl;
		cout<<endl;
	}*/

	/*//interpola con el polinomio
	vector<long double> vectorResultante;
	int contador = vectorXInterpolado_0_05.size();
 
	for(i = 0; i < contador; i++){
		xt = 1;
		yi = tablaVal[0][0];
		
		for(j = 0; j < tamano - 1; j++){
			xt = xt * (vectorXInterpolado_0_05[i]-vectorX[j]);
			yi = yi + tablaVal[0][j+1] * xt;
		}

		vectorResultante.push_back(yi);
	}*/
	
}

//Método de Interpolacion: Diferencias divididas
vector<long double> Interpolacion::diferenciaDivididas(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05)
{
	int tamano = vectorX.size();
	long double tablaDif[tamano][tamano];
	long double xt;
	long double yi;
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
	vector<long double> vectorResultante;
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
void Interpolacion::minimosCuadrados(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05, int grado)
{
	long double **matriz,*matriz2,*matriz3;
	int i,j,tamano=vectorX.size();
	int maxGrado = 2*grado;
	long double matrizSum[maxGrado];
	//cout<<"EL tamano es: "<<tamano<<endl;
	
	
	matriz = (long double**)calloc((grado+1),sizeof(long double*));
   	for (i = 0 ; i <= grado; ++i)
     	matriz[i] = (long double*)calloc(grado+1,sizeof(long double));
    matriz2 = (long double*)calloc((maxGrado),sizeof(long double));
    matriz3 = (long double*)calloc((maxGrado),sizeof(long double));
    	 	
    //Creando las sumatorias
    
    for (i = 0; i < maxGrado; i++)
    {
    	matrizSum[i] = 0;
    }

    for (i = 0; i < maxGrado; i++)
    {
		for (j = 0; j < tamano; j++)
		{	
			//cout<<"El numeor a sumar es :"<<pow(vectorX[j],(long double)(i+1))<<endl;
			matrizSum[i] = matrizSum[i] + (long double)pow(vectorX[j],(long double)(i+1));
			//cout<<"El numero acumulado es: "<< matrizSum[i]<<endl;
		}   
		//cout<<"Termino la primera vuelta ----------------"<<endl; 	
   	}
   	
   	
   	/*//Revisando sumatorias
   	for (i = 0; i < maxGrado; i++)
   	{
   		cout << "Resultado_" <<i<<":"<<matrizSum[i]<<endl;
   	}*/

   	//Rellenando matriz
   	for (i = 0; i <= grado; i++)
   	{
   		for (j = 0; j <= grado; j++)
   		{
   			if (i == 0 && j == 0)
   				matriz[i][j] = tamano;		
   			else
   				matriz[i][j] = matrizSum[i+j-1];
   		}	
   	}

   	/*//Revisando matriz
   	for (i = 0; i <= grado; i++)
   	{
   		for (j = 0; j <= grado; j++)
   		{
   			cout<<matriz[i][j]<<" - ";
   		}
   		cout<<endl;	
   	}*/

   	// Realizando matriz de Y

    for (i = 0; i < maxGrado; i++)
    {
		for (j = 0; j < tamano; j++)
		{	
			//cout<<"El numeor a sumar es :"<<pow(vectorX[j],(long double)(i+1))<<endl;
			matriz2[i] = matriz2[i] + vectorY[j] * (long double)pow(vectorX[j],(long double) (i));
			//cout<<"El numero acumulado es: "<< matrizSum[i]<<endl;
		}   
		//cout<<"Termino la primera vuelta ----------------"<<endl; 	
   	}

   	/*//Mostrando vector Y
   	for (j = 0; j < maxGrado; j++)
   	{
   		cout<<matriz2[j]<<endl;
   	}*/

   matriz3 = lu(&matriz,matriz2);	
}

//Método de Interpolacion: Spline Cubico
vector<long double> Interpolacion::splineCubico(vector<long double> t, vector<long double> y, vector<long double> x)
{
	if(t.size() != y.size()){
        printf("los vectores tienen distinto largo ");
    }

    int tamano = t.size();
    int i,j;
    
    vector<long double> h;
	long double hi;
	
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

    vector<long double> solucion;
    
    //interpolando
    i = 0;
    long double a,b,c,d,e,Rj;
	
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