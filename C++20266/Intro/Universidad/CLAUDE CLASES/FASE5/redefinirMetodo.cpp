#include <iostream>

class Persona {
public:
  void saludar() const {
    std::cout<<"Hola soy persona"<<std::endl;
  }
};

class Estudiante: public Persona {
public: 
  void saludar() const {
    std::cout<<"Hola soy estudiante"<<std::endl;
  }
};

int main() {

  Persona p;
  Estudiante e;

  p.saludar(); // como se hace sin virtual no se altera reallmente la definicion (se esconde y ya)
  e.saludar();

  return 0;
}