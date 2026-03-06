#include <iostream>
#include <vector>

std::vector<int> pedirValores(int numDatos) {
    std::vector<int> vectorUno;
    int datoActual;

    for (size_t i = 0; i < numDatos; ++i) {
        std::cout<<"Digite el valor numero "<< i+1 <<": "<<std::endl;
        std::cin>>datoActual;
        vectorUno.push_back(datoActual);
    }

    return vectorUno;
}


void mostrarVector(const std::vector<int>& vectorMostrar) {
    for (size_t i = 0; i < vectorMostrar.size(); i++){
        std::cout<< vectorMostrar.at(i) <<" ";
    }
}

int valorMayor(const std::vector<int>& mostrarVector) {
    int mayorActual = mostrarVector.at(0);
    for (size_t i = 0; i < mostrarVector.size(); i++) {
        if(mostrarVector.at(i) >= mayorActual) {
            mayorActual = mostrarVector.at(i); 
        }
    }

    return mayorActual;
}

int sumarValores(const std::vector<int>& vectorMostrar) {
    int sumatoria = 0;
    for (auto it = vectorMostrar.begin(); it != vectorMostrar.end(); it++){
        sumatoria += *it;
    }
    return sumatoria;
}

int main () {
    int datos;
    std::cout<<"Digite la cantidad de datos: "<<std::endl;
    std::cin>>datos;

    std::vector<int> vectorMostrar = pedirValores(datos);
    std::cout<<"El vector es: "<<std::endl;
    mostrarVector(vectorMostrar);

    int suma = sumarValores(vectorMostrar);
    std::cout<<std::endl;
    std::cout<<"La sumatoria es: "<< suma <<std::endl;

    int mayorNumero = valorMayor(vectorMostrar);
    std::cout<<"El valor mayor del arreglo es: "<< mayorNumero<<std::endl;
    
    return 0;
}