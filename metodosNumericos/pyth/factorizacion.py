import numpy as np
from scipy.linalg import lu, lu_factor, lu_solve


A = np.array([[2,3],
              [5,4]],)
b = np.array([8, 3])

P, L ,U = lu(A)
print("Matriz de permutacion: ", P)
print("Matriz triangular superior: ", U)
print("Matriz triangular inferior: ", L)

# verificar que (P @ A == L @ U)
print("¿P@A == L@U?\n", np.allclose(P @ A, L @ U))

lu_piv = lu_factor(A)

x = lu_solve(lu_piv, b)

print("Solucion es: ", x)


