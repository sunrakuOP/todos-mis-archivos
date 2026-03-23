#include <iostream>

static int *crearPersistente() {
  static int valor = 42;
  return &valor;

}
int main() {
  int *p = crearPersistente();
  std::cout<< *p << std::endl;

  *p = 100;   // podemos cambiarle el valor
  std::cout<< *p;

  return 0;
}