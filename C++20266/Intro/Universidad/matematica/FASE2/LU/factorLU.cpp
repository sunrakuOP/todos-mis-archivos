#include <iostream>
#include <vector>

class Matriz{
private:
  int filas, columnas; 
  std::vector<std::vector<double>> datos;
public:
  Matriz(int f, int c): filas(f), columnas(c), datos(f, std::vector<double>(c)) {}
  ~Matriz() {} // como es un tipo de dato predet ya tiene sus propios constructores automaticos

  double getDato(int f, int c) { return datos.at(f).at(c); }

  Matriz& setDato(int f, int c, double valor) {
    datos.at(f).at(c) = valor;
    return *this;
  }

  void pedirValores() {
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; ++j) {
        std::cout<<"Digite elemento ["<<i+1<<"]["<<j+1<<"]: ";
        std::cin>>datos.at(i).at(j);
      }
      std::cout<<std::endl;
    }
  }
  void mostrarMatriz() const {
    for(int i=0; i<filas; ++i) {
      for(int j=0; j<columnas; ++j){
        std::cout<<datos.at(i).at(j)<<", ";
      }
      std::cout<<std::endl;
    }
  }

  
  void intercambiarFilas(int fila1, int fila2) {
    std::swap(datos.at(fila1), datos.at(fila2));
  }
};
 
class SistemaLineal {   // composicion de Matriz en SistLineal
private:
  int tamano;
  Matriz A, L, U, b;
public:
  SistemaLineal(int t): tamano(t), A(t,t),L(t,t),U(t,t), b(t,1) {}
  ~SistemaLineal() {}
  
  void pedirSistema() {
    std::cout<<"Digite la matriz de coeficientes: "<<std::endl;
    A.pedirValores();
    std::cout<<"Digite la matriz de resultados: "<<std::endl;
    b.pedirValores();
  }

  void factorizarLU() {
    // copiar A en U para poder reutilizar A luego
    for(int i=0; i < tamano; ++i) {
      for(int j=0; j < tamano; ++j) {
        U.setDato(i, j, A.getDato(i,j));
      }
    }
    // todas las operaciones las hacemos directamente desde U
    //1. organizar en orden la matriz usando Intercambiarfilas
    for(int k=0; k < tamano; ++k) {   // k maneja la columna en la que estamos operando
      int indice = k;
      for(int i=k+1; i < tamano; ++i) {  // 
        if(std::abs(U.getDato(k,k)) < std::abs(U.getDato(i,k))) {
          indice = i;  
        }
      }
      U.intercambiarFilas(k,indice);

      L.setDato(k,k, 1.0); // L tiene la diagonal en 1
      //2. reducir la matriz
      for(int i=k+1; i < tamano; ++i) {
        double pivote = U.getDato(i,k) / U.getDato(k,k); // siempre se divide entre el elemento de la diagonal
        L.setDato(i,k, pivote);
        for(int j=k; j < tamano; ++j) {
          double nuevoValor = U.getDato(i,j) - pivote* U.getDato(k,j);
          U.setDato(i,j, nuevoValor);
        }
      }
    }   
  }

  void mostrarLU() const {
    A.mostrarMatriz();
    std::cout<<"Matriz L:"<<std::endl;
    L.mostrarMatriz();
    std::cout<<"Matriz U:"<<std::endl;
    U.mostrarMatriz();
  }
};


int main() {
/*
  Matriz A(3,3);
  A.pedirValores();
  A.mostrarMatriz();
*/
  SistemaLineal s1(3);
  s1.pedirSistema();
  s1.factorizarLU();
  s1.mostrarLU();


  return 0;
}

