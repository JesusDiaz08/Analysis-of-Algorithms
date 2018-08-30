#include <stdio.h>
#include <stdlib.h>
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