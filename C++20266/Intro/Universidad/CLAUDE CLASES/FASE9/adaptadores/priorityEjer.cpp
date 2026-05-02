#include <iostream>
#include <queue>
// priority queue

class Emergencia{
protected:
    std::priority_queue<std::pair<int, std::string>> pacientes;
public:
    Emergencia& agregarPaciente(int prioridad, const std::string& nombre) {
        pacientes.push({prioridad, nombre});
        return *this;
    }
    // acceder a elementos del pair con .first y .second
    Emergencia& atender() { // el de mayor prioridad
        if(pacientes.empty()){
            std::cout<<"Fila de pacientes vacia..."<<std::endl;
            return *this;
        }
        std::cout<<"Mayor prioridad: "<<pacientes.top().second
            <<" con prioridad: "<<pacientes.top().first <<std::endl;

        pacientes.pop();
        return *this;
    }
    void mostrarSiguiente() const {
        if(pacientes.empty()) {
            std::cout<<"Fila vacia..."<<std::endl;
            return;
        }
        std::cout<<"Paciente a atender: "<<pacientes.top().second
            <<" con prioridad: "<<pacientes.top().first<<std::endl;
    }

    bool hayPacientes() { return !pacientes.empty(); }
};

int main() {
    Emergencia sala;

    sala.agregarPaciente(3, "Ana")
        .agregarPaciente(9, "Carlos")
        .agregarPaciente(1, "Luis")
        .agregarPaciente(7, "Maria");

    sala.mostrarSiguiente(); // Carlos (prioridad 9)

    sala.atender(); // Carlos
    sala.atender(); // Maria
    sala.atender(); // Ana
    sala.atender(); // Luis
    sala.atender(); // vacía

    return 0;
}
