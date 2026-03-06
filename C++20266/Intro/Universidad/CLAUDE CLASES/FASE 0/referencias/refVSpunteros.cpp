#include <iostream>
// paso por referencia, valor y puntero

void porValor(int x) {
    x = 900; // no cambia el valor internamente
}
void porRef(int &x) {
    x = 900; // aca si lo cambia internamente
} 

int main() {
    int x = 100;
    int& ref = x; // creamos una referencia a x
    std::cout<< x <<std::endl;
    std::cout<< ref << std::endl;  // se refieren a lo mismo, misma direccion en memoria

    // problemas con redireccionar
    int y = 200;
    ref = y;  // ahora ref y x valen 200
    std::cout<< x <<std::endl;
    std::cout<< ref << std::endl;

    // ejemplos correctos de paso por valor y por referencia
    int a = 10;
    porValor(a);
    std::cout << "Despues de porValor(a): " << a << std::endl; // sigue en 10

    porRef(a);
    std::cout << "Despues de porRef(a): " << a << std::endl;   // cambia a 900

    return 0;
}