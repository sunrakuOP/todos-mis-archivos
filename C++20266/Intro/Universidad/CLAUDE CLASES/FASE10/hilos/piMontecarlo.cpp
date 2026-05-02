#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

class MonteCarloPi {
protected:
    long long totalDentro = 0;
    std::mutex mtx;
public:
    MonteCarloPi() = default;

    MonteCarloPi& lanzar(int ct){
        // genera valor aleatorio
        std::mt19937 gen(std::random_device{}()); // genero la semilla desde el random del SO
        std::uniform_real_distribution<double> dist(0.0, 1.0);

        int cuenta = 0;
        for(int i=0; i<ct; ++i){
            double x = dist(gen);
            double y = dist(gen);
            if(x*x + y*y <= 1.0){
                cuenta++;
            }
        }
        // ahora si vamos a escribir en datos compartidos
        std::lock_guard<std::mutex> guard(mtx);
        totalDentro += cuenta;
        return *this;
    }

    double calcularPi(long long totalDardos){
        return 4.0*(totalDentro/(double)totalDardos);
    } 

};

int main() {
    std::vector<std::thread> hilos;
    MonteCarloPi calcPi;
    // crear 4 hilos para que trabajen al tiempo
    for(int i=0; i<4; ++i){
        hilos.push_back(std::thread([&calcPi](){
            calcPi.lanzar(25000000); // lanzar 25 millones de dardos
        }));
    }

    // esperar a que temrminen todos los hilos
    for(auto& t: hilos){
        t.join();
    }

    double pi = calcPi.calcularPi(100000000); // 100 millones de dardos en total
    std::cout<<"PI esttimado: "<<pi<<std::endl;

    return 0;
}