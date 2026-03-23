// ejercicio que genera un vector en coordendas rectangulares
#include <iostream>
#include <cmath>

class Vector2D {
private: 
  int xcoor, ycoor;
public:
  Vector2D(int x, int y): xcoor(x), ycoor(y) {}

  // en este caso definamos la sobrecarga dentro de la funcion
  //1. operadores aritmeticos (crean nuevo objeto)
  Vector2D operator+(const Vector2D& otro) const {
    return Vector2D(xcoor + otro.xcoor, ycoor + otro.ycoor);  // retorna un nuevo objeto
  }
  Vector2D operator-(const Vector2D& otro) const {
    return Vector2D(xcoor-otro.xcoor, ycoor-otro.ycoor);
  }
  Vector2D operator*(double c) const {   // multiplicacion escalar
    return Vector2D(c*xcoor, c*ycoor);
  }
  Vector2D operator/(double c) const {
    return Vector2D(xcoor/c, ycoor/c);
  }

  double dot(const Vector2D& otro) const {  // producto punto (multiplicar componentes y sumarlas)
    return xcoor*otro.xcoor + ycoor*otro.ycoor;    
  }

  // 2. alteran el mismo objeto (*this)
  Vector2D& operator+=(const Vector2D& otro) {
    xcoor += otro.xcoor;
    ycoor += otro.ycoor;
    return *this;  // referencia al mismo objeto para alterar
  }
  Vector2D& operator-=(const Vector2D& otro) {
    xcoor -= otro.xcoor;
    ycoor -= otro.ycoor;
    return *this;
  }

  // 3. Comparacion (SIEMPRE DEBEN IR JUNTOS)
  bool operator==(const Vector2D& otro) {
    return (xcoor == otro.xcoor && ycoor == otro.ycoor);
  }
  bool operator!=(const Vector2D& otro) {
    return !(*this == otro);
  }

  // operador unitario (negar el vector)
  Vector2D operator-() {
    return Vector2D(-xcoor, -ycoor);
  }
  // operador stream <<
  friend std::ostream& operator<<(std::ostream& os, const Vector2D& otro) {
    return os <<"("<<otro.xcoor<<", "<<otro.ycoor<<")";
  }

};



int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    std::cout << "v1 = "      << v1 << "\n";
    std::cout << "v2 = "      << v2 << "\n";
    std::cout << "v1+v2 = "   << v1+v2 << "\n";
    std::cout << "v1-v2 = "   << v1-v2 << "\n";
    std::cout << "v1*2 = "    << v1*2.0 << "\n";
    std::cout << "v1/2 = "    << v1/2.0 << "\n";
    std::cout << "-v1 = "     << -v1 << "\n";
    std::cout << "v1·v2 = "   << v1.dot(v2) << "\n";
    std::cout << "v1==v2: "   << (v1==v2 ? "si" : "no") << "\n";

    v1 += v2;
    std::cout << "v1+=v2: "   << v1 << "\n";
}