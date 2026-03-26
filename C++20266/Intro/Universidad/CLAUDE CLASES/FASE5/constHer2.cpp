#include <iostream>

class Persona{
protected:
  std::string nombre;
  int edad;
public:
  Persona(const std::string& n, int e): nombre(n), edad(e) {}
//  copia
  Persona(const Persona& otro): nombre(otro.nombre), edad(otro.edad) {}
// operador =
  Persona& operator=(const Persona& otro) {
    if(this == &otro) {
      return *this;  // retorna el objeto
    }
    nombre = otro.nombre;
    edad = otro.edad;
    return *this;
  }
// move
  Persona(Persona&& otro): nombre(std::move(otro.nombre)), edad(otro.edad) {
    otro.edad = 0;
    otro.nombre = "";
  }

  ~Persona() {
    std::cout<<"Destruyendo persona "<<nombre<<std::endl;
  }

  void mostrarPersona() const {
    std::cout<<"Nombre: "<<nombre<<", edad: "<<edad;
  }
};

class Estudiante: public Persona {
protected:
  std::string carrera;
  double promedio;
public:
  Estudiante(const std::string& n, int e, const std::string& c, double p): Persona(n, e), carrera(c), promedio(p) {}

  Estudiante(const Estudiante& otro): Persona(otro), carrera(otro.carrera), promedio(otro.promedio) {}

  Estudiante& operator=(const Estudiante& otro) {
    if(this == &otro) {
      return *this;
    }
    Persona::operator=(otro); // debo copiar la parte persona de esa forma
    carrera = otro.carrera;
    promedio = otro.promedio;
    return *this;
  } 

  Estudiante(Estudiante&& otro): Persona(std::move(otro)), carrera(std::move(otro.carrera)), promedio(otro.promedio) {
    otro.promedio = 0; // cadenas y vectores se pasan con move, al igual que Herencia
  }

  void mostrarEst() const {
    mostrarPersona();
    std::cout<<"Carrera: "<<carrera<<", promedio: "<<promedio<<std::endl;
  }

  ~Estudiante() {
    std::cout<<"Destruyendo estudiante "<<std::endl;
  }

};

class Becado:public Estudiante{
protected:
  double montoBeca;
public:
  Becado(const std::string& n, int e, const std::string& c, double p, double m): Estudiante(n,e,c,p), montoBeca(m) {}

  Becado(const Becado& otro): Estudiante(otro), montoBeca(otro.montoBeca) {}

  Becado& operator=(const Becado& otro) {
    if(this == &otro) {
      return *this;
    }
    Estudiante::operator=(otro);  // muy importante saber sintaxis de copia en herencia
    montoBeca = otro.montoBeca;
    return *this;
  }

  Becado (Becado&& otro): Estudiante(std::move(otro)), montoBeca(otro.montoBeca) { // MOVE usa && (RVALUE)
    otro.montoBeca = 0;
  } 

  ~Becado() {
    std::cout<<"Destruyendo becado"<<std::endl;
  }

  void mostrarBecado() const {
    mostrarEst();    // usando herencia multiple (uso metodos de clases padres)
    std::cout<<"Monto de beca: "<<montoBeca<<std::endl;
  }
};


int main() {
  Becado b("Juan", 20, "Sistemas", 9.2, 5000.0);
  b.mostrarBecado();

  Estudiante e = b;        // copy — Estudiante copiado desde un Becado
  e.mostrarEst();

  return 0;
}


// operador de igualdad es que retorna Obj&