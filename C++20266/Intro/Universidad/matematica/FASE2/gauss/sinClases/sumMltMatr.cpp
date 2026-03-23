#include <iostream>
#include <vector>

using Matriz = std::vector<std::vector<double>>;

Matriz pedirMatrizA(int filas) {
  Matriz matrizA (filas, std::vector<double>(filas));

  for(int i=0; i < filas; i++) {
    for(int j=0; j < filas; ++j) {
      std::cout<<"Digite elemento fila "<<i+1<<" y columna "<<j+1<<": ";
      std::cin>> matrizA.at(i).at(j);
    }
  }
  return matrizA;
}
Matriz pedirMatrizB(int filas) {
  Matriz matrizB (filas, std::vector<double> (filas));

  for(int i=0; i < filas; i++) {
    for(int j=0; j < filas; ++j) {
      std::cout<<"Digite elemento fila "<<i+1<<" y columna "<<j+1<<": ";
      std::cin>> matrizB.at(i).at(j);
    }
  }

  return matrizB;
}
void mostrarMatrices(int filas, const Matriz& matrizA, const Matriz& matrizB) {
  std::cout<<"MATRIZ A"<<std::endl;

  for(int i=0; i<filas; ++i) {
    for(int j=0; j<filas; ++j) {
      std::cout<< matrizA.at(i).at(j)<<", ";
    }
    std::cout<<std::endl;
  }
  std::cout<<"MATRIZ B"<<std::endl;

  for(int i=0; i<filas; ++i) {
    for(int j=0; j<filas; ++j) {
      std::cout<< matrizB.at(i).at(j)<<", ";
    }
    std::cout<<std::endl;
  }
}

Matriz sumarMatrices(int filas, const Matriz& matrizA, const Matriz& matrizB){
  Matriz sumada (filas, std::vector<double>(filas));

  for(int i=0; i < filas; ++i) {
    for(int j=0; j < filas; j++){
      sumada.at(i).at(j) = matrizA.at(i).at(j) + matrizB.at(i).at(j);
    }
  }
  return sumada;
}
void mostrarSumada(int filas, const Matriz& suma) {
  std::cout<<"Matriz Sumada: "<<std::endl;

  for(int i=0; i < filas; ++i) {
    for(int j=0; j < filas; j++){
      std::cout<< suma.at(i).at(j) << ", ";
    }
    std::cout<<std::endl;
  }
}

Matriz multiplicarMatrices(int filas, const Matriz& matrizA, const Matriz& matrizB) {
  Matriz multiplicada(filas, std::vector<double> (filas));

  for(int i=0; i < filas; ++i) {
    for(int j=0; j < filas; ++j) {
      double sumaTemp = 0;
      for(int k=0; k < filas; ++k) {
        sumaTemp += matrizA.at(i).at(k)*matrizB.at(k).at(j); 
      }
      multiplicada.at(i).at(j) = sumaTemp;
    }
  }
  return multiplicada;
}
void mostrarMultiplicada(int filas, const Matriz& mult) {
  std::cout<<"Matriz multiplicada: "<<std::endl;
  for(int i=0; i<filas; ++i) {
    for(int j=0; j<filas; ++j){
      std::cout<< mult.at(i).at(j) <<", ";
    }
    std::cout<<std::endl;
  }
}


int main() {
  int numFilas;
  std::cout<<"OPERACIONES MATRIZ CUADRADA"<<std::endl;
  std::cout<<"Digite numero de filas: "<<std::endl;
  std::cin>> numFilas;

  Matriz matrizA = pedirMatrizA(numFilas);
  Matriz matrizB = pedirMatrizB(numFilas);

  mostrarMatrices(numFilas, matrizA, matrizB);

  Matriz suma =  sumarMatrices(numFilas, matrizA, matrizB);
  mostrarSumada(numFilas, suma);

  Matriz mult = multiplicarMatrices(numFilas, matrizA, matrizB);
  mostrarMultiplicada(numFilas, mult);

  return 0;
}