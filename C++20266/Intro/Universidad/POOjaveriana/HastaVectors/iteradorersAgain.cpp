#include <iostream>
#include <vector>

// recorrer vectores usando iteradores 
int main() {
    std::vector<int> numeros = {1,2,3,4,5,6,7,8,9,0};

    // forma tradicional (larga)
    std::cout<<"Vector recorrido de forma tradicional: "<<std::endl;
    for (std::vector<int>::iterator it = numeros.begin(); it != numeros.end(); ++it) {
        std::cout<< *it <<" ";    // recordar que para mostrar el iterador usar *****
    }

    // forma moderna de C++
    std::cout<<"Vector recorrido de forma moderna: "<<std::endl;
    for (auto it = numeros.begin(); it != numeros.end(); ++it) {
        std::cout<< *it <<" ";
    }

    // recorrer el vector de atras para adelante
    std::cout<<"Vector recorrido al reves: "<<std::endl;
    for (auto it = numeros.rbegin(); it != numeros.rend(); ++it) {
        std::cout<< *it <<" ";
    }


    return 0;
}