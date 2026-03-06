import numpy as np
from scipy.linalg import lu, lu_factor, lu_solve

filas = int(input("Digite el numero de filas: "))
A = [[0 for _ in range(filas)] for _ in range(filas)]

# llena matriz con valores ingresados
for i in range(filas):
	for j in range(filas):
		A[i][j] = float(input(f"Introduce el valor para la posicion [{i}][{j}]: "))

# Imprime la matriz completa, fila por fila
print("Matriz ingresada:")
for fila in A:
	print(fila)

# Inicializa el vector de resultados (filas x 1)
b = [0 for _ in range(filas)]

# Llena el vector de resultados con valores ingresados
for i in range(filas):
	b[i] = float(input(f"Introduce el valor del resultado para la ecuación {i}: "))

# Imprime el vector de resultados
print("Vector de resultados:")
print(b)

# factorizar para A = LU
lu_piv = lu_factor(A)
# resolver para x
x = lu_solve(lu_piv, b)

print("Solucion del sistema es: ", x)