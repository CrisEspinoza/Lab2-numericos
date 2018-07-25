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
	long double largo = vectorYInterpolado.size();
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
		vectorResultante.push_back(i);
	}

	if (vectorResultante[vectorResultante.size() - 1 ] != 200.0)
	{
		vectorResultante.push_back(200.0);
	}
	
	return vectorResultante;
}


/*Funcion que retorna el vector que se forma para x, con la diferencia
que se ingresa como parametro*/
vector<long double> Interpolacion::vectorY(vector<long double> vectorInterX, int i)
{
	vector<long double> vectorResultante;
	long double valor = 0.0;
	int j;

	//para funcion1
	if(i == 1)
	{
		for(j = 0; j < vectorInterX.size(); j++)
		{
			//cout<<"El valor a evaluar : "<<vectorInterX[j]<<endl;
			valor = func1(vectorInterX[j]);
			vectorResultante.push_back(valor);
			valor = 0.0;
		}
	}

	//para funcion2
	else if(i == 2)
	{
		for(j = 0; j < vectorInterX.size(); j++)
		{
			
			valor = func2(vectorInterX[j]);
			vectorResultante.push_back(valor);
		}
	}

	return vectorResultante;
}

long double** Interpolacion::crearMatrizMet1(vector<long double> vectorX, vector<long double> vectorY)
{
	int tamano = vectorX.size();
	//cout << "El numero del arreglo es de: " << tamano << endl;

	int i,j,descuento=0;
	long double **matriz,**matrizA;
	matriz = (long double**)calloc((tamano+1),sizeof(long double*));
   	for (i = 0 ; i <= tamano; i++)
     	matriz[i] = (long double*)calloc(tamano,sizeof(long double));

     	matrizA = (long double**)calloc((tamano+1),sizeof(long double*));
   	for (i = 0 ; i <= tamano; i++)
     	matrizA[i] = (long double*)calloc(tamano,sizeof(long double));

    for (i = 0; i <= tamano; i++)
    {
    	for (j = 0; j < tamano; j++)
    	{
    		matriz[i][j] = 1.0;
    	}
    }
	
	//inicializa la tabla de diferencias y tabla de valores
	for (i = 0; i < tamano; i++)
	{
		matriz[0][i] = vectorX[i];
		matriz[1][i] = vectorY[i];
		//cout << matriz[0][i] << ", " << matriz[1][i] << endl;
	}


	// Me falta rellenar los demas :o ... 
	for (j = 2; j <= tamano; j++)
	{
		//cout<<"J ES : " <<j<<endl;
		for (i = 0 ; i < tamano-descuento-1; i++)
		{
			//cout<<matriz[j-1][i+1]<<endl;
			//cout<< matriz[j-1][i]<<endl;
			//cout<<matriz[0][i+1]<<endl;
			//cout<<matriz[0][i]<<endl;
			
			//cout<<"aca"<<endl;
			matriz[j][i] = ( (matriz[j-1][i+1] - matriz[j-1][i]) / (matriz[0][i+1] - matriz[0][i]) );
			
			//cout<<"El resultado es j:"<<j<<", i:"<<i<<"- matriz : "<<matrizA[j][i]<<endl;
			
			//cout<<"aca"<<endl;
		}
		descuento++;
	}

	//cout<<"Sasali ---- "<< endl;
	
	for (i = 2; i <= tamano ; i++)
	{
		for (j = 0; j < tamano; j++)
		{
			matrizA[i-2][j] = matriz[i][j];
		}
		//cout<<endl;
		//cout<<endl;
	}

	for (i = 2; i <= tamano ; i++)
	{
		for (j = 0; j < tamano; j++)
		{
			//cout << matrizA[i][j] << " - ";
		}
		//cout<<endl;
		//cout<<endl;
	}

	return matrizA;
}

