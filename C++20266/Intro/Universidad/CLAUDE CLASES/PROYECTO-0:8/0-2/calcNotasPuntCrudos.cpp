#include <iostream>
#include <vector> 
#include <string>

class Materia {
protected:
    std::string nombreMateria;
    std::vector<double> notas;
public:
    Materia(const std::string& nm): nombreMateria(std::move(nm)) {}

    const std::string& getNombre() const { return nombreMateria; }
    
    Materia& agregarNota(double nota) {
        notas.push_back(nota);
        return *this;
    }

    double calcularPromedio() const {
        double sumaNotas = 0;
        if(notas.empty()) {
            std::cout<<"Vector vacio, nada que calcular"<<std::endl;
            return 0;
        }
        for(const auto& n: notas) {
            sumaNotas += n;
        }
        return sumaNotas / (int)notas.size();
    }

    void infoMateria() const {
        std::cout<<"Nombre de materia: "<<nombreMateria<<std::endl;
        if(notas.empty()) {
            std::cout<<"No hay notas"<<std::endl;
            return;
        }
        std::cout<<"Notas: "<<std::endl;
        for(const auto& n: notas) {
            std::cout<<n<<", ";
        }
        std::cout<<std::endl;
        std::cout<<"Promedio de la materia: "<<Materia::calcularPromedio()<<std::endl;
    }
};

class Estudiante {
protected:
    std::string nombreEstudiante;
    int id;
    std::vector<Materia*> materias;
public:
    Estudiante(const std::string& ne, int i): nombreEstudiante(std::move(ne)), id(i) {}
    ~Estudiante() {
        for(const auto& m: materias) {
            delete m;
        }
    }

    const std::string& getNombreEst() const { return nombreEstudiante; }
    // solo agregar de una forma, de 0 desde estudiante
    Estudiante& agregarMateria(const std::string& nm) {
        for(const auto& m: materias) {
            if(m->getNombre() == nm) {
                std::cout<<"Materia ya agregada.."<<std::endl;
                return *this;
            }
        }
        materias.push_back(new Materia(nm));
        return *this;
    }
    // agregar nota de materia por nombre
    Estudiante& agregarNota(const std::string& nm, double nota) {
        for(const auto& m: materias) {
            if(m->getNombre() == nm) {
                m->agregarNota(nota);
                return *this;
            }
        }
        std::cout<<"Materia no encontrada"<<std::endl;
        return *this;
    }

    void infoEstudiante() const {
        std::cout<<"Nombre estudiante: "<<nombreEstudiante<<", id: "<<id<<std::endl;
        if(materias.empty()) {
            std::cout<<"No hay materias para mostrar.."<<std::endl;
            return;
        }
        for(const auto& m: materias) {
            m->infoMateria();
        }
    }

    double promedioGeneral() const {    
        double sumaTotal = 0;
        if(materias.empty()){
            std::cout<<"No hay materias"<<std::endl;
            return 0;
        }
        for(const auto& m: materias) {
            sumaTotal += m->calcularPromedio();
        }
        return sumaTotal / (int)materias.size();
    }
};

class Sistema {
protected:  
    std::vector<Estudiante*> estudiantes;
    // cada estudiante tiene sus propias materias
public:
    Sistema() = default;
    ~Sistema() {
        // solo hacerle destructor al que compone
        // estudiante ya destruye sus materias
        for(const auto& e: estudiantes) {
            delete e;
        }
        estudiantes.clear();
    }
    // hacerle el destructor
    Sistema& agregarEstudidiante(const std::string& nombre, int id) {
        estudiantes.push_back(new Estudiante(nombre, id));
        return *this;
    }

    Sistema& buscarEstudiante(const std::string& nombre) {
        for(const auto& e: estudiantes) {
            if(nombre == e->getNombreEst()) {
                e->infoEstudiante();
            }
        }
        std::cout<<"Estudiante no encontrado.."<<std::endl;
    }
};




int main() {

    return 0;
}

/*
El problema con punteros crudos es no saber quien libera la memoria
La clase o el main?

cuando no hacer delete
1. puntero a obj del stack (nunca hacer delete, se destruye al salir del scope)
2. Puntero que observa, alguien mas es dueno
3. Puntero que es dueno, debe de hacer delete 

Retornar por referencia
!!! Solo si el objeto ya existe y va a seguir existiendo
    No devolver referencia a una variable local

Retornar puntero ???
    Solo si no eres dueno

    
*/