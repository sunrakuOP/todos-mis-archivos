#include <iostream>
#include <set>

class Conjunto {
protected:
  std::multiset<double> notas;
public:
  Conjunto() = default;

  Conjunto& agregarNota(double nota) {
    notas.insert(nota);
    return *this;  // agrega notas repetidas tambien
  }

  Conjunto& eliminarNotaRepetida(double nota) {
    if(notas.empty()) {
      std::cout<<"Set vacio..."<<std::endl;
      return *this;
    }
    if(notas.count(nota) == 0) {  
      std::cout<<"Nota no encontrada"<<std::endl;
      return *this;
    }
    notas.erase(notas.find(nota));
    return *this;
  }

  int numVeces(double nota) {
    std::cout<<nota<<" aparece: "<<notas.count(nota)<<" veces"<<std::endl;
    return notas.count(nota);
  }

  void mostrarSet() const {
    std::cout<<"Set: "<<std::endl;
    for(const auto& n: notas) {
      std::cout<<n<<", ";
    }
    std::cout<<std::endl;
  }

};

int main() {
    Conjunto c;
    c.agregarNota(90).agregarNota(75).agregarNota(88)
     .agregarNota(90).agregarNota(60).agregarNota(75)
     .agregarNota(95).agregarNota(88).agregarNota(90);

    c.numVeces(90);           // 90 aparece: 3 veces
    c.eliminarNotaRepetida(90);
    c.numVeces(90);           // 90 aparece: 2 veces
    c.mostrarSet();
    return 0;
}

