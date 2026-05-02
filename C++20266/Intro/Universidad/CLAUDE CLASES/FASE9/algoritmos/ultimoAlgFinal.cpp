// sistema de tienda usando algrtimos y punteros
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Producto {
protected:
    std::string nombre;
    double precio; 
    int stock;
public:
    Producto(const std::string& n, double p, int s):
        nombre(std::move(n)), precio(p), stock(s) {}
    
        // como es class ahora hacerle gettes, antes era struct, public no protected
    const std::string& getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }
    
    void infoProd() const {
        std::cout<<"Nombre: "<<nombre<<"< precio: "
            <<precio<<", stock: "<<stock<<std::endl;
    }
};

class Tienda{
protected:
    std::string nombreTienda;
    std::vector<Producto*> productos;
public:
    Tienda(const std::string& nt): nombreTienda(std::move(nt)) {}
    // tienda maneja el ownership
    ~Tienda() {
        for(const auto& p: productos){
            delete p;
        }
        productos.clear();
    }

    // solamente los creo desde Tienda
    Tienda& agregarProducto(const std::string& n, double p, int s){
        auto it = std::find_if(productos.begin(), productos.end(),
            [&n](const Producto* prod){return prod->getNombre() == n; });
        if(it != productos.end()){
            std::cout<<"Producto ya agregado"<<std::endl;
            return *this;
        }
        productos.push_back(new Producto(n,p,s));
        return *this;
    }
    // retorna un puntero
    Producto* buscar(const std::string& nombre){
        auto it = std::find_if(productos.begin(), productos.end(),
            [&nombre](const Producto* prod){return prod->getNombre() == nombre; });
        if(it == productos.end()){
            std::cout<<"Producto no encontrado"<<std::endl;
            return nullptr;
        }
        (*it)->infoProd();
        return *it;
    }
    // buscar producto mas caro
    Producto* masCaro() {
        if(productos.empty()){
            std::cout<<"Vector vacio.."<<std::endl;
            return nullptr;
        }
        auto it = std::max_element(productos.begin(), productos.end(), 
            [](const Producto* a, const Producto* b){return a->getPrecio() < b->getPrecio(); });
            // lambdas siempre comparan en orden, a < b, y van ajustando internamente
        (*it)->infoProd();
        return *it;
    }

    double precioTotal() {
        if(productos.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return 0.0;
        }
        double sumatoria = 0;
        for(const auto&p : productos){
            sumatoria += p->getPrecio();
        }
        std::cout<<"Total: "<<sumatoria<<std::endl;
        return sumatoria;
    }

    Tienda& ordenarPorPrecio() {
        // sort no retorna nada
        std::sort(productos.begin(), productos.end(),
            [](const Producto* a, const Producto* b){return a->getPrecio() > b->getPrecio(); });
        return *this;
    }

    Tienda& eliminarSinStock() {
        // modificar vector mientras lo recorro usar remove
        // recordar, siempre para eliminar, FOR ITERADOR MANUAL
        for(auto it = productos.begin(); it != productos.end();) {
            if((*it)->getStock() == 0) {
                delete *it;
                it = productos.erase(it); // reasignar al siguiente
                // erase hace que apunte al siguiente elemento valido, avance automatico
            } else {
                ++ it;
            }
        }
        return *this;
    }

    // any/all/none of, devuelve un bool
    bool hayMenorA(double precio) {
        return std::any_of(productos.begin(), productos.end(),
            [precio](const Producto* prod){return prod->getPrecio() < precio;});
    }

    void mostrar() const {
        if(productos.empty()) {
            std::cout<<"Vector vacio"<<std::endl;
            return;
        }
        std::cout<<"Productos: "<<std::endl;
        for(const auto& p: productos){
            p->infoProd();
        }
    }
};

int main() {
    Tienda t("MiTienda");

    t.agregarProducto("Laptop", 1500.0, 10)
     .agregarProducto("Mouse", 25.0, 0)
     .agregarProducto("Teclado", 80.0, 5)
     .agregarProducto("Monitor", 400.0, 0)
     .agregarProducto("Laptop", 999.0, 1); // duplicado

    t.mostrar();

    t.buscar("Mouse");
    t.buscar("Audifonos"); // no existe

    Producto* caro = t.masCaro();
    if(caro) std::cout << "Mas caro: " << caro->getNombre() << std::endl;

    std::cout << t.hayMenorA(100.0) << std::endl; // true

    t.precioTotal();

    t.eliminarSinStock();
    t.mostrar(); // sin Mouse ni Monitor

    t.ordenarPorPrecio();
    t.mostrar();

    return 0;
}
