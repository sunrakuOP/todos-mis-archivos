// practicar ejercicios cuando varios objetos apuntan al mismo puntero
// ejemplo: paciente puede tener varias clases
#include <memory>
#include <iostream>
#include <vector>
#include <string>

class Paciente {
protected:
    std::string nombre;
    int edad;
    std::vector<std::string> historial;
public:
    Paciente(const std::string& n, int e): nombre(n), edad(e) {}

    Paciente& agregarDiagnostico(const std::string& d) {
        historial.push_back(d);
        return *this;
    }

    void mostrarHistorial() const {
        for(const auto& h: historial) {
            std::cout<<h<<", ";
        } 
        std::cout<<std::endl;
    }
};

class Medico {
protected:
    std::string nombre;
    std::string especialidad;
    std::shared_ptr<Paciente> pacienteActual; // puede o no tener paciente
public:
    Medico(const std::string& n, const std::string& e): nombre(n), especialidad(e) {}

    Medico& asignarPaciente(std::shared_ptr<Paciente> p) {
        pacienteActual = p;
        return *this;
    }
    Medico& liberar() {

    }
    
    
};


int main() {

    return 0;
}