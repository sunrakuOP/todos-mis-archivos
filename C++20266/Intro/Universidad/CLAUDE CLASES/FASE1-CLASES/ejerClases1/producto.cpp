#include "producto1.h"
#include <iostream>

int Producto::contador = 0;

Producto::Producto(const std::string& n, double p, int s)
    : nombre(n), precio(p), stock(s), id(++contador) {}

Producto::~Producto() {
    std::cout << "Producto " << nombre << " eliminado\n";
}

void Producto::vender(int c) {
    if (c <= 0) {
        std::cout << "Error: cantidad inválida\n";
        return;
    }
    if (c > stock) {
        std::cout << "Error: stock insuficiente\n";
        return;
    }
    stock -= c;
}

void Producto::reabastecer(int c) {
    if (c <= 0) {
        std::cout << "Error: cantidad inválida\n";
        return;
    }
    stock += c;
}

std::string Producto::getNombre() const { return nombre; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }
int Producto::getId() const { return id; }

void Producto::mostrarInfo() const {
    std::cout << "ID: "     << id     << "\n"
              << "Nombre: " << nombre << "\n"
              << "Precio: $" << precio << "\n"
              << "Stock: "  << stock  << "\n\n";
}

