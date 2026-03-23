#include <iostream>
#include <string>

class Persona {
private: 
  std::string nombre;
  int id;
  static int contador;

public: 
  Persona (std::string n, int i) : nombre(n), id(i) {
    contador++;
  }
  ~Persona() {}

  // vamos a hacerle getter y setters al objeto
  Persona& setNombre(std::string n) {
    nombre = n;
    return *this;
  }
  Persona& setId(int i) {
    id = i;
    return *this;
  }
  std::string getNombre() {
    return nombre;
  }
  int getId() {
    return id;
  }

  static int getContador() {
    return contador;
  }
};

int Persona::contador= 0;

int main() {
  Persona p1("Nicolas", 1000286649);   // creamos objeto usando constructor
  Persona p2("Juan", 20);
  // mostramos los atributos incializados
  std::cout<< p1.getNombre()<<std::endl;
  std::cout<< p1.getId() <<std::endl;

  // cambiamos los atributos con el setter y los volvemos a mostrar
  p1.setNombre("Julian");
  p1.setId(12);

  std::cout<< p1.getNombre()<<std::endl;
  std::cout<< p1.getId() <<std::endl;
    // ya se cambiaron los paramoetros en el objeto
  
    // usar encadenamiento
  p1.setNombre("Carlos").setId(17220);  // encadenamos los setters
  std::cout<< p1.getNombre()<<std::endl;
  std::cout<< p1.getId() <<std::endl;

  std::cout<< Persona::getContador() <<std::endl;
  


  return 0;
}