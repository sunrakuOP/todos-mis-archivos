#include <iostream>
#include <vector>

// interfaces 
class IFacturable {
public: // si no pongo public 
    // recordar que son virtual, obligan a implementarla en sus derivadas
    virtual double calcularCosto() = 0;
};

// abstracta, que tiene al menos un metodo virtual
class Persona {
protected:  
    std::string nombre;
    int edad;
public:
    Persona(const std::string& no, int e): nombre(no), edad(e) {}

    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    virtual void mostrarInfo() const {
        std::cout<<"Nombre: "<<nombre<<", edad: "<<edad<<std::endl;
    }
};

class Paciente: virtual public Persona, public IFacturable {
protected:
    std::vector<std::string> historialMedico;
public:
    Paciente(const std::string& no, int e): Persona(no,e) {}

    Paciente& agregarDiagnostico(std::string d) {
        historialMedico.push_back(d);
        return *this;
    }
    
    // implementar interfaz
    double calcularCosto() {
        double costo = historialMedico.size()*50;
        std::cout<<"Total a pagar paciente "<<Persona::getNombre()<<": "<<costo<<std::endl;
        return costo;
    }

};

class Medico: virtual public Persona {
protected:
    std::string especialidad;
    Paciente* pacienteAct; // compone a paciente, puede o no tener asignado
public:
    Medico(const std::string& no, int e, const std::string& es): Persona(no,e), especialidad(es), pacienteAct(nullptr) {}
    
    Medico& asignarPaciente(Paciente* p) {
        if(pacienteAct != nullptr) {
            std::cout<<"Paciente ya tiene asignado un medico"<<std::endl;
            return *this;
        }
        pacienteAct = p; // le asigno un paciente al medico
        std::cout<<"Medico asignado a paciente "<<p->getNombre()<<std::endl;
        return *this;
    }
    Medico& liberar() { 
        if(pacienteAct != nullptr) {
            std::cout<<"Liberando medico"<<std::endl;
            pacienteAct = nullptr; 
            return *this;
        }
        else{
            std::cout<<"Medico esta libre, ningun paciente asignado"<<std::endl;
            return *this;
        }
    }

    void mostrarInfo() const {
        Persona::mostrarInfo();
        std::cout<<"Especialidad: "<<especialidad<<std::endl;
    }
};

class Sala: public IFacturable {
protected:  
    int numero, capacidad;
    std::vector<Paciente*> pacientes;
public:
    Sala(int n, int cap): numero(n), capacidad(cap) {}

    virtual ~Sala() = default; // porque es abstracta, necesita destructor virtual

    Sala& admitir(Paciente* p) {
        if((int)pacientes.size() < capacidad) {
            pacientes.push_back(p);
            return *this;
        }
        else {
            std::cout<<"Capacidad max alcanzada"<<std::endl;
            return *this;
        }
    }

    virtual std::string tipo() = 0;
};
class SalaGeneral: public Sala { 
    // puedo acceder directamente a los atributos y metodos de Sala (padre)
public:
    SalaGeneral(int n, int cap): Sala(n,cap) {}

    double calcularCosto() {
        std::cout<<"Costo de la sala general: "<<pacientes.size()*100<<std::endl;
        return pacientes.size()*100;
    }

    std::string tipo() {
    return "General";
    }
};
class SalaUCI: public Sala {
public:
    SalaUCI(int n, int cap): Sala(n,cap) {}

    double calcularCosto() {
        std::cout<<"Costo de la sala UCI: "<<pacientes.size()*500<<std::endl;
        return pacientes.size()*500;
    }

    std::string tipo() {
        return "UCI";
    }
};

class Hospital {
protected:

    std::vector<Medico> medicos;
    std::vector<Sala*> salas; // porque puede ser General o UCI
public:
    Hospital& agregarMedico(Medico m) { 
        medicos.push_back(m); 
        return *this; 
    }
    Hospital& agregarSala(Sala* s) { 
        salas.push_back(s);  
        return *this;
    }

    void mostrarOcupacion() {
        std::cout<<"MEDICOS"<<std::endl;
        for(const auto& m: medicos) {
            m.mostrarInfo();
        }
        std::cout<<"SALAS"<<std::endl;
        for(const auto& s: salas) {
            std::cout<< s->tipo()<<std::endl;
        }
    }

    // ya en salas tengo agregados los pacientes, solo itero desde ahi
    double facturaTotal() {
        double sumatoria = 0;
        for(const auto& s: salas) {
            sumatoria += s->calcularCosto();
        }   
        return sumatoria;
    }

};

int main() {
    // pacientes
    Paciente p1("Carlos", 45);
    Paciente p2("Maria", 32);
    Paciente p3("Luis", 60);

    p1.agregarDiagnostico("Fractura").agregarDiagnostico("Hipertension");
    p2.agregarDiagnostico("Gripe");
    p3.agregarDiagnostico("Diabetes").agregarDiagnostico("Cardiopatia").agregarDiagnostico("Insuficiencia renal");

    // medicos
    Medico m1("Dr. Gomez", 50, "Cardiologia");
    Medico m2("Dra. Lopez", 38, "Traumatologia");

    m1.asignarPaciente(&p1);
    m2.asignarPaciente(&p2);

    // salas
    SalaGeneral sg(1, 5);
    SalaUCI uci(2, 2);

    sg.admitir(&p1).admitir(&p2);
    uci.admitir(&p3);

    // hospital
    Hospital h;
    h.agregarMedico(m1).agregarMedico(m2);
    h.agregarSala(&sg).agregarSala(&uci);

    h.mostrarOcupacion();

    std::cout<<"\n--- FACTURA TOTAL ---"<<std::endl;
    std::cout<<"Total: "<<h.facturaTotal()<<std::endl;

    return 0;
}