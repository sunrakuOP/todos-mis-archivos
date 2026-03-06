#include <iostream>

int sumar(int a, int b) {   // las funciones deben declararse fuera del main
        return a+b; 
}

int main() {
    int(*p)(int, int) = sumar; // puntero a la funcion
    std::cout<<p<<std::endl;  //muestra direccion en memoria en de la funcion
    // usar la funcion
    std::cout<< sumar(1,2) <<std::endl; 
    std::cout<< p(1,2) <<std::endl; 

    // sumar() = p(), dos formas distintas de usar la misma funcion
    return 0;
}