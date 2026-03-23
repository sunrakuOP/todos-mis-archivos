#include<iostream>

class Buffer {
private:
  int tamanio;
  int* datos; // solo declaro el puntero
public:
  Buffer(int t): tamanio(t) , datos(nullptr) {  // nullptr para direccion vacia inicial
    datos = new int[tamanio]();     // creamos el arreglo dinamico de tamano variable
  }
  ~Buffer() { 
    delete[] datos; 
    datos = nullptr;   // buena practica
  }   // solo es de una dimension

  void pedirDatos() {
    for(int i=0; i < tamanio; i++) {
      std::cout<<"Digite elemento "<<i+1<<": ";
      std::cin>>datos[i];    // igual que *(datos+i)
    }  
    std::cout<<std::endl;
  }

  void mostrarDatos() const {
    std::cout<<"Arreglo dinamico: "<<std::endl;
    for(int i=0; i < tamanio; ++i) {
      std::cout<<datos[i] <<",";
    }
    std::cout<<std::endl;
  }

  // constructor de copia
  Buffer(const Buffer& otro) : tamanio(otro.tamanio), datos(nullptr) {
    // ya copiamos tamanio directamente porque es entero, no puntero
    datos = new int[tamanio]; // creamos el arreglo del otro
    for(int i=0; i < tamanio; ++i) {
      datos[i] = otro.datos[i];  // copiamos uno por uno
    }
  }

  Buffer& operator=(const Buffer& otro) {
    if (this == &otro) {
      return *this;
    }
    delete[] datos;  // eliminar bloque de memoria anterior

    tamanio = otro.tamanio;
    datos = new int[tamanio];
    for(int i=0; i < tamanio; i++) {
      datos[i] = otro.datos[i];
    }
    
  return *this;
  }
  

};

int main() {
  int n;
  std::cout<<"Digite el tamano del vector: "<<std::endl;
  std::cin>>n;

  Buffer v1(n);
  v1.pedirDatos();
  v1.mostrarDatos();

  // probar constructor de copia
  Buffer v2(v1);
  v2.mostrarDatos();

  // probar constructor de asignacion
  Buffer v3(4);
  v3.pedirDatos();
  v3.mostrarDatos();

  v3 = v1;
  v3.mostrarDatos();


  return 0;
}