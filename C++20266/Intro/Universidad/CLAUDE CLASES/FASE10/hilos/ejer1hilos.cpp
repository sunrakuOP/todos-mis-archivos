#include <iostream>
#include <thread>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> texto = {"Hola", "Adios", "Carros", "Salud", "Dinero"};
    std::vector<std::thread> hilos;

    for(int i=0; i<5; ++i){
        hilos.push_back(std::thread([i, &texto](){
            std::cout<<"Hilo "<<i<<": "<<texto.at(i)<<std::endl;
        }));
    }

    for(auto& t: hilos){
        t.join();
    }
    
    return 0;
}