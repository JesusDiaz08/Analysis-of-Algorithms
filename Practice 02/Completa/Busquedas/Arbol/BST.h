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

typedef struct param {
    struct tNode * root;
    int nf;
} param;

struct tNode* newtNode(int data);
struct tNode * insert (struct tNode *root, int data);
int searchBST (struct tNode *root, int data);
void * searchBST_thread (void * param);
	

