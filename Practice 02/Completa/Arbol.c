#include <string.h>
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
	int isFound;

	int * numbers = readNumbers(n);

	int i = 0;
    /* Creando el arbol con el primer valor del arreglo */
    struct tNode * root = newtNode (numbers [0]);
    /* Insertando todo el vector en el arbol */
    for (i = 1; i < n; i++)
        insert (root, numbers [i]);


	uswtime(&utime0, &stime0, &wtime0);
	isFound = searchBST(root, nf);
	uswtime(&utime1, &stime1, &wtime1);
	double real, user, syst, cpu_wall;
	real = wtime1 - wtime0;
	user = utime1 - utime0;
	syst = stime1 - stime0;
	cpu_wall = 100 * (user + syst) / real;
    showTimeEfficiency(user, syst, real, cpu_wall, n);

	if (isFound >= 0){
		printf("s, ");
	}
	else {
		printf("n, ");
	}
	free(numbers);

	return 0;
}
