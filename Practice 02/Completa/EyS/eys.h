/*
  Librería para:
  	-- Leer los datos desde entrada estandar
    -- Copiar arreglo original de numeros
  	-- Calculo del rendimiento de CPU/Wall
  	-- Imprimir datos del rendimiento de tiempo
*/
int * readNumbers(int n);
int * cpyArray(int const * number, size_t len);
void showTimeEfficiency(double user, double syst, double real, double cpu_wall, int n);
void printSorting(int* numbers,int n);
