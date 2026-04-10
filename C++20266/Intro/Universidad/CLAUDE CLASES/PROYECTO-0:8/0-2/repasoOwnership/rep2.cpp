#include <iostream>
#include <vector>

class Producto {
protected:  
    std::string nombre;
    double precio;
    int stock;
public:
    Producto(const std::string& n, double p, int s): 
        nombre(std::move(n)), precio(p), stock(s) {}

    const std::string& getNombre() const { return nombre; }
    const double getPrecio() const { return precio; }
    const int getStock() const { return stock; }

    Producto& setPrecio(double p) { 
        precio = p;
        return *this;
    }

    void infoProducto() const {
        std::cout<<"Nombre: "<<nombre<<", precio: "<<precio<<", stock: "
            <<stock<<std::endl;
    }
};

class Inventario {
protected:
    std::vector<Producto*> productos;
public:
    Inventario() = default;
    ~Inventario() {
        for(const auto& p: productos) {
            delete p;
        }
        productos.clear();
    }
    // agregar producto nuevo
    Inventario& agregarProdctNuevo(const std::string& n, double p, int s) {
        for(const auto& p: productos){
            if(p->getNombre() == n) {
                std::cout<<"Producto con mismo nombre ya agregado.."<<std::endl;
                return *this;
            }
        }
        productos.push_back(new Producto(n,p,s));
        return *this;
    }
    // agregar producto ya creado pasando propiedad
    Inventario& agregarPrdctCreado(Producto* producto) {
        for(const auto& p: productos) {
            if(p == producto) {
                std::cout<<"Producto ya agregado..."<<std::endl;
                return *this;
            } else if(p->getNombre() == producto->getNombre()) {
                std::cout<<"Producto con mismo nombre ya agregado.."<<std::endl;
                return *this;
            }
        }
        productos.push_back(producto);
        return *this;   // pasa a ser propiedad del vector
    }
    // buscar por producto
    Producto* buscarProducto(const std::string& nombre) {
        for(const auto& p: productos) {
            if(p->getNombre() == nombre) {
                p->infoProducto();
                return p;
            }
        }
        std::cout<<"Producto no encontrado..."<<std::endl;
        return nullptr;
    }

    Producto* buscarMasCaro() {
        if(productos.empty()) {
            std::cout<<"Vector vacio..."<<std::endl;
            return nullptr;
        }
        Producto* masCaro = productos.at(0);
        for(const auto& p: productos) {
            if(p->getPrecio() > masCaro->getPrecio()) {
                masCaro = p;
            }
        }
        std::cout<<"Producto mas caro: "<<std::endl;
        masCaro->infoProducto(); 
        return masCaro;
    }

    Inventario& rebajar(const std::string& nombre, double descuento) {
        if(productos.empty()) {
            std::cout<<"Inventario vacio.."<<std::endl;
            return *this;
        }
        Producto* p = buscarProducto(nombre);
        if(!p) {
            return *this;
        }
        p->setPrecio(p->getPrecio() - descuento);
        return *this;
    }

    Inventario& eliminarProducto(const std::string& nombre) {
        if(productos.empty()) {
            std::cout<<"Inventario vacio.."<<std::endl;
            return *this;
        }
        for(auto it = productos.begin(); it != productos.end(); ++it) {
            if((*it)->getNombre() == nombre) {
                delete *it; // eliminar de memoria
                std::cout<<"Eliminando producto..."<<std::endl;
                productos.erase(it);
                return *this;
            }
        }
        std::cout<<"Producto no encontrado.."<<std::endl;
        return *this;
    }
};


int main() {
    Inventario inv;

    inv.agregarProdctNuevo("Laptop", 1500.0, 10)
       .agregarProdctNuevo("Mouse", 25.0, 50)
       .agregarProdctNuevo("Teclado", 80.0, 30)
       .agregarProdctNuevo("Monitor", 400.0, 15);

    // buscar existente y no existente
    Producto* p = inv.buscarProducto("Mouse");
    if(p) p->infoProducto();

    inv.buscarProducto("Audifonos"); // no existe

    // buscar mas caro
    Producto* caro = inv.buscarMasCaro();
    if(caro) std::cout<<"El mas caro es: "<<caro->getNombre()<<std::endl;

    // rebajar precio
    inv.rebajar("Laptop", 200.0);
    inv.buscarProducto("Laptop"); // verificar nuevo precio

    // eliminar
    inv.eliminarProducto("Mouse");
    inv.buscarProducto("Mouse"); // debe decir no encontrado

    // agregar externo (transfiere ownership)
    Producto* ext = new Producto("Webcam", 60.0, 20);
    inv.agregarPrdctCreado(ext);
    // NO hacer delete ext — Inventario es dueño ahora

    return 0; // ~Inventario() destruye todo
}
