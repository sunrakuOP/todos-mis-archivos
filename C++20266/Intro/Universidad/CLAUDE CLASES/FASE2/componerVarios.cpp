// sistema de facturacion
#include <iostream>
#include <string>
#include <vector>

class Producto {
  friend class Factura;  // factura puede usar los atributos de privados de Producto
private: 
  std::string nombre;
  double precio;
  int cantidad;
public:
  Producto(std::string n, double p, int c) : nombre(n), precio(p), cantidad(c) {}
  ~Producto() {}

  std::string getNombre() const { return nombre; }
  double getPrecio() const { return precio;}
  int getCantidad() const { return cantidad; }

  void mostrarInfo() {
    std::cout<<"Nombre: "<<nombre << std::endl
             <<"Precio: "<<precio <<std::endl
             <<"Cantidad: "<<cantidad<<std::endl;
  }
};

class Cliente {
  friend void imprimirCliente(const Cliente& cliente);
private:
  std::string nombreCliente;
  int id;
public:
  Cliente (std::string n, int i) : nombreCliente(n), id(i) {}
  ~Cliente () {}

  Cliente& setNombre(std::string n) {    // siempre se deben devoler con referencia
    nombreCliente = n;  
    return *this;
  }
  Cliente& setId(int i) {
    id = i;
    return *this;
  }

  std::string getNombreCliente() const { return nombreCliente; }   // los getters devuelven valor, no son void
  int getId() const { return id; }

};

void imprimirCliente(const Cliente& cliente) {
  std::cout<<"Nombre: "<< cliente.nombreCliente <<std::endl
           <<"Id: "<< cliente.id <<std::endl;    // funcion que puede acceder a los metodos de la clase usando objeto
}


class Factura {  // compone a Cliente y vector<Productos>
private: 
  int numeroFactura;
  static int contador;  // para seguir almacenando el numero de productos
  Cliente cliente;
  std::vector<Producto> productoss;
public: 
  Factura (Cliente c) : numeroFactura(++contador), cliente(c) {}  // hago la factura para el cliente y ya
  ~Factura () {}

  void agregarProducto(const Producto& p) {
    productoss.push_back(p);
  }

  double calcularTotal() {
    double total = 0;
    for(auto& p: productoss) {
      total += p.precio*p.cantidad; // para acceder directamente debido a que Factura es friend de Productos
    }
    std::cout<<"Precio total: "<<total <<std::endl;
    return total;
  }
   
  void imprimirFactura () {
    imprimirCliente(cliente);  // usar el metodo friend (cualquier clase la puede usar)
    for(const auto& p: productoss) {
      std::cout<<"Producto: "<<p.nombre <<", cantidad: "<<p.cantidad <<std::endl;
      std::cout<<"Subtotal: "<< p.precio*p.cantidad <<std::endl;
    }
    calcularTotal();
    
  }

};

int Factura::contador = 0; // inicializar el static siempre afuera




int main() {
  Cliente c1("Juan", 1);
  Producto p1("Laptop",  2000.0, 1);
  Producto p2("Mouse",     50.0, 2);
  Producto p3("Teclado",   80.0, 1);

  Factura f(c1);
  f.agregarProducto(p1);
  f.agregarProducto(p2);
  f.agregarProducto(p3);
  f.imprimirFactura();

  return 0;

  return 0;
}