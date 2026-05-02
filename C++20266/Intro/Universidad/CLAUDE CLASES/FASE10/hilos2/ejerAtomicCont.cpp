#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

// se crea la variable directamente desde el atomic 
std::atomic<int> contador = 0;
void contar() {
    contador++;
}   


int main() {
    std::vector<std::thread> hilos;

    for(int i=0; i<4; ++i){
        // primero crear los hilos, luego aplicarle a cada uno la suma
        hilos.push_back(std::thread([](){
            for(int j=0; j<100000; ++j){
                contar();
            }
        }));
        
    }
    // hacer el join, esperar a que terminen
    for(auto& t: hilos){
        t.join();
    }

    std::cout<<"Cuenta: "<<contador<<std::endl;

    return 0;
}