#include <iostream>
#include <vector>
#include <thread>

/*
crear un hilo por cada numero y que calcule el cuadrado y lo guarde en un vector de hilos
*/

int main(){
    std::vector<int> numeros = {1,2,3,4,5,6};
    std::vector<int> resultados (numeros.size()); // vector del mismo tamanio
    std::vector<std::thread> hilos; 

    // mostrar el vector inicial
    for(const auto& n: numeros){
        std::cout<<n<<", ";
    }
    std::cout<<std::endl;

    for(size_t i=0; i<numeros.size(); ++i){
        // crear lambda que guarde el cuadrado del valor
        hilos.push_back(std::thread([i,&numeros, &resultados](){ 
            resultados.at(i) = numeros.at(i)*numeros.at(i);
        }));
    }
    for(auto&t: hilos){
        t.join();
    }
    // imprimir los resultados
    for(const auto& n: resultados){
        std::cout<<n<<", ";
    }
    std::cout<<std::endl;


    return 0;
}