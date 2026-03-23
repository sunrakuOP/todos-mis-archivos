// crear clase de 2D usando apuntadores (sin usar vectores)
#include <iostream>

class Tablero {
private: 
  int filas, columnas;
  int** celdas;
public:
  Tablero(int f, int c) : filas(f), columnas(c), celdas(nullptr) {
    celdas = new int *[filas];  // defino el primer arreglo de punteros
    for(int i=0; i < filas; ++i) {
      celdas[i] = new int[columnas]();  // cada puntero apunta a un arreglo (cada uno representa filas)
    }
  }
  ~Tablero() {
    for(int i=0; i < filas; ++i) {   // primero elimino los arreglos interiores
      delete[] celdas[i];
    }
    delete[] celdas; // despues elimino el primer arreglo de punteros
  }
  // cosntructor de copia
  Tablero(const Tablero& otro): filas(otro.filas), columnas(otro.columnas), celdas(nullptr) {
    
    celdas = new int*[filas];   // creo un nuevo bloque de memoria para la copia (propio)
    for(int i=0; i < filas; ++i) {
      celdas[i] = new int[columnas]; // ya copie el primer arreglo
      for(int j=0; j < columnas; ++j) {
        celdas[i][j] = otro.celdas[i][j];   // ahora copio elemento por elemento
      }
    }
  }

  // operador de asignacion
  Tablero& operator=(const Tablero& otro) {  // debo eliminar la informacion del elemento anterior que va a ser copiado
    // siempre comprobar que el elemento no es el mismo anterior
    if (this == &otro) {
      return *this;
    }
    // eliminar la informacion del objeto anterior
    for(int i=0; i < filas; i++) {
      delete[] celdas[i];
    }
    delete[] celdas;

    // hacer la copia
    filas = otro.filas;
    columnas = otro.columnas;
    celdas = new int*[filas]; // creamos bloque en memoeria
    for(int i=0; i < filas; ++i) {
      celdas[i] = new int[columnas];
      for(int j=0; j < columnas; ++j) {
        celdas[i][j] = otro.celdas[i][j];
      }
    } // dos loops porque es en dos dimensiones

    return *this;
  }
  void pedirValores() {
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; ++j) {
        std::cout<<"Digite elemento ["<<i+1<<"]["<<j+1<<"]: ";
        std::cin>>celdas[i][j];
      }
    }
    std::cout<<std::endl;
  }

  void mostrarValores() const {
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; ++j) {
        std::cout<< celdas[i][j]<<", ";
      }
      std::cout<<std::endl;
    }
  }


};

int main() {
  int filas, columnas;
  std::cout<<"Digite numero de filas: "<<std::endl;
  std::cin>>filas;
  std::cout<<"Digite numero de columnas: "<<std::endl;
  std::cin>>columnas;

  Tablero c1(filas, columnas);
  c1.pedirValores();
  c1.mostrarValores();



  return 0;
}