long double** Interpolacion::crearMatrizMet2(vector<long double> vectorX, vector<long double> vectorY)
{
	int tamano = vectorX.size();
	//cout << "El numero del arreglo es de: " << tamano << endl;

	int i,j,descuento = 0;
	long double h = 0.0;

	long double **matriz,**matrizA;
	matriz = (long double**)calloc((tamano+1),sizeof(long double*));
   	for (i = 0 ; i <= tamano; i++)
     	matriz[i] = (long double*)calloc(tamano,sizeof(long double));

     	matrizA = (long double**)calloc((tamano+1),sizeof(long double*));
   	for (i = 0 ; i <= tamano; i++)
     	matrizA[i] = (long double*)calloc(tamano,sizeof(long double));

    for (i = 0; i <= tamano; i++)
    {
    	for (j = 0; j < tamano; j++)
    	{
    		matriz[i][j] = 1.0;
    	}
    }
	
	//inicializa la tabla de diferencias y tabla de valores
	for (i = 0; i < tamano; i++)
	{
		matriz[0][i] = vectorX[i];
		matriz[1][i] = vectorY[i];
		//cout << matriz[0][i] << ", " << matriz[1][i] << endl;
	}


	// Me falta rellenar los demas :o ... 
	for (j = 2; j <= tamano; j++)
	{
		//cout<<"J ES : " <<j<<endl;
		for (i = 0 ; i < tamano-descuento-1; i++)
		{
			//cout<<matriz[j-1][i+1]<<endl;
			//cout<< matriz[j-1][i]<<endl;
			//cout<<matriz[0][i+1]<<endl;
			//cout<<matriz[0][i]<<endl;
			
			//cout<<"aca"<<endl;
			matriz[j][i] = (matriz[j-1][i+1] - matriz[j-1][i]);
			
			//cout<<"El resultado es j:"<<j<<", i:"<<i<<"- matriz : "<<matrizA[j][i]<<endl;
			
			//cout<<"aca"<<endl;
		}
		descuento++;
	}

	h = vectorX[1]-vectorX[0];
	
	for(j = 2; j < tamano ; j++)
	{
		for(i = 0; i < tamano - descuento - 1 ; i++)
		{
            //cout << "b[i][j]: " << b[i][j] << "pow(h,j): " << pow(h,j) << "factorial(j):" << factorial(j) << endl;
			matriz[j][i] = (matriz[j][i])/((pow(h,j))*factorial(j,1));
            //cout << "(pow(h,j): " << pow(h,j) << endl; 
            //cout << "factorial(j): " << factorial(j) << endl;
            //cout << endl;
		}
		descuento++;
	}

	//cout<<"Sasali ---- "<< endl;
	
	for (i = 2; i <= tamano ; i++)
	{
		for (j = 0; j < tamano; j++)
		{
			matrizA[i-2][j] = matriz[i][j];
		}
		//cout<<endl;
		//cout<<endl;
	}

	for (i = 2; i <= tamano ; i++)
	{
		for (j = 0; j < tamano; j++)
		{
			//cout << matrizA[i][j] << " - ";
		}
		//cout<<endl;
		//cout<<endl;
	}

	return matrizA;
}

//Método de Interpolación: Diferencias finitas
vector<long double> Interpolacion::diferenciasFinitas(vector<long double> vectorX, vector<long double> vectorY,vector<long double> vectorXInterpolado_0_05, int corte)
{

	//cout<<"Llegue"<<endl;
	long double **matriz;
	matriz = crearMatrizMet2(vectorX,vectorY);

	int tamano = vectorX.size();
	int i,j,z;
	int descuento;	
	long double xt;
	long double yi;
	long double limiteMayor = 6.03588e+86;

	//cout<<"Llegue 1"<<endl;
	
	// Comprobando la matriz que resulto
	for (j = 0; j <= tamano; j++)
	{
		for (i = 0 ; i < tamano-descuento-1; i++)
		{
			//cout << "Matriz" <<"[" << i <<"]"<<"["<< j << "] : " << matriz[j][i] << endl;
		}
		//cout<<endl;
		//cout<<endl;
		descuento++;
	}
	

	//interpola con el polinomio
	vector<long double> vectorResultante;
	int contador = vectorXInterpolado_0_05.size();

	for (j = 0; j < contador; j++)
	{
		xt = 1.0;
		yi = matriz[0][0];
		for (z = 0 ; z < tamano - corte ; z++)
		{
			xt = xt * (vectorXInterpolado_0_05[j]-vectorX[z]);
			//if ((yi + ( matriz[i+1][0] * xt )) > limiteMayor) break;
			yi = yi + ( matriz[0][i+z] * xt );
			
		}
		vectorResultante.push_back(yi);
	}

	return vectorResultante;
}

