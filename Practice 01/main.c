/*
Equipo:		- Díaz Medina Jesús Kaimorts.
			- Herrera Ramírez Absalom.
			- Ferrer González Daniela.

Materia:	Análisis de Algoritmos.
Fecha:		30 de Agosto del 2018.
Practica:	01.
Grupo:		3CM2.
Tema:		Algoritmos de ordenamiento.
*/

/*-------- LIBRERIAS --------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include "leer.h"
#include "sortingAlgorithms.h"
/*---------------------------*/

/* |----- Instrucciones para compilar código -----|
   | 1. Los .h y los .c deben estar en una sola carpeta.
   | 2. gcc main.c sortingAlgorithms.c tiempo.c leer.c -o main
   |----------------------------------------------|
*/

int main(int argc, char const *argv[]){
	
	if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);	/*Tomamos el tamaño del arreglo a ordenar*/
	int* numbers = leer(n);	/*Leemos los n-números del arreglo a ordenar*/

	return 0;
}