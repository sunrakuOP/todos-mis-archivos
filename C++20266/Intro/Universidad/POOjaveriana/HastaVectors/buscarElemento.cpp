#include <iostream>
#include <vector>

// recorrer vectores usando iteradores 
int main() {
    std::vector<int> numeros = {1,2,3,4,5,6,7,8,9,0};
    int numeroBuscar;
    bool encontrado = false;
    // mostrar el arreglo antes de buscar el numero
    for (auto it = numeros.begin(); it != numeros.end(); ++it ) {
        std::cout<< *it <<" ";
    }

    std::cout<<std::endl;
    std::cout<<"Digite el numero a buscar: "<<std::endl;
    std::cin>>numeroBuscar;

    // hacer sumatoria de vector usando iteradores 
    for (auto it = numeros.begin(); it != numeros.end(); ++it) {
        if (*it == numeroBuscar) {
            std::cout<<"El numero ha sido encontrado"<<std::endl;
            encontrado = true;
            break;  // si lo encuentra termina el programa
        }
    }
    if (!encontrado)  std::cout<<"El numero no fue encontrado"<<std::endl;

    return 0;
}