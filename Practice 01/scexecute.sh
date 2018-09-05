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
./insertion 5000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 10000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 50000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 100000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 200000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 400000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 600000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 800000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 100000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 1000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 2000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 3000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 4000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 5000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 6000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 7000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 8000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 9000000 < Numeros/numeros10millones.txt >> insertion.txt
./insertion 10000000 < Numeros/numeros10millones.txt >> insertion.txt


echo "Selection Sort" >> selection.txt
echo " " >> selection.txt
./selection 100 < Numeros/numeros10millones.txt >> selection.txt
./selection 1000 < Numeros/numeros10millones.txt >> selection.txt
./selection 5000 < Numeros/numeros10millones.txt >> selection.txt
./selection 10000 < Numeros/numeros10millones.txt >> selection.txt
./selection 50000 < Numeros/numeros10millones.txt >> selection.txt
./selection 100000 < Numeros/numeros10millones.txt >> selection.txt
./selection 200000 < Numeros/numeros10millones.txt >> selection.txt
./selection 400000 < Numeros/numeros10millones.txt >> selection.txt
./selection 600000 < Numeros/numeros10millones.txt >> selection.txt
./selection 800000 < Numeros/numeros10millones.txt >> selection.txt
./selection 1000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 2000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 3000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 4000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 5000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 6000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 7000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 8000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 9000000 < Numeros/numeros10millones.txt >> selection.txt
./selection 10000000 < Numeros/numeros10millones.txt >> selection.txt

echo "Binary Search Tree" >> binary_search_tree.txt
echo " " >> binary_search_tree.txt
./bst 100 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 1000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 5000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 10000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 50000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 100000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 200000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 400000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 600000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 800000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 1000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 2000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 3000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 4000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 5000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 6000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 7000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 8000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 9000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt
./bst 10000000 < Numeros/numeros10millones.txt >> binary_search_tree.txt

echo "Shell Sort" >> shell.txt
echo " " >> shell.txt
./shell 100 < Numeros/numeros10millones.txt >> shell.txt
./shell 1000 < Numeros/numeros10millones.txt >> shell.txt
./shell 5000 < Numeros/numeros10millones.txt >> shell.txt
./shell 10000 < Numeros/numeros10millones.txt >> shell.txt
./shell 50000 < Numeros/numeros10millones.txt >> shell.txt
./shell 100000 < Numeros/numeros10millones.txt >> shell.txt
./shell 200000 < Numeros/numeros10millones.txt >> shell.txt
./shell 400000 < Numeros/numeros10millones.txt >> shell.txt
./shell 600000 < Numeros/numeros10millones.txt >> shell.txt
./shell 800000 < Numeros/numeros10millones.txt >> shell.txt
./shell 1000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 2000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 3000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 4000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 5000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 6000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 7000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 8000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 9000000 < Numeros/numeros10millones.txt >> shell.txt
./shell 10000000 < Numeros/numeros10millones.txt >> shell.txt