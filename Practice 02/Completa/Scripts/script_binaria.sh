#!/bin/bash
#clear
echo Busqueda Binaria Ejecutando ...
echo Inicio de la prueba: $(date)
echo "Algoritmo  |  Forma  |  Numero a buscar  |  Tam N.  |  Real  |  Encontrado  |" > Salidas/resultados_binaria.csv

./main_binary 100 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 1000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 5000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 10000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 50000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 100000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 200000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 400000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 600000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 800000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 1000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 2000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 3000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 4000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 5000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 6000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 7000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 8000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 9000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
./main_binary 10000000 < Numeros/10millonesOrdenados.txt >> Salidas/resultados_binaria.csv
echo Final de la prueba: $(date)
