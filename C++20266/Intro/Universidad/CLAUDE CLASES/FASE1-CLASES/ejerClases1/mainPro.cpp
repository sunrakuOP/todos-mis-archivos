#include <iostream>
#include "producto1.h"

int main() {
    Producto p1("Laptop",  1200.0, 10);
    Producto p2("Mouse",     25.0,  5);
    Producto p3("Teclado",   80.0, 30);

    std::cout << "=== Inventario inicial ===\n\n";
    p1.mostrarInfo();
    p2.mostrarInfo();
    p3.mostrarInfo();

    std::cout << "=== Operaciones ===\n\n";

    p1.vender(3);
    std::cout << "Despues de vender 3 laptops:\n";
    p1.mostrarInfo();

    p2.vender(100);  // stock insuficiente
    std::cout << "Stock mouse sin cambios:\n";
    p2.mostrarInfo();

    p3.reabastecer(20);
    std::cout << "Despues de reabastecer teclados:\n";
    p3.mostrarInfo();

    return 0;
}