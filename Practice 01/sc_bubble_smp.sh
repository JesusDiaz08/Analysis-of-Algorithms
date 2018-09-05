#!/bin/bash

echo "Bubble Sort Simple" >> bubble_simple.txt
echo " " >> bubble_simple.txt
./bbs 100 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 1000 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 10000 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 50000 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 100000 < Numeros/numeros10millones.txt >> bubble_simple.txt
