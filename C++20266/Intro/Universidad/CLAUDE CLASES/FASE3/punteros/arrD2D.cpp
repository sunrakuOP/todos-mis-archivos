#include <iostream>

int main() {
  int filas = 0, columnas = 0;
  std::cout<<"Digite numero de filas: "<<std::endl;
  std::cin>>filas;
  std::cout<<"Digite numero de columnas: "<<std::endl;
  std::cin>>columnas;

  // crear arreglo de 2 dimensiones (puntero de punteros)
  int** matriz = new int *[filas];   // cada elemento del arreglo es un puntero (que aun no apunta a ningun lado)
  // [puntero0 | puntero1 | puntero2 ....] 

  // ahora hay que darle direcciones a los punteros (decirles donde apuntar)
  for(int i=0; i < filas; ++i) {  // por cada elemento de el arrerglo "matriz" (tamanio filas)
    matriz[i] = new int[columnas]();
    // cada elemento de el 1er arreglo es un puntero que apunta a otro arreglo de tamanio culumnas
      // () es inicializar en 0
  }

  // hacer la eliminacion de las direcciones (delete)              ORDEN DE ELIMINACION AL REVES
  // primero eliminar el 2ndo arreglo. Luego eliminar el arreglo de punteros
  for(int i=0; i < filas; ++i) {
    delete[] matriz[i];
  }
  delete[] matriz;
  

  return 0;
}