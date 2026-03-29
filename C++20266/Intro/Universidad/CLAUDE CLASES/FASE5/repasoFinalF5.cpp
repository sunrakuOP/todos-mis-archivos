`#include <iostream>
#include <vector>

class Empleado {
protected:
  std::string nombre;
  int id;
public:
  Empleado(const std::string& no, int i): nombre(no), id(i) {}

  virtual void mostrar() const {
    std::cout<<"Nombre: "<<nombre<<", id: "<<id<<std::endl;
  }
  virtual double calcularSalario() {
    std::cout<<"Salario base..."<<std::endl;
    return 0;
  }
};

class PorHora: virtual public Empleado {
protected:
  int horasTrabajadas;
  double tarifaHora;
public:
  PorHora(const std::string& no, int i, int ht, double th): Empleado(no, i), horasTrabajadas(ht), tarifaHora(th) {}

  void mostrar() const {
    Empleado::mostrar();
    std::cout<<"Tarifa por hora: "<<tarifaHora<<", horas trabajadas: "<<horasTrabajadas<<std::endl;
  }
  double calcularSalario() {
    std::cout<<"Salario: "<< tarifaHora*horasTrabajadas <<std::endl;
    return tarifaHora*horasTrabajadas;
  }
};
class Fijo: virtual public Empleado {
protected:
  double salarioMensual;
public:
  Fijo(const std::string& no, int i, double sm): Empleado(no, i), salarioMensual(sm) {}

  void mostrar() const {  
    Empleado::mostrar();
    std::cout<<"Salario fijo"<<std::endl;
  }
  double calcularSalario() {
    std::cout<<"Salario fijo: "<<salarioMensual<<std::endl;
    return salarioMensual;
  }
};

class Freelancer: public PorHora, public Fijo {
public:
  Freelancer(const std::string& no, int i, int ht, double th, double sm): Empleado(no,i), PorHora(no,i,ht,th), Fijo(no,i,sm) {}

  // como freelancer hereda de fijo y por hora no sabe cual mostrar usar
  void mostrar() const {\
    Empleado::mostrar();
    std::cout<<"Freelancer.. "<<std::endl;
  }

  double calcularSalario() {
    std::cout<<"Salario freelancer: "<<salarioMensual + horasTrabajadas*tarifaHora<<std::endl;
    return salarioMensual + horasTrabajadas*tarifaHora;
  }
};


int main() {
  Empleado e("Sebastian", 2002);
  Fijo f("Carlos", 2004, 100000);
  PorHora ph("Esteban", 2005, 10, 1000);
  Freelancer fr("Nicolas", 2003, 15, 1000, 100000);

  std::vector<Empleado*> empleados;
  empleados.push_back(&e);
  empleados.push_back(&f);
  empleados.push_back(&ph);
  empleados.push_back(&fr);

  double nomima = 0;
  for(const auto& e: empleados) {
    e->mostrar();
    nomima += e->calcularSalario();
  }
  std::cout<<"Nomina total: "<<nomima<<std::endl;



  return 0;
}