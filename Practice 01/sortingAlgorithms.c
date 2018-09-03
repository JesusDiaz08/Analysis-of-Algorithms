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
				por burbuja con mejoras para evitar re-
				corridos extras innecesarios.
Complejidad:	O(n*n)
*/
void bubbleSortOptimized(int* numbers, int n){
    /* cambios es una bandera, se inicializa en
    1, de lo contrario no se entra al for. aux
    una variable temporal para guardar valores.
    i y j variables para recorrer el arreglo */
    int i, j, aux, cambios = 1; 
    /* Mientras se esten haciendo cambios (es de-
    cir que cambios == 1 y que se hayan intercam-
    biado de posiciones valores en el arreglo), 
    seguiremos recorriendolo. De lo contrario 
    paramos de leerlo. He ahi la optimizacion con
    respecto del algoritmo anterior.
    Potencialmente, en el peor caso, se recorrera
    el arreglo n - 1 veces*/
    for (i = 0; i < n - 1 && cambios != 0; i++){ 
        /* Comprobar que no haya cambios en el
        recorrido */
        cambios = 0;
        for (j = 0; j <= n - 2 - i; j++){
            /* Comparamos si el número en la posición
            actual es mayor al valor que está a su 
            derecha */
            if (numbers [j] > numbers [j + 1]){
                /* Intercambio de posiciones del
                numero menor con el numero mayor
                a su derecha */
                aux = numbers [j];
                numbers [j] = numbers [j + 1];
                numbers [j + 1] = aux;
                /* Se han hecho cambios, hay que
                seguir recorriendo el arreglo */
                cambios = 1;
            }//cierra if 
        }//cierra segundo for
    }//cierra primer for
}//cierra metodo de bubbleSortOptimized


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
	
	int i, p, k, tmp;
	
	for(k = 0; k < n - 1;k++)  		 /*Auxiliar para recorrer el arreglo*/
	{
		p = k;		/*Variable que guarda la posición del valor más pequeño en el arreglo */
		for(i = k + 1; i < n; i++)		/*Auxiliar para recorrer el subarreglo*/
		{
			if(numbers[i] < numbers[p])
				p = i; /*Compara el valor del arreglo con los valores restantes
				 y guarda la posición del valor más pequeño*/
		}//cierra for de recorrido por subarreglos
		tmp = numbers[p];
		numbers[p] = numbers[k];
		numbers[k] = tmp; /*Intercambia el valor más pequeño del arreglo
		con el primer valor y se genera un subarreglo a partir de este último*/
	}//cierra for de recorrido del arreglo
}//cierra metodo de selectionSort

/*
Nombre:			binarySearchTree
Parámetros:		int* numbers, int n.
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				con árbol binario de búsqueda al conjunto
				de números dado.
Complejidad:	O(n*n)
*/
void binarySearchTree (int * numeros, int n){
    int i = 0;
    /* Creando el arbol con el primer valor del arreglo */
    struct tNode * root = newtNode (numeros [0]);
    /* Insertando todo el vector en el arbol */
    for (i = 1; i < n; i++)
        insert (root, numeros [i]);
    /* Haciendo recorrido inOrder del arbol */
    inOrder(root, numeros);
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
			}//cierra ciclo comparación por subarreglos
			numbers[b + gap] = tmp;	/*Se asigna el valor del número almacenado en tmp a su
									nueva posición en el (b+gap)-esimo indice del arreglo. */
		}/*cierra bucle de i*/
		gap /= 2;		/*Se vuelve a dividir el arreglo a la mitad de la mitad.*/
	}/*Ya no hay más subarreglo por procesar*/
}/*cierra metodo de shell-sort*/
