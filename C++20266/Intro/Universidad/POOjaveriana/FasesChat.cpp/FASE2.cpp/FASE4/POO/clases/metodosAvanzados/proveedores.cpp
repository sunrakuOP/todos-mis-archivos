#include <iostream>
#include <string>
#include <vector>

class Producto {
    private:
    std::string nombre;
    double precio;
    int cantidad;
    std::vector<std::string> proveedores;

    public:
    Producto(std::string n, double p, int c) {
        nombre = n;
        precio = p;
        cantidad = c;
    }
    ~Producto() {
    }
    Producto& setNombre(std::string n) {
        nombre = n;
        return *this;
    }
    Producto& setPrecio(double p) {
        precio = p;
        return *this;
    }
    Producto& setCantidad(int c) {
        cantidad = c;
        return *this;
    }
    std::string getNombre() {
        return nombre;
    }
    double getPrecio() {
        return precio;
    }
    int getCantidad() {
        return cantidad;
    }

    int cantidadVendida(int ventas) {
        if (ventas <= cantidad) {
            cantidad -= ventas;
            std::cout<<"Cantidad actual: "<<cantidad;
            return cantidad;
        }
        else {
            std::cout<<"Cantidad invalida"<<std::endl;
            return cantidad;
        }
    }

    void agregarProveedor(const std::string& p) {
        for(const auto& proveedor: proveedores) {
            if (p == proveedor) {
                std::cout<<"Proveedor ya esta "<<std::endl;
                return;
            }
        }
        proveedores.push_back(p);
    }

    void mostrarProveedores() {
        std::cout<<"Lista de proveedores"<<std::endl;
        for(auto& p: proveedores) {
            std::cout<< p <<std::endl;
        }
    }    

    void mostrarInfo() {
        std::cout<<"Nombre: "<<nombre<<std::endl;
        std::cout<<"Precio: "<<precio<<std::endl;
        std::cout<<"Cantidad: "<<cantidad<<std::endl;
    }
};

int main() {
    // crear un objeto para probar
    Producto p1("Producto 1", 20000, 103);
    p1.mostrarInfo();
    // cambiar atributos
    p1.setNombre("New").setPrecio(0).setCantidad(30);  // encadenar metodos 
    p1.mostrarInfo();

    // metodo ventas 
    p1.cantidadVendida(20);

    p1.agregarProveedor("Proveedor1");
    p1.agregarProveedor("Proveedor2");
    p1.mostrarProveedores();
    return 0;
}