#include <iostream>
#include <future>
#include <cmath>
#include <chrono>
#include <vector>
#include <thread>

std::vector<int> valores = {16, 25, 36, 49};
std::vector<std::future<double>> resultados;

double raiz(int x) {
    // demorar la funcion un poco
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Resultado: "<<std::sqrt(x)<<std::endl;
    return std::sqrt(x);
}


int main() {
    // auto o se puede std::future<int> resultado
    // aca creo 4 hilos conrriendo en paralelo, un hilo por launch::async
    for(const auto& v: valores){
        auto resultado = std::async(std::launch::async, raiz, v);
        resultados.push_back(std::move(resultado));
    }

    // hacerle el get como se le hace el join
    for(auto& fut: resultados){
        std::cout<<fut.get()<<std::endl;
    }

    // mostremos ambos vectores
    for(const auto& v: valores){
        std::cout<<v<<std::endl;
    }
    
    
    return 0;
}