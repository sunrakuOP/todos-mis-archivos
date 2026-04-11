#include <iostream>
#include <vector>
#include <memory>

enum class Tipo{
    programador,
    disenador,
    gerente
};

class Empleado {
protected: 
    std::string nombre;
    double salarioBase;
public:
    Empleado(const std::string& n, double sb): nombre(std::move(n)), salarioBase(sb) {}
    // destructor virtual
    virtual ~Empleado() = default;

    virtual double salario() = 0;
    virtual std::string cargo( ) = 0;
    virtual void info() {
        std::cout<<"Nombre: "<<nombre<<", salario base: "<<salarioBase<<std::endl;
    }
};

class Programador: public Empleado {
protected:
    std::string lenguaje;
public:
    Programador(const std::string& n, double sb, const std::string& l):
        Empleado(n,sb), lenguaje(std::move(l)) {}
    
    double salario() override {
        return salarioBase + 500;
    }
    std::string cargo() override {
        return "Programador";
    }
    void info() override {
        Empleado::info();
        std::cout<<"Salario programador: "<<Programador::salario()<<" cargo: "
            <<Programador::cargo()<<std::endl;
    }
    // metodo propio de Pogramador(clase derivada)
    void debugger() {
        std::cout<<"Debuggeando en: "<<lenguaje<<std::endl;
    }

};
class Disenador: public Empleado {
protected:
    std::string herramienta;
public:
    Disenador(const std::string& n, double sb, const std::string& h):
        Empleado(n,sb), herramienta(std::move(h)) {}
    
    double salario() override {
        return salarioBase + 300;
    }
    std::string cargo() override {
        return "Disenador";
    }
    void info() override {
        Empleado::info();
        std::cout<<"Salario dinseador: "<<Disenador::salario()<<" cargo: " 
            <<Disenador::cargo()<<std::endl;
    }
    
    void prototipar() {
        std::cout<<"Prototipando en: "<<herramienta<<std::endl;
    }
};
class Gerente: public Empleado {
protected:
    std::vector<std::string> nombresEquipo;
public:
    Gerente(const std::string& n, double sb): Empleado(n,sb) {}
    
    Gerente& agregarMiembro(const std::string& n) {
        nombresEquipo.push_back(n);
        return *this;
    }
    double salario() override {
        return salarioBase + 1000;
    }
    std::string cargo() override {
        return "Gerente";
    }
    void info() override {
        Empleado::info();
        std::cout<<"Trabajadores a cargo: "<<std::endl;
        if(nombresEquipo.empty()) {
            std::cout<<"Vacio..."<<std::endl;
            return;
        }
        for(const auto& n: nombresEquipo){
            std::cout<<n<<", ";
        }
        std::cout<<std::endl;
    }
    void reunir() {
        if(nombresEquipo.empty()) {
            std::cout<<"Vacio..."<<std::endl;
            return;
        }
        std::cout<<"Reuniendo.."<<std::endl;
        for(const auto& n: nombresEquipo){
            std::cout<<n<<", ";
        }
        std::cout<<std::endl;
    }
};

class Empresa {
protected:
    std::vector<std::unique_ptr<Empleado>> empleados;
public:
    Empresa() = default;
    // no debo hacer eliminacion manual
    Empresa& agregarEmpleado(Tipo t, const std::string& n, double sb, const std::string& extra1="") {
        if(t == Tipo::programador) {
            empleados.push_back(std::make_unique<Programador>(n,sb,extra1));
            return *this;
        } else if(t == Tipo::disenador) {
            empleados.push_back(std::make_unique<Disenador>(n,sb,extra1));
            return *this;
        } else if(t == Tipo::gerente) {
            empleados.push_back(std::make_unique<Gerente>(n,sb));
            return *this;
        }
        std::cout<<"Tipo no aceptado.."<<std::endl;
        return *this;
    }
    // polimorfismo con virtual
    double nominaTotal() {
        if(empleados.empty()) {
            std::cout<<"Vacio..."<<std::endl;
            return 0;
        }
        double sumaTotal = 0;
        for(const auto& e: empleados) {
            sumaTotal += e->salario();
        }
        std::cout<<"Nominal total: "<<sumaTotal<<std::endl;
        return sumaTotal;
    }
    // dynamic cast para metodos propios, debo usar puntero crudo
    void trabajar(size_t i) {
        if(empleados.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return;
        } else if(i >= empleados.size()) {
            std::cout<<"Indice no valido..."<<std::endl;
            return;
        }
        Empleado* ptrCrudo = empleados.at(i).get();
        if(Programador* proPtr = dynamic_cast<Programador*>(ptrCrudo)) {
            proPtr->debugger();
        } else if(Disenador* disPtr = dynamic_cast<Disenador*>(ptrCrudo)) {
            disPtr->prototipar();
        } else if(Gerente* gerPtr = dynamic_cast<Gerente*>(ptrCrudo)) {
            gerPtr->reunir();
        }
    }

    void mostrarTodos() const {
        if(empleados.empty()) {
            std::cout<<"Vector vacio..."<<std::endl;
            return;
        }
        std::cout<<"Empleados: "<<std::endl;
        for(const auto& e: empleados) {
            e->info();
        }
    }
};



int main() {

    return 0;
}