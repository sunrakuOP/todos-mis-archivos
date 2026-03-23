#pragma once
#include <string>

class Producto {
private:
    std::string nombre;
    double precio;
    int stock;
    int id;
    static int contador;

public:
    Producto(const std::string& n, double p, int s);
    ~Producto();

    void vender(int c);
    void reabastecer(int c);

    std::string getNombre() const;
    double getPrecio() const;
    int getStock() const;
    int getId() const;

    void mostrarInfo() const;
};