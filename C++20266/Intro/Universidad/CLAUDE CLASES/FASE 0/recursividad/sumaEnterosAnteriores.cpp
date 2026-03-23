// contar digitos de un numero
// invertir un numero
// recorrer e imprimir arreglo al derecho y al reves

#include <iostream>

int sumaEnteros(int n) {
  if (n < 0) {
    return -1;
  }
  if (n <= 1) {
    return 1;
  }
  return n+ sumaEnteros(n-1);
}

int main() {
  std::cout<< sumaEnteros(5)<<std::endl;

  return 0;
}