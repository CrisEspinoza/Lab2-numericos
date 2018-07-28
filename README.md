# Laboratorio numero 2: Cristian Espinoza Silva

							* * Dificultades para enfrentar los problemas del laboratorio* *

* Parte 1 : 
	Una de las complicaciones se que tuvieron para poder desarrollar el laboratorio en la primero parte es que algunos valores se seteaban finalmente en -nan, inf o -inf. La solución que se llego luego de recibir el feedback en las oportunidades que se fue hablar presencialmente, fue que no era necesario calcular en su totalidad el polinomio mediante que llega un punto que luego de eso no van cambiando los valores del error ya que son muy minimos y no influye en el calculo final. Además, de tener que cambiar el tipo de dato de "double" a "long double" el cual nos almacenar valores numericos con mayor cantidad de decimales y así recrear una aproximación mas exacta.
	
	Además que al momento de realizar todos los calculos respectivos se obtenia que la arquitectura de la maquina no soportaba exponenetes tan elevados, esto se vio reflejado en la funcion numero 1 la cual constaba con una exponencial que aumentaba su exponente de manera muy rapida y producia que nuevos valores calculados superaran la arquitectura de la maquina que se esta utilizando. 
	
	Por lo cual se produjo a cortar en un numero tentativo, el cual fue obtenido probando el programa hasta donde soportaba la arquitectura de la maquina.

	Tambien tocar un punto el cual en el metodo de los minimos cuadrados especificamente a pesar que se llego a un error muy aceptable tanto en la función 1 como en la función 2, tambien se pudiera haber mejorado su aproximación en la funcion 1 cambiando la función base, ya que se ocupo la generica (x^0,x^1,x^2,....,....,x^9,.,...,.,x^(n-1),x^n) para generar la tabla de valores y luego del feedaback recibido en la ultima clase de labotario, pudimos entender que la aproximación del error hubiese sido de mucho mejor forma si ocupariamos como función base una Exponencial (e) para la funcion 1, ya que contiene uno, entonces hubieramos llegado a una aprocimación mucho mas cercana de la que ya logramos llegar. En cambio, para la función 2 se ocupo una funcion base muy aceptable, ya que la función cuenta con un polinomio de x, entonces la función escogido es la mas aceptable para ese caso.

	Finalmente se pudo llegar a una solución viable y sensata, donde optuvimos resultados cercanos a los reales de la función. Destacar que principalmente estos problemas mencionados anteriormente se vierón reflejados en los metodos de diferencias divididas, diferencias finitas y en menor medida en el metodo de minimos cuadrados al momento de aplicarlos a la funcion numero 1 la cual contenia una exponencial. 

* Parte 2: 
	Esta parte del lab se pudo realizar de forma completa y sin tener mayores inconvenientes, ya que se pudo trabajar con la totalidad de los datos, así generando el error correspondiente para funciones ocupando los dos metodos correspondientes.
	El error obtenido en la parte numerico 2 del laboratorio es aceptable, pero no del mejor, pero dejar en claro que esto no pasa por que el metodo este mal implementado, si no, especificamente porque cada vez que se realiza un calculo se acumula un error, el cual al realizar tantos calculos por la canidad de puntos que se tiene, este error afecta en el resultado final que se obtiene, dejar en claro que a pesar de esto se obtiene un error considerablemente bueno del orden de la e^-6. Pudiendo concluir que se llega a un resultado totalemente aceptable.

										* * Modo de uso * * 

1. En primera instancia tenemos un programa realizado en c++, el cual consta con un menu que ayuda a la UX del usuario, para poder hacer mas amigable el trato con el usuario. Se creo una makefile para poder simplificar la compilación de dicho codigo, es decir, que basta con colocar make en la consola dentro de la carpeta que se encuentra (La cual es "/home/huaso/Escritorio/Numericos/Lab2-numericos/Integración/test") para que se compile el programa y luego poder ejecutarlo con la siguiente instrucción "./main".

	* 1° opción: Es la encargada de realizar la primera parte del laboratorio, la cual genera los archivos con los datos de cada uno de los metodos. Estos datos son calculados con las exigencia que se pedian en el laboratorio, ya sea con separación de 0.5 - 1 - 5 - 10, y finalmente para graficar tambien se hace el calculo con 0.05. Cada uno de estos resutlados son almacenados en una carpeta llamada "Graficar Matlab", la cual contiene sub-carpetas que llevan el nombre de cada uno de los metodos donde se guardan los resultados obtenidos de la funcion 1 y la funcion 2 para ese respectivo metodo. 
		     Ademas genera un archivo con los errores obtenidos el cual se almacena en la carpeta "test" del programa, el archivo anteriormente mencionado lleva como nombre "ErroresRMSEParte1.txt".

	* 2° opción: Es la encargada de realizar la parte numero 2 del laboratorio, el cual genera un archivo con los errores obtenidos en la carpeta "test" del programa, el archivo anteriormente mencionado lleva como nombre "ErroresRMSEParte2.txt".

	* 3° opcion: Funcion que se encarga de reiniciar el programa para poder volver a ocuparlo sin necesidad de volver a ejecutar el programa.

	* 4° opcion: Muestra los creditos que contiene el programa.

	* 5° opcion: Se encarga de terminar la ejecución del programa.

2. Por otra parte, tenemos un programa que se ejecuta en matlab el cual se encarga de graficar los datos obtenidos creando distintos graficar los cuales se almacen en una carpeta llamada "Fotos graficos", donde se puede encontrar cada uno de los grafios obtenidos para todo los metodos aplicados en la funcion 1 y la funcion 2. 

	* Tenemos un menu en matlab igual, el cual se encarga de entregar cada uno de los graficos al usuario segun el metodo que quiera ocupar y en la funcion que el escoja, donde se encuentran las siguientes opciones:

	* 1° opción: Funcion que entrega el grafico de la funcion 1 con el metodo de Diferencias divididas.

	* 2° opción: Funcion que entrega el grafico de la funcion 1 con el metodo de Diferencias finitas.

	* 3° opción: Funcion que entrega el grafico de la funcion 1 con el metodo de Minimos cuadrados.

	* 4° opción: Funcion que entrega el grafico de la funcion 1 con el metodo de Spline cubico.

	* 5° opción: Funcion que entrega el grafico de la funcion 2 con el metodo de Diferencias divididas.

	* 6° opción: Funcion que entrega el grafico de la funcion 2 con el metodo de Diferencias finitas.

	* 7° opción: Funcion que entrega el grafico de la funcion 2 con el metodo de Minimos cuadrados.

	* 8° opción: Funcion que entrega el grafico de la funcion 2 con el metodo de Spline cubico.

	* 9° opción: Funcion que permite abandonar el programa.

	*Estos graficos son guardados en una carpeta llamada "Fotos Graficos" donde se guardan con el nombre de FuncX_YY, donde:
		* X -> Representa a la funcion que se esta haciendo referencia.
		* YY -> Representa las iniciales del metodo el cual se ocupo para esa determinada función.
