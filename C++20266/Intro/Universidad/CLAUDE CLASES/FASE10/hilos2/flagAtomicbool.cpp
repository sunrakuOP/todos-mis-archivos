#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono> // para detener el hilo 500ms
#include <random>

// generar la flag para generar datos 
std::atomic<bool> detener = false;

// generar numero aleatorio 
double leer() {
    while(!detener){
        std::mt19937 gen(std::random_device{}()); // genera semilla y numero a partir de ahi
        // en rango de temperatura de (15,45)
        std::uniform_real_distribution<double> dist(15.0, 45.0);

        double x = dist(gen);
        return x;
    }
    // hacer que trabaje cada 5ms 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}


int main(){
    // solo creamos un hilo
    std::thread t(leer); 

    // solo lo vamos a dejar funcionar 5seg
    std::this_thread::sleep_for(std::chrono::seconds(5));
    detener = true;

    t.join();
    std::cout<<"Hilo detenido.."<<std::endl;

    return 0;
}