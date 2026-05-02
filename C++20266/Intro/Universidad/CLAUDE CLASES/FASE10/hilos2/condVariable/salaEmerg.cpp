#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <chrono>
#include <random>

std::vector<std::string> prioridad = {"leve","moderado","grave","critico"};
std::queue<std::string> pacientes;
std::mutex mtx;
std::condition_variable cv;
bool cerrado = false;

void ambulancia() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, prioridad.size()-1);
    for(int i=0; i<6; ++i){
        std::string pac = prioridad[dist(gen)];
        {
            std::lock_guard<std::mutex> guard(mtx);
            pacientes.push(pac);
        }
        cv.notify_one();  // hay pacientes en la cola, despertar medico
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
    std::lock_guard<std::mutex> guard(mtx);
    cerrado = true;
    cv.notify_one();  // ya acabo, despertar medico

}

void medico() {
    int contador = 0;
    while(!cerrado || !pacientes.empty()){
        std::unique_lock<std::mutex> lock(mtx);
        // ahora el lambda de cv.wait()
        cv.wait(lock, []{ return cerrado || !pacientes.empty(); });
        // mientras la cola no este vacia
        if(!pacientes.empty()){
            std::string pac = pacientes.front();
            pacientes.pop();
            // hacerle el sleep al hilo
            lock.unlock(); // unlock al hacerle sleep para que no espere 
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            contador++;
        }

    }
    std::cout<<"Pacientes atendidos: "<<contador<<std::endl;
}




int main() {

    return 0;
}