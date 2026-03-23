#include "estudiante.h"
#include <stdexcept>

// :: operador de resolucion de scope, le dice de que clase es el metodo
  // igual a definir metodos fuera de las clases


Estudiante::Estudiante(std::string n, int e) 
  : nombre(n), edad(e) {}

Estudiante::~Estudiante() {}

void Estudiante::agregarNota(double nota) {  // hay que dar el tipo de dato de retorno del metodo antes de Clase
  if (nota < 0 || nota > 5.0) {
    throw std::invalid_argument("Nota invalida");   // throw va a la funcion, try excpept va al main
  }
  notas.push_back(nota);
}

double Estudiante::calcularPromedio() const {
  if (notas.empty()) {
    return 0;
  }
  double suma = 0;
  for (const auto& nota: notas) {
    suma += nota;
  }
  return suma / notas.size();
}

bool Estudiante::aprobo() const {
  return calcularPromedio() >= 3.0;
}

std::string Estudiante::getNombre() const {
  return nombre;
}
int Estudiante::getEdad() const {
  return edad;
}

// cual es el uso del const despues del ()  no recuerdo
  // no olvidar usar el const y el auto en parametros 