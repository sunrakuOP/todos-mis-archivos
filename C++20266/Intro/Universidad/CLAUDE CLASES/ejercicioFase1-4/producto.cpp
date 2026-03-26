#include <iostream>
#include "product.h"
#include "dinero.h"

int Producto::contador = 0; // definir la variable static del .h

Producto::Producto(std::string n, int e, int c, int s): nombre(n), precio(e, c), stock(s), id(contador++) {}

void Producto::vender(int c) {
  if(c < 0) {
    std::cout<<"Cantidad negativa"<<std::endl;
    return;
  }
  if (stock < c) {
    std::cout<<"Stock insuficiente"<<std::endl;
    return;
  } 
  stock -= c;
}

void Producto::reabastecer(int c) {
  if(c < 0) {
    std::cout<<"Cantidad negativa"<<std::endl;
    return;
  }
  stock += c;
}

bool Producto::operator==(const Producto& otro) {
  return (id==otro.id);
}
bool Producto::operator!=(const Producto& otro) {
  return !(*this==otro);   // niega este obj comparado al parametro
}

std::string Producto::getNombre() const { return nombre; }
Dinero Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }
int Producto::getID() const { return id; }

// operador de ostream
std::ostream& operator<<(std::ostream& os, const Producto& obj) {
  os << "Nombre: " << obj.getNombre()
     << "\nPrecio: " << obj.getPrecio()
     << "\nStock: " << obj.getStock()
     << "\nId: " << obj.getID();
  return os;
}