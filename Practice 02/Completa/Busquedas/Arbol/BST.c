#include "BST.h"
//#include "btStack.h"
#include<stdio.h>
#include<stdlib.h>

  
  
/* Crear nodo arbol */
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*) malloc(sizeof(struct tNode));
  tNode->key = data;
  tNode->left = NULL;
  tNode->right = NULL;
  return(tNode);
}

  
/* Insercion iterativa al arbol */
struct tNode * insert(struct tNode *root, int data) {
    struct tNode ** pp = &root;
    /* Hacemos recorrido de todo el arbol */
    while (*pp != NULL) {
        /* Si nuestro numero es mayor
        que el del nodo actual, entonces
        nos vamos a la derecha, si no,
        entonces a la izquierda */
        if (data > (*pp) -> key)
            pp = & (*pp) -> right;
        else
            pp = & (*pp) -> left;
    }
    /* Creamos el nodo que va a guardar a nuestro
    numero */
    * pp = newtNode(data);
    return root;
}

/* Busqueda iterativa en arbol */
int searchBST (struct tNode *root, int data) {
  struct tNode ** pp = &root;
  /* Hacemos recorrido de todo el arbol */
  while (*pp != NULL) {
    if (data == (*pp) -> key)
      return 1;
    else if (data > (*pp) -> key)
      pp = & (*pp) -> right;
    else if (data < (*pp) -> key)
      pp = & (*pp) -> left;
    }
    return 0;
}

void * searchBST_thread (void * p) {
  param * p2 = (param *) p;
  //printf("dato buscar en func: %d\n", p2 -> nf);
  //printf("dato en  key func: %d\n", p2 -> root -> key);

  struct tNode ** pp = &p2 -> root;
  /* Hacemos recorrido de todo el arbol */
  while (*pp != NULL) {
    if (p2 -> nf == (*pp) -> key)
      return (void *) 1;
    else if (p2 -> nf > (*pp) -> key)
      pp = & (*pp) -> right;
    else if (p2 -> nf < (*pp) -> key)
      pp = & (*pp) -> left;
    }
    return (void *) 0;
}
