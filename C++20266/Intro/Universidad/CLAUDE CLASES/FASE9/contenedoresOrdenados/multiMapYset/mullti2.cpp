#include <iostream>
#include <map>
#include <set> // no pueden haber dos profesores iguales en la misma materia

class Salon{ 
protected:
  std::map<std::string, std::set<std::string>> materiass;
  // o puedo modelarlo con multimap
  std::multimap<std::string, std::string> materias; // una clave(materia) puede tener multiples valores (profesores)
public:
  // por ahora modelarlo con el multimap
  Salon() = default;

  Salon& agrergarParMateria(const std::string& materia, const std::string& profesor) {
    // no importa que materia ya exista la inserta
    materias.insert({materia, profesor});
    return *this;
  }
  // mostrar profesores por materia (busqueda por clave)
  void profesoresPorMateria(const std::string& materia) {
    if(materias.count(materia) == 0) {
      std::cout<<"Materia no existente"<<std::endl;
      return;
    }
    auto rango = materias.equal_range(materia);
    for(auto it = rango.first; it != rango.second; ++it) {
      std::cout<<it->second <<std::endl;   // toca hacerle doble auto, para el rango y para el iterador
    }
  } 

  void imprimirContenido() const {
    if(materias.empty()) {
      std::cout<<"Sin materias registradas..."<<std::endl;
      return;
    }
    std::cout<<"Mapa de materias: "<<std::endl;
    for(const auto&[materia, profesor]: materias) {
      std::cout<<materia<<": "<<profesor<<std::endl;
    }
  }

};

int main() {
    Salon s;
    s.agrergarParMateria("Fisica", "Prof. Garcia")
     .agrergarParMateria("Fisica", "Prof. Lopez")
     .agrergarParMateria("Calculo", "Prof. Ruiz")
     .agrergarParMateria("Calculo", "Prof. Torres");

    s.imprimirContenido();

    std::string buscar;
    std::cout << "Buscar materia: ";
    std::cin >> buscar;
    s.profesoresPorMateria(buscar);
    return 0;
}
