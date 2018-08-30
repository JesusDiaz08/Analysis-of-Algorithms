/*
La estructura de un nodo será la siguiente
	valor: 	Se almacenara el valor a ingresar
	der:	Hace referencia al nodo del lado derecho que esta debajo de él.
	izq:	Hace referencia al nodo del lado izquierdo que esta debajo de él.

*/


typedef struct nodo{
	int valor;
	struct nodo* der;
	struct nodo* izq;
} Nodo;