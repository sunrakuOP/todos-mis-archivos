#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

enum class Tipo {
    fijo,
    contrato
};

class Empleado{
protected:
    std::string nombre;
    std::string departamento;
    double salario;
    int aniosExper;
public:
    Empleado(const std::string& n, const std::string& d, double s, int ae):
        nombre(std::move(n)), departamento(std::move(d)), salario(s), aniosExper(ae) {}
    // destructor vitual 
    virtual ~Empleado() = default;
    
    const std::string& getNombre() const { return nombre; }
    const std::string& getDepart() const { return departamento; }
    double getSalario() const { return salario; }
    int getAniosExp() const { return aniosExper; }

    virtual double calcularBono() const = 0;
};
class EmpleadoFijo: public Empleado {
    // no tiene atributos extra
public:
    EmpleadoFijo(const std::string& n, const std::string& d, double s, int ae):
        Empleado(n,d,s,ae) {}
    
    double calcularBono()const override {
        std::cout<<"Bono: "<< salario/10<<std::endl;
        return salario/10;
    }
};
class EmpleadoContrato: public Empleado {
protected:
    int duracionMeses;
public:
    EmpleadoContrato(const std::string& n, const std::string& d, double s, int ae, int dm):
        Empleado(n,d,s,ae), duracionMeses(dm) {}

    int getDuracionMeses() const { return duracionMeses; }

    double calcularBono() const override {
        if(duracionMeses < 6) {
            std::cout<<"No hay bono, duracion de meses baja"<<std::endl;
            return 0.0;
        }
        std::cout<<"Bono: "<<salario/20<<std::endl;
        return salario/20;
    }
    
};

class Oficina {
protected:
    std::vector<Empleado*> empleados;
public:
    Oficina() = default;

    ~Oficina() {
        for(const auto& e: empleados){
            delete e;
        }
        empleados.clear();
    }
    // agregar empleado desde la mimsa clase
    Oficina& agregarEmpleado(Tipo tipo, const std::string& n, const std::string& d, double s, int ae, int dm=0){
        for(const auto& e: empleados){
            if(e->getNombre() == n){
                std::cout<<"Empleado ya agregado.."<<std::endl;
                return *this;
            }
        }
        switch (tipo)
        {
        case Tipo::fijo: {
            empleados.push_back(new EmpleadoFijo(n,d,s,ae));
            break;
        }
        case Tipo::contrato: {
            empleados.push_back(new EmpleadoContrato(n,d,s,ae,dm));
            break;
        }
        default:
            std::cout<<"Tipo invalido.."<<std::endl;
            break;
        }
        return *this;
    } 

    // si lo quisiera hacer con accomulate a ver
    double calcularBonoTotal() const {
        if(empleados.empty()){
            std::cout<<"Oficina vacia..."<<std::endl;
            return 0.0;
        }
        double suma = std::accumulate(empleados.begin(), empleados.end(), 0.0,
            [](double suma, const Empleado* e){return suma + e->calcularBono(); });
        return suma;
    }

    // encontrar solo tipo contrato y ver cuantos meses llevan
    void mesesContrato() {
        if(empleados.empty()){
            std::cout<<"Lista empleado vacia"<<std::endl;
            return;
        }
        for(const auto& e: empleados){
            EmpleadoContrato* ptrCr = dynamic_cast<EmpleadoContrato*>(e);
            if(ptrCr != nullptr){
                std::cout<<ptrCr->getNombre()<<" es empleado de contrato"<<std::endl;
                std::cout<<"Numero meses: "<<ptrCr->getDuracionMeses()<<std::endl;
            }
        }
    }
    // ordenar por salario
    Oficina& ordenarPorSalario() {
        std::sort(empleados.begin(), empleados.end(), 
            [](const Empleado* a, const Empleado* b){return a->getSalario() < b->getSalario(); });
        return *this;
    }
    // empleado con max experiencia
    Empleado* masExperiencia() {
        auto it = std::max_element(empleados.begin(), empleados.end(), 
            [](const Empleado* a, const Empleado* b){return a->getAniosExp() < b->getAniosExp();});

            std::cout<<"Empleado con mas experiencia: "<<(*it)->getNombre()<<", "
                <<(*it)->getAniosExp()<<" anios"<<std::endl;
            return *it;
            // iterador funciona como puntero, debo desreferenciarlo
    }

