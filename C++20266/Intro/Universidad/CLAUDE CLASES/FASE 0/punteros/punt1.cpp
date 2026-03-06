#include <iostream>

// puntero guarda direccion de memeria de una variable, para mayor control (eficiencia)
int main() {
    int x = 0;
    int *a = &x; // puntero a guarda la direccion en memoria de x
    // *a = x, mismo nombre para dos cosas iguales
    if (a != nullptr) {  // a ee
        *a = 42;
    }
    std::cout<<a <<std::endl; // direccion de la memoria
    std::cout<<*a <<std::endl; // variable como tal 

    return 0;
}