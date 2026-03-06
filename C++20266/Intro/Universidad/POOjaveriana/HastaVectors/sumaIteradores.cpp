#include <iostream>
#include <vector>

// recorrer vectores usando iteradores 
int main() {
    std::vector<int> numeros = {1,2,3,4,5,6,7,8,9,0};
    int sumatoria = 0;

    // hacer sumatoria de vector usando iteradores 
    for (auto it = numeros.begin(); it != numeros.end(); ++it) {
        std::cout<< *it <<" ";     // imprimir el vector al mismo tiempo
        sumatoria += *it;
    }
    std::cout<< std::endl;    // salto de linea entre textos
    std::cout<<"Sumatoria es: "<<sumatoria <<std::endl;

    return 0;
}