#include <stdio.h>	/*printf y scanf*/
#include <stdlib.h>	/*malloc*/
#include <string.h>	/*memcpy*/
#include "leer.h"

/*
Nombre:			readNumbers
Parámetros:		int n
Retorno:		int* numbers
Descripción:	La función se encarga de leer los 
				números desde la entrada estándar.
*/
int * readNumbers(int n){
	int* numbers;							//Arreglo de números
	numbers = (int*)malloc(sizeof(int)*n);	/*Reservamos la memoria a ocupar: dinámico*/

	for(int i=0; i < n; i++)
		scanf("%d",&numbers[i]); 

	return numbers;
}

/*
Nombre:			cpyArray
Parámetros:		int const * number: Arreglo original a copiar
				size_t len: Un tipo integral sin signo: tamaño de arreglo
Retorno:		int* array_aux: Arreglo original copiado
Descripción:	La función se encarga de copiar el arreglo original
				para que este sea procesado por el algoritmo de ordenamiento
				que en la main le especifiquemos.
*/
int * cpyArray(int const * numbers, size_t len){
	int * array_aux = malloc(len * sizeof(int));
	memcpy(array_aux, numbers, len * sizeof(int));
	return array_aux;
}

/*
Nombre:			getCPU_WALL
Parámetros:		double user: Tiempo de procesamiento en CPU
				double syst: Tiempo en acciones de E/S
				double real: Tiempo total
Retorno:		double cpu_wall: rendimiento del CPU/Wall
Descripción:	La función se encarga de realizar el calculo
				del rendimiento del CPU/Wall
*/
double getCPU_WALL(double user, double syst, double real){
	return ((user + syst)*100)/real;
}

/*
Nombre:			printSorting
Parámetros:		int * numbers: Arreglo previamente ordenado
				int n:	Longitud del arreglo ordenado.
Retorno:		void
Descripción:	La función se encargará de leer los 
				números desde la entrada estándar.
*/
void printSorting(int* numbers, int n){
	int k;
	for(k=0;k < n; k++)
		printf("%d - ",numbers[k]);
}

/*
Nombre:			desc_time_efficiency
Parámetros:		double user: Tiempo de procesamiento en CPU
				double syst: Tiempo en acciones de E/S
				double real: Tiempo total
				double cpu_wall: rendimiento del CPU
Retorno:		void
Descripción:	La función se encarga de mostrar en pantalla
				los tiempos de ejecución que describen el
				rendimiento del algoritmo de ordenamiento 
*/
void desc_time_efficiency(double user, double syst, double real, double cpu_wall, char* typeAlgorithm){
    
    printf ("%s | %.10f s |  %.10f s | %.10f s | %.10f s | %.10f s",typeAlgorithm,user,syst,real,cpu_wall);
	printf("\n");
    printf ("%s |  %.10e s |  %.10e s | %.10e s | %.10e s | %.10f s",typeAlgorithm,user,syst,real,cpu_wall);
	printf("\n");
}
