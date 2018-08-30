/*
Nota general:
	Para cada uno de los algoritmos de ordenamiento
	se contemplarán dos parámetros:

	n:			Número de elementos a ordenar
	numbers:	Arreglo de n-numeros a ordenar
*/

#include "sortingAlgorithms.h"

/*
Nombre:			bubbleSort
Parámetros:		int* numbers, int n. 
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento 
				por burbuja	al conjunto de números dado.
Complejidad:	O(n*n)
*/
void bubbleSort(int* numbers, int n){

}

/*
Nombre:			bubbleSortOptimized
Parámetros:		int* numbers, int n. 
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				por burbuja con mejoras, al conjunto 
				de números dado.
Complejidad:	O(n*n)
*/
void bubbleSortOptimized(int* numbers, int n){

}


/*
Nombre:			insertionSort
Parámetros:		int* numbers, int n. 
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				por inserción al conjunto de números dado.
Complejidad:	O(n*n)
*/
void insertionSort(int* numbers, int n){
	int i = 0, pos, tmp;		/*Auxiliar para recorrer el arreglo*/
	for(i; i < n; i++){
		pos = i;				/*Nos ubicamos en la posición actual*/
		tmp = numbers[i];		/*Guardamos el valor de la posición actual*/

		while((pos > 0) && (numbers[pos - 1] > tmp)){
			 /*Si el elemento a la izquierda del número actual es mayor
			 al número actual, vamos haciendo la inserción para mantenerlos
			 ordenados de menor a mayor*/
			numbers[pos] = numbers[pos - 1];
			pos--;
		}
		numbers[pos] = tmp;
	}
}

/*
Nombre:			selectionSort
Parámetros:		int* numbers, int n. 
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				por selección al conjunto de números dado.
Complejidad:	O(n*n)
*/
void selectionSort(int* numbers, int n){

}

/*
Nombre:			binarySearchTree
Parámetros:		int* numbers, int n. 
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				con árbol binario de búsqueda al conjunto 
				de números dado.
Complejidad:	O(n*n)
*/
void binarySearchTree(int* numbers, int n){

}

/*
Nombre:			shellSort
Parámetros:		int* numbers, int n. 
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				Shell al conjunto de números dado.
Complejidad:	O(n*n)
*/
void shellSort(int* numbers, int n){
	
}