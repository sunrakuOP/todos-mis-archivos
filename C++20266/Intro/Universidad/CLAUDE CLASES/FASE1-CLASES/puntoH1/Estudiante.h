#pragma once // evitar incluir el header mas de una vez

#include <string>
#include <vector>

class Estudiante {
private:
  std::string nombre;
  int edad;
  std::vector<double> notas;

public: 
  // solo declarar, no definir las funciones (eso se hace en el .cpp)
    // constructor y destructor
  Estudiante(std::string n, int edad);
  ~Estudiante();

  void agregarNota(double nota);
  double calcularPromedio() const;
  bool aprobo() const;

  std::string getNombre() const;
  int getEdad() const;

};