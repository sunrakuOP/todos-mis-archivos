#include <iostream>
#include <string>
#include <vector>

// objeto matriz
class Matriz {
private:
  int filas, columnas;
  std::vector<std::vector<double>> datos;
public:
  Matriz(int f, int c) : filas(f), columnas(c), datos(f, std::vector<double> (c)) {} 
  ~Matriz () {}

  void pedirMatriz() {
    std::cout<<"Matriz "<<filas<<"x"<<columnas<<std::endl;
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; j++) {
        std::cout<<"Digite elemento fila"<<i+1<<" columna "<<j+1<<": ";
        std::cin>>datos.at(i).at(j);
      }
    }
  }
  void mostrarMatriz() const {
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; j++) {
        std::cout<< datos.at(i).at(j)<<", "; 
      }
      std::cout<<std::endl;
    }
  }

  // para poder acceder a los elementos y modificarlos en el sistema
  double getDato(int f, int c) {
    return datos.at(f).at(c);
  }

  void setDato(int f, int c, double dato) {
    datos.at(f).at(c) = dato;
  }
  

};

// clase Sistema Lineal que contiene Matrices
class SistemaLineal {
private:
  int num;
  Matriz A, x, b;  // crear 3 objetos (matrices)
public:
  SistemaLineal(int n) : num(n), A(n, n), x(n, 1), b(n, 1) {}  // respetar el numero de parametros
  ~SistemaLineal() {}

  void pedirSistema() {
    std::cout<<"Digite matriz de coef: "<<std::endl;
    A.pedirMatriz();
    std::cout<<"Digite vector de resultados: "<<std::endl;
    b.pedirMatriz();
  }

  Matriz aumentada() {
    Matriz aumentada(num, num+1);
    
    for(int i=0; i < num; ++i) {
      for(int j=0; j < num; ++j) {
        aumentada.setDato(i,j, A.getDato(i,j));    // busco el elemento en A con el getter y lo seteo con el setter (metodos de la matriz)
      }
    }
    for(int i=0; i < num; ++i) {
        aumentada.setDato(i,num, b.getDato(i, 0));
    }
    return aumentada;
  }

};

int main() {
  /*
  Matriz m1(3,3);
  m1.pedirMatriz();
  m1.mostrarMatriz();
  */

  SistemaLineal s1(3);
  s1.pedirSistema();
  s1.aumentada().mostrarMatriz();   // como retorna objeto tipo matriz puedo aplicarle metodo directamente

  return 0;
}