//Método de Interpolacion: Diferencias divididas
vector<long double> Interpolacion::diferenciaDivididas(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05, int corte)
{
	//cout<<"Llegue"<<endl;
	long double **matriz;
	matriz = crearMatrizMet1(vectorX,vectorY);

	int tamano = vectorX.size();
	int i,j,z;
	int descuento;	
	long double xt;
	long double yi;
	long double limiteMayor = 6.03588e+86;

	//cout<<"Llegue 1"<<endl;
	
	// Comprobando la matriz que resulto
	for (j = 0; j <= tamano; j++)
	{
		for (i = 0 ; i < tamano-descuento-1; i++)
		{
			//cout << "Matriz" <<"[" << i <<"]"<<"["<< j << "] : " << matriz[j][i] << endl;
		}
		//cout<<endl;
		//cout<<endl;
		descuento++;
	}
	

	//interpola con el polinomio
	vector<long double> vectorResultante;
	int contador = vectorXInterpolado_0_05.size();

	for (j = 0; j < contador; j++)
	{
		xt = 1.0;
		yi = matriz[0][0];
		for (z = 0 ; z < tamano - corte ; z++)
		{
			xt = xt * (vectorXInterpolado_0_05[j]-vectorX[z]);
			//if ((yi + ( matriz[i+1][0] * xt )) > limiteMayor) break;
			yi = yi + ( matriz[0][i+z] * xt );
			
		}
		vectorResultante.push_back(yi);
	}
	/*for(i = 0; i < contador; i++)
	{
		xt = 1.0;
		yi = matriz[1][0];
		
		for(j = 0; j < tamano - 10 ; j++)
		{
			xt = xt * (vectorXInterpolado_0_05[i]-vectorX[j]);
			yi = yi + ( matriz[j+1][0] * xt );
		}
		//cout<<"El vector agregar es: "<< yi << endl;
		
		vectorResultante.push_back(yi);
	}*/
 
	/* BUENO ..... 11 for(i = 0; i < contador; i++)
	{
		xt = 1.0;
		yi = matriz[1][0];
		
		for(j = 0; j < tamano - 10 ; j++)
		{
			xt = xt * (vectorXInterpolado_0_05[i]-vectorX[j]);
			yi = yi + ( matriz[j+1][0] * xt );
		}
		//cout<<"El vector agregar es: "<< yi << endl;
		
		vectorResultante.push_back(yi);
	}*/

	return vectorResultante;
}

