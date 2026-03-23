#include <iostream>

// SOBRECARGA DE FUNCIONES 
int sumar(int a, int b) { return a+b; }
double sumar(double a, double b) { return a+b; }
int sumar(int a, int b, int c) { return a+b+c; }
 
int main() {
  int suma1 = sumar(1, 2);
  double suma2 = sumar(1.0, 2.0);
  int suma3 = sumar(1,2,3);

  std::cout<< suma1<<std::endl;
  std::cout<< suma2<<std::endl;
  std::cout<< suma3<<std::endl;
  // dependiendo del tipo y cantidad de parametros decide cual usar
  return 0;
}