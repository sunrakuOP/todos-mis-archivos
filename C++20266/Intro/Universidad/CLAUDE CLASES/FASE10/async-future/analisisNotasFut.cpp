#include <iostream>
#include <vector>
#include <thread>
#include <mutex> // aca no lo necesito creo
#include <future>
#include <algorithm>

double prom(const std::vector<double>& vect) {
    double suma = 0;
    for(const auto&v: vect){
        suma += v;
    }
    return suma / (double)vect.size();
}   

int main() {
    std::vector<std::vector<double>> grupos = {
        {3.5, 4.2, 2.8, 4.9, 3.1},
        {4.5, 3.8, 4.1, 2.9, 4.7},
        {2.5, 3.0, 4.4, 3.7, 2.1},
        {4.8, 4.2, 3.9, 4.5, 4.1}
    };
    std::vector<std::future<double>> proms;
    std::vector<double> promsDouble;

    for(int i=0; i<4; ++i){
        auto result = std::async(std::launch::async, [&grupos, i]{
            return prom(grupos.at(i));  // lambda debe tener siempre valor de retorno
        });
        proms.push_back(std::move(result));
    }

    // pasar el vector de futures a un vector normal y de una hacerle el .get
    for(auto& p: proms){
        promsDouble.push_back(p.get());
    }
    // ahora trabajar con el vector de doubles
    // 1. promedio por grupo
    int indice = 1;
    for(const auto& p: promsDouble){
        std::cout<<"Grupo "<<indice<<", prom: "<<p<<std::endl;
        indice++;
    }
    /*
    auto maxIt = std::max_element(proms.begin(), proms.end());
    std::cout<<"Mejor promedio: "<< *(maxIt) <<std::endl;
    el problema es que max element no puede comparar future, pasar a un vector de doubles
    */
   auto maxIt = std::max_element(promsDouble.begin(), promsDouble.end());
   int idx = maxIt - promsDouble.begin(); // saber el indice del iterador
   std::cout<<"Mayor promedio: "<<*(maxIt)<<", grupo: "<<idx<<std::endl;

    // promedio global
    double sumaT = 0;
    for(const auto& p: promsDouble){
        sumaT += p;
    }
    std::cout<<"Prom total: "<<sumaT/(double)promsDouble.size()<<std::endl;

    return 0;
}