#include <iostream>
#include <vector>

std::vector<double> pedirDatos(size_t n) {
    std::vector<double> promedios;
    double datoActual;
    for(size_t i = 0; i < n; ++i) {
        std::cout<<"Digite dato numero "<< i+1 <<": "<<std::endl;
        std::cin>> datoActual;
        promedios.push_back(datoActual);
    }
    return promedios;
}

void mostrar(const std::vector<double>& promedios){
    for(size_t i = 0; i < promedios.size(); ++i) {
        std::cout << promedios.at(i) << " ";
    }
    std::cout << std::endl;
}

double promedio(std::vector<double>& promedios) {
    double sumatoria = 0;
    for (size_t i =0; i < promedios.size(); ++i) {
        sumatoria += promedios.at(i);
    }
    return sumatoria / promedios.size();
}

int main() {
    size_t numeroDatos;
    std::cout<<"Digite el numero de datos: "<<std::endl;
    std::cin>>numeroDatos;

    std::vector<double> vect = pedirDatos(numeroDatos);
    mostrar(vect);

    double prom = promedio(vect);
    std::cout<<"Promedio del vector: "<< prom <<std::endl;
    
    return 0;
}