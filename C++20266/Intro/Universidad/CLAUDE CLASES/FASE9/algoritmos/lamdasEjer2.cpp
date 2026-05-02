#include <iostream>
#include <vector>
#include <algorithm>

class Filtro {
protected:
    std::vector<int> numeros;
public:
    Filtro() = default;

    Filtro& cargar(const std::vector<int>& vectCargar){
        numeros = vectCargar;
        return *this;
    }
    // multiplicar todos por numero dado
    Filtro& multiplPor(int num){
        std::for_each(numeros.begin(), numeros.end(), [num](int &x){ return x*= num; });

        return *this;
    }
    // eliminar menores a num
    Filtro& eliminarMenoresA(int num){
        // remove mas erase
        // remove_if, mueve todos los elementos que no cumplen condicion al final del vector
        auto it = std::remove_if(numeros.begin(), numeros.end(), [num](int x){return x < num;});
        // elimina los elementos basuta
        numeros.erase(it, numeros.end());
        return *this;
    }

};




int main() {

    return 0;
}