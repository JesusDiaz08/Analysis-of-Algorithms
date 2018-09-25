# -*- coding: utf-8 -*-
"""
Created on Mon Sep 24 18:01:21 2018

@author: Díaz Medina Jesús Kaimorts.
@subject: Analysis of Algorithms.
@group: 3CM2.
@title: Complexity Orders.
@school: Escuela Superior de Cómputo.

@Steps:
    1. Run de code
    2. Set the 'n' to graphs complexity orders
       The most famous complexity functions will be graphed:
       a) Constant Complexity: O(1)
       b) Logarithm Complexity: O(log(n))
       c) Lineal Complexity: O(n)
       d) Cuadratic Complexity: O(n^2)
       e) Cubic Complexity: O(n^3)
       f) Exponential Complexity O(c^n) : c>1
       g) Factorial Complexity O(n!)
    
"""
import math
import numpy as np
import matplotlib.pyplot as plt

N = 2

#Graph individual complexity orders
#x = np.arange(1.0,N+1,1.0)

#plt.plot(x, x/x, label="O(1)")
#plt.plot(x, log2(x) ,  label="O(log2(n))")
#plt.plot(x, log10(x) , label="O(log10(n))")
#plt.plot(x, x ,label="O(n)")
#plt.plot(x, x**2 , label="O(n^2)")
#plt.plot(x, x**3 , label="O(n^3)")
#plt.plot(x, 2**(x) ,'-r', label="O(2^n)")
#plt.plot(x, math.factorial(x), label="O(n!)")

#__________________________________

#Graph together complexity orders
x = np.linspace(1, N, 100)
#plt.plot(x, x/x, label="O(1)")
#plt.plot(x, log2(x) ,  label="O(log2(n))")
#plt.plot(x, log10(x) , label="O(log10(n))")
#plt.plot(x, x ,label="O(n)")
#plt.plot(x, x**2 , label="O(n^2)")
#plt.plot(x, x**3 , label="O(n^3)")
#plt.plot(x, 2**(x) ,'-r', label="O(2^n)")
plt.plot(x, math.factorial(x), label="O(n!)")
plt.grid(True)
plt.xlabel('N')
plt.ylabel('Operations')
plt.title("Complexity Orders")
plt.legend()
plt.show()

print("\n")
print(math.factorial(3))