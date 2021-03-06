/*
Equipo:		- Díaz Medina Jesús Kaimorts.
			    - Ferrer González Daniela.
			    - Herrera Ramírez Absalom.

Materia:	Análisis de Algoritmos.
Fecha:		03 de Octubre del 2018.
Practica:	02.
Grupo:		3CM2.
Tema:		  Algoritmos de Búsqueda.
*/

/*
   |------------ Instrucciones para compilar código --------------------|
   | 1. Los .h y los .c deben estar en una sola carpeta.				        |                                 |
   | 2. gcc main_binary.c searching.c tiempo.c leer.c BST.c btStack.c   |
	 |     -o main_binary -lpthread 																			|
   | 3. ./main_binary cantidad < Numeros/10millonesOrdenados.txt				|
	 |     >> Salidas/resultados_binaria.csv															|
   |--------------------------------------------------------------------|
*/

/* ------- Librerias ------- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "MedicionTiempo/tiempo.h"
#include "EyS/eys.h"
#include "Busquedas/Busquedas.h"
//#include "Busquedas/Arbol/BST.h"
/* ------------------------ */
#define N 20
#define TOTAL_ARCHIVO 10000000

typedef double D;

int main(int argc, char const *argv[]){

	if (argc!=2){
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}

	int count_Tosearch = N;	/*Tomamos el tamaño del arreglo a ordenar*/
	int numbers[N] = { 322486, 14700764, 3128036, 6337399, 61396, 10393545,
					           2147445644, 1295390003, 450057883, 187645041, 1980098116,
					           152503, 5000, 1493283650, 214826, 1843349527, 1360839354,
					           2109248666, 2147470852, 0 };

	int count_numbers = atoi(argv[1]);	/*Tomamos el tamaño del arreglo a ordenar*/
	int * array_original = readNumbers(TOTAL_ARCHIVO);	/*Leemos los n-números del arreglo a ordenar*/
	int * array_binaria = cpyArray(array_original, count_numbers);

	free(array_original); /*Libreramos el espacio de memoria del arreglo original.*/

	int i = 0;
	int encontrado = -1;
	D usr_time_binaria_10, sys_time_binaria_10, wall_time_binaria_10, 		/*Medicion para Busqueda Binaria*/
	  usr_time_binaria_11, sys_time_binaria_11, wall_time_binaria_11,
      real, user, syst, cpu_wall;

			printf("\n");
    /* ------- Busqueda Lineal -------*/
      for( i = 0; i < count_Tosearch; i++){
      	encontrado = -1;
      	int is_number = numbers[i];
      	uswtime(&usr_time_binaria_10, &sys_time_binaria_10, &wall_time_binaria_10);
      	busquedaBinaria(array_binaria, is_number, 0, count_numbers, &encontrado);
      	uswtime(&usr_time_binaria_11, &sys_time_binaria_11, &wall_time_binaria_11);

      	real = wall_time_binaria_11 - wall_time_binaria_10;

      	if( encontrado >= 0 )
      		printf("Binaria  |  Normal  |  %d  |  %d  |  %.15f  |  SI  \n", is_number, count_numbers, real);
      	else
      		printf("Binaria  |  Normal  |  %d  |  %d  |  %.15f  |  NO  \n", is_number, count_numbers, real);

      }
    /*--------------------------------*/
    printf("\n");
    /* ------- Busqueda Binaria con Hilos -------*/
      for( i = 0; i < count_Tosearch; i++){
      	encontrado = -1;
      	int is_number = numbers[i];
      	uswtime(&usr_time_binaria_10, &sys_time_binaria_10, &wall_time_binaria_10);
      	busquedaBinaria_Hilos(array_binaria, is_number, 0, count_numbers, &encontrado);
      	uswtime(&usr_time_binaria_11, &sys_time_binaria_11, &wall_time_binaria_11);

				real = wall_time_binaria_11 - wall_time_binaria_10;

      	if( encontrado >= 0 )
      		printf("Binaria  |  Hilos  |  %d  |  %d  |  %.15f  |  SI  \n", is_number, count_numbers, real);
      	else
      		printf("Binaria  |  Hilos  |  %d  |  %d  |  %.15f  |  NO  \n", is_number, count_numbers, real);

      }
    /*------------------------------------------*/
		printf("\n\n");
	return 0;
}
