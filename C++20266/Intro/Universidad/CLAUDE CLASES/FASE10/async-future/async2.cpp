#include <iostream>
#include <vector>
#include <thread>
#include <future>



int main() {
    // vector de vectores
    std::vector<std::vector<int>> sucursales = {
        {150, 200, 320, 180, 90},   // sucursal 0
        {400, 150, 280, 310, 220},  // sucursal 1
        {100, 450, 200, 180, 360},  // sucursal 2
        {280, 190, 410, 150, 300}   // sucursal 3
    };
    // crear el vector de resultados
    std::vector<std::future<int>> resultadoPorSucursal;
    // lanzar 4 hilos
    for(int i=0;  i<4; ++i){
        auto fut = std::async(std::launch::async, [&sucursales, i](){
            int suma = 0;
            for(const auto& s: sucursales[i]){
                suma += s;
            }
            return suma;
        });
        resultadoPorSucursal.push_back(std::move(fut));
    }
    // suma completa
    int sumaFinal = 0;
    for(auto& fut: resultadoPorSucursal){
        sumaFinal += fut.get();
    }
    std::cout<<"Suma final: "<<sumaFinal<<std::endl;


    return 0;
}