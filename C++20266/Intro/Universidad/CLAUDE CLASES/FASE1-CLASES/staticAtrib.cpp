#include <iostream>

class Matematica {
public:  // el atributo debe ser public
  static const double pi;  // static y const 
};

// inicializar atributo static (siempre debe ser afuera)
const double Matematica::pi = 3.141592;

int main() {
  // acceder al atributo publico de la clase
  std::cout<< Matematica::pi <<std::endl;

  return 0;
}