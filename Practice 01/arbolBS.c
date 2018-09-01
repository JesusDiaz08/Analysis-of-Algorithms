#include <stdlib.h>
#include <stdio.h>
#include "arbolBS.h"

int index = 0;

/*
Nombre:			init
Parámetros:		tree* a
Retorno:		void
Descripción:	La función se encargará inicializar
				el apuntador al árbol
*/
void init(tree* a){
	*a = NULL;
	return;
}

/*
Nombre:			isEmpty
Parámetros:		tree* a
Retorno:		int
Descripción:	La función se encargará verificar
				si el árbol está vacío: 1 si lo está
				y 0 para caso contrario.
*/
int isEmpty(tree* a){
	return (a==NULL);
}

/*
Nombre:			newNode
Parámetros:		tree* a, int valor
Retorno:		void
Descripción:	La función se encarga de crear un nodo de manera
				recursiva
*/
void newNode(tree* a, int valor){
	if(isEmpty(a)){			/*Si el nodo está vacio, se crea el nodo raíz*/
		*a = createNode(valor);
	}else{					/*Ya hay un nodo previamente creado*/
		/*Se verifica hacia que lado hay que mover
		la posición para asignarlo.*/
		if((*a)->valor < valor){	/*Si es mayor al dato del nodo actual va
									hacia la derecha*/
			newNode(&((*a)->right),valor);
		}else						/*Si es mayor al dato del nodo actual va
									hacia la derecha*/
			newNode(&((*a)->left),valor);
	}
	return;
}

/*
Nombre:			createNode();
Parámetros:		int valor
Retorno:		Node* 
Descripción:	La función se encarga de crear un nuevo nodo
				asignandole el valor que es enviado por parametro
*/
Node* createNode(int valor){
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->valor = valor;
	return tmp;
}

/*
Nombre:			fill_inOrden();
Parámetros:		int valor
Retorno:		Node* 
Descripción:	La función se encarga de crear un nuevo nodo
				asignandole el valor que es enviado por parametro
*/
void fill_inOrden(tree* a, int* array){
	
}