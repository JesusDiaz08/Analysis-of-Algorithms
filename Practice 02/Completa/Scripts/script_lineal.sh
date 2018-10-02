#!/bin/bash
#clear
echo Busqueda Lineal Ejecutando ...
echo Inicio de la prueba: $(date)
echo "Algoritmo  |  Forma  |  Numero a buscar  |  Tam N.  |  Real  |  Encontrado  |" > Salidas/resultados_lineal.csv

./main_lineal 100 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 1000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 5000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 10000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 50000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 100000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 200000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 400000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 600000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 800000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 1000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 2000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 3000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 4000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 5000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 6000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 7000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 8000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 9000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
./main_lineal 10000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_lineal.csv
echo Final de la prueba: $(date)
