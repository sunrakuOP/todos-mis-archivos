#pragma once
#include <string>
#include "dinero.h"

class Producto {
private:
  std::string nombre;
  Dinero precio; // composicion de clases
  int stock, id;
  static int contador;
public:
  Producto(std::string n, int e, int c, int s);   // en constructor de composicion se ponen atributos del objeto compuesto
  
  void vender(int c);
  
  void reabastecer(int c);

  bool operator==(const Producto& otro); // operador de comparacion
  bool operator!=(const Producto& otro); // deben ir ambos juntos

  friend std::ostream& operator<<(std::ostream& os, const Producto& obj); // operador de ostream para imprimir el producto

  std::string getNombre() const;
  Dinero getPrecio() const;
  int getStock() const;
  int getID() const;


};