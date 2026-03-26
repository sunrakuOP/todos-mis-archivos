#include <iostream>

class Vehiculo{
public:
  std::string marca;
  Vehiculo(const std::string& m): marca(m) {
    std::cout<<"Constructor de vehiculo: "<< marca <<std::endl;
  }
};

class Terrestre: public Vehiculo {  // hereda de vehiculo
public:
  int ruedas; 
  Terrestre(const std::string& m, int r): Vehiculo(m), ruedas(r) {}
};

class Acuatico: public Vehiculo {  // hereda de vehiculo
public:
  double eslora;
  Acuatico(const std::string& m, double e): Vehiculo(m), eslora(e) {}
};

class Anfibio: public Terrestre, public Acuatico {
public:
  Anfibio(const std::string& m, int r, double e): Terrestre(m,r), Acuatico(m, e) {}   // usa los dos cosntructores
};



int main() {

  Anfibio a("ford", 3, 5);

  return 0;
}