#include <iostream>

class Producto {
private: 
    std::string nombre;
    double precio;
    int cantidad;

public:
    // setters primero para pedir valor (void)
    void setNombre(std::string n) {
        nombre = n;
    }

    void setPrecio(double p) {
        if(p >= 0) precio = p;  // solo una linea no necesidad de {}
    }

    void setCantidad(int c) {
        if(c >= 0) cantidad = c;
    }

    // getters para leer el valor
    std::string getNombre() const {
        return nombre;
    }

    double getPrecio() const {
        return precio;
    }

    int getCantidad() const {
        return cantidad;
    }

    void mostrarInfo() const {  // tambien const para que no se pueda alterar
        std::cout<<"Producto: "<< nombre <<std::endl;   // dentro de clase puedo usar nombreVariables normal
        std::cout<<"Precio: "<< precio <<std::endl;
        std::cout<<"Cantidad: "<< cantidad <<std::endl;
    }

};
int main(){
    Producto p1, p2;
    p1.setNombre("Producto1");
    p1.setPrecio(1000);
    p1.setCantidad(24);

    p2.setNombre("Producto2");
    p2.setPrecio(2000);
    p2.setCantidad(13);

    p1.mostrarInfo();
    p2.mostrarInfo();
    


    return 0;
}