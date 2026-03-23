#include <iostream>
#include <vector>

// primero hacerlo con vector, luego con arrays para practicar manejo de memoria
class Buffer {
private:
  int tamanio;
  std::vector<double> datos;
public:
  Buffer(int t) : tamanio(t), datos(t) {}
  ~Buffer() {}  // se hace automatico, no debo hacerlo ni copy no assignment con vectores

  Buffer(const Buffer& otro) {
    tamanio = otro.tamanio;
    datos = otro.datos;
  }

  void pedirDatos() {
    for(int i=0; i < tamanio; ++i) {
      std::cout<<"Digite elemento "<<i+1<<": ";
    std::cin>>datos.at(i);
    }
  }

  double getDato(int indice) { return datos.at(indice); }

  Buffer& setDato(int indice, double valor) {
    datos.at(indice) = valor;
    return *this;
  }

  Buffer& operator=(const Buffer& otro) {   // comprobar que no se este copiando el mismo objeto 
    // debe copiar todos los atributos
    if (this == &otro) {
      return *this;
    }
    tamanio = otro.tamanio;
    datos = otro.datos;
    return *this;
  } 

  void mostrarVector() const {
    for(const auto& dato: datos) {
      std::cout<< dato <<", ";
    }
  }


};

int main() {
  Buffer obj1(5);
  obj1.pedirDatos();
  std::cout << "obj1: "; obj1.mostrarVector(); std::cout << std::endl;

  // constructor de copia
  Buffer obj2 = obj1;
  std::cout << "obj2 (copia de obj1): "; obj2.mostrarVector(); std::cout << std::endl;

  // operador de asignación
  Buffer obj3(5);
  obj3 = obj1;
  std::cout << "obj3 (asignado de obj1): "; obj3.mostrarVector(); std::cout << std::endl;

  // verificar independencia — modificar obj2 no afecta obj1
  obj2.setDato(0, 999);
  std::cout << "obj1 después de modificar obj2: "; obj1.mostrarVector(); std::cout << std::endl;
  std::cout << "obj2 modificado: "; obj2.mostrarVector(); std::cout << std::endl;

  return 0;
}