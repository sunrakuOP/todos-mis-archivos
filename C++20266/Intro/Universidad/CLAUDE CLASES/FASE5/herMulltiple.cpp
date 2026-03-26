// ejercicio de herencia multiple
#include <iostream>
#include <string>

class Dispositivo {  // base 1
protected:  
  std::string marca;
  double peso;
public: 
  Dispositivo(const std::string& m, double p): marca(m), peso(p) {}

  ~Dispositivo() {}
  // constructor de copia. crea un nuevo obj basandose en otro (mismos atributos)
  Dispositivo(const Dispositivo& otro): marca(otro.marca), peso(otro.peso) {}
  // operador de asignacion, resetea caracteristicas de obj ya existente y pone las de otro
  Dispositivo& operator=(const Dispositivo& otro) {
    // comprueba que no sea el mismo obj
    if (this == &otro) {
      return *this;
    }
    marca = otro.marca;
    peso = otro.peso;
    return *this;
  }
  // movimiento, pasa de uno a otro y deja el anterior vacio
  Dispositivo (Dispositivo&& otro): marca(std::move(otro.marca)), peso(otro.peso) {
    otro.peso = 0;
    otro.marca = "";
  }
     
  void mostrar() const {
    std::cout<<"Marca: "<<marca<<", peso: "<<peso<<std::endl;
  }
};

class Bateria {  // base 2
protected:
  double *capacidadMh;
public:
  Bateria(double cap): capacidadMh(new double(cap)) {}  // creo valor en heap y un puntero que apunte a el

  ~Bateria() { // como estoy usando punteros debo hacerle manejo propio de memoria
    delete capacidadMh;
  }
  // cosntructores usando punteros 
  Bateria(const Bateria& otro): capacidadMh(new double(*otro.capacidadMh)) {} // al usar new se crea un nuevo bloque de memoria

  Bateria& operator=(const Bateria& otro) {
    if(this == &otro) {
      return *this;
    }
    delete capacidadMh;

    capacidadMh = new double (*otro.capacidadMh); // manejo con punteros, CUIDADO
    return *this;
  }

  // operador de adicion
  Bateria& operator+=(double valor) {
    *capacidadMh += valor;  // desreferenciar porque es directamente e objeto
    return *this;
  }

  Bateria (Bateria&& otro): capacidadMh(otro.capacidadMh) {
    std::cout<<"Destruyendo bateria..."<<std::endl;
    otro.capacidadMh = nullptr;
  }

  void mostrar() const {
    std::cout<<"Capacidad de bateria: "<< *capacidadMh<<std::endl; // desreferenciar el puntero
  }

  friend std::ostream& operator<<(std::ostream& os, const Bateria& obj) {
    os << "Capacidad de bateria: "<< *obj.capacidadMh;
    return os;
  }

};

// ahora tenemos que hacer clase Celular que hereda de Dispositivo y Bateria
class Celular: public Dispositivo, public Bateria { // herencia multiple
protected:
  int almacenamiento;
public: 
  // constructor, se crea en orden de escritura en la clase
  Celular(const std::string& m, double p, double cap, int al): Dispositivo(m,p), Bateria(cap), almacenamiento(al) {}

  void mostrar() const {   // redefinicion de metodos
    Dispositivo::mostrar();
    Bateria::mostrar(); // llamo a los metodos de cada uno
    std::cout<<"Almacenamiento: "<<almacenamiento<<std::endl;
  }

  friend std::ostream& operator<<(std::ostream& os, const Celular& obj) {
    os<< "Marca: "<<obj.marca<<", peso: "<<obj.peso<<", capacidad: "<<* obj.capacidadMh <<", almacenamiento: "<<obj.almacenamiento;
    return os;
  }
}; // recordar que capMah es un puntero



int main() {
  Dispositivo d1("Iphone", 12);
  Bateria b1(100);

  d1.mostrar();
  b1.mostrar();

  Celular c1("Samsung", 12, 100, 16);
  c1.mostrar();
  return 0;
}