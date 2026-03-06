#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int pedirCadena(std::string& cadena) {     // recordar siempre hacerle la copia al vector
    std::vector<char> vocales = {'a','e','i','o','u'};
    int contador = 0;
    // funcion tolower para volver texto minuscula
    for (char &c : cadena) {
        c = tolower(c);  // vuelvo cada caracter minuscula
        if (std::find(vocales.begin(), vocales.end(), c) != vocales.end()) {
            contador++;
// comparar un caracter con un vector (si esta dentro)
/* que hace ???
   find devuelve un iterador que recorre vector de begin-end, si llega hasta el final significa que no encontro valores iguales
   si no llega hasta el final (!= v.end) es que si hayo coicidencia y sumamos al valor
*/
        }
    }
    return contador;
}


int main() {
    std::string text;
    std::cout<<"Digite la cadena a chequear: "<<std::endl;
    std::getline(std::cin, text);   // lee toda la linea incluyendo espacios

    int numero = pedirCadena(text);
    std::cout<<"El numero de vocales en la frase es: "<<numero<<std::endl;

    return 0;
}


// TIP: siempre pensar en el tipo de retorno de la funcion para devolver 