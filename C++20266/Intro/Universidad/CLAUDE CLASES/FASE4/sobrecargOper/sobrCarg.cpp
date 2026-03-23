#include <iostream>
#include <vector>
// sobrecarga de operadores
  // cambiarle el uso a los operadores, asignandoles uno nuevo

class Matriz {
private:
  int filas, columnas;
  std::vector<std::vector<double>> datos;
private:
  Matriz(int f, int c): filas(f), columnas(c), datos(f, std::vector<double>(c)) {}
  ~Matriz() {}

  void pedirDatos() {
    for(int i=0; i<filas; ++i) {
      for(int j=0;j<columnas; ++j) {
        std::cout<<"Digite dato["<<i+1<<"]["<<j+1<<"]: ";
        std::cin>>datos.at(i).at(j);
      }
    }
    std::cout<<std::endl;
  }

  // sobrecargar el operador de suma,             1. DENTRO DE LA CLASE
 

};

int main() {

  return 0;
}