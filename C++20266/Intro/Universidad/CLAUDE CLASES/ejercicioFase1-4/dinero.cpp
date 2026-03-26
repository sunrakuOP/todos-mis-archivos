#include "dinero.h"
#include <iostream>

std::istream& operator>>(std::istream& is, Dinero& obj) {
  is >> obj.enteros >> obj.centavos;
  obj.simplificar();
  return is;
} // ahora cuando se digite en pantalla el >> separa en dos variables

std::ostream& operator<<(std::ostream& os, const Dinero& obj) {
  os << "$" << obj.enteros << ".";
  if (obj.centavos < 10) {
    os << "0";
  }
  os << obj.centavos;
  return os;
}

void Dinero::simplificar() {
  if (centavos>=100) {
    enteros += centavos / 100;
    centavos = centavos % 100;
  }
}

Dinero::Dinero(int e, int c): enteros(e), centavos(c) {
  if(enteros < 0 || centavos < 0) {
    std::cout<<"Valor invalido"<<std::endl;
    enteros = 0;
    centavos = 0;
    return;
  }
  simplificar();
}

// puedo sumar tipos dinero
Dinero Dinero::operator+(const Dinero& otro) const {
  Dinero resultado(enteros+otro.enteros, centavos+otro.centavos);
  resultado.simplificar();
  return resultado;
}

Dinero& Dinero::operator+=(const Dinero& otro) {
  enteros += otro.enteros;
  centavos += otro.centavos;
  simplificar();
  return *this;
}

// dinero puede operar con cantidades enteras
Dinero Dinero::operator*(int c) const {
  if (c <= 0) {
    return Dinero(0, 0);
  }
  Dinero resultado(c * enteros, c * centavos);
  resultado.simplificar();
  return resultado;
}

