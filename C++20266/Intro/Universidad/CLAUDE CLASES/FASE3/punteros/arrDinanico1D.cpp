#include <iostream>

int main() {
  int n;
  std::cout<<"Digite el tamano del arreglo dinamico: "<<std::endl;
  std::cin>>n;
  // crear arreglo dinamico usando new int (hacer uso del heap y manipular memoria manualmente)

  int *arreglo = new int[n];  // arreglo de tamano dinamico (resevera bloque de memoria de tamano n en el heap)

  // pedir arreglo
  for(int i=0; i < n; ++i) {
    std::cout<<"Digite elemento "<<i+1<<":";
    std::cin>>arreglo[i];
  }
  std::cout<<std::endl;
  // mostrar arreglo
  std::cout<<"Mostrarlo usando sintaxis"<<std::endl;
  for(int i=0; i < n; ++i) {
    std::cout<< arreglo[i] <<", ";  // mostrarlo usando acceso al arreglo
  }
  std::cout<<"Mostrarlo desreferenciando el puntero"<<std::endl;
  for(int i=0; i < n; ++i) {
    std::cout<< *(arreglo+i) <<",";   // mostrarlo desreferenciando 
  }

  // borrar memoria manualmente
  delete[] arreglo;
  arreglo = nullptr;



  return 0;
}