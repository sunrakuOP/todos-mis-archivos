#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> pedirNombres(int filas) {
  std::vector<std::vector<std::string>> estudiantes(filas, std::vector<std::string> (1));

  for(int i=0; i < filas; ++i) {
    std::cout<<"Digite nommbre estudiante "<<i+1<<": "<<std::endl;
    std::cin>> estudiantes[i][0];
  }
  
  return estudiantes;
}

std::vector<std::vector<std::string>> pedirMaterias(int columnas) {
  std::vector<std::vector<std::string>> materias(1, std::vector<std::string> (columnas));

  for(int j=0; j < columnas; ++j) {
    std::cout<<"Digite nombre materia "<<j+1<<": "<<std::endl;
    std::cin>> materias[0][j];
  }
  
  return materias;
}

std::vector<std::vector<int>> pedirNotas(int filas, int columnas) {
  std::vector<std::vector<int>> notas(filas, std::vector<int> (columnas));

  for(int i=0; i < filas; ++i) {
    for(int j=0; j < columnas; ++j) {
      std::cout<<"Digite nota estudiante "<<i+1<<" y materia "<<j+1<<": "<<std::endl;
      std::cin>>notas[i][j];
    }
  }
  
  return notas;
}
  

int main() {
  int numEstud, numMaterias;
  std::cout<<"Digite el numero de estudiantes: "<<std::endl;
  std::cin>>numEstud;
  std::cout<<"Digite el nuemero de materias: "<<std::endl;
  std::cin>>numMaterias;

  std::vector<std::vector<std::string>> estudiantes = pedirNombres(numEstud);
  std::vector<std::vector<std::string>> materias = pedirMaterias(numMaterias);
  std::vector<std::vector<int>> notas = pedirNotas(numEstud, numMaterias);

  // recorrer los vectores
  std::cout<<"Vector de nombres"<<std::endl;
  for(int i=0; i < numEstud; i++) {
    std::cout<< estudiantes[i][0] <<", ";
  }
  std::cout<<std::endl;

  std::cout<<"Vector de materias: "<<std::endl;
  for(int j=0; j < numMaterias; ++j) {
    std::cout<< materias[0][j] <<","<<std::endl;
  }

  std::cout<<"Matriz de notas"<<std::endl;
  for(int i=0; i < numEstud; ++i) {
    for(int j=0; j< numMaterias; ++j) {
      std::cout<< notas[i][j] <<", ";
    }
    std::cout<<std::endl;
  }
  
  return 0;
}