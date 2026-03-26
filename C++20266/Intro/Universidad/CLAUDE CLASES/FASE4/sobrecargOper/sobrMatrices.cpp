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
      for(int j=0; j<columnas; ++j) {
        std::cout<<datos.at(i).at(j)<<", ";
      }
      std::cout<<std::endl;
    }
  }

  // operadores aritmeticosn (crean nuevo objeto)
  Matriz operator+(const Matriz& o) const {
    if(filas != o.filas || columnas != o.columnas) {
      std::cout<<"Dimensiones distintas, no se puede operar"<<std::endl;
      // que devuelvo??????    devolver el mismo objeto
      return *this;
    }
    Matriz result(filas, columnas);
    for(int i=0; i<filas; ++i){
      for(int j=0; j<columnas; ++j) {
        result(i,j) = datos.at(i).at(j) + o.datos.at(i).at(j);
      }
    }
    return result;
  }
  Matriz operator-(const Matriz& o) {
    if(filas != o.filas || columnas != o.columnas) {
      std::cout<<"Dimensiones distintas, no se puede operar"<<std::endl;
      // que devuelvo??????
      return *this;
    }
    Matriz result(filas, columnas);
    for(int i=0; i<filas; ++i) {
      for(int j=0; j<columnas; ++j) {
        result(i,j) = datos.at(i).at(j) - o.datos.at(i).at(j);
      }
    }
    return result;
  }
  // mult por un escalar
  Matriz operator*(double c) {
    Matriz result(filas, columnas);
    for(int i=0; i<filas; ++i) {
      for(int j=0; j<columnas; ++j) {
        result(i,j) = c*datos.at(i).at(j);
      }
    }
    return result;
  }

  // mult de matrices
  Matriz operator*(const Matriz& o) {
    if(columnas != o.filas) {
      std::cout<<"No se puede operar"<<std::endl;
      return *this;
    }
    Matriz result(filas, o.columnas);
    for(int i=0; i<filas; ++i){
      for(int j=0; j<columnas; ++j){
        for(int k=0; k<columnas;++k) {
          result(i,j) += datos.at(i).at(k)*o.datos.at(k).at(j);
        }
      }
    }
    return result;
  }

  bool operator==(const Matriz& o) {
    if (filas != o.filas || columnas != o.columnas) {
      return false;
    }
    for(int i=0; i<filas; ++i){
      for(int j=0; j<columnas; ++j){
        if(datos.at(i).at(j) != o.datos.at(i).at(j)) {
          return false;
        }
      }
    }
    return true; // hacer toda la ruta de posibles fallas, si las pasa todas retorna true
  }

  friend std::ostream& operator<<(std::ostream& os, const Matriz& obj) {
    for(int i=0; i < obj.filas; ++i) {
      for(int j=0; j < obj.columnas; ++j) {
        os<< obj.datos.at(i).at(j)<< ", ";
      }
      os <<std::endl;  // usar el stream que recibi, asi puedo imprimir matrices directamente (practicar usarlo en mis ejercicios de matrices)
    }
    return os;
  }


};

int main() {
    Matriz A(2, 2);
    A(0,0)=1; A(0,1)=2;
    A(1,0)=3; A(1,1)=4;

    Matriz B(2, 2);
    B(0,0)=5; B(0,1)=6;
    B(1,0)=7; B(1,1)=8;

    std::cout << "A:" << std::endl << A;   // puedo imprimri directamente la matriz sin necesitar mostrar matriz
    std::cout << "A+B:" << std::endl << A+B;
    std::cout << "A-B:" << std::endl << A-B;
    std::cout << "A*B:" << std::endl << A*B;
    std::cout << "A*2:" << std::endl << A*2.0;
    std::cout << "A==B: " << (A==B) << std::endl;

    return 0;
}