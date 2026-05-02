#include <iostream>
#include <string>
#include <unordered_map>

class Producto {
protected:
  std::string nombre;
  double precio;
public:
  Producto(const std::string& n, double p): nombre(std::move(n)), precio(p) {}
  virtual ~Producto() = default;

  const std::string getNombre() const { return nombre;}
  double getPrecio() const { return precio; }

  virtual void descripcion() const {
    std::cout<<"Producto: "<<nombre<<", precio: "<<precio<<std::endl;
  }
  
};

class ProductoDigital: public Producto {
protected:
  int tamanioMB;
public:
  ProductoDigital(const std::string& n, double p, int td): Producto(n,p), tamanioMB(td) {}

  void descripcion() const override {
    Producto::descripcion();
    std::cout<<"Tamanio MB: "<<tamanioMB<<std::endl;
  }
};

class Tienda {
protected:
std::string nombreTienda;
  std::unordered_map<std::string, Producto*> productos;
public:
  Tienda(const std::string& n): nombreTienda(std::move(n)) {}
  ~Tienda() {
    // destructor solo sobre VALOR que es el puntero
    for(const auto&[id, producto]: productos) {
      delete producto;
    }
    productos.clear();
  }

  // pasar el producto ya creado 
  Tienda& agregarProducto(const std::string& id, Producto* producto) {
    if(productos.count(id)){
      std::cout<<"Id ya registrado.."<<std::endl;
      return *this;
    }
    productos.insert({id, producto}); // si el id ya esta lo ignora
    return *this;
  }

  void buscarId(const std::string& idd) {
    auto it = productos.find(idd); //  iterador a la posicion del par en el mapa
    if(it == productos.end()) {
      std::cout<<"Producto no encontrado..."<<std::endl;
      return;
    }
    std::cout<<"Info del producto..."<<std::endl;
    it->second->descripcion();

    /* for es innecesario, lo puedo hacer con iteradores que es mas limpio
    if(!productos.count(idd)) {
      std::cout<<"Id no encontrado..."<<std::endl;
      return;
    }
    
    for(const auto&[id, producto]: productos) {
      if(id == idd) {
        // llama al polimorfismo usando virtual
        producto->descripcion(); 
      }
    }
    */
  }

  Tienda& eliminarProducto(const std::string& idd) {
    auto it = productos.find(idd); // iterador al elemento que queremos buscar
    if(it == productos.end()) {
      std::cout<<"Producto no encontrado..."<<std::endl;
      return *this;
    }
    // IMPORTANTE. HACER DELETE DEL PRODUCTO
    delete it->second; // se refiere al producto
    productos.erase(it); // eliminar el par del mapa
    return *this;
  }



};

int main() {
    Tienda t("MiTienda");
    t.agregarProducto("P001", new Producto("Teclado", 50.0));
    t.agregarProducto("P002", new ProductoDigital("Antivirus", 30.0, 200));
    t.buscarId("P001");
    t.buscarId("P002");
    t.eliminarProducto("P001");
    t.buscarId("P001");
    
    return 0;
}
