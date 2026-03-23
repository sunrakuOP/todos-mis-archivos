#include <iostream>

class Fraccion {
private: 
  int numerador, denominador;
public:
  friend std::istream& operator>>(std::istream& is, Fraccion& obj) {
    char barra;
    is >> obj.numerador >> barra >> obj.denominador;  // guardo la informacion que me escrita en orden
    obj.simplificar();
    return is; 
  } 

  friend std::ostream& operator<<(std::ostream& os, const Fraccion& obj) {
    os << obj.numerador <<"/"<< obj.denominador;
    return os;
  }

  int mcd(int a, int b) const {
    return b==0 ? a : mcd(b, a % b);
  }

  void simplificar() {
    if (denominador == 0) {
      std::cout<<"Division entre 0 no valida"<<std::endl;
      return;
    }
    int m = mcd(std::abs(numerador), std::abs(denominador));
    numerador /= m;
    denominador /=m;
    if( denominador < 0) {
      numerador = -1*numerador;
      denominador = -1*denominador;
    }
  }

  Fraccion(): numerador(0), denominador(1) {} // por defecto por si no dan parametros
  Fraccion(int n, int d): numerador(n), denominador(d) {
    // al llamar al constructor automaticamente llama a simplificar
    simplificar();
  }

  // operadores aritmeticos
  Fraccion operator+(const Fraccion& otro) const {
      return Fraccion(numerador*otro.denominador + otro.numerador*denominador, denominador*otro.denominador);
  }
  Fraccion operator-(const Fraccion& otro) const {
    return Fraccion(numerador*otro.denominador - denominador*otro.numerador, denominador*otro.denominador);
  }
  Fraccion operator*(const Fraccion& otro) const {
    return Fraccion(numerador*otro.numerador, denominador*otro.denominador);
  }
  Fraccion operator/(const Fraccion& otro) const {
    return Fraccion(numerador*otro.denominador, denominador*otro.numerador);
  }

  // operadores condicionales
  bool operator==(const Fraccion& otro) const  {
    return (numerador == otro.numerador && denominador == otro.denominador);
  }
  bool operator!=(const Fraccion& otro) const {
    return !(*this == otro);  // niega lo anterior
  }

  // que modifican el objeto
  Fraccion& operator+=(const Fraccion& otro) {
    numerador = numerador*otro.denominador + denominador*otro.numerador;
    denominador = denominador*otro.denominador;
    simplificar();
    return *this;
  }
  Fraccion& operator-=(const Fraccion& otro) {
    numerador = numerador*otro.denominador - denominador*otro.numerador;
    denominador = denominador*otro.denominador;
    simplificar();
    return *this;
  }

};

int main() {
    Fraccion f1, f2;

    std::cout << "Fracción 1 (n/d): "; std::cin >> f1;
    std::cout << "Fracción 2 (n/d): "; std::cin >> f2;

    std::cout << "f1     = " << f1 << "\n";
    std::cout << "f2     = " << f2 << "\n";
    std::cout << "f1+f2  = " << f1+f2 << "\n";
    std::cout << "f1-f2  = " << f1-f2 << "\n";
    std::cout << "f1*f2  = " << f1*f2 << "\n";
    std::cout << "f1/f2  = " << f1/f2 << "\n";
    std::cout << "f1==f2: " << (f1==f2 ? "si" : "no") << "\n";
    std::cout << "f1!=f2: " << (f1!=f2 ? "si" : "no") << "\n";

    f1 += f2;
    std::cout << "f1+=f2: " << f1 << "\n";

    f1 -= f2;
    std::cout << "f1-=f2: " << f1 << "\n";
}