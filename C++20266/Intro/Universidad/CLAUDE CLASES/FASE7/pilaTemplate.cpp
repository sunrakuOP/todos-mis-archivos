#include <iostream>
#include <vector>

template <typename T> // t es el tipo de dato variable
class Pila {
protected:
    std::vector<T> datos;
public:
    void push(const T& valor) {
        datos.push_back(valor);
    }
    T pop() {
        T ultimo = datos.back();
        datos.pop_back();
        return ultimo;  // elimina el ultimo y devuelve el ultimo valor
    }

    T top() {
        return datos.back(); // ultimo dato
    }

    bool vacio() {
        return datos.empty();
    }

    int tamano() {
        return datos.size();
    }


    
};



int main() {
    Pila<int> pilasEnteros; // se crea una clase Pila de enteros
    pilasEnteros.push(10);
    pilasEnteros.push(20);
    pilasEnteros.push(30);
    pilasEnteros.push(40);
    std::cout<<"Tamano: "<<pilasEnteros.tamano()<<std::endl;

    Pila<std::string> pilasStrings;
    pilasStrings.push("Hola");
    pilasStrings.push("Adios");
    pilasStrings.push("Donde estas");
    std::cout<<"Ultimo elemento: "<<pilasStrings.pop() <<std::endl;

    return 0;
}