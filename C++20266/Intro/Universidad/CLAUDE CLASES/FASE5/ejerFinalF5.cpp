#include <iostream>
#include <string>
#include <vector>

class Vehiculo {
protected:
  std::string marca, modelo;
  int anio;
public: 
  Vehiculo(const std::string& ma, const std::string& mo, int a): marca(ma), modelo(mo), anio(a) {}

  void describir() const {
    std::cout<<"Marca"<<marca<<", modelo: "<<modelo<<", anio: "<<anio<<std::endl;
  }

  virtual double calcularImpuesto() {
    std::cout<<"Cada uno tiene su propia forma de hacerlo.."<<std::endl;
    return 0;
  }
};

class Terrestre: virtual public Vehiculo {
protected:
  int numRuedas, caballosFuerza;
public:
  Terrestre(const std::string& ma, const std::string& mo, int a, int nr, int cf): Vehiculo(ma, mo, a), numRuedas(nr), caballosFuerza(cf) {}
  
};
class Auto: public Terrestre {
public:
  Auto(const std::string& ma, const std::string& mo, int a, int nr, int cf): Vehiculo(ma, mo, a), Terrestre(ma,mo,a,nr,cf) {}

  double calcularImpuesto() {
    std::cout<<"Impuesto al auto: "<<caballosFuerza*0.5<<std::endl;
    return caballosFuerza*0.5;
  }
};

class Camion: public Terrestre {
public:
  Camion(const std::string& ma, const std::string& mo, int a, int nr, int cf): Vehiculo(ma,mo,a), Terrestre(ma,mo,a,nr,cf) {}

  double calcularImpuesto() {
    std::cout<<"Impuesto al camion: "<<caballosFuerza*1.2 + numRuedas*50 <<std::endl;
    return caballosFuerza*1.2 + numRuedas*50 ;
  }
};


class Acuatico: virtual public Vehiculo {
protected:
  double eslora;
  std::string tipoMotor;
public:
  Acuatico(const std::string& ma, const std::string& mo, int a, double e, const std::string& tm): 
    Vehiculo(ma, mo, a), eslora(e), tipoMotor(tm) {}
};

class Lancha: public Acuatico {
public:
  Lancha(const std::string& ma, const std::string& mo, int a, double e, const std::string& tm): Vehiculo(ma,mo,a), Acuatico(ma, mo, a, e, tm) {}

  double calcularImpuesto() {
    std::cout<<"Impuesto de la lancha: "<<eslora*100<<std::endl;
    return eslora*100;
  }
};




class Anfibio: public Camion, public Lancha {
public:
  Anfibio(const std::string& ma, const std::string& mo, int a, int nr, int cf, double e, const std::string& tm): 
    Vehiculo(ma, mo, a), Camion(ma, mo, a, nr, cf), Lancha(ma, mo, a, e, tm) {}

  double calcularImpuesto() {
    std::cout<<"Impuesto anfibio: "<<caballosFuerza*0.8 + eslora *120<<std::endl;
    return caballosFuerza*0.8 + eslora *120;
  }
};

int main() {
  // crear un objeto por cada tipo. todos heredan de vehiculo
  Auto a("ford","fiesta",2010, 4, 110);
  Camion c("ford","raptor",2020,6,300);
  Lancha l("jmm","menos",2025,30,"ni idea");
  Anfibio an("agua", "no se otra", 20266,2,100,4,"nop se");

  std::vector<Vehiculo*> vehiculos;
  vehiculos.push_back(&a);
  vehiculos.push_back(&c);
  vehiculos.push_back(&l);
  vehiculos.push_back(&an);

  double impTotal = 0;
  for(const auto& v: vehiculos) {
    v->describir();
    v->calcularImpuesto();  // por virtual se ejecuta de la manera que quiero
    impTotal += v->calcularImpuesto();
  }
  std::cout<<"Impuesto total: "<< impTotal;



  return 0;
}