//Método de Interpolacion de los Minimos Cuadrados
vector<long double> Interpolacion::minimosCuadrados(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05, int grado)
{
	//	long double **matriz,*matriz2,*matriz3;
	int i,j,tamano=vectorX.size();
	int maxGrado = 2*grado;
	long double matrizSum[maxGrado];
	long double matrizY[maxGrado];
    vector<long double> FXresultante;
	int tamanoMatriz = grado+1;
	//cout<<"EL tamano es: "<<tamano<<endl;
	
	
	//matriz = (long double**)calloc((grado+1),sizeof(long double*));
   	//for (i = 0 ; i <= grado; ++i)
     	//matriz[i] = (long double*)calloc(grado+1,sizeof(long double));
    //matriz2 = (long double*)calloc((maxGrado),sizeof(long double));
    //matriz3 = (long double*)calloc((maxGrado),sizeof(long double));
    mat matriz = mat(tamanoMatriz,tamanoMatriz);
    mat matriz2 = mat(tamanoMatriz,1);
    vec matriz3;	 	
    //Creando las sumatorias
    
    for (i = 0; i < maxGrado; i++)
    {
    	matrizSum[i] = 0;
    	matrizY[i] = 0;
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
   	
   	
   	//Revisando sumatorias
   	for (i = 0; i < maxGrado; i++)
   	{
   		//cout << "Resultado_" <<i<<":"<<matrizSum[i]<<endl;
   	}

   	//Rellenando matriz
   	for (i = 0; i < tamanoMatriz; i++)
   	{
   		for (j = 0; j < tamanoMatriz; j++)
   		{
   			if (i == 0 && j == 0)
   				matriz(i,j) = tamano;		
   			else
   				matriz(i,j) = matrizSum[i+j-1];
   		}	
   	}

   	//Revisando matriz
   	/*for (i = 0; i < tamanoMatriz; i++)
   	{
   		for (j = 0; j < tamanoMatriz; j++)
   		{
   			cout<<matriz(i,j)<<" - ";
   		}
   		cout<<endl;	
   	}*/

   	// Realizando matriz de Y

    for (i = 0; i < tamanoMatriz; i++)
    {
		for (j = 0; j < tamano; j++)
		{	
//			cout<<"El numeor a sumar es :"<<pow(vectorX[j],(long double)(i+1))<<endl;

//			cout<<"El numeor a vectorY[j] es :"<<vectorY[j]<<endl;

//			cout<<"El numeor a vectorY[j] es :"<<vectorY[j]*pow(vectorX[j],(long double)(i+1))<<endl;

			matrizY[i] = matrizY[i] + ( vectorY[j] * (long double)pow(vectorX[j],(long double) (i)) );
//			cout<<"El numero acumulado es: "<< matrizY[i]<<endl;
		}
		matriz2(i,0) = matrizY[i];

//		cout<<"Termino la primera vuelta ----------------"<<endl; 	
   	}

   	   	//Revisando matriz
   	for (i = 0; i < tamanoMatriz; i++)
   	{
   		//cout<<matriz2(i,0)<<endl;
   	}

   	//Mostrando vector Y
   	for (j = 0; j < tamanoMatriz; j++)
   	{
   		//cout << "Resultado_" <<i<<":"<<matriz2(j,0)<<endl;
   	}

    int tamano1 = vectorXInterpolado_0_05.size(); 
    long double yResultante = 0.0;

    mat L, U;
    lu(L, U, matriz);
    mat Y = inv(L)*matriz2;
    mat C = inv(U)*Y;

    for (i = 0; i < tamano1; i++)
    {
    	for (j = 0; j < tamanoMatriz; j++)
    	{
    		//cout<<"El vector a evaluar ahora es : "<<vectorXInterpolado_0_05[i]<<endl;
    		//cout<<"El C[" << j << "] :"<<C(j)<<endl;
    		//cout<<"El i : " << i << ", el j : " << j << endl;
    		yResultante = yResultante + ( C(j) * (long double) pow(vectorXInterpolado_0_05[i],(long double) j ) ) ;
    		//cout<<"El resultado acumulado es : " << yResultante<<endl;	
    	}
    	//cout << "El resultado final es : " << yResultante << endl;
    	//cout << "------------------ TERMINO ------------------" << endl;
        //yResultante = C(0) + C(1)*vectorXInterpolado_0_05[i] + C(2)* pow(vectorXInterpolado_0_05[i],2.0) + C(3) * pow(vectorXInterpolado_0_05[i],3.0);
        FXresultante.push_back(yResultante);
        yResultante = 0.0;
    }

    return FXresultante;	
}

//Método de Interpolacion: Spline Cubico
vector<long double> Interpolacion::splineCubico(vector<long double> vectorX, vector<long double> vectorY, vector<long double> vectorXInterpolado_0_05)
{
	if(vectorX.size() != vectorY.size())
	{
		cout<< "Los vectores ingresados como parametros tiene distinto largo" ; 
    }

    int tamano = vectorX.size();
    int i,j;
    
    vector<long double> distancia;
	long double hi;
	
	//damos valor al vector h(distancia entre los x)
    for(i = 0 ; i < tamano - 1; i++)
    {
        hi = vectorX[i+1] - vectorX[i];
        distancia.push_back(hi);
    }
    
	//se inicializan las matrices
	mat Matriz_A(tamano - 2, tamano - 2);
    mat Matriz_B(tamano - 2, 1);
    
    for(i = 0; i < tamano - 2; i++)
    {
		for(j = 0; j < tamano - 2; j++)
		{
			Matriz_A(i,j) = 0; 	
		}
	}
	
	//se llena la matriz A
	j = 0;
	Matriz_A(0,0) = 2 * (distancia[0] + distancia[1]);
	Matriz_A(0,1) = distancia[1];
		
    for(i = 1; i < tamano - 3 ; i++)
    {
		Matriz_A(i,j) = distancia[i];
		Matriz_A(i,j+1) = 2 * (distancia[i] + distancia[i+1]);
		Matriz_A(i,j+2) = distancia[i+1];
		j++; 
	}
	
	Matriz_A(tamano - 3,tamano - 3) = 2 * (distancia[tamano - 3] + distancia[tamano - 2]);
	Matriz_A(tamano - 3,tamano - 4) = distancia[tamano - 3];
	
	//se llena la matriz B
	for(i = 0 ; i < tamano - 2; i++)
	{
		Matriz_B(i,0) = 6 * ( ( (vectorY[i+2] - vectorY[i+1]) / (vectorX[i+2] - vectorX[i+1]) ) - ( (vectorY[i+1] - vectorY[i]) / (vectorX[i+1] - vectorX[i]) ) );	
	}
	
	//resolver sistema ecuaciones con la funcion de armadillo "solve":
	vec Vec_X_1 = solve(Matriz_A, Matriz_B);

    vector<long double> solucion;
    
    //interpolando
    i = 0;
    long double inter_a,inter_b,inter_c,inter_d,inter_e,inter_Rj;
	
    while(i < vectorXInterpolado_0_05.size())
    {
		for(j = 0; j < tamano - 1; j++)
		{
			if(vectorXInterpolado_0_05[i] >= vectorX[j] && vectorXInterpolado_0_05[i] < vectorX[j+1])
			{
				break;
			}
		}
		if(j == 0)
		{
			inter_a = 0 * (vectorX[j+1] - vectorXInterpolado_0_05[i]) * (vectorX[j+1] - vectorXInterpolado_0_05[i])*(vectorX[j+1] - vectorXInterpolado_0_05[i]) / 6*distancia[j];
			inter_b = (vectorXInterpolado_0_05[i] - vectorX[j])*(vectorXInterpolado_0_05[i] - vectorX[j])*(vectorXInterpolado_0_05[i] - vectorX[j]) * Vec_X_1[j] / 6*distancia[j];
			inter_c = ( ( (vectorY[j+1] - vectorY[j]) / distancia[j]) - ((Vec_X_1[j] - 0) * distancia[j] /6)) * vectorXInterpolado_0_05[i];
			inter_d = ( (vectorY[j]*vectorX[j+1]) - (vectorY[j+1]*vectorX[j])) / distancia[j] ;
			inter_e = distancia[j]*(( (vectorX[j]*Vec_X_1[j]) - (vectorX[j+1]* 0 )) / 6);
		}

		if(j == tamano-2)
		{
			inter_a = Vec_X_1[j-1] * (vectorX[j+1] - vectorXInterpolado_0_05[i])*(vectorX[j+1] - vectorXInterpolado_0_05[i])*(vectorX[j+1] - vectorXInterpolado_0_05[i]) / 6*distancia[j];
			inter_b = (vectorXInterpolado_0_05[i] - vectorX[j])*(vectorXInterpolado_0_05[i] - vectorX[j])*(vectorXInterpolado_0_05[i] - vectorX[j]) * 0 / 6*distancia[j];
			inter_c = ( ( (vectorY[j+1] - vectorY[j]) / distancia[j]) - ((0 - Vec_X_1[j-1]) * distancia[j] /6)) * vectorXInterpolado_0_05[i];
			inter_d = ( (vectorY[j]*vectorX[j+1]) - (vectorY[j+1]*vectorX[j])) / distancia[j] ;
			inter_e = distancia[j]*(( (vectorX[j]*0) - (vectorX[j+1]*Vec_X_1[j-1])) / 6);
		}
		
		if(j != (tamano - 2) && j != 0)
		{
			inter_a = Vec_X_1[j-1] * (vectorX[j+1] - vectorXInterpolado_0_05[i])*(vectorX[j+1] - vectorXInterpolado_0_05[i])*(vectorX[j+1] - vectorXInterpolado_0_05[i]) / 6*distancia[j];
			inter_b = (vectorXInterpolado_0_05[i] - vectorX[j])*(vectorXInterpolado_0_05[i] - vectorX[j])*(vectorXInterpolado_0_05[i] - vectorX[j]) * Vec_X_1[j] / 6*distancia[j];
			inter_c = ( ( (vectorY[j+1] - vectorY[j]) / distancia[j]) - ((Vec_X_1[j] - Vec_X_1[j-1]) * distancia[j] /6)) * vectorXInterpolado_0_05[i];
			inter_d = ( (vectorY[j]*vectorX[j+1]) - (vectorY[j+1]*vectorX[j])) / distancia[j] ;
			inter_e = distancia[j]*(( (vectorX[j]*Vec_X_1[j]) - (vectorX[j+1]*Vec_X_1[j-1])) / 6);
		}

		inter_Rj = inter_a+inter_b+inter_c+inter_d+inter_e;
		solucion.push_back(inter_Rj);
		i++;
	}
    
    return solucion;
}