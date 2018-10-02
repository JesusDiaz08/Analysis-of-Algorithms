#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "MedicionTiempo/tiempo.h"		
#include "EyS/eys.h"
#include "Busquedas/Arbol/BST.h"

int main (int argc, char const * argv []) {
	double utime0, stime0, wtime0,utime1, stime1, wtime1;

	if (argc!=3){
		printf("\nEror. Indique numero a buscar y tamaño de espacio de busqueda. Ejemplo: [user@equipo]$ %s 3 100\n",argv[0]);
		exit(1);
	}

	int n = atoi(argv[1]);
	int nf = atoi(argv[2]);
	int isFound, isFound2;

	int * numbers = readNumbers(n);

	int i = 0;
    /* Creando el arbol con el primer valor del arreglo */
    struct tNode * root = newtNode (numbers [0]);
    /* Insertando todo el vector en el arbol */
    for (i = 1; i < n; i++)
        insert (root, numbers [i]);
	
    //printf("%d\n", root->key);
    uswtime(&utime0, &stime0, &wtime0);

    if (nf == root -> key){
    	isFound = 1;
    	//printf("nf igual\n");
    }
    else if (nf > root -> key){
    	//printf("nf mayor\n");
    	root = root -> right;
    }
    else if (nf < root -> key){
    	//printf("nf menor\n");
    	root = root -> left;
    }

    pthread_t thread;
    param datos;
    datos.nf = nf;
    datos.root = root -> right;
    if (pthread_create (&thread, NULL, searchBST_thread, (void *)&datos) != 0)
    {
    	perror("El thread no  pudo crearse");
		exit(-1);
    } 

	isFound = searchBST(root -> left, nf);    
	isFound2 = (int) searchBST_thread (&datos);
	uswtime(&utime1, &stime1, &wtime1);
	double real, user, syst, cpu_wall;
	real = wtime1 - wtime0;
	user = utime1 - utime0;
	syst = stime1 - stime0;
	cpu_wall = 100 * (user + syst) / real;
    showTimeEfficiency(user, syst, real, cpu_wall, n);

	if (isFound || isFound2){
		printf("s, ");
	}
	else {
		printf("n, ");
	}
	free(numbers);
	free (root);
	return 0;
}	