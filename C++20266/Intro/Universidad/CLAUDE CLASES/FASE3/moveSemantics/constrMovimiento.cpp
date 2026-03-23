#include <iostream>

class Imagen {
private: 
  int **pixeles;
  int alto, ancho;
public: 
  Imagen(int al, int an) : alto(al), ancho(an), pixeles(nullptr) {
    pixeles = new int*[alto];   // recordar que es un puntero de punteros 
    for(int i=0; i < alto; ++i) {
      pixeles[i] = new int[ancho]();  // a cada elemento de el arreglo de punteros le asignamos un arreglo
    } 
  }
  ~Imagen() {
    for(int i=0; i < alto; ++i) {
      delete[] pixeles[i];
    }
    delete[] pixeles;
  }
  //constructor de copia- COPIA LOS DATOS (AL FINAL QUEDAN DOS OBJETOS COMPLETAMENTE IGUALES)
  // Con Lvalue reference
  Imagen(const Imagen& otro) : alto(otro.alto), ancho(otro.ancho), pixeles(nullptr) {  // se inicialliza a vacio y luego se llena    
    // siempre hay que reservar el bloque en memoria para la copia
    pixeles = new int*[alto];    // reservamos espacio de filas
    for(int i=0; i<alto; ++i) {
      pixeles[i] = new int[ancho];  // reservamos el espacio de memoria de columnas
      for(int j=0; j < ancho; ++j) {
        pixeles[i][j] = otro.pixeles[i][j];
      }
    }
  }

  // operador de asignacion
  Imagen& operator=(const Imagen& otro) {
    // comprobar que no se refieran al mismo objeto
    if(this == &otro) {
      return *this;
    }
    // borra informacion pasada 
    for(int i=0; i<alto; ++i) {
      delete[] pixeles[i];
    }
    delete[] pixeles;
    // copiar todo
    alto = otro.alto;
    ancho = otro.ancho;
    pixeles = new int*[alto];
    for(int i=0; i < alto; ++i) {
      pixeles[i] = new int[ancho];
      for(int j=0; j < ancho; ++j) {
        pixeles[i][j] = otro.pixeles[i][j];
      }
    }
  }

  // constructor de movimiento (PARECIDO AL DE COPIA PERO PASANDO DATOS EN VEZ DE COPIARLOS), queda un objeto lleno y el otro vacio
    // en los de copia se hace paso por referencia(&)  LVALUE
    // en move se pasa por (&&)  RVALUE, sin el const
  Imagen(Imagen&& otro) noexcept : alto(otro.alto), ancho(otro.ancho), pixeles(otro.pixeles) {  // robamos los datos
    // se usa rvalue && del otro objeto
    // ahora dejamos los datos del otro en 0 en el orden inverso
    otro.pixeles = nullptr;
    otro.ancho = 0;
    otro.alto = 0;
  }

  // operador de asignacion por movimiento,   al inicio es igual, confirmar que no sea mismo objeto, y liberar memoria del objeto anterior
  Imagen& operator=(Imagen&& otro) noexcept {
    if(this == &otro) {
      return *this;
    }
    for(int i=0; i<alto; ++i){
      delete[] pixeles[i];
    }
    delete[] pixeles;

    // ahora copiamos los datos y luego dejamos los otros en 0
    alto = otro.alto;
    ancho = otro.ancho;
    pixeles = otro.pixeles;

    otro.pixeles = nullptr;
    otro.ancho = 0; 
    otro.alto = 0;

    return *this; 
  }

   
    
};

int main() {

  return 0;
}