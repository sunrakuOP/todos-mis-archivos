#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Paciente {
protected:
    std::string nombre;
    std::vector<std::string> historial;
public:
    Paciente(const std::string& n): nombre(std::move(n)) {}

    Paciente& agregarHistorial(const std::string& historia) {
        for(const auto& h: historial) {
            if(h == historia) {
                std::cout<<"Historia ya en el historial"<<std::endl;
                return *this;
            }
        }
        historial.push_back(historia);
        return *this;
    }

    Paciente& eliminarHistoria(const std::string& historia) {
        for(auto it = historial.begin(); it != historial.end(); it++) {
            if(*it == historia) {
                std::cout<<"Borrando del historial"<<std::endl;
                historial.erase(it);
                return *this;
            }
        }
        std::cout<<"Historia no encontrada en el historial.."<<std::endl;
        return *this;
    }

    void info() const {
        std::cout<<"Paciente nombre: "<<nombre<<", con historial: "<<std::endl;
        if(historial.empty()) {
            std::cout<<"Historial vacio"<<std::endl;
            return;
        }
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
    std::vector<std::shared_ptr<Paciente>> pacientes; // medico puede atender varios pacientes
public:
    Medico(const std::string& n, const std::string& e): nombre(std::move(n)), especialidad(std::move(e)) {}

    Medico& agregarPaciente(const std::shared_ptr<Paciente>& paciente) {
        for(const auto& p: pacientes) {
            if(p == paciente) {
                std::cout<<"Paciente ya agregado.."<<std::endl;
                return *this;
            }
        }
        pacientes.push_back(paciente);
        return *this;
    }

    Medico& liberar(const std::shared_ptr<Paciente>& paciente) {
        for(auto it = pacientes.begin(); it != pacientes.end(); it++) {
            if(*it == paciente) {
                pacientes.erase(it);
                return *this;
            }
        }
        std::cout<<"Paciente no encontrado.."<<std::endl;
        return *this;
    }

    Medico& atender(const std::shared_ptr<Paciente>& paciente, const std::string& diagnostico) {
        for(const auto& p: pacientes) {
            if(p == paciente) {
                p->agregarHistorial(diagnostico);
                return *this;
            }
        }
        std::cout<<"Paciente no encontrado"<<std::endl;
        return *this;
    }
};

class Hospital {
protected:
    std::vector<std::shared_ptr<Paciente>> pacientes;
    std::vector<std::shared_ptr<Medico>> medicos;
public:
    Hospital() = default;
    // no necesito destructor
    Hospital& agregarPaciente(const std::shared_ptr<Paciente>& paciente) {
        for(const auto& p: pacientes) {
            if(p == paciente) {
                std::cout<<"Paciente ya agregado"<<std::endl;
                return *this;
            }
        }
        pacientes.push_back(paciente);
        return *this;
    }

    Hospital& agregarMedico(const std::shared_ptr<Medico>& medico) {
        for(const auto& m: medicos) {
            if(m == medico) {
                std::cout<<"Medico ya agregado.."<<std::endl;
                return *this;
            }
        }
        medicos.push_back(medico);
        return *this;
    }

    void mostrarPacientes() const {
        if(pacientes.empty()) {
            std::cout<<"No hay pacientes por mostrar"<<std::endl;
        }
        for(const auto& p: pacientes) {
            p->info();
            std::cout<<"Cuenta: "<<p.use_count()<<std::endl;
        }
    }
};


int main() {
    // crear pacientes
    auto p1 = std::make_shared<Paciente>("Sebastian");
    auto p2 = std::make_shared<Paciente>("Esteban");
    p1->agregarHistorial("Dolor estomago").agregarHistorial("Fractura").agregarHistorial("Dolor cabeza");
    p2->agregarHistorial("Resfriado").agregarHistorial("Migrana");

    // crear medicos
    auto m1 = std::make_shared<Medico>("Juan","Pediatra");
    auto m2 = std::make_shared<Medico>("Frank","General");
// asignar el mismo paciente a dos medicos
    m1->agregarPaciente(p1);
    m2->agregarPaciente(p2);

    Hospital hospital;
    hospital.agregarPaciente(p1).agregarPaciente(p2);
    hospital.agregarMedico(m1).agregarMedico(m2);

    hospital.mostrarPacientes();

    m1->atender(p1, "Hipertension");
    m2->atender(p1, "Diabetes");

    m1->liberar(p1);
    hospital.mostrarPacientes();

    return 0;
}