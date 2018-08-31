/*
La estructura de un nodo será la siguiente
	valor: 	Se almacenara el valor a ingresar
	rigth:	Hace referencia al nodo del lado derecho que esta debajo de él.
	left:	Hace referencia al nodo del lado izquierdo que esta debajo de él.
Asimismo los nodos:
	tree: 	Hace referencia al árbol a crear
	pos:	Especifica la posición del apuntador
*/

typedef struct node{
	int valor;
	struct node* left;
	struct node* right;
} Node;

typedef Node *pos;
typedef Node *tree;

void init(tree* a);
int isEmpty(tree* a);
void newNode(tree* a, int data);
Node* createNode(int valor);
void fill_inOrden(tree* a, int* array);