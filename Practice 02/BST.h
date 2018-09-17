/*
La estructura de un nodo será la siguiente
	valor: 	Se almacenara el valor a ingresar, es decir, el numero a ordenar
	rigth:	Hace referencia al nodo del lado derecho que esta debajo de él.
	left:	Hace referencia al nodo del lado izquierdo que esta debajo de él.
*/

#define bool int

struct tNode
{
   int key;
   struct tNode* left;
   struct tNode* right;
};

struct tNode* newtNode(int data);
void inOrder(struct tNode *root, int * A);
struct tNode * insert (struct tNode *root, int data);
	

