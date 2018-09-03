/*
**
  Librería para:
  	-- Leer los datos desde entrada estandar
  	-- Copiar arreglo original de numeros
  	-- Calculo del rendimiento de CPU/Wall
  	-- Imprimir datos del rendimiento de tiempo
  	-- Imprimir arreglo ordenado gracias al algoritmo
  	   de ordenamiento.
**
*/

int * readNumbers(int n);
int * cpyArray(int const * number, size_t len);
double getCPU_WALL(double user, double syst, double real);
void printSorting(int* numbers,int n);
void desc_time_efficiency(double user, double syst, 
						  double real, double cpu_wall);

/*Esta es una prueba que hago desde Manjaro*/
