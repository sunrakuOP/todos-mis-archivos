#include <iostream>

int main() {
  /*
  int a = 42;
  int *p = &a;


  std::cout<<"Puntero a a (direccion): "<< p <<std::endl;
  std::cout<<"Valor del puntero igual que el de variable: "<< *p <<std::endl;
  */

  // inicializacion de punteros (QUE NO APUNTE A NADA)
  int *x = nullptr;
  std::cout<<"Puntero que no apunta a nada: "<< x <<std::endl;

  // aritmetica de punteros
    // ARREGLOS
  int arreglo[] = {1,2,3,4,5,6,7};
  int *b = arreglo;  // puntero apunta a direccion de memoria del 1er elemento
  
  // (p+1) muestra direccion del segundo elemento
  // *(p+1) muestra el valor del segundo elemento
  std::cout<<"Direccion 2ndo elemento: "<< b+1 <<std::endl;
  std::cout<<"Valor del segundoe elemento: "<< *(b+1) <<std::endl;

  // RECORDAR QUE LOS PUNTEROS RECORREN USANDO BYTES NO ELEMENTOS
  int n = sizeof(arreglo) / sizeof(arreglo[0]);   // tamano en bytes total / tamano de un elemento

  for (int *p = arreglo; p < arreglo + n; ++p) {
    std::cout<< p <<std::endl;
    std::cout<< *p <<std::endl;
  }

  


  return 0;
}