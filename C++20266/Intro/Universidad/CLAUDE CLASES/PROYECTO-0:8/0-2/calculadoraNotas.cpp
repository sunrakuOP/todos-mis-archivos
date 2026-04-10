#include <iostream>
#include <vector>
#include <memory>

class Materia {
protected:
    std::string nombreMateria;
    std::vector<double> notas;
public:
    Materia(const std::string& nm): nombreMateria(std::move(nm)) {}

    const std::string& getNombreMateria() const { return nombreMateria; }

    Materia& agregarNota(const double nota) {
        notas.push_back(nota);
        return *this;
    }

    double calcularPromedio() const {
        if(notas.empty()) {
            std::cout<<"Materia no tiene ninguna nota.."<<std::endl;
            return 0;
        }
        double suma = 0;
        for(const auto& n: notas) {
            suma += n;
        }
        return suma/ (int)notas.size();
    }

    void materiaInfo() const {
        std::cout<<"Nombre materia: "<<nombreMateria<<std::endl;
        if(notas.empty()) {
            std::cout<<"No hay notas"<<std::endl;
            return;
        }
        for(const auto& n: notas) {
            std::cout<<n<<", ";
        }
        std::cout<<std::endl;
        std::cout<<"Promedio de materia: "<<Materia::calcularPromedio()<<std::endl;
    }

};

class Estudiante {
protected:
    std::string nombre;
    int id;
    std::vector<std::shared_ptr<Materia>> materias;
public:
    Estudiante(const std::string& n, int i): nombre(std::move(n)), id(i) {}

    const std::string& getNombre() const { return nombre; }

    Estudiante& agregarMateria(const std::shared_ptr<Materia>& materia) {
        for(const auto& m: materias) {
            if(materia->getNombreMateria() == m->getNombreMateria()) {
                std::cout<<"Materia ya agregada"<<std::endl;
                return *this;
            }
        }
        materias.push_back(materia);
        return *this;
    }

    void mostrarMaterias() const {
        if(materias.empty()) {
            std::cout<<"np hay materias"<<std::endl;
            return;
        }
        for(const auto& m: materias) {
            m->materiaInfo();
        }
    }

    // promedio general de materias
    double promedioMaterias() const {
        if(materias.empty()) {
            std::cout<<"No hay materias a promediar"<<std::endl;
            return 0;
        }
        double sumaTotal = 0;
        for(const auto& m: materias) {
            sumaTotal += m->calcularPromedio();
        }
        return sumaTotal / (int)materias.size();
    }
};

class Sistema {
protected:
    std::vector<std::unique_ptr<Estudiante>> estudiantes;
    std::vector<std::shared_ptr<Materia>> materias;
public:
    Sistema() = default;
    // destructor no es necesario
    Sistema& agregarEstudianteExistente(const std::unique_ptr<Estudiante>& estudiante) {
        for(const auto& e: estudiantes) {
            if(e->getNombre() == estudiante->getNombre()) {
                std::cout<<"Estudiante ya agregado"<<std::endl;
                return *this;
            }
            if(e == estudiante) {
                std::cout<<"Estudiante ya agregado (misma direccion)"<<std::endl;
                return *this;
            }
        }
        estudiantes.push_back(std::move(estudiante));
        return *this;
    }

    Sistema& agregarEstudianteNuevo(const std::string& n, int i) {
        estudiantes.push_back(std::make_unique<Estudiante>(n,i));
        return *this;
    }

    Sistema& agregarMateriaExistente(const std::shared_ptr<Materia> materia) {
        for(const auto& m: materias) {
            if(m->getNombreMateria() == materia->getNombreMateria()) {
                std::cout<<"Materia ya agregada"<<std::endl;
                return *this;
            }
            if(m == materia) {
                std::cout<<"Materia ya agregada (misma direccion)"<<std::endl;
                return *this;
            }
        }
        materias.push_back(materia);
        return *this;
    }

    Sistema& agregarMateriaNueva(const std::string& nm) {
        materias.push_back(std::make_shared<Materia>(nm));
        return *this;
    }

    void menu() const {
        // mirar como hacer el menu, despues hacer el ejercicio usando punteros crudos
    }
};   

int main() {

    return 0;
}