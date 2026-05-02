#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>

std::vector<double> lecturas;
std::mutex mtx;

void medir(double inicio, double final){
    // generar los valores aleatorios, eso no debe ir dentro del lock
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(inicio, final);
    // hacer que lea 10 veces dentro de la misma funcion
    for(int i=0; i<10; ++i){
        double x = dist(gen);
        std::lock_guard<std::mutex> guard(mtx);
        lecturas.push_back(x);   
    }
}


int main() {
    std::vector<std::thread> hilos;
    
    // hilos generan lecturas en paralelo
    hilos.push_back(std::thread([](){
        medir(-10,5);
    }));
    hilos.push_back(std::thread([](){
        medir(10,25);
    }));
    hilos.push_back(std::thread([](){
        medir(30,50);
    }));
    hilos.push_back(std::thread([](){
        medir(0,40);
    }));

    for(auto& t: hilos){
        t.join();
    }

    for(const auto& l: lecturas){
        std::cout<<l<<", ";
    }
    std::cout<<std::endl;

    double suma = 0;
    for(const auto& l : lecturas) suma += l;
    std::cout << "Promedio global: " << suma / lecturas.size() << "\n";

}