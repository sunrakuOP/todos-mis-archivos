#include <iostream>
#include <deque>
#include <vector>

class Sistema {
protected:
    std::vector<std::string> historial;
    std::deque<std::string> cola;
public:
    Sistema() = default;

    Sistema& agregarPaciente(const std::string& paciente) {
        cola.push_back(paciente);
        return *this;
    }
    // agregar urgente lo adiciona al inicio
    Sistema& agregarUrgente(const std::string& paciente) {
        cola.push_front(paciente);
        return *this;
    }

    Sistema& atender() {
        if(cola.empty()) {
            std::cout<<"No hay pacientes en cola.."<<std::endl;
            return *this;
        }
        std::cout<<"Atendiendo paciente..."<<std::endl;
        historial.push_back(cola.at(0));
        cola.pop_front();

        return *this;
    }

    void mostrarCola() {
        if(cola.empty()) {
            std::cout<<"Cola vacia"<<std::endl;
            return;
        }
        std::cout<<"Cola: "<<std::endl;
        for(const auto& c: cola) {
            std::cout<<c<<", ";
        }
        std::cout<<std::endl;
    }
    void mostrarHistorial() {
        if(historial.empty()) {
            std::cout<<"Histortial vacio"<<std::endl;
            return;
        }
        std::cout<<"Historial: "<<std::endl;
        for(const auto& h: historial) {
            std::cout<<h<<", ";
        }
        std::cout<<std::endl;    
            
        
    }

};

int main() {
        /*
    std::vector<int> v = {1,2,3,4,5};
    // vector solo permite anadir/eliminar elementos al final
    v.push_back(6);

    std::deque<int> d = {2,3,4,5};
    d.push_front(1); // anade elemento al inicio
    d.push_back(6);

    */

    Sistema s;

    s.agregarPaciente("Carlos")
     .agregarPaciente("Isa")
     .agregarPaciente("Luis");

    s.mostrarCola(); // Carlos, Ana, Luis

    s.agregarUrgente("Jose"); // va al frente
    s.mostrarCola(); // Maria, Carlos, Ana, Luis

    s.atender(); // atiende a Jose
    s.atender(); // atiende a Carlos
    s.mostrarCola();     //  Isa, Luis
    s.mostrarHistorial(); // Jose, Carlos

    s.atender().atender().atender(); // atiende Ana, Luis, y uno más (cola vacía)

    return 0;
}