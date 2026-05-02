#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::map<std::string, int> palabras;

    std::string texto;
    std::cout<<"Digite texto: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, texto);

    // istringstream ss(texto)
    std::istringstream ss(texto);

    // leer palabra por palabra
    std::string palabra;
    while(ss >> palabra) {
        palabras[palabra]++;
    }
    // ya con eso guarda en cada clave la palabra y la suma

    for(const auto&[palabra, cuenta]: palabras){
        std::cout<<palabra<<", "<<cuenta<<std::endl;
    }

    return 0;
}

/*
Ejercicios de Fase 9 (STL)
Ejercicio 1: Frecuencia de palabras con map
Escribí un programa que reciba un texto hardcodeado (un párrafo largo) y usando std::map<std::string, int>:

Cuente cuántas veces aparece cada palabra
Imprima las palabras ordenadas alfabéticamente con su frecuencia
Muestre la palabra más frecuente y cuántas veces apareció
*/