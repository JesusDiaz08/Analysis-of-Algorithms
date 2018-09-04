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
   |------------ Instrucciones para compilar código --------------------------|
   | 1. Los .h y los .c deben estar en una sola carpeta.				                                         |
   | 2. gcc main.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o main   |
   |-------------------------------------------------------------------------|
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
	
	/*------- Variables para el manejo de tiempo -------*/
	D usr_time_Bs_10, sys_time_Bs_10, wall_time_Bs_10, 		/*Medicion para bubbleSort*/
	  usr_time_Bs_11, sys_time_Bs_11, wall_time_Bs_11, 
	  usr_time_Bo_20, sys_time_Bo_20, wall_time_Bo_20, 		/*Medicion para bubbleSortOptimized*/
	  usr_time_Bo_21, sys_time_Bo_21, wall_time_Bo_21,
	  usr_time_In_30, sys_time_In_30, wall_time_In_30, 		/*Medicion para insertionSort*/
	  usr_time_In_31, sys_time_In_31, wall_time_In_31,
	  usr_time_Se_40, sys_time_Se_40, wall_time_Se_40, 		/*Medicion para selectionSort*/
	  usr_time_Se_41, sys_time_Se_41, wall_time_Se_41,
	  usr_time_Sh_50, sys_time_Sh_50, wall_time_Sh_50, 		/*Medicion para shellSort*/
	  usr_time_Sh_51, sys_time_Sh_51, wall_time_Sh_51,
	  usr_time_BST_60, sys_time_BST_60, wall_time_BST_60,	/*Medicion para binarySearchTree*/
	  usr_time_BST_61, sys_time_BST_61, wall_time_BST_61,
	  real, user, syst, cpu_wall; 
	/*--------------------------------------------------*/

	if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);	/*Tomamos el tamaño del arreglo a ordenar*/
	int* numbers = readNumbers(n);	/*Leemos los n-números del arreglo a ordenar*/
	
	/*----------- Algoritmos de ordenamiento -----------*/
		/*------------- BubbleSort -------------*/
            int * array_bubble = cpyArray(numbers,n);
			uswtime(&usr_time_Bs_10, &sys_time_Bs_10, &wall_time_Bs_10);
			bubbleSort(array_bubble,n);
			uswtime(&usr_time_Bs_11, &sys_time_Bs_11, &wall_time_Bs_11);
			
			real = wall_time_Bs_11 - wall_time_Bs_10;
			user = usr_time_Bs_11 - usr_time_Bs_10;
			syst = sys_time_Bs_11 - sys_time_Bs_10;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,"Bubble Sort");

			free(array_bubble);
		/*--------------------------------------*/

		/*---------- BubbleSortOptimized -------*/
			int * array_bubbleO = cpyArray(numbers,n);
			uswtime(&usr_time_Bo_20, &sys_time_Bo_20, &wall_time_Bo_20);
			bubbleSortOptimized(array_bubbleO,n);
			uswtime(&usr_time_Bo_21, &sys_time_Bo_21, &wall_time_Bo_21);

			real = wall_time_Bo_21 - wall_time_Bo_20;
			user = usr_time_Bo_21 - usr_time_Bo_20;
			syst = sys_time_Bo_21 - sys_time_Bo_20;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,"Bubble Sort Opt");
			
			free(array_bubbleO);				
		/*--------------------------------------*/

		/*------------ InsertionSort -----------*/
            int * array_insertion = cpyArray(numbers,n);
			uswtime(&usr_time_In_30, &sys_time_In_30, &wall_time_In_30);
			insertionSort(array_insertion,n);
			uswtime(&usr_time_In_31, &sys_time_In_31, &wall_time_In_31);

			real = wall_time_In_31 - wall_time_In_30;
			user = usr_time_In_31 - usr_time_In_30;
			syst = sys_time_In_31 - sys_time_In_30;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,"Insertion Sort");
			
			free(array_insertion);
		/*--------------------------------------*/

		/*------------ SelectionSort -----------*/
			int * array_selection = cpyArray(numbers,n);
			uswtime(&usr_time_Se_40, &sys_time_Se_40, &wall_time_Se_40);
			selectionSort(array_selection,n);
			uswtime(&usr_time_Se_41, &sys_time_Se_41, &wall_time_Se_41);

			real = wall_time_Se_41 - wall_time_Se_40;
			user = usr_time_Se_41 - usr_time_Se_40;
			syst = sys_time_Se_41 - sys_time_Se_40;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,"Selection Sort");
			
			free(array_selection);
		/*--------------------------------------*/

		/*------------- ShellSort --------------*/
			int * array_shell = cpyArray(numbers,n);
			uswtime(&usr_time_Sh_50, &sys_time_Sh_50, &wall_time_Sh_50);
			shellSort(array_shell,n);
			uswtime(&usr_time_Sh_51, &sys_time_Sh_51, &wall_time_Sh_51);

			real = wall_time_Sh_51 - wall_time_Sh_50;
			user = usr_time_Sh_51 - usr_time_Sh_50;
			syst = sys_time_Sh_51 - sys_time_Sh_50;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,"Shell Sort");
			
			free(array_shell);		
		/*--------------------------------------*/
		
		/*---------- BinarySearchTree ----------*/
			int * array_bst = cpyArray(numbers,n);
			uswtime(&usr_time_BST_60, &sys_time_BST_60, &wall_time_BST_60);
			binarySearchTree(array_bst,n);
			uswtime(&usr_time_BST_61, &sys_time_BST_61, &wall_time_BST_61);
			
			real = wall_time_BST_61 - wall_time_BST_60;
			user = usr_time_BST_61 - usr_time_BST_60;
			syst = sys_time_BST_61 - sys_time_BST_60;
			cpu_wall = getCPU_WALL(user, syst, real);

			desc_time_efficiency(user, syst, real, cpu_wall,"BInary Search Tree");
			
			free(array_bst);
		/*--------------------------------------*/
	/*--------------------------------------------------*/
	return 0;
}//cierra main
