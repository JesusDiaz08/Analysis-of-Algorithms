#!/bin/bash

echo "Compilando..."
#gcc Busquedas/Busquedas.c EyS/eys.c MedicionTiempo/tiempo.c Lineal.c -o bLineal
#echo "Compilacion de Busqueda Lineal lista!"
#gcc EyS/eys.c MedicionTiempo/tiempo.c Busquedas/Arbol/BST.c Arbol.c -o bArbol
# echo "Compilacion de Busqueda en BST lista!"
gcc EyS/eys.c MedicionTiempo/tiempo.c Busquedas/Arbol/BST.c ArbolThread.c -lm -lpthread -o bArbolThread
echo "Compilacion de Busqueda en BST con hilos lista!"

echo "Compilando Busqueda Lineal ..."
gcc main_lineal.c Busquedas/Busquedas.c EyS/eys.c MedicionTiempo/tiempo.c -o main_lineal -lpthread

echo "Compilando Busqueda Binaria ..."
gcc main_binaria.c Busquedas/Busquedas.c EyS/eys.c MedicionTiempo/tiempo.c -o main_binary -lpthread