    double salarioTotal() const {
        if(empleados.empty()){
            std::cout<<"No hay empleados en la oficina..."<<std::endl;
            return 0.0;
        }
        // sumatoria debe mostrar que arranca en 0
        double suma = std::accumulate(empleados.begin(), empleados.end(), 0.0,
            [](double suma, const Empleado* a){return suma + a->getSalario(); });
        std::cout<<"Salario total de la oficina: "<<suma<<std::endl;
        return suma;
    }

    int contarPorSalario(double salarComp){
        if(empleados.empty()){
            std::cout<<"No hay empleados en la oficina..."<<std::endl;
            return 0;
        }
        int cuenta = std::count_if(empleados.begin(), empleados.end(),
            [salarComp](const Empleado* a){ return salarComp < a->getSalario(); });
        std::cout<<"Numero empleados ganando mas de: "<<salarComp<<": "<<cuenta<<std::endl;
        return cuenta;
    }

    Oficina& eliminarMenosDosAnios() {
        for(auto it = empleados.begin(); it != empleados.end();){
            if((*it)->getAniosExp() < 2){
                delete *it;
                it = empleados.erase(it);
            } else {
                ++it;
            }
        }
        return *this;
    }

    void menu() {
        int opcion;
        do {
            std::cout<<"0. Salir"<<std::endl;
            std::cout<<"1. Agregar empleado"<<std::endl;
            std::cout<<"2. Calcular bono total"<<std::endl;
            std::cout<<"3. Mostrar meses contrato (para empl.contratados): "<<std::endl;
            std::cout<<"4. Ordenar por salario"<<std::endl;
            std::cout<<"5. Empleado con mas experiencia"<<std::endl;
            std::cout<<"6. Calcular salario total"<<std::endl;
            std::cout<<"7. Eliminar menos de dos anios de exp"<<std::endl;
            std::cout<<"8. Contar por salario"<<std::endl;
            std::cout<<"Digite una opcion: "<<std::endl;
            std::cin>>opcion;

            switch (opcion)
            {
            case 1: {
                int tipoInt;
                std::string nombre, departamento;
                double salario;
                int aniosExp;
                std::cout<<"0. fijo, 1. contratado"<<std::endl;
                std::cout<<"Digite tipo: "<<std::endl;
                std::cin>>tipoInt;
                std::cout<<"Digite nombre: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout<<"Digite departamento: "<<std::endl;
                std::getline(std::cin, departamento);
                std::cout<<"Digite salario: "<<std::endl;
                std::cin>>salario;
                std::cout<<"Digite anios experiencia: "<<std::endl;
                std::cin>>aniosExp;
                Tipo it = static_cast<Tipo>(tipoInt);
                if(it == Tipo::fijo){
                    agregarEmpleado(it,nombre,departamento,salario,aniosExp);
                } else {
                    int nMeses;
                    std::cout<<"Digite meses de contrato: "<<std::endl;
                    std::cin>>nMeses;
                    agregarEmpleado(it,nombre,departamento,salario,aniosExp,nMeses);
                }
                break;
            }
            case 2: {
                calcularBonoTotal();
                break;
            }
            case 3: {
                mesesContrato();
                break;
            }
            case 4: {
                ordenarPorSalario();
                break;
            }
            case 5: {
                masExperiencia();
                break;
            }
            case 6: {
                salarioTotal();
                break;
            }
            case 7: {
                eliminarMenosDosAnios();
                break;
            }
            case 8: {
                double salarComp;
                std::cout<<"Digite el salario a comparar: "<<std::endl;
                std::cin>>salarComp;
                contarPorSalario(salarComp);
                break;
            }
            default:
                std::cout<<"Opcion invalida..."<<std::endl;
                break;
            }

        } while(opcion != 0);
    } 

};


int main() {
    Oficina o; 
    o.menu();
    
    
    

    return 0;
}