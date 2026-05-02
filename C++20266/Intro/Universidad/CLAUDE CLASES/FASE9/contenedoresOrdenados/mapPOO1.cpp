// ejercicio para practicar map
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class Biblioteca {
protected:  
  std::map<std::string, int> libros; // clave es titulo, stock el valor;
  std::vector<std::pair<std::string, int>> vector;
public:
    Biblioteca() = default;

    // el mismo map gestiona y organiza alfabeticamente los libros (sin permitir copias)
    
    Biblioteca& agregarLibro(const std::string& titulo, int cantidad) {
      if(libros.count(titulo)) {
        std::cout<<"Libro ya agregado, solo adicionar cantidad"<<std::endl;
        libros[titulo] += cantidad;
        return *this;
      }
      libros.insert({titulo,cantidad});
      return *this;
    }

    Biblioteca& prestar(const std::string& titulo, int cantidad) {
      if(!libros.count(titulo)) {
        std::cout<<"Libro no agregado, imposible prestar"<<std::endl;
        return *this;
      }
      if(libros[titulo] < cantidad) {
        std::cout<<"Cantidad insuficiente..."<<std::endl;
        return *this;
      }
      libros[titulo] -= cantidad;
      return *this;
    }

    void mostrar() const {
      if(libros.empty()) {
        std::cout<<"Biblioteca vacia"<<std::endl;
        return;
      }
      std::cout<<"Biblioteca: "<<std::endl;
      for(const auto&[libro, cantidad]: libros) {
        std::cout<<"Titulo: "<<libro<<", stock: "<<cantidad<<std::endl;
      }
    }

  void mostrarOrdenado() {
      if(libros.empty()) {
        return; }
      
      std::vector<std::pair<std::string,int>> vec;  // local, se crea fresco cada vez
      for(const auto& [titulo, cantidad]: libros) {
          vec.push_back({titulo, cantidad});
      }
      std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
          return a.second < b.second;
      });
  }


};

int main() {
    Biblioteca b;
    b.agregarLibro("Clean Code", 3)
     .agregarLibro("C++ Primer", 2)
     .agregarLibro("Clean Code", 1);  // suma stock
    b.prestar("Clean Code", 2);
    b.mostrar();
    return 0;
}
