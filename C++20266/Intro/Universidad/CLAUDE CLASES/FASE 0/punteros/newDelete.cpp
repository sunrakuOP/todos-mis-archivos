#include <iostream>

int main(){

  // pedimos el numero de elementos para el arreglo
  int n;
  std::cout<<"Digite el tamano del arreglo: "<<std::endl;
  std::cin>>n;
  // creamos el arreglo con memoria dinamica
  int *arr = new int[n]{};          // si no usamos delete no se termina nunca el ciclo

  for(int i=0; i < n; ++i) {
    std::cout<<"Digite elemento "<<i+1<<": ";
    std::cin>> arr[i];
  }  // pedimos el arreglo dinamico

  for(int i=0; i < n; ++i) {
    std::cout<< arr[0] <<", ";
  } // mostramos el arreglo

  // debemos de olvidar la variable porque sino el bucle sigue hasta que se llene el heap (ram)
  delete [] arr;
  arr = nullptr;  


  return 0;
}