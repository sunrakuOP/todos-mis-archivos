#include "autor1.h"
#include <iostream>
#include <string>

Autor::Autor (std::string no, std::string na) : nombre(no), nacionalidad(na) {}
Autor::~Autor() {}

std::string Autor::getNombre() const { return nombre; }
std::string Autor::getNacionalidad() const { return nacionalidad; }

void Autor::mostrarInfo() const {
  std::cout<<"Nombre del autor: "<< nombre <<std::endl
           <<"Nacionalidad del autor: "<< nacionalidad <<std::endl;
}
