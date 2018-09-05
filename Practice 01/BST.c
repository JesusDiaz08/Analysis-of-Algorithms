#include "BST.h"
#include "btStack.h"
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

/* Inorder iterativo del arbol */
void inOrder(struct tNode *root, int * A)
{
  int i = 0; /* Indice para el vector ordenado */

  /* Raiz del arbol actual */
  struct tNode *current = root;
  /* Inicializar pila s */
  struct sNode *s = NULL;  
  bool done = 0;
 
  while (!done)
  {
    /* Ir al tNode mas a la izquierda de la raiz actual */
    if(current !=  NULL)
    {
      /* Meter el tNode a la pila y actualizar el valor de la raiz actual */
      push(&s, current);                                               
      current = current->left;  
    }
    /* Regresar desde el subarbol vacio y ver el tNode en el top
    de la pila. Si esta vacia, entonces se termina el procedimiento */
    else                                                             
    {
      if (!isEmpty(s))
      {
        current = pop(&s);
        //printf("%d ", current->key);
        /* Ordenando vector */
        A [i] = current->key;
        i++;
        /* Recorrimos el nodo y su subarbol izquierdo.
        Ahora el derecho */
        current = current->right;
      }
      else
        done = 1; 
    }
  } /* Fin del while */ 
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
