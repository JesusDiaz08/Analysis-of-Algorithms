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
	int i, j, tmp;	/*Se colocan los contadores i y j para recorrer el arreglo.
					Además de una variable temporal tmp para guardar el valor
					de la posición que sea más grande al valor actual*/
	for(i = 0;i < n; i++){	/*Ciclos que recorran al arreglo totalmente*/
		for (j = 0; j < n; j++){
			if(numbers[j] > numbers[j+1]){	/*Comparamos si el número en la posición actual
											es mayor al valor que está a su derecha*/
				tmp  = numbers[j];			/*Guardamos el valor que es mayor en tmp*/
				numbers[j] = numbers[j+1];	/*Asignamos el valor mas pequeño de la comparación
											en la posición donde estaba el mayor */
				numbers[j+1] = tmp;			/*Colocamos el valor mas grande de la comparación
											en la posicion donde estaba el menor*/
			}/*cierra condición*/
		}/*cierra ciclo de j*/
	}/*cierra ciclo de i*/
}/*cierra metodo de bubbleSort*/

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
    int aux, i, cambios = 0; /*i es una bandera*/
    while ((i < n - 1) && (cambios != 0)){
        cambios = 0;
        for (int j = 0; j <= n - 2 - i; j++){
            if (numbers [i] < numbers [j]){
                aux = numbers [j];
                numbers [j] = numbers [i];
                numbers [i] = aux;
                cambios = 1;
            } /* cierre if */
        } /* cierre for */
        i++;
    } /* cierre while*/
} /* fin procedimiento */


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
		numbers[pos] = tmp; /*Asignamos el valor de tmp en el indice 'pos'*/
	}/*cierra ciclo de i*/
}/*cierra metodo insertionSort*/

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
				Shell (incrementos decrecientes) al
				conjunto de números dado.
Complejidad:	O(n*n)
*/
void shellSort(int* numbers, int n){
	int gap;	/*Se guarda el tamaño de los subarreglos, el cual sera n/2 y sera
				siempre menor al tamaño del problema: n. Se toma gap->suelo*/
	int i;		/*Es el indice que permite recorrer los i-esismo subarreglos
				comenzando de la posicion gap.*/
	int b;		/*Es el indice que permite el recorrido en el i-esimo subarreglo
				desde la posicion 0 hasta la posicion de gap*/
	int tmp;	/*Sera nuestra variable temporal en donde almacenaremos el valor
				de la gap-esima posicion para ser comprado*/

	gap = n/2;			/*Realizamos el primer subarreglo: la mitad del arreglo original*/
	while(gap >= 1){   	/*Se hacen subarreglos hasta que los incrementos sean de 1 en 1*/
		for(i = gap; i < n; i++){	/*Se hace el recorrido en el arreglo desde la posicion gap*/
			tmp = numbers[i];		/*Se almacena el valor del arreglo en la i-esima posicion*/
			b = i - gap;			/*Se hacen los brincos de gap-posiciones*/
			while((b>=0) && (numbers[b] > tmp)){	/*Verificamos tantas veces necesarias si el
													valor de la posicion b es mayor a tmp*/
				numbers[b + gap] = numbers[b];		/*Si el valor en la posicion b si es mayor, se
													cambia el valor de dicha posición a la posicion
													b+gap dentro del arreglo*/
				b -= gap;
			}
			numbers[b + gap] = tmp;	/*Se asigna el valor del número almacenado en tmp a su
									nueva posición en el (b+gap)-esimo indice del arreglo. */
		}/*cierra bucle de i*/
		gap /= 2;		/*Se vuelve a dividir el arreglo a la mitad de la mitad.*/
	}/*Ya no hay más subarreglo por procesar*/
}/*cierra metodo de shell-sort*/
