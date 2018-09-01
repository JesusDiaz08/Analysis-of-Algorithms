#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leer.h"

/*
Nombre:			readNumbers
Parámetros:		int n
Retorno:		int* numbers
Descripción:	La función se encargará de leer los 
				números desde la entrada estándar.
*/
int* readNumbers(int n){
	int* numbers;							//Arreglo de números
	numbers = (int*)malloc(sizeof(int)*n);	/*Reservamos la memoria a ocupar: dinámico*/

	for(int i=0; i < n; i++)
		scanf("%d",&numbers[i]); 

	return numbers;
}

void printSorting(int* numbers, int n){
	int k;
	for(k=0;k < n; k++)
		printf("%d - ",numbers[k]);
}

int * cpyArray(int const * number, size_t len){
	int * array_aux = malloc(len * sizeof(int));
	memcpy(array_aux, numbers, len * sizeof(int));
	return array_aux;
}