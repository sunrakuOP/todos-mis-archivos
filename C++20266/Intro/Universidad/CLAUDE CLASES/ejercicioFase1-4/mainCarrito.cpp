#include <iostream>
#include "carrito.h"
#include "product.h"

int main() {
  Producto p1("Arroz", 4, 50, 10);
  Producto p2("Leche", 3, 20, 8);
  Producto p3("Pan", 1, 75, 20);

  Carrito carrito;
  carrito.agregar(p1, 2);
  carrito.agregar(p2, 1);
  carrito.agregar(p3, 4);

  std::cout << "=== Carrito antes de confirmar ===" << std::endl;
  carrito.mostrar();

  carrito.confirmarCompra();

  std::cout << "\n=== Carrito despues de confirmar ===" << std::endl;
  carrito.mostrar();

  std::cout << "\n=== Stock restante ===" << std::endl;
  std::cout << p1 << std::endl << std::endl;
  std::cout << p2 << std::endl << std::endl;
  std::cout << p3 << std::endl;

  return 0;
}
