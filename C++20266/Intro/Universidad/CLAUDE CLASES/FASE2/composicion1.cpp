// COMPOSICION DE OBJETOS, clase que tiene como atributo objetos de otra clase
#include <iostream>
#include <string>

class Motor {
private:
  int cilindros;
  double cilindrada;
  bool encendido;
public: 
  Motor(int c, double cc) : cilindros(c), cilindrada(cc), encendido(false) {}
  ~Motor() {}

  void encender() {
    encendido = true;
  }
  void apagar() {
    encendido = false;
  }

  
  bool estaEcendido() {
    return encendido;
  }

  void mostrarInfo() const {
    std::cout<<"Cilindros: "<<cilindrada <<std::endl;
    std::cout<<"Cilindros: "<<cilindros<<std::endl;
    std::cout<<"Encendido: "<< encendido <<std::endl;
  }
};

// vehiculo es un objeto que dentro de si contiene objeto de otra clase
class Vehiculo {
private: 
  std::string marca, modelo;
  Motor motor; // atrributo de tipo Motor en clase Vehiculo (Vehiculo compone a Motor)

public:
  Vehiculo(std::string ma, std::string mo, int c, double cc) : marca(ma), modelo(mo), motor(c, cc) {}  // llamo al constructor de Motor en Vehiculo
  // le debo pasar los parametros de Motor e inicializarlo

  // puedo llamarlo como objeto
  void encender() {
    motor.encender();
    std::cout<<"Encendiendo vehiculo"<<std::endl;
  }
  void apagar() {
    motor.apagar();
    std::cout<<"Apagando vehiculo..."<<std::endl;
  }

  void mostrarInformacion() const {
    std::cout<<"Marca: "<<marca <<std::endl;
    std::cout<<"Modelo: "<< modelo <<std::endl;
    motor.mostrarInfo();
  }


};

int main (){
  Vehiculo v1("Ford",   "Fiesta", 4, 1600);
    Vehiculo v2("Nissan", "March",  4, 1400);

    v1.mostrarInformacion();
    std::cout << std::endl;

    v1.encender();
    std::cout << std::endl;

    v1.mostrarInformacion();  // encendido cambia a Si
    std::cout << std::endl;

    v1.apagar();
    std::cout << std::endl;

    v2.mostrarInformacion();

  return 0;
}