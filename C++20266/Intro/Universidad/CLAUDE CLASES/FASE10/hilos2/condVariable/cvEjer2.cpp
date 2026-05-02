#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <vector>
#include <string>
#include <chrono>
#include <queue>
#include <condition_variable>
#include <atomic>

std::vector<std::string> menu = {"pizza", "hamburguesa", "sushi", "tacos"};
std::queue<std::string> pedidos;
std::mutex mtx;
std::condition_variable cv;
bool terminado = false;

// clientes activos para saber cuando todos terminan
std::atomic<int> clientesActivos = 3;

void productor() {
    // primero elegir el valor del menu al azar y sacar 3 pedidos al azar
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, menu.size()-1);

    // hacer los 3 pedidos al azar
    for(int i=0; i<3; ++i){
        std::string pedido = menu[dist(gen)];
        {
            std::lock_guard<std::mutex> guard(mtx);
            pedidos.push(pedido);
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    if(--clientesActivos == 0){
        std::lock_guard<std::mutex> guard(mtx);
        terminado = true;
        cv.notify_all();
    }
}

void consumidor() {
    while(!terminado || !pedidos.empty()){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return terminado || !pedidos.empty();});
        if(!pedidos.empty()){
            std::string pedido = pedidos.front();
            pedidos.pop();
            // hacerle el unlock manual para no esperar el tiempo
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
            std::cout<<"Pedido "<<pedido<<" cocinandose"<<std::endl;
        }

    }
}


int main() {
    std::vector<std::thread> hilos;

    for(int i = 0; i < 3; i++)
        hilos.push_back(std::thread(productor));

    for(int i = 0; i < 2; i++)
        hilos.push_back(std::thread(consumidor));

    for(auto& t : hilos) t.join();

    return 0;
}
