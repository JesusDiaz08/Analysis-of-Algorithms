#include "btStack.h"
#include "BST.h"
#include<stdio.h>
#include<stdlib.h>

/* Funcion para meter un nodo en la pila */
void push(struct sNode** top_ref, struct tNode *t)
{
  /* Asignando memoria para el nodo de pila */
  struct sNode* new_tNode = (struct sNode*) malloc(sizeof(struct sNode));
  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     getchar();
     exit(0);
  }            
  /* Guardando el nodo de arbol  */
  new_tNode->t = t;
  /* Link con el nodo de abajo */
  new_tNode->next = (*top_ref);   
  /* El nodo creado es el top */
  (*top_ref) = new_tNode;
}
 
/* Regresa verdadero si la pila esta vacia, si no, falso */
bool isEmpty(struct sNode *top)
{
   return (top == NULL)? 1 : 0;
}   
 
/* Sacar nodo de la pila */
struct tNode *pop(struct sNode** top_ref)
{
  struct tNode *res;
  struct sNode *top;
 
  /* Si la pila esta vacia, hay un error */
  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     getchar();
     exit(0);
  } 
  else
  {
     top = *top_ref;
     res = top->t;
     /* Liberamos el nodo sacado */
     *top_ref = top->next;
     free(top);
     /* Retornamos una copia del nodo sacado */
     return res;
  }
}
