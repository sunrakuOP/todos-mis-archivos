#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;   // creo la llave para que cada hilo no sumen
int contador = 0;

// metodo peligroso usanso lock() y unlock()
void incrementar() {
    for(int i=0; i < 100000; ++i){
        mtx.lock();
        contador++;
        mtx.unlock();
    }
}


int main(){
    std::vector<std::thread> hilos;
    for(int i=0; i < 4; ++i){
        hilos.push_back(std::thread(incrementar));
    }
    for(auto& t: hilos){
        t.join();
    }
    std::cout<<"Contador: "<<contador<<std::endl;

    return 0;
}