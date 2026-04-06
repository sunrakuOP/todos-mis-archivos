#include <iostream>
#include <vector>

class Producto {
protected:
    double precio;
    std::string nombre;
public:
    Producto(int p, const std::string& n): precio(p), nombre(n) {}

    Producto& aplicarDescuento(double porcentaje) {
        if(porcentaje > 100 || porcentaje < 0) {
            std::cout<<"Porcentaje no valido.."<<std::endl;
            return *this;
        }
        
        std::cout<<"Precio despues del porcentaje: "<<(porcentaje/100)*precio<<std::endl;
        precio = (porcentaje/100)*precio;
        return *this;
    }

    void mostrar() const {
        std::cout<<"Nombre: "<<nombre<<", precio: "<<precio<< std::endl;
    }
};


int main() {
    std::vector<Producto*> productos;
    Producto p1(1000, "P1");
    Producto p2(2000, "p2");
    Producto p3(300, "p3");

    productos.push_back(&p1);
    productos.push_back(&p2);
    productos.push_back(&p3);

    for(const auto& p: productos) {
        p->mostrar();
    }
    
    p1.aplicarDescuento(20);

    return 0;
}