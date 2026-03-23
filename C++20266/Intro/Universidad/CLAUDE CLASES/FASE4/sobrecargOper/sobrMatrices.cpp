// sobrecarga de operadores usando matrices (mejor sintaxis)
#include <iostream>
#include <vector>

class Matriz {
private: 
  int filas, columnas;
  std::vector<std::vector<double>> datos;
public:
  Matriz(int f, int c): filas(f), columnas(c), datos(f, std::vector<double>(c)) {}

  // operador de llamada
  double&  operator() (int i, int j) {
    return datos.at(i).at(j);
  } // podemos usarlo con matriz directamente pero necesitamos un objeto ya creado

  void pedirValores() {
    for(int i=0; i<filas; i++) {
      for(int j=0; j<columnas; j++) {
        std::cout<<"Digite elemento["<<i+1<<"]["<<j+1<<"]: ";
        std::cin>>datos.at(i).at(j);
      }
    }
    std::cout<<std::endl;
  }
  void mostrarMatriz() const {
    for(int i=0; i<filas; ++i) {
      for(int j=0; i<columnas; ++j) {
        std::cout<<datos.at(i).at(j)<<", ";
      }
      std::cout<<std::endl;
    }
  }

  // operadores aritmeticosn (crean nuevo objeto)
  Matriz operator+(const Matriz& o) const {
    if(filas != o.filas || columnas != o.columnas) {
      std::cout<<"Dimensiones distintas, no se puede operar"<<std::endl;
      // que devuelvo??????
    }
    Matriz result(filas, columnas);
    for(int i=0; i<filas; ++i){
      for(int j=0; j<columnas; ++j) {
        result(i,j) = datos.at(i).at(j) + o.datos.at(i).at(j);
      }
    }
    return result;
  }
  Matriz operator-=(const Matriz& o) {
    if(filas != o.filas || columnas != o.columnas) {
      std::cout<<"Dimensiones distintas, no se puede operar"<<std::endl;
      // que devuelvo??????
    }
    Matriz result(filas, columnas);
    for(int i=0; i<filas; ++i) {
      for(int j=0; j<columnas; ++j) {
        result(i,j) = datos.at(i).at(j) - o.datos.at(i).at(j);
      }
    }
  }
  // mult por un escalar
  Matriz operator*=(double c) {
    Matriz result(filas, columnas);
    for(int i=0; i<filas; ++i) {
      for(int j=0; j<columnas; ++j) {
        result(i,j) = c*datos.at(i).at(j);
      }
    }
    return result;
  }

  // mult de matrices
  Matriz operator*=(const Matriz& o) {
    if(columnas != o.filas) {
      std::cout<<"No se puede operar"<<std::endl;
    }
    Matriz result(filas, columnas);

  }

  bool operator==(const Matriz& o) {
    if (filas != o.filas || columnas != o.columnas) {
      return false;
    }
    for(int i=0; i<filas; ++i){
      for(int j=0; j<columnas; ++j){
        if(datos.at(i).at(j) != o.datos.at(i).at(j)) {
          
        }
      }
    }
    return true; // hacer toda la ruta de posibles fallas, si las pasa todas retorna true
  }



};

int main() {
  
  return 0;
}