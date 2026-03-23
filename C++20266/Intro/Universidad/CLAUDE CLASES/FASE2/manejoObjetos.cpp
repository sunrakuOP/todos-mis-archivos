#include <iostream>
#include <vector>
#include <string>

// crear clase para ejemplificar
class Vehiculo {
private: 
  std::string marca, modelo;
  int anio, kilometraje;
public: 
  Vehiculo(std::string ma, std::string mo, int a, int km) : marca(ma), modelo(mo), anio(a), kilometraje(km) {}
  ~Vehiculo () {} // no es necesario pero ps aja

  Vehiculo& conducir(int k) {
    kilometraje += k;
    return *this;
  } 

  void mostrarInfo () const {
    std::cout<<"Marca: "<<marca<<std::endl;
    std::cout<<"Modelo: "<<modelo<<std::endl;
    std::cout<<"Anio: "<<anio<<std::endl;
    std::cout<<"Kilometraje: "<<kilometraje<<std::endl;
  }
};

int main() {
  // crear objeto en el stack
  Vehiculo v1("Ford","fiesta", 2000, 0);  
  Vehiculo v2("Nissan","march",2001, 2030);
  // crear objeto en el heap
  Vehiculo* v3 = new Vehiculo("Nissan","Versa", 2020, 1000);
  Vehiculo* v4 = new Vehiculo("Tesla","Model s", 2026, 0);

  // usar metodo de la clase en el objeto
  v1.mostrarInfo();
  v2.mostrarInfo();
  v3->mostrarInfo();    // con puteros se usa esa sintaxis (-> en vez de .)
  v4->mostrarInfo();

  // vector de objetos
  std::vector<Vehiculo> vectorOjetos;
  vectorOjetos.push_back(v1);
  vectorOjetos.push_back(v2);

  for (const auto& v: vectorOjetos) {  // si le pongo el const no puedo modificar, solo leo, no puedo modificar
    v.mostrarInfo();
  }
  for (auto& v: vectorOjetos) {
    v.conducir(1000);
  }

  // vector de punteros a objetos, para objetos creados con el new/delete
  std::vector<Vehiculo*> vectorPunterObj;
    // se incluyen usando el punto
  vectorPunterObj.push_back(v3);
  vectorPunterObj.push_back(v4);

  for(const auto& v: vectorPunterObj) {
    v->mostrarInfo();     // para acceder a los elementos
  }



  // eliminamos la memoria manual en el heap
  delete v3;
  v3 = nullptr;
  delete v4;
  v4 = nullptr;

  return 0;
}
