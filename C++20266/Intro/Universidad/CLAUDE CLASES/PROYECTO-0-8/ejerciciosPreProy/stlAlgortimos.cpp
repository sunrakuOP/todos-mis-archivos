/*
Ejercicio 5: Algoritmos STL con lambdas
Dado un vector<int> con 15 números aleatorios entre -50 y 50, usando solo algoritmos STL y lambdas (sin loops manuales):

Ordenar de mayor a menor
Contar cuántos son negativos
Encontrar el mayor valor absoluto
Calcular la suma de los positivos
Crear un nuevo vector con solo los pares
Verificar si todos son mayores que -100
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Ordenar {
protected:
    std::vector<int> numeros = {23, -15, 7, -42, 50, 3, -8, 19, -50, 33, -1, 44, -27, 12, -6};
public:
    Ordenar() = default;
    // usar algoritmos con lamdas
    Ordenar& ordenarMaM() {
        std::sort(numeros.begin(), numeros.end());
        // sort los ordena por defecto asi
        return *this;
    }
    // contar cuantos son negativos??
    int contarNegativos() {
        int cuenta = std::count_if(numeros.begin(), numeros.end(),
            [](int x){return x < 0;});
        
        return cuenta;
    }
    // encontrar valor mas grande
    int mayor() {
        auto it = std::max_element(numeros.begin(), numeros.end(),
            [](int a, int b){ return a < b;});
        
        std::cout<<"Valor mas grande: "<<*it<<std::endl;
        return *it;
    }


    // como sumo solo los pares??? 


    Ordenar& nuevoPositivo() {
        // ordena eso al final
        auto it = std::remove_if(numeros.begin(), numeros.end(),
            [](int x){return x % 2 != 0; });
        // ahora eliminamos el final del vector (basura)
        numeros.erase(it, numeros.end());
        return *this;
    }


    // verificar si todos son mayores que -100
    bool mayoresMenosCien() {
        return std::all_of(numeros.begin(), numeros.end(), 
            [](int x){return x > -100; });

    }
};


int main() {
    


    return 0;
}