#include <iostream>
#include <vector>
#include <map>

class Calificacion {
protected:
    std::map<std::string, std::vector<double>> calificaciones;
public  :
    Calificacion() = default;
    
    Calificacion& agregarVectorNotas(const std::string materia, std::vector<double>& notas) { 
        for(const auto& n: notas) {
            calificaciones[materia].push_back(n);
        }
        return *this;
    }
    // agregar nota por nota
    Calificacion& agregarNota(const std::string& materia, double nota) {
        calificaciones[materia].push_back(nota);
        return *this;
    } // no hay que verificar nada

    double promedioMateria(const std::string& materia) const {
        auto it = calificaciones.find(materia);
        if(it == calificaciones.end()) {
            std::cout<<"Materia no registrada"<<std::endl;
            return 0;
        }
        double sumaP = 0;
        for(const auto& n: it->second) { // it->second es el vector(valor de clave materia)
            sumaP += n;
        }
        std::cout<<"Promedio: "<<materia<<": "<<sumaP/(int)it->second.size() <<std::endl;
        return sumaP/(int)it->second.size();
    }

    void mejorMateria() const {
        double mejorProm = 0;
        for(const auto&[nombre, notas]: calificaciones){
            if(Calificacion::promedioMateria(nombre) > mejorProm) {
                mejorProm = Calificacion::promedioMateria(nombre);
            }
        }
        std::cout<<"Mejor promedio: "<<mejorProm<<std::endl;
    }

    std::string mejorPromMateria() const {
        if(calificaciones.empty()) {
            return "";
        }
        double mayorProm = 0;
        std::string materia;
        for(const auto&[nombre, notas]: calificaciones) {
            double prom = promedioMateria(nombre); // a cada materia se le calcula prom
            if(prom > mayorProm) {
                mayorProm = prom;
                materia = nombre;
            }
        }
        std::cout<<"Materia mas alta: "<<materia<<", promedio: "<<mayorProm<<std::endl;
        return materia;
    }
};






int main() {

    return 0;
}