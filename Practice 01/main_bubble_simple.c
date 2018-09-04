/*
Equipo:		- Díaz Medina Jesús Kaimorts.
			- Ferrer González Daniela.
			- Herrera Ramírez Absalom.

Materia:	Análisis de Algoritmos.
Fecha:		30 de Agosto del 2018.
Practica:	01.
Grupo:		3CM2.
Tema:		Algoritmos de Ordenamiento.
*/

/* 
 * Este archivo solo contiene el método de ordenamiento de burbuja simple: Bubble Sort Simple
   |------------ Instrucciones para compilar código ---------------------------------------- |
   | 1. Los .h y los .c deben estar en una sola carpeta.				                                                                       |
   | 2. gcc main_bubble_simple.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o bbs   |
   |--------------------------------------------------------------------------------------- |
*/

/*-------- LIBRERIAS --------*/
#include <stdio.h>		/*printf y scanf*/
#include <stdlib.h>		/*malloc*/
#include <string.h>		/*memcpy*/
#include "tiempo.h"		
#include "leer.h"
#include "BST.h"
#include "sortingAlgorithms.h"
/*---------------------------*/
typedef double D;

/*
|--------- Especificacion de variables que miden rendimiento en tiempo ---------|
	* Las variables que miden el rendimiento en tiempo total (wall_time), 
	  tiempo de procesamiento de CPU (usr_time), tiempo en acciones E/S (sys_time) 
	  y CPU Wall, en cada algoritmo de ordenamiento, van acompañados con el posfijo
	  del método de ordenamiento que se está ejecutando:

					_Bs: 	Bubble Sort Simple
					_Bo: 	Bubble Sort Optimized
					_In: 	Insertion Sort
					_Se: 	Selection Sort
					_Sh: 	Shell Sort
					_BST: 	Binary Searching Tree

	* Además, despues de dicho posfijo, vienen enumarados con una referencia que 
	  describe qué número de algoritmo es, y antes o despues del algoritmo ejecutado:
					
		_Bs_10: 	Bubble Sort Simple - Conteo de tiempo para las evaluaciones de rendimiento
		_Bs_11:		Bubble Sort Simple - Evaluación de los tiempos de ejecución.		
|-------------------------------------------------------------------------------|
*/

int main(int argc, char const *argv[]){
    D usr_time_Bs_10, sys_time_Bs_10, wall_time_Bs_10, 		/*Medicion para bubbleSort*/
	    usr_time_Bs_11, sys_time_Bs_11, wall_time_Bs_11,
        real, user, syst, cpu_wall;
    
    
    if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);	/*Tomamos el tamaño del arreglo a ordenar*/
	int* numbers = readNumbers(n);	/*Leemos los n-números del arreglo a ordenar*/
    
    /*------------- BubbleSort -------------*/
            int * array_bubble = cpyArray(numbers,n);
			uswtime(&usr_time_Bs_10, &sys_time_Bs_10, &wall_time_Bs_10);
			bubbleSort(array_bubble,n);
			uswtime(&usr_time_Bs_11, &sys_time_Bs_11, &wall_time_Bs_11);
			
			real = wall_time_Bs_11 - wall_time_Bs_10;
			user = usr_time_Bs_11 - usr_time_Bs_10;
			syst = sys_time_Bs_11 - sys_time_Bs_10;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,n);

			free(array_bubble);
    /*--------------------------------------*/
    return 0;
}
