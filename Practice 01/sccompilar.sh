#!/bin/bash

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

gcc main_bst.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o bst >> comandos.txt
echo "Binary Search Tree ready" >> comandos.txt

gcc main_shell.c sortingAlgorithms.c tiempo.c leer.c BST.c btStack.c -o shell >> comandos.txt
echo "Shell Sort ready" >> comandos.txt
