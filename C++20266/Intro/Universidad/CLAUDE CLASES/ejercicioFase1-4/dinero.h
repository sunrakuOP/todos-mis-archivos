#pragma once
#include <iostream>

class Dinero {
private: 
  int enteros, centavos;
public: 
  Dinero(int e=0, int c=0);

  void simplificar();

  // tengo que definir operaciones que pueden hacer mis objetos con otro tipo de datos
  Dinero operator+(const Dinero& otro) const;
  Dinero& operator+=(const Dinero& otro);
  Dinero operator*(int c) const; 

  friend std::istream& operator>>(std::istream& is, Dinero& obj);
  friend std::ostream& operator<<(std::ostream& os, const Dinero& obj);
};