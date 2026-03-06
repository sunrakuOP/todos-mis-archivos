#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> lista;
    int numeroValores, datoActual;
    std::string frasePrueba1, frasePrueba2;

    std::cout<<"Digite el numero de valores: "<<std::endl;
    std::cin>>numeroValores;

    for (int i = 0; i < numeroValores; i++) {
        std::cout<<"Digite dato numero "<< i+1 <<": "<<std::endl;
        std::cin>>datoActual;
        lista.push_back(datoActual);
    }
    std::cout<<"El vector es: "<<std::endl;
    for (int c: lista) {
        std::cout<< c <<std::endl;
    }

    return 0;
}

























/*
    std::cout<<"Digite una frase de prueba para almacenar usando cin: "<<std::endl;
    std::cin>>frasePrueba1;   // cin solo toma la primera palabra 
    std::cout<<frasePrueba1<<std::endl;
    std::cin.ignore();  // cin deja un salto de linea pendiente en el buffer, usar .ignore() para limpiar antes de getline

    std::cout<<"(Si no se copia completa con espacios es por el cin solo, usar getline)"<<std::endl;
    
    std::cout<<"Digite una frase de prueba para almacenar usando getline: "<<std::endl;
    std::getline(std::cin, frasePrueba2);
    std::cout<<frasePrueba2<<std::endl;

    std::cout<<"Hay alguna diferencia?"<<std::endl;
*/