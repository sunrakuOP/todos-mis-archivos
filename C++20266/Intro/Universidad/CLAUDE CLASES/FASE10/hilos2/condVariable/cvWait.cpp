#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <random>
#include <queue>
#include <condition_variable>

std::queue<int> numeros;
bool terminado = false;
std::mutex mtx;
std::condition_variable cv;


void productor() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100);
    // necesito que calcule 5 valores al azar y anadirlo al quee
    for(int i=0; i<5; ++i){
       {
        std::lock_guard<std::mutex> guard(mtx);
        int valor = dist(gen);
        numeros.push(valor);
        // notifica si ya no esta vacio
       }
       cv.notify_one();
    }
    // ahora cuando sale del for, ya esta la cola llena
    {
        std::lock_guard<std::mutex> guard(mtx);
        terminado = true;
    }
    cv.notify_one();
}

void consumidor() {
    // hacerle el while para que sepa cuando trabajar
    while(!terminado || !numeros.empty()){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return terminado || !numeros.empty();});
        // verificar que la cola no este vacia
        if(!numeros.empty()){
            // ahora guardo el valor en este ciclo
            int valor = numeros.front(); 
            numeros.pop();
            std::cout<<"Numero: "<<valor<<", cuadrado: "<<valor*valor<<std::endl;
        }
    }
}


int main() {
    std::vector<std::thread> hilos;
    
    // hilo productor
    hilos.push_back(std::thread(productor));
    hilos.push_back(std::thread(consumidor));

    for(auto& t: hilos){
        t.join();
    }


    return 0;
}