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

/* |------------ Instrucciones para compilar código ------------|
   | 1. Los .h y los .c deben estar en una sola carpeta.		|
   | 2. gcc main.c sortingAlgorithms.c tiempo.c leer.c -o main  |
   |------------------------------------------------------------|
*/

/*-------- LIBRERIAS --------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include "leer.h"
#include "sortingAlgorithms.h"
/*---------------------------*/
typedef double D;

/*|--------- Especificacion de variables que miden rendimiento en tiempo ---------|
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

  |-------------------------------------------------------------------------------|*/

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
	  real, user, system, cpu_wall; 
	
	/*--------------------------------------------------*/

	if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);	/*Tomamos el tamaño del arreglo a ordenar*/
	int* numbers = leer(n);	/*Leemos los n-números del arreglo a ordenar*/

	
	/*----------- Algoritmos de ordenamiento -----------*/
		/*------------- BubbleSort -------------*/
			int * array_bubble = cpyArray(numbers,n);
			uswtime(&usr_time_Bs_10, &sys_time_Bs_10, &wall_time_Bs_10);
			bubbleSort(array_bubble,n);
			uswtime(&usr_time_Bs_11, &sys_time_Bs_11, &wall_time_Bs_11);
		/*--------------------------------------*/

		/*---------- BubbleSortOptimized -------*/
			int * array_bubbleO = cpyArray(numbers,n);
			uswtime(&usr_time_Bo_20, &sys_time_Bo_20, &wall_time_Bo_20);
			bubbleSortOptimized(array_bubbleO,n);
			uswtime(&usr_time_Bo_21, &sys_time_Bo_21, &wall_time_Bo_21);				
		/*--------------------------------------*/

		/*------------ InsertionSort -----------*/
			int * array_insertion = cpyArray(numbers,n);
			uswtime(&usr_time_In_30, &sys_time_In_30, &wall_time_In_30);
			insertionSort(array_insertion,n);
			uswtime(&usr_time_In_31, &sys_time_In_31, &wall_time_In_31);
		/*--------------------------------------*/

		/*------------ SelectionSort -----------*/
			int * array_selection = cpyArray(numbers,n);
			uswtime(&usr_time_Se_40, &sys_time_Se_40, &wall_time_Se_40);
			selectionSort(array_selection,n);
			uswtime(&usr_time_Se_41, &sys_time_Se_41, &wall_time_Se_41);

		/*--------------------------------------*/

		/*------------- ShellSort --------------*/
			int * array_shell = cpyArray(numbers,n);
			uswtime(&usr_time_Sh_50, &sys_time_Sh_50, &wall_time_Sh_50);
			shellSort(array_shell,n);
			uswtime(&usr_time_Sh_51, &sys_time_Sh_51, &wall_time_Sh_51);		
		/*--------------------------------------*/
		
		/*---------- BinarySearchTree ----------*/
			int * array_bst = cpyArray(numbers,n);
			uswtime(&usr_time_BST_60, &sys_time_BST_60, &wall_time_BST_60);
			binarySearchTree(array_bst,n);
			uswtime(&usr_time_BST_61, &sys_time_BST_61, &wall_time_BST_61);
		/*--------------------------------------*/
	/*--------------------------------------------------*/
	return 0;
}