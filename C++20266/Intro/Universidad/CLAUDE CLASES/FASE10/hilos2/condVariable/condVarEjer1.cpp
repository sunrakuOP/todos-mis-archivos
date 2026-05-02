#include <iostream>
#include <mutex>
#include <thread>
#include <random>
#include <atomic>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
// hagamos valor atomic porque es sencillo
double valor = 0;
bool listo = false;

// genera un numero aleatorio y tarda un seg en procesarlo
void productor(){
    // para que demore un segundo
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // genera el dato random
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0,100.0);
    { // abrir para hacer el lock con el mutx
        std::lock_guard<std::mutex> guard(mtx);
        valor = dist(gen);
        listo = true;
    }
    cv.notify_one();
}
void consumidor(){
    std::unique_lock<std::mutex> lock(mtx); // deber ser unique lock
    cv.wait(lock, []{ return listo; });
    valor *= valor;
    lock.unlock();
}

int main() {

    return 0;
}