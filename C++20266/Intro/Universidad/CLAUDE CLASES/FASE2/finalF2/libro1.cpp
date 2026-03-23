#include "libro1.h"
#include "autor1.h"
#include <iostream>
#include <string>

int Libro::contador = 0; // inicializo el contador a 0

Libro::Libro(std::string t, int an, int s, double p, std::string no, std::string na) : titulo(t), anio(an), stock(s), id(++contador), precio(p), autor(no, na) {}
// incializamos el autor de una 
Libro::~Libro() {}

std::string Libro::getTitulo() const { return titulo; }
int Libro::getAnio() const { return anio; }
int Libro::getStock() const { return stock; }
int Libro::getId() const { return id; }
double Libro::getPrecio() const { return precio; }

int Libro::vender(int c) {
  if (c > stock) {
    std::cout<<"Cantidad mayor al stock"<<std::endl;
    return 1;
  }
  stock -= c;
  return stock;
}
int Libro::reabastecer(int c) {
  stock += c;
  return stock;
}

void Libro::mostrarInfoLibro() const {
  std::cout<<"Titulo: "<<titulo<<std::endl
           <<"Anio de publicacion: "<<anio<<std::endl
           <<"Stock del libro: "<<stock<<std::endl
           <<"Id: "<<id<<std::endl
           <<"Precio: "<<precio<<std::endl;
  autor.mostrarInfo();
}