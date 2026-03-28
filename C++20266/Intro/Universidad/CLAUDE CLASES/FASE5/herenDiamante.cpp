#include <iostream>
#include <string>

class Vehiculo {
protected:
  std::string marca;
  int anio, velmax, velact;
public:
  Vehiculo(const std::string& m, int a, int vm): marca(m), anio(a), velmax(vm), velact(0) {}

  ~Vehiculo() {}

  Vehiculo& acelerar(int a) {
    if(a < 0){
      std::cout<<"Velocidad no puede ser negativa"<<std::endl;
      return *this;
    }
    if ((velact+a) > velmax) {
      std::cout<<"Velocidad no permitida..."<<std::endl;
      return *this;
    }
    velact += a;
    return *this;
  }

  Vehiculo& frenar(int a) {
    if(a < 0){
      std::cout<<"Velocidad no puede ser negativa"<<std::endl;
      return *this;
    }
    if(velact < a) {
      velact = 0;
      std::cout<<"Frenado de emergencia..."<<std::endl;
      return *this;
    }
    velact -= a;
    return *this;
  }

  void describir() const {
    std::cout<<"Marca: "<<marca<<", anio: "<<anio<<", vel max: "<<velmax<<", vel actual: "<< velact<<std::endl;
  }
};

class Terrestre: virtual public Vehiculo {
protected: 
  int ruedas;
  std::string tipoCamino;
public:
  Terrestre(const std::string& m, int a, int vm,int r, const std::string& tp):
    Vehiculo(m,a,vm), ruedas(r), tipoCamino(tp) {}
  ~Terrestre() {}

  void moverEnTierra() const {
    std::cout<<"Se mueve en tierra de forma: "<<tipoCamino<<std::endl;
  }

  void describir() const {
    Vehiculo::describir();
    std::cout<<"Numero de ruedas: "<<ruedas<<"\n, tipo camino: "<<tipoCamino<<std::endl;
  }
};

class Acuatico: virtual public Vehiculo {
protected:
  double calado;
  std::string tipoCasco;
public:
  Acuatico(const std::string& m, int a, int vm, double c, const std::string& tc):
    Vehiculo(m,a,vm), calado(c), tipoCasco(tc) {}
  ~Acuatico() {}

  void moverEnAgua() const {
    std::cout<<"Modo de movimiento en agua: "<<tipoCasco<<std::endl;
  }

  void describir() const {
    Vehiculo::describir(); // ser explicito al sobreescribir con mismo nombre
    std::cout<<"Calado: "<<calado<<", tipo de casco: "<<tipoCasco<<std::endl;
  }
};

class Anfibio: public Terrestre, public Acuatico{
protected:
  std::string modoActual;
public:
  

};

int main () {

  return 0;
}