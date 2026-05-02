#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <chrono>
#include <mutex>

int saldoA = 1000;
int saldoB = 1000;
std::mutex mtxA, mtxB;

void transferirAB() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    std::scoped_lock lock(mtxA, mtxB);
    saldoA += 100;
    saldoB -= 100;
}
void transferirBA() {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    std::scoped_lock lock(mtxA, mtxB);
    saldoB += 100;
    saldoA -= 100;
}

int main() {
    std::vector<std::thread> hilos;
    // crear dos hilos
    hilos.push_back(std::thread(transferirAB));
    hilos.push_back(std::thread(transferirBA));

    std::cout<<saldoA<<", "<<saldoB<<std::endl;
    for(auto& t: hilos){
        t.join();
    }



    return 0;
}