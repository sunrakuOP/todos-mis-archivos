#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

double sumaGlobal = 0;
std::mutex mtx;

void suma(int i1, int i2){
    double sumaLocal = 0;

    for(int i=i1; i<i2; ++i){
        sumaLocal += i;
    }
    // hacerle el mutex solo al escribir
    std::lock_guard<std::mutex> guard(mtx);
    sumaGlobal+=sumaLocal;
}

int main(){
    std::vector<int> numeros;
    std::vector<std::thread> hilos;
// llenar el vector
    for(int i=1; i<=1000; ++i){
        numeros.push_back(i);
    }

    // vamos a crear los 4 hilos, cada valor suma 250 valores
    int porHilo = 250; // rango de valores
    for(int i=0; i<4; ++i){
        int inicio = i*porHilo + 1;  // hacerle los indices de suma
        int final = inicio + porHilo;
        hilos.push_back(std::thread([inicio, final](){
            suma(inicio, final);
        }));
    } // el hace la suma local y luego en la funcion altera los valores globale

    for(auto& t: hilos){
        t.join();
    }
    std::cout<<"Suma total usando hilos es: "<<sumaGlobal<<std::endl;


    return 0;
}