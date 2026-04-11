#include <iostream>
#include <vector>

enum class Cargos {
    Desarrollador,
    Disenador,
    Gerente
};

class Empleado {
protected:
    std::string nombre;
    double salarioBase;
public:
    Empleado(const std::string& no, double sb): nombre(no), salarioBase(sb) {}
    virtual ~Empleado() = default;

    virtual double salario() = 0;
    virtual std::string cargo() = 0;
    virtual void info() {
        std::cout<<"Nombre: "<<nombre<<", salario base: "<<salarioBase<<std::endl;
    }
};

class Desarrollador: public Empleado {
protected:
    std::string lenguaje;
public: 
    Desarrollador(const std::string& no, double sb, const std::string& l):
        Empleado(no, sb), lenguaje(l) {}
    
    double salario() override {
        return salarioBase+50;
    }
    std::string cargo() override {
        return "Desarrollador";
    }
    void info() override {
        Empleado::info();
        std::cout<<"Lenguaje: "<<lenguaje<<",salario desarrollador: "
            <<Desarrollador::salario()<<std::endl;
    }
};
class Disenador: public Empleado {
protected:
    std::string herramienta;
public:
    Disenador(const std::string& no, double sb, const std::string& h):
        Empleado(no, sb), herramienta(h) {}

    double salario() override {
        return salarioBase+300;
    }
    std::string cargo() override {
        return "Disenador";
    }
    void info() override {
        Empleado::info();
        std::cout<<"Herramienta: "<<herramienta<<",salario disenador: "
            <<Disenador::salario()<<std::endl;
    }   
};

class Gerente: public Empleado {
protected:
    int numPerCargo;
public:
    Gerente(const std::string& no, double sb, int np): Empleado(no,sb), numPerCargo(np) {}

    double salario() override {
        return salarioBase+1000;
    }
    std::string cargo() override {
        return "Gerente";
    }
    void info() override {
        Empleado::info();
        std::cout<<"Personas a cargo: "<<numPerCargo<<",salario gerente: "
            <<Gerente::salario()<<std::endl;
    }   
};

class Empresa {
protected:
    std::vector<std::unique_ptr<Empleado>> empleados;
public:
    // constructor default
    Empresa() = default;

    // empleado ya creado con unique
    Empresa& agregar(std::unique_ptr<Empleado> e) {
        empleados.push_back(std::move(e));
        return *this;
    }

    // POLIMORFISMO REAL
    // hacer downcasting
    void inspeccionar() {
        for(const auto& e: empleados) {
            Empleado* ptr = e.get(); // guardo el puntero como crudo temporalmente
            if (Desarrollador* d = dynamic_cast<Desarrollador*>(ptr)) {
                d->info();
            } else if (Disenador* dd = dynamic_cast<Disenador*>(ptr)) {
                dd->info();
            } else if (Gerente* g = dynamic_cast<Gerente*>(ptr)) {
                g->info();
            }
        }
    }
    
};


int main() {

    return 0;
}