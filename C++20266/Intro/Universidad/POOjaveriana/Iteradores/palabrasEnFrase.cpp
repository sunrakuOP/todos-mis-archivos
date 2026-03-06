#include <iostream>
#include <vector>
#include <string>

int contadorPalabras(std::string fraseAcontar){
    int contador = 0;
// usar variable booleana para chequear si esta dentro de una palabra o no
    bool enPalabra = false;

    for (char c: fraseAcontar) {
        if (c != ' ' && !enPalabra) {
            contador++;
            enPalabra = true;
        } 
        else if (c == ' ') {
            enPalabra = false;
        }     
    }
    return contador;
}

int main(){
    std::string cadena;
    std::cout<<"Digite la frase : "<<std::endl;
    std::getline(std::cin, cadena);

    int num = contadorPalabras(cadena);
    std::cout<<"Numero de palabras en frase es: "<<num<<std::endl;

    return 0;
}