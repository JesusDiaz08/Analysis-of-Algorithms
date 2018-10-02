
/*=======Librerias=======*/
#include "Busquedas.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define num_threads 2
/*=======================*/

/*======= Funciones para Hilos ======*/

void * searchLineal_byThread(void * searchingLineal){
	auxLineal * lineal = (auxLineal *)searchingLineal;
	busquedaLineal(lineal->arreglo, lineal->isValue, lineal->inicio,
				   lineal->fin, lineal->encontrado);

}

void * searchBinary_byThread(void * searchingBinary){
	auxLineal * binaria = (auxLineal *)searchingBinary;
	busquedaBinaria(binaria->arreglo, binaria->isValue, binaria->inicio,
				   binaria->fin, binaria->encontrado);
}

/*===================================*/


/*
==================
Nombre: 	busquedaLineal
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int fin:	Especifica el punto fin de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda secuencial a traves de un
			arreglo, especificando el inicio, fin y el valor
			a buscar. Si se encuentra el valor, este sera asignado
			a una variable con paso por referencia.
==================
*/
void busquedaLineal(int * arreglo, int isValue,
					int inicio, int fin, int * encontrado){
	int i = 0;
	for(i = inicio; i < fin; i++){
		//printf("en busqueda lineal: %d\n", arreglo[i]);
		if(arreglo[i] == isValue){
			*encontrado = isValue;
			 //printf("Si lo encontro a %d\n", *encontrado);
			 break;
		}

		/*if(*encontrado >= 0) Lo encontró
				break;*/
	}
}

/*
==================
Nombre: 	busquedaLineal_Hilos
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int fin:	Especifica el punto fin de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda secuencial a traves de un
			arreglo, especificando el inicio, fin y el valor
			a buscar. Si se encuentra el valor, este sera asignado
			a una variable con paso por referencia. La busqueda se
			realiza 'paritiendo' al arreglo total en 2 subarreglos
			para que cada hilo busque en su subarreglo asignado el
			numero que queremos encontrar
==================
*/
void busquedaLineal_Hilos(int * arreglo, int isValue, int inicio,
						  int fin, int * encontrado){

	int j = 0;
	int middle = (fin - inicio)/2;
	if(middle > 0){
		/*Asignacion de los subarreglos usando el arreglo original*/
		pthread_t *thread;
		thread = malloc(num_threads*sizeof(pthread_t));

		/*----- Usamos los auxiliares -----*/
		auxLineal * sub_izq = (auxLineal *)malloc(sizeof(auxLineal));
		sub_izq->arreglo = arreglo;
		sub_izq->isValue = isValue;
		sub_izq->encontrado = encontrado;
		sub_izq->inicio = inicio;
		sub_izq->fin = middle;

		auxLineal * sub_der = (auxLineal *)malloc(sizeof(auxLineal));
		sub_der->arreglo = arreglo;
		sub_der->isValue = isValue;
		sub_der->encontrado = encontrado;
		sub_der->inicio = middle + 1;
		sub_der->fin = fin;

		/*----- Creacion de hilos -----*/
		if(pthread_create(&thread[0], NULL, searchLineal_byThread, (void *)sub_izq) != 0){
			perror("El thread no pudo crearse -> Lineal \n");
			exit(-1);
		}

		if(pthread_create(&thread[1], NULL, searchLineal_byThread, (void *)sub_der) != 0){
			perror("El thread no pudo crearse -> Lineal \n");
			exit(-1);
		}

		/*----- Los dos hilos comienzan su chamba -----*/
		for( ; j < num_threads; j++)
			pthread_join(thread[j], NULL);

		free(thread);
	}
}

/*===================================
Nombre: 	busquedaBinaria
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int fin:	Especifica el punto fin de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda binaria a traves de un
			arreglo, especificando el inicio, fin, y calculando
			el punto medio, y el valor a buscar. Si se encuentra
			el valor, este sera asignado a una variable con paso
			por referencia.
====================================*/
void busquedaBinaria(int * arreglo, int isValue, int inicio,
					 int fin, int * encontrado){

	while(inicio <= fin){
		if(*encontrado >= 0)
			break;

		int middle = (inicio + fin)/2;

		if(arreglo[middle] == isValue){
			*encontrado = isValue;
		}else if(arreglo[middle] > isValue){
			fin = middle - 1;
		}else{
			inicio = middle + 1;
		}
	}
}

/*===================================
Nombre: 	busquedaBinaria_Hilos
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int fin:	Especifica el punto fin de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda binaria a traves de 2 subarreglos
			hecho a partir del arreglo original, especificando
			el inicio, fin, y calculando el punto medio, y el
			valor a buscar. Si se encuentra	el valor, este sera
			asignado a una variable con paso por referencia.
			La carga de la busqueda sera repartida por 2 hilos.
====================================*/
void busquedaBinaria_Hilos(int * arreglo, int isValue, int inicio,
					 int fin, int * encontrado){
	int k = 0;
	int middle = (fin - inicio)/2;

	if(middle > 0){
		pthread_t * thread;
		thread = malloc(num_threads*sizeof(pthread_t));

		auxLineal * sub_izq = (auxLineal *)malloc(sizeof(auxLineal));
		sub_izq->arreglo = arreglo;
		sub_izq->isValue = isValue;
		sub_izq->encontrado = encontrado;
		sub_izq->inicio = inicio;
		sub_izq->fin = middle;


		auxLineal * sub_der = (auxLineal *)malloc(sizeof(auxLineal));
		sub_der->arreglo = arreglo;
		sub_der->isValue = isValue;
		sub_der->encontrado = encontrado;
		sub_der->inicio = middle + 1;
		sub_der->fin = fin;

		/*----- Creacion de hilos -----*/
		if(pthread_create(&thread[0], NULL, searchBinary_byThread, (void *)sub_izq) != 0){
			perror("El thread no pudo crearse -> Binaria \n");
			exit(-1);
		}

		if(pthread_create(&thread[1], NULL, searchBinary_byThread, (void *)sub_der) != 0){
			perror("El thread no pudo crearse -> Binaria \n");
			exit(-1);
		}

		/*----- Los dos hilos comienzan su chamba -----*/
		for( ; k < num_threads; k++)
			pthread_join(thread[k], NULL);

		free(thread);
	}
}
