#!/bin/bash
clear
echo "Iniciando compilacion"
gcc main.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o ord >> comandos.txt

echo "Algoritmo | user | syst | real | cpu_wall" >> salida.txt
./ord 10000 < Numeros/numeros10millones.txt >> salida.txt
./ord 50000 < Numeros/numeros10millones.txt >> salida.txt
./ord 100000 < Numeros/numeros10millones.txt >> salida.txt
./ord 200000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 400000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 600000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 800000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 1000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 2000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 3000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 4000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 5000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 6000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 7000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 8000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 9000000 < Numeros/numeros10millones.txt >> salida.txt
#./ord 10000000 < Numeros/numeros10millones.txt >> salida.txt


