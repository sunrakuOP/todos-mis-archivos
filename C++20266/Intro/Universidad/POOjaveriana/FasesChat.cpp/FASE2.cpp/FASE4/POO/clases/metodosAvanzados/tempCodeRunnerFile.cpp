/*



EN EL main(), DEBES PROBAR:
1. Crear 2 productos con constructor normal
2. Crear un tercero como copia del primero
3. Usar operador de asignación
4. Llamar a esIgual() para comparar dos productos
5. Llamar a fusionar() para sumar stocks
6. Llamar a masBarato() para comparar precios
7. Mostrar todos los productos

REQUISITOS EXTRA:
- Usa lista de inicialización en el constructor
- Implementa correctamente el operador de asignación con verificación
- Los métodos que usan objetos como parámetro deben ser const
- Encapsulación correcta (atributos private, métodos public)

*/

#include <iostream>

class Producto{
    private:
    std::string nombre;
    double precio;
    int stock, identificador;

    public:
    // constructor normal
    Producto (std::string n, double p, int s, int i) : nombre(n), precio(p), stock(s), identificador(i) {
        std::cout<<"Producto: "<<nombre<<", codigo: "<<identificador<<std::endl;
    }
    // constructor de copia
    Producto (const Producto& otro) {
        nombre = otro.nombre;
        precio = otro.precio;
        stock = otro.stock;
        identificador = otro.identificador;
        std::cout<<"Copia producto ["<<nombre<<"] creada"<<std::endl;
    }
    // operador de asignacion
    Producto operator=(const Producto& otro) {
        if (this == &otro) {
            std::cout<<"Es el mismo objeto"<<std::endl;
            return *this;
        }
        std::cout<<"Nombre actualizado"<<std::endl; // como se llama nombre anterior y nuevo?
        return *this;
    }
    void mostrar() {
        std::cout<<"Nombre: "<<nombre<<std::endl;
        std::cout<<"Id: "<<identificador<<std::endl;
        std::cout<<"Precio"<<precio<<std::endl; 
        std::cout<<"Stock: "<<stock<<std::endl;
    }
    // metodo que dice si dos productos tienen mismo ID
    bool esIgual(const Producto& otro) {
        if (identificador == otro.identificador) {
            std::cout<<"Mismo ID para ambos"<<std::endl;
            return true;
        }
        return false;
    }
    // metodo que suma stock de ambos productos, tomando como parametro otro producto
    int fusionar(const Producto& otro) {
        std::cout<<"Stock total: "<< stock + otro.stock <<std::endl;
        return stock + otro.stock;  // se guarda en el stock? o solo es para imprimir?
    }
    void masBarato(const Producto& otro) {
        if (precio > otro.precio) {
            std::cout<<nombre<<" producto es mas barato"<<std::endl;
        }
        else if (precio < otro.precio) {
            std::cout<<otro.nombre<<" producto es mas barato"<<std::endl;
        }
        else { std::cout<<"Precio es igual"<<std::endl; }
    }

};


int main(){
    // crear 2 objetos con constructor normal
    Producto p1("producto1", 1000, 30, 100028);
    Producto p2("producto2", 2000, 34, 100029);
    // crear tercer objeto como copia del primero
    Producto p3(p1);
    p3.mostrar();
    // crear objeto 4 para copiarlo luego y verificar
    Producto p4("producto4", 3000, 38, 100027);
    p4.mostrar();
    p4 = p2;
    p4.mostrar();



    return 0;
}