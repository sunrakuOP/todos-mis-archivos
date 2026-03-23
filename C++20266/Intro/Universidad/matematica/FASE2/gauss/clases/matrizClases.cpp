#include <iostream>
#include <vector>

using arreglo = std::vector<std::vector<double>>;

class Matriz {
private: 
  int filas, columnas;
  arreglo datos;

public:
  Matriz (int f, int c) : filas(f), columnas(c), datos(f, std::vector<double> (c)) {}   // crear el objeto y darle el tamano a la matriz
  ~Matriz () {}  // no necesario cuando no manejo memoria manualmente

  void agregarDatos() {
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; ++j) {
        std::cout<<"Digite elemento fila"<<i+1<<" y columna"<<j+1<<": ";
        std::cin>> datos.at(i).at(j);
      }
    }
  }

  void mostrarDatos() const {
    for(int i=0; i < filas; ++i) {
      for(int j=0; j < columnas; ++j) {
        std::cout<< datos.at(i).at(j) <<", ";
      }
      std::cout<<std::endl;
    }  
  }

  Matriz& setDato(int f, int c, double dato) {
    datos.at(f).at(c) = dato;
    return *this;
  }
  
  double getDato(int f, int c) const {
    return datos.at(f).at(c);
  }


  Matriz sumarMatrices(const Matriz& otra) const {
    if (filas != otra.filas || columnas != otra.columnas) {
        std::cout << "Error: matrices de diferentes tamanos" << std::endl;
        return Matriz(0, 0);  // retorna matriz vacía
    }

    Matriz suma(filas, columnas);
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            suma.datos.at(i).at(j) = datos.at(i).at(j) + otra.datos.at(i).at(j);
    return suma;
  }
};

int main() {
  Matriz m1(3,3);
  m1.agregarDatos();
  m1.mostrarDatos();
  
  m1.setDato(2,2,100);
  std::cout<< m1.getDato(2,2) << std::endl;
  m1.mostrarDatos();
  
  Matriz m2(3,3);
  m2.agregarDatos();

  Matriz sumadas = m1.sumarMatrices(m2);
  sumadas.mostrarDatos();

  return 0;
}