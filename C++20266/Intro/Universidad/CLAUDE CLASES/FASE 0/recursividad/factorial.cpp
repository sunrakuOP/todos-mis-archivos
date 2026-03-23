#include <iostream>

long long factorial(int n) {
  if (n < 0) {
    return -1;
  }

  if (n <= 1) {
    return 1;
  }

  return n * factorial(n - 1);
}

int main() {
  int numero = 10;
  long long resultado = factorial(numero);

  if (resultado == -1) {
    std::cout << "El factorial no esta definido para negativos." << std::endl;
  } else {
    std::cout << "Factorial de " << numero << " = " << resultado << std::endl;
  }

  return 0;
}