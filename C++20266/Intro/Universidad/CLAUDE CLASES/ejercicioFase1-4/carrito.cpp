#include <iostream>
#include <vector>
#include "carrito.h"

void Carrito::agregar(Producto& p, int c) {
  if (c <= 0){
    std::cout<<"Cantidad Invalida"<<std::endl;
    return;
  }
  if(c > p.getStock()) {
    std::cout<<"Cantidad excesde el stock"<<std::endl;
    return;
  }
  productos.push_back(&p);   // agrego referencia al producto que cree
  cantidades.push_back(c);        
  // ambos vectores tienen mismo indice de acceso porque se llenan a la vez
}

Dinero Carrito::total() const {
  Dinero total(0,0); // solo un for porque es el mismo indice
  for(size_t i=0; i<productos.size(); ++i) {
    total += productos.at(i)->getPrecio() * cantidades.at(i);    // como es puntero en vez de . usa ->
  }
  return total;
}

void Carrito::confirmarCompra() { // para descontar del stock del producto
  for(size_t i=0; i < productos.size(); ++i){
    productos.at(i)->vender(cantidades.at(i));
  }
  std::cout<<"Compra confirmada, Total: "<< total() <<std::endl;
}

void Carrito::mostrar() const {
  for(size_t i=0; i<productos.size(); ++i){
    std::cout<<"Producto: "<< productos.at(i)->getNombre() <<"x"<< cantidades.at(i) <<" = "
    << productos.at(i)->getPrecio() * cantidades.at(i) <<std::endl;
  }
  std::cout<<"Total: "<<total()<<std::endl;
}

