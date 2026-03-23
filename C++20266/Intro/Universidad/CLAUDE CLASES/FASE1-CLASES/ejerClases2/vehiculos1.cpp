#include "vehiculos1.h"
#include <iostream>

int Vehiculo::contador = 0;

Vehiculo::Vehiculo(const std::string& m, const std::string& mo, int a, int km) : marca(m), modelo(mo), anio(a), kilometraje (km), id(++contador) {}
Vehiculo::~Vehiculo() {}

Vehiculo& Vehiculo::conducir(int km) {
  if (km <= 0) {
    std::cout<<"Km no puede ser negativo";
    return *this;   // retorna objeto aunque falle
  }
  kilometraje += km;
  return *this;
}

std::string Vehiculo::getMarca() const {
  return marca;
}

std::string Vehiculo::getModelo() const {
  return modelo;
}

int Vehiculo::getAnio() const {
  return anio;
}

int Vehiculo::getKilometraje() const {
  return kilometraje;
}

int Vehiculo::getId() const {
  return id;
}

void Vehiculo::mostrarInfo() const {
  std::cout<<"Marca: "<< marca <<std::endl;
  std::cout<<"Modelo: "<< modelo <<std::endl;
  std::cout<<"Anio: "<< anio <<std::endl;
  std::cout<<"Kilometraje: "<< kilometraje <<std::endl;
  std::cout<<"Id: "<< id <<std::endl;
}

