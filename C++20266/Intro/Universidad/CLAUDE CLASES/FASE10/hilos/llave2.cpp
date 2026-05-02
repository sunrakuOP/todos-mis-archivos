#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

std::mutex mtx; //llave para evitar errores
std::vector<int> numeros;

void agregar() {
    for(int i=0; i<3; ++i){
        std::lock_guard<std::mutex> guard(mtx);  
        numeros.push_back(0);
    }
}

int main() {
    std::vector<std::thread> hilos;
    // crear 5 hilos que agreguen 3 numeros
    for(int i=0; i<5; ++i){
        hilos.push_back(std::thread(agregar));
    }
    // hacer el join
    for(auto& t: hilos){
        t.join();
    }

    // mostrar el vector
    std::cout<<"Tamano: "<<numeros.size()<<std::endl;
    for(const auto n: numeros){
        std::cout<<n<<", ";
    }

    return 0;
}