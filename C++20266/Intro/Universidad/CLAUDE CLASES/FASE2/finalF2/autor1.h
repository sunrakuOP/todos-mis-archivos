#pragma once

#include <string>

class Autor {
private: 
  std::string nombre, nacionalidad;
public: 
// aca solo declaramos los metodos
  Autor(std::string no, std::string na);
  ~Autor (); 

  std::string getNombre() const;
  std::string getNacionalidad() const;

  void mostrarInfo() const;
};