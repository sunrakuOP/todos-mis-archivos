#pragma once
#include "autor1.h"
#include <string>

class Libro {
private:  // recordar que al definir se debe seguir el mismo orden que en la declaracion
  std::string titulo;
  int anio, stock, id;
  double precio;
  static int contador;

  Autor autor;
public:
  Libro(std::string t, int an, int s, double p, std::string no, std::string na);
  ~Libro();

  std::string getTitulo() const; 
  int getAnio() const;
  int getStock() const;
  int getId() const;
  double getPrecio() const;

  int vender(int c);
  int reabastecer(int c);

  void mostrarInfoLibro() const;
};