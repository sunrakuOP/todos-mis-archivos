#include <iostream>
#include <vector>

// crear clase matriz que tiene como parametros filas, columnas 
class Matriz {
private:  
  int filas, col;
  std::vector<std::vector<double>> datos;
public: 
  // constructor para crear la matriz
  Matriz (int f, int c) : filas(f), col(c), datos(f, std::vector<double> (c, 0))  {}   // creo el objeto solo con parametros filas y columnas
  ~Matriz() {}

  // constructor de copia
  Matriz(const Matriz& otra) : filas(otra.filas), col(otra.col), datos(otra.datos) {}
  // si paso como referencia otra matriz, se crea un nuevo objeto con valores del objeto a copiar
    // aunque el mismo compilador me lo genera, no es necesario

  // aun la matriz no pide valores pero ahora aprendemos
 

};

int main() {
  Matriz a(3,3); 
  Matriz b(a); // b se crea copiando a a

  Matriz c = a; // con vectores no es necesario usar constructor de copia
    // ni operador de asignacion ni destructor

  return 0;
}