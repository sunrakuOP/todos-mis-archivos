#include <iostream>
#include <string>
#include <vector>

// objeto matriz
class Matriz {
private:
  int filas, columnas;
  std::vector<std::vector<double>> datos;
public:
  Matriz(int f, int c) : filas(f), columnas(c), datos(f, std::vector<double>(c)) {} 
  ~Matriz() {}

  void pedirMatriz() {
    std::cout << "Matriz " << filas << "x" << columnas << std::endl;
    for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; j++) {
        std::cout << "Digite elemento fila " << i+1 << " columna " << j+1 << ": ";
        std::cin >> datos.at(i).at(j);
      }
    }
  }

  void mostrarMatriz() const {
    for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; j++)
        std::cout << datos.at(i).at(j) << "\t"; 
      std::cout << std::endl;
    }
  }

  double getDato(int f, int c) const {
    return datos.at(f).at(c);
  }

  void setDato(int f, int c, double dato) {
    datos.at(f).at(c) = dato;
  }

  void intercambiarFilas(int fila1, int fila2) {
    std::swap(datos.at(fila1), datos.at(fila2));
  }
};

// clase Sistema Lineal que contiene Matrices
class SistemaLineal {
private:
  int num;
  Matriz A, b;
public:
  SistemaLineal(int n) : num(n), A(n, n), b(n, 1) {}
  ~SistemaLineal() {}

  void pedirSistema() {
    std::cout << "Digite matriz de coeficientes: " << std::endl;
    A.pedirMatriz();
    std::cout << "Digite vector de resultados: " << std::endl;
    b.pedirMatriz();
  }

  Matriz aumentada() {
    Matriz aug(num, num+1);
    for (int i = 0; i < num; ++i) {
      for (int j = 0; j < num; ++j)
        aug.setDato(i, j, A.getDato(i, j));
      aug.setDato(i, num, b.getDato(i, 0));
    }
    return aug;
  }

  /*
  Matriz pivoteoParcial(Matriz& aumentada) {
    for(int k=0; k < num; ++k) {
      int indice = k;
      for(int i=k+1; i < num; ++i) {
        if(std::abs(aumentada.getDato(i,k)) > std::abs(aumentada.getDato(indice,k)))
          indice = i;
      }
      aumentada.intercambiarFilas(k, indice);
    }
  }
  */

  Matriz eliminacionHaciaAdelante(Matriz& aug) {
    // pivoteo parcial — estabilidad numérica
    for (int k = 0; k < num; ++k) {
      int indice = k;
      for (int i = k+1; i < num; ++i) {
        if (std::abs(aug.getDato(i,k)) > std::abs(aug.getDato(indice,k)))
          indice = i;
      }
      aug.intercambiarFilas(k, indice);  // ✅ fuera del if, siempre intercambia

      // eliminación hacia adelante
      for (int i = k+1; i < num; ++i) {
        double factor = aug.getDato(i,k) / aug.getDato(k,k);
        for (int j = 0; j < num+1; ++j) {
          double nuevoValor = aug.getDato(i,j) - factor * aug.getDato(k,j);
          aug.setDato(i, j, nuevoValor);
        }
      }
    }
    return aug;
  }

  std::vector<double> sustitucionHaciaAtras(const Matriz& aug) {
    std::vector<double> x(num);
    for (int i = num-1; i >= 0; --i) {
      double suma = 0;
      for (int j = i+1; j < num; ++j)
        suma += aug.getDato(i,j) * x.at(j);
      x.at(i) = (aug.getDato(i,num) - suma) / aug.getDato(i,i);
    }
    return x; // devuelvo el vector x
  }

  bool verificar(const std::vector<double>& x) { // A y b ya son atributos, no necesito pasarlos como parametros
    for(int i=0; i < num; ++i) {
      double sumaFilaAct = 0;
      for(int j=0; j < num; j++) {
        sumaFilaAct += A.getDato(i,j)*x.at(j);  // x es un vector, no es objeto Matriz
      }
      double resiuduo = b.getDato(i,0) - sumaFilaAct; 
      if(std::abs(resiuduo)>1e-9) {
        return false;
      }
    }
    return true; // ya despues de que todas las filas pasaron
  }
};

int main() {
  SistemaLineal s1(3);
  s1.pedirSistema();

  std::cout << "\nMatriz aumentada:" << std::endl;
  Matriz aug = s1.aumentada();
  aug.mostrarMatriz();

  std::cout << "\nMatriz reducida:" << std::endl;
  Matriz reducida = s1.eliminacionHaciaAdelante(aug);
  reducida.mostrarMatriz();

  std::vector<double> sol = s1.sustitucionHaciaAtras(reducida);

  std::cout << "\nSolucion:" << std::endl;
  for (int i = 0; i < (int)sol.size(); ++i)
    std::cout << "x" << i+1 << " = " << sol.at(i) << std::endl;

  if (s1.verificar(sol))
    std::cout << "\nSolucion correcta" << std::endl;
  else
    std::cout << "\nSolucion incorrecta" << std::endl;

  return 0;
}