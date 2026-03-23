#include <iostream>
#include <vector>
#include "libro1.h"
#include "autor1.h"

void mostrarCatalogo(const std::vector<Libro>& catalogo) {
  for(const auto& l: catalogo) {
    l.mostrarInfoLibro();
  }
}

Libro& getMasVendido(std::vector<Libro>& catalogo) {
  int menorStock = catalogo.at(0).getStock();
  int indice = 0;
  for(int i=1; i < catalogo.size(); ++i) {
    if(catalogo.at(i).getStock() < menorStock){
      menorStock = catalogo.at(i).getStock();
      indice = i;
    }
  }
  return catalogo.at(indice);
}

int main() {
  // crear un catalogo de libros
  std::vector<Libro> catalogo;


  catalogo.push_back(Libro("Cien años de soledad", 1967, 10, 25000,
                            "Gabriel García Márquez", "Colombiano"));
  catalogo.push_back(Libro("El tunel",             1948,  5, 18000,
                            "Ernesto Sabato",        "Argentino"));
  catalogo.push_back(Libro("Rayuela",              1963,  8, 22000,
                            "Julio Cortázar",        "Argentino"));

  mostrarCatalogo(catalogo);

  // Vender
  catalogo[0].vender(4);
  catalogo[1].vender(3);

  // Reabastecer
  catalogo[2].reabastecer(10);

  std::cout << "=== Despues de operaciones ===\n\n";
  mostrarCatalogo(catalogo);

  // El más vendido
  Libro& masVendido = getMasVendido(catalogo);
  std::cout << "=== Mas vendido ===\n";
  masVendido.mostrarInfoLibro();


  return 0;
}