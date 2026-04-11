/*
teoria del contenedor set

contenedor como map que almacena claves y no permite valores repetidos
los ordena en orden automaticos
*/
#include <iostream>
#include <vector>
#include <set>

int main() {    
  std::vector<int> numeros =  {4, 2, 7, 2, 9, 4, 1, 7, 3};
  // crear un set vacio
  std::set<int> unicos;

  for(const auto& n: numeros) {
    unicos.insert(n); // recorre el vector y anade a set, si es repetido lo ignora
  }
  // recorrer y mostrar ambos conjuntos
  std::cout<<"Vector incial: "<<std::endl;
  for(const auto& n: numeros){
    std::cout<<n<<", ";
  }
  std::cout<<std::endl;
  std::cout<<"Set final: "<<std::endl;
  for(const auto& n : unicos) {
    std::cout<<n<<", ";
  }






  return 0;
}