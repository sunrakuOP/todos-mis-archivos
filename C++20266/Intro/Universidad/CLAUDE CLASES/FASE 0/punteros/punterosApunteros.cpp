#include <iostream>

int main() {
    int a = 0; // inicializar variable int 
    int *p = &a; // creamos puntero como referencia a 
    int **pp = &p; // creamos puntero que apunte al puntero

    // a = *p = **pp , desreferenciar dos veces
    std::cout<<a<<std::endl;
    std::cout<<*p<<std::endl;
    std::cout<<**pp<<std::endl;

    return 0;
}