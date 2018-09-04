#!/bin/bash
clear
echo "Iniciando compilacion" >> comandos.txt
echo " "
gcc main_bubble_simple.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o bbs >> comandos.txt
echo "Bubble Sort Simple ready" >> comandos.txt

gcc main_bubble_optimized.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o bbo >> comandos.txt
echo "Bubble Sort Optimized ready" >> comandos.txt

gcc main_insertion.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o insertion >> comandos.txt
echo "Insertion Sort ready" >> comandos.txt

gcc main_selection.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o selection >> comandos.txt
echo "Selection Sort ready" >> comandos.txt

gcc main_bst.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o bst
echo "Binary Search Tree ready" >> comandos.txt

gcc main_shell.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o shell >> comandos.txt
echo "Shell Sort ready" >> comandos.txt


echo "Bubble Sort Simple" >> bubble_simple.txt
echo " " >> bubble_simple.txt
./bbs 100 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 1000 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 10000 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 50000 < Numeros/numeros10millones.txt >> bubble_simple.txt
./bbs 100000 < Numeros/numeros10millones.txt >> bubble_simple.txt

echo "Bubble Sort Optimized" >> bubble_optimized.txt
echo " " >> bubble_optimized.txt
./bbo 100 < Numeros/numeros10millones.txt >> bubble_optimized.txt
./bbo 1000 < Numeros/numeros10millones.txt >> bubble_optimized.txt
./bbo 10000 < Numeros/numeros10millones.txt >> bubble_optimized.txt
./bbo 50000 < Numeros/numeros10millones.txt >> bubble_optimized.txt
./bbo 100000 < Numeros/numeros10millones.txt >> bubble_optimized.txt

echo "Insertion Sort" >> insertion.txt
echo " " >> insertion.txt
./insertion 100 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 1000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 10000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 100000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 500000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 1000000 < Numeros/numeros10millones.txt >> insertion.txt



