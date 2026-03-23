#include <iostream>
#include <vector>

int main() {
  int filas, columnas;
  std::cout<<"Digite numero de filas: "<<std::endl;
  std::cin>>filas;
  std::cout<<"Digite numero: "<<std::endl;
  std::cin>>columnas;

  // crear arreglo dinamico
  int **matriz = new int *[filas];  // crear una matrz de punteros, y cada puntero apunta a una fila
  for(int i=0; i<filas; ++i) {
    matriz[i] = new int[columnas];
  }

  for (int i=0; i<filas; ++i) {
    for (int j=0; j < columnas; ++j) {
      std::cout<<"Digite elemento fila "<<i+1<<" columna "<<j+1<<": "<<std::endl;
      std::cin>>matriz[i][j];
    }
  }
  // recorrer matriz y mostrarla
  for (int i=0; i < filas; ++i) {
    for(int j=0; j < columnas; ++j) {
      std::cout<< matriz[i][j] <<", ";
    }
    std::cout<<std::endl;
  }

  // como usamos new, eliminar memoria nosotros 
    // orden inverso ELIMINAR (1. matriz dentro filas , 2. Punteros)
  
  for(int i=0; i< filas; ++i) {
    delete [] matriz[i];
  }

  delete [] matriz;
  matriz = nullptr;

  return 0;
}