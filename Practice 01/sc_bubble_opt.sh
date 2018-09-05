#!/bin/bash

echo "Bubble Sort Optimized" >> bubble_optimized.txt
echo " " >> bubble_optimized.txt
#./bbo 100 < Numeros/numeros10millones.txt >> bubble_optimized.txt
#./bbo 1000 < Numeros/numeros10millones.txt >> bubble_optimized.txt
#./bbo 10000 < Numeros/numeros10millones.txt >> bubble_optimized.txt
#./bbo 50000 < Numeros/numeros10millones.txt >> bubble_optimized.txt #si lo hace
./bbo 75000 < Numeros/numeros10millones.txt >> bubble_optimized.txt #si lo hace
#./bbo 87500 < Numeros/numeros10millones.txt >> bubble_optimized.txt
#./bbo 100000 < Numeros/numeros10millones.txt >> bubble_optimized.txt 
#./bbo 500000 < Numeros/numeros10millones.txt >> bubble_optimized.txt #Lo hace en aprox. 15 min
#./bbo 1000000 < Numeros/numeros10millones.txt >> bubble_optimized.txt #en 45 no acabó
