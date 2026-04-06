#include <iostream>
#include <vector>

class Persona {
protected:
    std::string nombre;
    int edad;
public:
    Persona(const std::string& n, int e): nombre(n), edad(e) {}
    
    // metodo virtual puro
    virtual double calcularSalario() = 0;
        // hace que las hijas la deban definir, no se puede implementar en la base
        // no puedo instanciarla, constructor no funciona
};

class Empleado: public Persona {
protected: 
    static int contador;
    int id;
    std::string fecha;
public:
    Empleado(const std::string& n, int e, const std::string& f): Persona(n,e), id(++contador), fecha(f) {}
    // ?? aca deberia poner el id??

    virtual void info()  {
        std::cout<<"Nombre: "<<nombre<<", edad: "<<edad<<"\n id: "<<id<<", fecha de contratacion: "<< fecha<<std::endl;
    }
};
int Empleado::contador=0;


class Desarrollador: virtual public Empleado {
protected:
    std::vector<std::string> lenguajes;
    double tarifaHora;
public:
// como inicializo el vector en el constructor???
    Desarrollador(const std::string& n, int e, const std::string& f, std::vector<std::string> l, double th): Empleado(n,e,f), lenguajes(l), tarifaHora(th) {}

    void info() override {
        Empleado::info();
        std::cout<<"Lenguajes que maneja: "<<std::endl;
        for(const auto& l: lenguajes) {
            std::cout<<l<<", ";
        }
        std::cout<<"\nTarifa por hora: "<<tarifaHora<<std::endl;
    }
    double calcularSalario() override {
        std::cout<<"Salario del desarrollador: "<<160*tarifaHora<<std::endl;
        return 160*tarifaHora;
    }
};
class Disenador: virtual public Empleado {
protected:
    int diasProy;
    double tarifaDia;
public:
    Disenador(const std::string& n, int e, const std::string& f, int dp, double td): Empleado(n,e,f), diasProy(dp), tarifaDia(td) {}

    void info() override {
        Empleado::info();
        std::cout<<"Dias del proyecto: "<<diasProy<<std::endl;
        std::cout<<"\nTarifa por dia: "<<tarifaDia<<std::endl;
    }

    double calcularSalario() override {
        std::cout<<"Salario del disenador: "<<diasProy*tarifaDia<<std::endl;
        return diasProy*tarifaDia;
    }
};

class LiderTecnico: public Desarrollador, public Disenador {
protected:
// toca llamar de forma independiente a todos los constructores 
    int equipoCargo;
    double bonificacion;
public:
    LiderTecnico(const std::string& n, int e, const std::string& f, 
        std::vector<std::string> l, double th, int dp, double td, int ec, double b):
        Empleado(n,e,f), Desarrollador(n,e,f,l,th), Disenador(n,e,f,dp,td), equipoCargo(ec),bonificacion(b) {}
    
    void info() override {
        Empleado::info();
        
        std::cout<<"Lenguajes que maneja: "<<std::endl;
        for(const auto& l: lenguajes) {
            std::cout<<l<<", ";
        }
        std::cout<<"\nTarifa por hora: "<<tarifaHora<<std::endl;
        std::cout<<"Dias del proyecto: "<<diasProy<<std::endl;
        std::cout<<"\nTarifa por dia: "<<tarifaDia<<std::endl;
    }

    double calcularSalario() override {
        std::cout<<"Salario de lider tecnico: "<<Desarrollador::calcularSalario() + Disenador::calcularSalario() <<std::endl;
        return Desarrollador::calcularSalario() + Disenador::calcularSalario();
    }

};

int main() {

    return 0;
}