#pragma once
#include <string>

class Vehiculo {
private: 
  std::string marca, modelo;
  int anio, kilometraje;
  int id;
  static int contador;

public:
  explicit Vehiculo(const std::string& m, const std::string& mo, int a, int k);
  ~Vehiculo();

  Vehiculo& conducir(int km);
  void mostrarInfo() const;

  std::string getMarca() const;
  std::string getModelo() const;
  int getAnio() const;
  int getKilometraje() const;
  int getId() const;
};

