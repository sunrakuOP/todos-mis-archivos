#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Estadistica {
protected:
    std::vector<double> datos;
public:
    Estadistica() = default;

    Estadistica& cargar(const std::vector<double>& vectCargar){
        datos = vectCargar;
        return *this;
    }
    
    double suma() {
        double sumatoria = std::accumulate(datos.begin(), datos.end(), 0.0);
        return sumatoria; // debo poner paraetro que inicia en 0
    }

    double promedio() {
        if(datos.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return 0;
        }
        return suma()/(double)datos.size();
    }

    double maxValor() {
        // max_element y min_element retorna iterador
        auto maxIt = std::max_element(datos.begin(), datos.end());
        return *maxIt; // devuelvo el valor desreferenciado
    }
    double minValor() {
        auto minIt = std::min_element(datos.begin(), datos.end());
        return *minIt;
    }

    Estadistica& ordenar() { // de mayor a menor
        std::sort(datos.begin(), datos.end());
        return *this;
    }
    // invertir orden, reverse
    Estadistica& invertir() {
        std::reverse(datos.begin(), datos.end());
        return *this;
    }
    // buscar con atd::find
    int buscar(double num) { // retorna el indice
        auto it = std::find(datos.begin(), datos.end(), num);
        if(it == datos.end()){
            std::cout<<"Numero no encontrado"<<std::endl;
            return -1;
        }
        return std::distance(datos.begin(), it); // retorna indice del elemento
    } 

    void mostrar() {
        if(datos.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return;
        }
        for(const auto& d: datos){
            std::cout<<d<<", ";
        }
        std::cout<<std::endl;
    }
};

int main() {
    Estadistica e;

    e.cargar({3.5, 7.2, 1.8, 9.0, 4.5, 6.3});
    e.mostrar();

    std::cout << "Suma: " << e.suma() << std::endl;
    std::cout << "Promedio: " << e.promedio() << std::endl;
    std::cout << "Maximo: " << e.maxValor() << std::endl;
    std::cout << "Minimo: " << e.minValor() << std::endl;

    std::cout << "Posicion 7.2: " << e.buscar(7.2) << std::endl;
    std::cout << "Posicion 99: " << e.buscar(99) << std::endl;

    e.ordenar();
    e.mostrar();

    e.invertir();
    e.mostrar();

    return 0;
}
