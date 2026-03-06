#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool validarContrasena(std::string contr) {
    if (contr.size() < 8) {
        std::cout<<"Debe tener al menos 8 caracteres."<<std::endl;
        return false;
    }
    bool mayuscula = false;
    bool minuscula = false;
    bool numero = false;

    for (char c: contr) {
        if (isupper(c)) mayuscula = true;
        if (islower(c)) minuscula = true;
        if (isdigit(c)) numero = true;
    }

    return mayuscula && minuscula && numero;
} 

int main () {
    std::string contrasena;
    bool valida = false;

    do {
        std::cout<<"Digite su contrasena: "<<std::endl;
        std::cin>>contrasena;
        valida = validarContrasena(contrasena);
        if (!valida) {
            std::cout<<"Contrasena invalida"<<std::endl;
        }
    } while (!valida);

    return 0;
}