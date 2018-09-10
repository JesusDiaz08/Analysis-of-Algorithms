/*
Equipo:	- Díaz Medina Jesús Kaimorts.
		- Ferrer González Daniela.
		- Herrera Ramírez Absalom.

Materia:	Análisis de Algoritmos.
Fecha:		30 de Agosto del 2018.
Practica:	01.
Grupo:		3CM2.
Tema:		Algoritmos de Ordenamiento.
*/

/* 
 * Este archivo solo contiene el método de ordenamiento de seleccion: Selection Sort
   |------------ Instrucciones para compilar código ----------------------------------------|
   | 1. Los .h y los .c deben estar en una sola carpeta.				                                                                      |
   | 2. gcc main_selection.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o selection   |
   |---------------------------------------------------------------------------------------|
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

int main(int argc, char const *argv[]){
    D usr_time_Se_40, sys_time_Se_40, wall_time_Se_40, 		/*Medicion para selectionSort*/
	    usr_time_Se_41, sys_time_Se_41, wall_time_Se_41,
        real, user, syst, cpu_wall;
	  
    if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);	/*Tomamos el tamaño del arreglo a ordenar*/
	int* numbers = readNumbers(n);	/*Leemos los n-números del arreglo a ordenar*/
    
   /*------------ SelectionSort -----------*/
		int * array_selection = cpyArray(numbers,n);
		uswtime(&usr_time_Se_40, &sys_time_Se_40, &wall_time_Se_40);
		selectionSort(array_selection,n);
		uswtime(&usr_time_Se_41, &sys_time_Se_41, &wall_time_Se_41);

		real = wall_time_Se_41 - wall_time_Se_40;
		user = usr_time_Se_41 - usr_time_Se_40;
		syst = sys_time_Se_41 - sys_time_Se_40;
		cpu_wall = getCPU_WALL(user, syst, real);

		desc_time_efficiency(user, syst, real, cpu_wall,n);
		
		free(array_selection);
		/*--------------------------------------*/    
        
    return 0;
}
