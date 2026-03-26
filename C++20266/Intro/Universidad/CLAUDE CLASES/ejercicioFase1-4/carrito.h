#pragma once 

#include "product.h"
#include "dinero.h"
#include <vector>

class Carrito {
private:
// el carrito se compone de dos vectores, uno de Productos* y el otro de cantidades
  std::vector<Producto*> productos;   // vector de puntero a producto
  std::vector<int> cantidades;
public:
  void agregar(Producto& p, int c);

  Dinero total() const;
  void confirmarCompra();
  void mostrar() const;
}; 