#include <iostream>

// funcion que usa variable static para aumentar su lifetime
void contar() {
  static int veces = 0;
  ++veces;
  std::cout<<"Llamanada numero: "<< veces <<std::endl;
}

int main() {
  contar();
  contar();
  contar();
  // a pesar de que sale del scope "veces" sigue manteniendo su valor
  
  return 0;
}