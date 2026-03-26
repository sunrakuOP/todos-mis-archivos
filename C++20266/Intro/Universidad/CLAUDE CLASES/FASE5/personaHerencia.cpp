#include <iostream>
#include <string>

class Persona { // clase padre
protected:
  std::string nombre;
  int edad;
public: 
  Persona(const std::string& n, int e): nombre(n), edad(e) {}

  void mostrarPersona() const {
    std::cout<<"Nombre: "<<nombre<<", edad: "<<edad <<std::endl; 
  }

  std::string getNombre() const { return nombre; }
  int getEdad() const { return edad; }

  //en vez de cout voy a sobrecargar operador << (solo para practicar)
  friend std::ostream& operator<<(std::ostream& os, const Persona& obj) {
    os <<"Nombre: "<< obj.getNombre() <<", edad: "<< obj.getEdad() <<std::endl;
    return os;
  }
};

// clase hija que hereda 
class Estudiante: public Persona {
private:  
  std::string carrera;
public:
  Estudiante(const std::string& n, int e, const std::string& c): Persona(n,e), carrera(c) {}

  void mostrarEstudiante() const {
    mostrarPersona();
    std::cout<<"Carrera: "<<carrera<<std::endl;
  }
};

int main() {
  Persona p("Juan", 30);
  Estudiante e("Isa", 20, "Deporte");

  std::cout << p << "\n";
  e.mostrarEstudiante();
  return 0;
}