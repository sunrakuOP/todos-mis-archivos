#include <iostream>
#include <vector>

class Figura {
protected:
  std::string color;
public:
  Figura(const std::string& c): color(c) {}

  void mostrar() const {
    std::cout<<"Color: "<<color<<std::endl;
  }
  double area() {
    std::cout<<"Area no definida.."<<std::endl;
    return 0;
  }
};

class Rectangulo: public Figura {
protected:
  double base, altura;
public:
  Rectangulo(const std::string& c, double b, double a): Figura(c), base(b), altura(a) {}

  void mostrar() const {
    Figura::mostrar();
    std::cout<<"Altura: "<<altura<<", base: "<<base<<std::endl;
  }

  double area() {
    std::cout<<"Area del rectangulo: "<< base*altura <<std::endl;
    return base*altura;
  }
};

class Circulo: public Figura {
protected:
  double radio;
  static double pi;
public:
  Circulo(const std::string& c, double r): Figura(c), radio(r) {}

  void mostrar() const {
    Figura::mostrar();
    std::cout<<"Radio: "<<radio<<std::endl;
  }

  double area() {
    std::cout<<"Area del circulo: "<<pi*radio*radio<<std::endl;
    return pi*radio*radio;
  }
};

double Circulo::pi = 3.141516;

int main() {
  Rectangulo r1("rojo", 5.0, 3.0);
  Circulo c1("azul", 4.0);

  // upcasting, puntero base apunta a obj derivado 
  Figura* p1 = &r1;
  Figura* p2 = &c1;

  // como el puntero solo apunta a la parte Figura no puede acceder a la parte propia (muestra lo de class Figura)
  p1->mostrar();
  p1->area();
  p2->mostrar();
  p2->area();
  // se soluciona con VIRTUAL

  // vector de punteros 
  std::vector<Figura*> figuras;
  figuras.push_back(p1);
  figuras.push_back(p2);

  for(Figura* f: figuras) {
    f->area();
    f->mostrar();
  }
  // puedo recorrer los elementos del vector (sin importar que sean subojetos diferenntes) porque comparten la parte Base

  return 0;
}