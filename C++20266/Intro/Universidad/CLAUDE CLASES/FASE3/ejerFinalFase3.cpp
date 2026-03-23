// clase que simule un vector
#include <iostream>

class MiVector {
private:
  int capacidad, tamano; // tamano es inicial, 
  int* datos;
public:
  MiVector(int c): capacidad(c), tamano(0), datos(nullptr) {
    datos = new int[capacidad];
  }
  ~MiVector() {
    delete [] datos;
  }

  MiVector(const MiVector& otro) : capacidad(otro.capacidad), tamano(otro.tamano), datos(nullptr) {
    datos = new int[capacidad]; // reservo espacio en memoria
    for(int i=0; i < tamano; ++i) {  // hago la copia profunda (elemento por elemento)
      datos[i] = otro.datos[i];
    }
  }

  MiVector& operator=(const MiVector& otro) {
    if(this == &otro) {
      return *this;
    }
    delete[] datos;
    // ahora si toca copiar 
    capacidad = otro.capacidad;
    tamano = otro.tamano;
    datos = new int[capacidad];
    for(int i=0; i < tamano; ++i) {  // hago la copia profunda (elemento por elemento)
      datos[i] = otro.datos[i];
    }
    return *this;
  }

//MOVE SEMANTICS
  // usando rvalue
  MiVector(MiVector&& otro) noexcept : capacidad(otro.capacidad), tamano(otro.tamano), datos(otro.datos) {
    otro.datos = nullptr;
    otro.tamano = 0;
    otro.capacidad = 0;
  } 
  
  MiVector& operator=(MiVector&& otro) noexcept {
    if(this == &otro) {
      return*this;
    }
    delete[] datos;

    capacidad = otro.capacidad;
    tamano = otro.tamano;
    datos = otro.datos;

    otro.datos = nullptr;
    otro.tamano = 0;
    otro.capacidad = 0;

    return *this;
  }

  void pushBack(int valor) {
    if(capacidad == tamano) {
      capacidad *= 2;
      int* nuevo = new int[capacidad]; // genero un nuevo espacio en memoria duplacado
      for(int i=0; i < tamano; ++i) {
        nuevo[i] = datos[i]; // copio los datos pasados en el nuevo arreglo
      }
      delete[] datos; // libero el bloque de memoria viejo
      datos = nuevo; // reasigna
    }
    datos[tamano] = valor;
    tamano++;
  }

  void pedirElementos(int n) {   // saber cuantos elemento vamos a pedir
    for(int i=0; i < n; ++i){
      int valorTemp;
      std::cout<<"Digite el valor"<<i+1<<": ";
      std::cin>>valorTemp;
      pushBack(valorTemp);
    }
  }

  int size() const { return tamano; }
  int capacity() const { return capacidad; }

  int at(int i) const {
    if (i >= tamano || i < 0) {
      std::cout<<"Elemento fuera de rango "<<std::endl;
      return -1;
    }
    std::cout<<"Dato: "<<datos[i]<<std::endl;
    return datos[i];

  }

  void mostrar() const {
    for(int i=0; i < tamano; ++i) {
      std::cout<< datos[i]<<", ";
    }
    std::cout<<std::endl;
  }


};
int main() {
    int n;
    std::cout << "Elementos iniciales: ";
    std::cin >> n;

    MiVector v1(n);
    v1.pedirElementos(n);
    v1.mostrar();

    // copy
    MiVector v2 = v1;
    v2.pushBack(99);
    std::cout << "v1: "; v1.mostrar();  // no cambió
    std::cout << "v2: "; v2.mostrar();  // tiene el 99

    // move
    MiVector v3 = std::move(v1);
    std::cout << "v3: "; v3.mostrar();  // tiene los datos
    std::cout << "v1: "; v1.mostrar();  // vacío
}