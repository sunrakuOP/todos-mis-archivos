#include <iostream>

int main() {
    double temperatura;
    while(true) {
        std::cout << "Digite temperaturas (-999 para terminar): " << std::endl;
        std::cin >> temperatura;
        if (temperatura == -999) {
            std::cout << "Saliendo.." << std::endl;
            return 0;
        }
        // Mostrar ALERTA si corresponde
        if (temperatura >= 35.0 && temperatura <= 45.0) {
            std::cout << "ALERTA" << std::endl;
        }
        // Clasificación
        if (temperatura > 0 && temperatura <= 24.0) {
            std::cout << "Buena." << std::endl;
        } else if (temperatura > 24.0 && temperatura <= 34.0) {
            std::cout << "Moderada." << std::endl;
        } else if (temperatura >= 35.0) {
            std::cout << "Insalubre" << std::endl;
        }
    }
    return 0;
}