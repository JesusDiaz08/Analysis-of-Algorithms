/*
Nota general:
	Para cada uno de los algoritmos de ordenamiento
	se contemplarán dos parámetros:

	n:			Número de elementos a ordenar
	numbers:	Arreglo de n-numeros a ordenar
*/

#include "sortingAlgorithms.h"
#include "BST.h"

/*
Nombre:			bubbleSort
Parámetros:		int* numbers, int n.
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				por burbuja	al conjunto de números dado.
Complejidad:	O(n*n)
*/
void bubbleSort(int* numbers, int n){
	int i, j, tmp;	
	for(i = 0;i < n; i++){	
		for (j = 0; j < n; j++){
			if(numbers[j] > numbers[j+1]){
										
				tmp  = numbers[j];		
				numbers[j] = numbers[j+1];
										
				numbers[j+1] = tmp;		
										
			}
		}
	}
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
    int i, j, aux, cambios = 1; 
    
    for (i = 0; i < n - 1 && cambios != 0; i++){ 
        cambios = 0;
        for (j = 0; j <= n - 2 - i; j++){
            if (numbers [j] > numbers [j + 1]){
                aux = numbers [j];
                numbers [j] = numbers [j + 1];
                numbers [j + 1] = aux;
                
                cambios = 1;
            } 
        }
    }
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
	int i = 0, pos, tmp;		
	for(i; i < n; i++){
		pos = i;				
		tmp = numbers[i];		

		while((pos > 0) && (numbers[pos - 1] > tmp)){
			numbers[pos] = numbers[pos - 1];
			pos--;
		}
		numbers[pos] = tmp; 
	}
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
	
	for(k = 0; k < n - 1;k++){
		p = k;		
		for(i = k + 1; i < n; i++){
			if(numbers[i] < numbers[p])
				p = i; 		 
		}
		tmp = numbers[p];
		numbers[p] = numbers[k];
		numbers[k] = tmp; 
	}
}//cierra metodo de selectionSort

/*
Nombre:			binarySearchTree
Parámetros:		int* numbers, int n.
Retorno:		void
Descripción:	Se aplicará algoritmo de ordenamiento
				con árbol binario de búsqueda al conjunto
				de números dado.
Complejidad:	O(n*log(n))
*/
void binarySearchTree (int * numeros, int n){
    int i = 0;
    struct tNode * root = newtNode (numeros [0]);
    
    for (i = 1; i < n; i++)
        insert (root, numeros [i]);
    
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
	int gap;					
	int i;						
	int b;						
	int tmp;	

	gap = n/2;			/*Realizamos el primer subarreglo: la mitad del arreglo original*/
	while(gap >= 1){   	
		for(i = gap; i < n; i++){	/*Se hace el recorrido en el arreglo desde la posicion gap*/
			tmp = numbers[i];		
			b = i - gap;			
			while((b>=0) && (numbers[b] > tmp)){	/*Verificamos tantas veces necesarias si el
													valor de la posicion b es mayor a tmp*/
				numbers[b + gap] = numbers[b];		
				b -= gap;
			}
			numbers[b + gap] = tmp;	
		}
		gap /= 2;		
	}
}/*cierra metodo de shell-sort*/
