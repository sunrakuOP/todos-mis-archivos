#include <iostream>
#include <mutex>
#include <thread>
#include <map>
#include <vector>
#include <string>
#include <chrono>

class Inventario{
protected:
    std::map<std::string, int> productos;
    std::mutex llave; // llave para los datos compartidos
    // nombre del producto y stock
public:
    Inventario() = default;

    Inventario& agregar(const std::string& np, int ct){
        auto it = productos.find(np);
        if(it != productos.end()){
            std::cout<<"Producto ya agregado"<<std::endl;
            return *this;
        }
        productos.insert({np, ct});
        return *this;
    }

    Inventario& comprar(const std::string& np, int ct) {
        // hacer que el hilo demore un poco en hacer la operacion
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        std::lock_guard<std::mutex> guard(llave);
        auto it = productos.find(np);
        if(it == productos.end()){
            std::cout<<"Producto no encontrado..."<<std::endl;
            return *this;
        }
        if(ct > it->second){
            std::cout<<"Stock insuficiente.."<<std::endl;
            return *this;
        }
        // si solo bloqueo al escribir sigue siendo race condition
        it->second-=ct;
        return *this;
    }

    Inventario& reabastecer(const std::string np, int ct){
        std::lock_guard<std::mutex> guard(llave);

        auto it = productos.find(np);
        if(it == productos.end()){
            std::cout<<"Producto no encontrado..."<<std::endl;
            return *this;
        }
        it->second+= ct;
        return *this;
    }

    void mostrar() const {
        if(productos.empty()){
            std::cout<<"Lista de productos vacia..."<<std::endl;
            return;
        }
        std::cout<<"Productos: "<<std::endl;
        for(const auto&[np, stock]: productos){
            std::cout<<"Nombre prod: "<<np<<", stock: "<<stock<<std::endl;
        }
    }
};

int main() {
    std::vector<std::thread> hilos; // para hacerles el join despues
    Inventario inv;
    inv.agregar("laptop", 5)
       .agregar("mouse", 8)
       .agregar("teclado", 6)
       .agregar("monitor", 3);

    
    // crear 4 hilos para compradores
    for(int i=0; i<4; ++i){
        hilos.push_back(std::thread([&inv](){
            inv.comprar("laptop", 1);
            inv.comprar("mouse", 1);
            inv.comprar("teclado",1);
        }));
    }
    // crear 2 hilos para reabastecer
    for(int j=0; j<2; ++j){
        hilos.push_back(std::thread([&inv](){
            inv.reabastecer("laptop", 5);
            inv.reabastecer("mouse", 5);
            inv.reabastecer("teclado", 5);
            inv.reabastecer("monitor", 5);
        }));
    }
    // hacerle join al vector
    for(auto& t: hilos){
        t.join();
    }

    inv.mostrar();

    return 0;
}