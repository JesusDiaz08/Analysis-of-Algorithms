/*
=================================================
	Fecha: 		16 de Septiembre del 2018.
	Alumno:		Díaz Medina Jesús Kaimorts.
	Materia: 	Analsis de Algoritmos

	Descripcion:
	Librería que contiene los algoritmos
	de búsqueda (no recursivos):
	Busqueda lineal y Busqueda Binaria.
=================================================
*/

/*=======Librerias=======*/
#include <pthread.h>
#include <stdlib.h>
//#include "BST.h"
/*=======================*/

/*==== Estructuras auxiliares para
	   las busquedas con hilos    ====*/

/*===== Busqueda Lineal ======*/
typedef struct aux_busqueda_lineal{
	int * arreglo;
	int isValue;
	int inicio;
	int fin;
	int * encontrado;
} auxLineal;
/*============================*/

/*===================================*/

/*===== Funciones para los hilos =====
Descripcion: Ayudara a lanzar la busqueda requerida:
			 lineal o binaria, por cada hilo.*/
void * searchLineal_byThread(void * searchingLineal);
void * searchBinary_byThread(void * searchingBinary);
/*====================================*/

/*====================================
Nombre: 	busquedaLineal
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int final:	Especifica el punto final de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda secuencial a traves de un
			arreglo, especificando el inicio, final y el valor
			a buscar. Si se encuentra el valor, este sera asignado
			a una variable con paso por referencia.
=====================================*/
void busquedaLineal(int * arreglo, int isValue,
					int inicio, int final, int * encontrado);

/*===================================
Nombre: 	busquedaLineal_Hilos
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int final:	Especifica el punto final de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda secuencial a traves de un
			arreglo, especificando el inicio, final y el valor
			a buscar. Si se encuentra el valor, este sera asignado
			a una variable con paso por referencia. La busqueda se
			realiza 'paritiendo' al arreglo total en 2 subarreglos
			para que cada hilo busque en su subarreglo asignado el
			numero que queremos encontrar.
====================================*/
void busquedaLineal_Hilos(int * arreglo, int isValue, int inicio,
						  int final, int * encontrado);

/*===================================
Nombre: 	busquedaBinaria
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int final:	Especifica el punto final de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda binaria a traves de un
			arreglo, especificando el inicio, final, y calculando
			el punto medio, y el valor a buscar. Si se encuentra
			el valor, este sera asignado a una variable con paso
			por referencia.
====================================*/
void busquedaBinaria(int * arreglo, int isValue, int inicio,
					 int final, int * encontrado);

/*===================================
Nombre: 	busquedaBinaria_Hilos
Parametro:	int * arreglo: Arreglo en el que se hara la busqueda.
            int isValue: Valor a buscar a traves del arreglo.
			int inicio:	Especifica el punto de inicio de la bsuqueda
			int final:	Especifica el punto final de la busqueda
			int * encontrado: Se usa para decir si el valor está en
							  el rango dado
Retorno:	void
Descrip:	Se realiza una busqueda binaria a traves de 2 subarreglos
			hecho a partir del arreglo original, especificando
			el inicio, final, y calculando el punto medio, y el
			valor a buscar. Si se encuentra	el valor, este sera
			asignado a una variable con paso por referencia.
			La carga de la busqueda sera repartida por 2 hilos.
====================================*/
void busquedaBinaria_Hilos(int * arreglo, int isValue, int inicio,
					 	   int final, int * encontrado);
