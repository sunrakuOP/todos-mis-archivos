#include <iostream>
#include "Estudiante.h"

int main() {
  Estudiante e1("Nicolas", 23);  // hacemos uso del constructor para inicializar
  // e1 es un objeto de clase estudiante
  e1.agregarNota(4.6);
  e1.agregarNota(3.4);
  e1.agregarNota(5.0);

  std::cout<<e1.getNombre() <<std::endl;
  std::cout<< e1.getEdad() <<std::endl;
  std::cout<<"Promedio: "<< e1.calcularPromedio() <<std::endl;
  std::cout << (e1.aprobo() ? "Aprobo" : "Reprobo") <<std::endl;
  /* 
  Misma sintaxis que:
  if (e1.aprobo()) {
    std::cout<< "Aprobo "<<std::endl;
  } 
    else {
    std::cout <<"No aprobo"<<std::endl;
    }
  
    Solo para elegir entre dos posibles casos   (?)
  */

  return 0;
}