#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Cuenta{
protected:
    int saldo;
    std::mutex mtx;  // creamos la llave
public:
    Cuenta(): saldo(1000) {}

    int getSaldo() const { return saldo; }

    Cuenta& depositar(int monto){
        std::lock_guard<std::mutex> guard(mtx);
        saldo += monto;
        return *this;
    }
    Cuenta& retirar(int monto){
        // hacer el lock antes de cualquier operacion 
        std::lock_guard<std::mutex> guard(mtx);
        if(monto> saldo){
            std::cout<<"Saldo insuficiente.."<<std::endl;
            return *this;
        }
        saldo-=monto;
        return *this;
    }

};

int main(){
    // crear 3 hilos 
    Cuenta c;
    std::vector<std::thread> hilos;

    // recordar que con clases se usan lambdas

    // 3 hilos que depositen 100 5 veces 
    for(int i=0; i<3;++i){
        // creo 3 hilos con lambdas
            // y en el {} creo un for que opere 5 veces
        hilos.push_back(std::thread([&c](){
            for(int j=0; j<5;++j){
                c.depositar(100);
            }
        }));
    }
    // 2 hilos que hagan retiros
    for(int i=0; i<2; ++i){
        hilos.push_back(std::thread([&c](){
            for(int j=0;j<3; ++j){
                c.retirar(150);
            }
        }));
    }

    // hacerle join a los hilos
    for(auto& t: hilos){
        t.join();
    }
    std::cout<<"Saldo final: "<<c.getSaldo()<<std::endl;


    return 0;
}

// hilos para operaciones en paralelo