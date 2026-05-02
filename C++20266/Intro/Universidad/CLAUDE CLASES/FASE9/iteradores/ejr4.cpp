#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventario{
protected:
    std::vector<std::string> productos;
public:
    Inventario() = default;

    Inventario& agregarProducto(const std::string& producto) {
        auto it = std::find(productos.begin(), productos.end(), producto);
        if(it != productos.end()){
            std::cout<<"Producto ya registrado"<<std::endl;
            return *this;
        }  
        productos.push_back(producto);
        return *this;
    }

    bool existe(const std::string& producto) {
        auto it = std::find(productos.begin(), productos.end(), producto);
        if(it != productos.end()) {
            return true;
        }
        return false;
    }
    // encontrar la posicion del producto
    int posicion(const std::string& producto) {
        auto it = std::find(productos.begin(), productos.end(), producto);
        if(it == productos.end()){
            std::cout<<"Producto no encontrado.."<<std::endl;
            return -1;// si devuelvo 0 puede ser posicion valida
        }
        // std::distance(n.begin(), it), cuenta la distancia
        return std::distance(productos.begin(), it);
        /*
        int indice = 0;
        for(size_t i=0; i < productos.size(); ++i) {
            if(productos.at(i) == producto) {
                indice = i+1;
                return indice;
            }
        }
        */
    }

    Inventario& eliminar(const std::string& producto) {
        auto it = std::find(productos.begin(), productos.end(), producto);
        if(it == productos.end()){
            std::cout<<"Producto no encontrado"<<std::endl;
            return *this;
        }
        productos.erase(it);
        return *this;
    }

    Inventario& reemplazar(const std::string& viejo, const std::string& nuevo){
        auto it = std::find(productos.begin(), productos.end(), viejo);
        if(it == productos.end()) {
            std::cout<<"Producto no encontrado"<<std::endl;
            return *this;
        }
        *it = nuevo; // sobreescribir sobre el objeto
        return *this;
    }

    void mostrar() const {
        if(productos.empty()){
            std::cout<<"Inventario vacio"<<std::endl;
            return;
        }
        std::cout<<"Inventario: "<<std::endl;
        for(const auto& p: productos){
            std::cout<<p<<", ";
        }
        std::cout<<std::endl;
    }
};

int main() {
    Inventario inv;

    inv.agregarProducto("Laptop")
       .agregarProducto("Mouse")
       .agregarProducto("Teclado")
       .agregarProducto("Monitor");

    inv.mostrar();

    std::cout << inv.existe("Mouse") << std::endl;     // 1
    std::cout << inv.existe("Audifonos") << std::endl; // 0

    std::cout << inv.posicion("Teclado") << std::endl; // 2
    std::cout << inv.posicion("Silla") << std::endl;   // -1

    inv.reemplazar("Mouse", "Mouse Gamer");
    inv.mostrar();

    inv.eliminar("Monitor");
    inv.mostrar();

    return 0;
}
