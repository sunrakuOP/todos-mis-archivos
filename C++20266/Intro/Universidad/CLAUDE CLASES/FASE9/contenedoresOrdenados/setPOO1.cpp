#include <iostream>
#include <set>
#include <string>

class RedSocial {
protected:
  // gestionar seguidores
  std::set<std::string> seguidores;
public:
  RedSocial() = default;

  RedSocial& agregarSeguidor(const std::string& nombre) {
    if(seguidores.count(nombre)) {
      std::cout<<"Persona ya agregada"<<std::endl;
      return *this;
    }
    seguidores.insert(nombre);
    return *this;
  }

  RedSocial& dejarSeguir(const std::string& nombre) {
    // usar iterador para hacer cambios mientras itero
    auto it = seguidores.find(nombre);
    if(it == seguidores.end()) {
      std::cout<<"Persona no esta en tus seguidores"<<std::endl;
      return *this;
    }
    seguidores.erase(it);  // erase o remove????
    return *this;
  }

  void mostrar() const {
    if(seguidores.empty()) {
      std::cout<<"Lista de seguidores vacia.."<<std::endl;
      return;
    }
    std::cout<<"Seguidores: "<<std::endl;
    for(const auto& s: seguidores) {
      std::cout<<s<<", ";
    }
    std::cout<<std::endl;
  }



};

int main() {
    RedSocial r;
    r.agregarSeguidor("Ana")
     .agregarSeguidor("Luis")
     .agregarSeguidor("Mia")
     .agregarSeguidor("Ana");  // ya existe
    r.mostrar();
    r.dejarSeguir("Luis");
    r.mostrar();
    return 0;
}


