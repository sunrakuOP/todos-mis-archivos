#include <iostream>
#include <string>

class Vehiculo {
protected:
  std::string marca;
  int anio;
  int * id;  // pedirle como se hace el puntero dinamico
public:
  Vehiculo(const std::string& m, int a, int idUs): marca(m), anio(a), id(new int(idUs)) {}
  // copy cosntructor
  Vehiculo(const Vehiculo& otro): marca(otro.marca), anio(otro.anio), id(new int(*otro.id)) {}
   
  Vehiculo(Vehiculo&& otro): marca(std::move(otro.marca)), anio(otro.anio), id(otro.id) {
    otro.id = nullptr;
    otro.anio = 0;
    // no se altera el atributo de cadena
  }

  Vehiculo& operator=(Vehiculo& otro) {
    if (this == &otro) {
      return *this;
    }
    delete id;

    marca = otro.marca;
    anio = otro.anio;
    id = new int(*otro.id);
    return *this;
  }

  ~Vehiculo() {
    std::cout<<"Destruyendo vehiculo: "<<marca<<std::endl;
    // como usamos static no liberamos codigo
    delete id;
  }
};

class Automovil:public Vehiculo {
protected:
  int* capacidadMotor; // solo lo declaro aca
public:
  Automovil(const std::string& m, int a, int idVal, int cap): Vehiculo(m,a,idVal), capacidadMotor(new int(cap)) {}
  
  // hacerle cada constructor llamando al de la base
  Automovil(const Automovil& otro): Vehiculo(otro), capacidadMotor(new int(*otro.capacidadMotor)) {}

  Automovil(Automovil&& otro): Vehiculo(std::move(otro)), capacidadMotor(otro.capacidadMotor) {
    
  } 
};



int main() {

  std::string galarza = "galarza";
  std::string *p = &galarza;

  std::cout<<"Direccion en memoria de variable Galarza: "<<p <<std::endl;
  std::cout<<*p;

  
  return 0;
}