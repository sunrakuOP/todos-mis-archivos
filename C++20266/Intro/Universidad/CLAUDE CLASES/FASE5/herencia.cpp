// primer ejercicio de herencia, clase Base
#include <iostream>
#include <string>

class Base { // clase de la que van a heredar las otras atributos y metodos
protected:
  std::string nombre;
  int edad;
  // metodos protected para que clase e hijas puedan acceder
public:
  Base(const std::string n, int e): nombre(n), edad(e) {}

  void mostrarBase() const {
    std::cout<< nombre <<", "<<edad<<std::endl;    
  }
};

// clase derivada hereda de base
class Derivada: public Base {  // clase hija puede acceder a atributos y metodos de clase padre

private: // anade atributos propios
  std::string extra;
public:
  // inicializar clase padre
  Derivada(const std::string n, int e, const std::string ex): Base(n,e), extra(ex) {}

  // anadir metodos propios
  void mostrarTodo() const {
    mostrarBase(); // uso metodo de clase base
    std::cout<< extra <<std::endl;
  }

};

int main() {
  Base b1("Nicolas", 23);
  b1.mostrarBase();

  Derivada d1("Isabella",21,"basket");
  d1.mostrarBase(); // puedo usar ambos metodos con la clase hija
  d1.mostrarTodo();

  return 0;
}