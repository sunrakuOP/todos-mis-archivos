#include <iostream>

int main() {
    int arreglo[] = {1,2,3,4,5,6}; // arreglo de 6 valores
    int *p = arreglo;  // creamos un puntero que apunte al arreglo
    // p va a apuntar al 1er elemento, (p+1) al segundo y asi
    // *p es el primer elemento como tal, *(p+1) el segundo y asi
    // direcciones
    std::cout<< p <<std::endl;  // dir 1er
    std::cout<< p+1<<std::endl;; //dir 2ndo
    std::cout<< p+2<<std::endl;; // dir 3ro
    // valores como tal
    std::cout<< *p <<std::endl;  // valor 1er
    std::cout<< *(p+1) <<std::endl;; // valor 2ndo
    std::cout<< *(p+2) <<std::endl;; // valor 3ro
    
    // recorrerlo con for, usando el sizeof
    int n = sizeof(arreglo) / sizeof(arreglo[0]);  // sizeof(arr) tamano total en bytes 
    // sizeof(arr[0]) tamano de un elemento
    // division da el numero de elementos del arreglo, vamos a recorrerlo asi usando bytes
    std::cout<<std::endl;
    std::cout<<"Recorrer arreglo usando for y punteros: "<<std::endl;
    for (int *p = arreglo; p < arreglo + n; ++p)  {
        // arreglo + p es direccion final en memoria justo despues del ultimo elemento
        std::cout<< p <<std::endl; // mostramos dir memoria
        std::cout<< *p <<std::endl; // mostramos el valor
    }

    return 0;
}