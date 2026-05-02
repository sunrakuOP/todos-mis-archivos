#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <map>

class Bodega {
protected:
    std::string nombre; 
    std::map<std::string, int> inventario;
public:
    // mutex debe ser publico
    std::mutex mtx; 

    auto getInventario() { return inventario; }

    int getStock(const std::string& prod) {
        auto it = inventario.find(prod);
        if(it == inventario.end()){
            std::cout<<"Producto no encontrado"<<std::endl;
            return 0;
        }
        return it->second;
    }

    Bodega& setStock(const std::string& prod, int nuevoSt){
        auto it = inventario.find(prod);
        if(it == inventario.end()){
            std::cout<<"Producto no encontrado"<<std::endl;
            return *this;
        }
        it->second = nuevoSt;
        return *this;
    }

    Bodega(const std::string& n): nombre(n) {}

    Bodega& agregarProducto(const std::string& prd, int ct){
        auto it = inventario.find(prd);
        if(it != inventario.end()){
            std::cout<<"Inventario ya agregado, sumando cantidad"<<std::endl;
            inventario[prd]+= ct;
            return *this;
        }
        inventario.insert({prd,ct});
        return *this;
    }
    // agregar metodo existe 
    bool existe(const std::string& nprod){
        return inventario.find(nprod) != inventario.end();
    }

    void mostrarInv() {
        if(inventario.empty()){
            std::cout<<"Inventario vacio"<<std::endl;
            return;
        }
        for(const auto&[prd, ct]: inventario){
            std::cout<<prd<<", "<<ct<<std::endl;
        }
    }
};  

// funcion libre que transfiere inventario
void transferir(Bodega& origen, Bodega& destino, const std::string& nprd, int ct){
    std::scoped_lock lock(origen.mtx, destino.mtx);

    if(!origen.existe(nprd)){
        std::cout<<"Producto no encontrado"<<std::endl;
        return;
    }
    if(origen.getStock(nprd) < ct){
        std::cout<<"Cantidad insuficiente.."<<std::endl;
        return;
    }
    origen.setStock(nprd, origen.getStock(nprd)-ct);
    destino.agregarProducto(nprd, ct);
}

int main() {
    std::vector<std::thread> hilos;
    // crear las clases
    Bodega bogota("Bogota");
    bogota.agregarProducto("laptop", 20)
          .agregarProducto("mouse", 50)
          .agregarProducto("teclado", 30);

    Bodega medellin("Medellin");
    medellin.agregarProducto("laptop", 15)
            .agregarProducto("mouse", 30)
            .agregarProducto("teclado", 40);

    Bodega cali("Cali");
    cali.agregarProducto("laptop", 10)
        .agregarProducto("mouse", 20)
        .agregarProducto("teclado", 25);


    // crear los hilos, hacen cosas diferentes, hacerlos uno por uno
    hilos.push_back(std::thread([&](){ transferir(bogota, medellin, "laptop", 5); }));
    hilos.push_back(std::thread([&](){ transferir(medellin, cali, "mouse", 10); }));
    hilos.push_back(std::thread([&](){ transferir(cali, bogota, "teclado", 8); }));
    hilos.push_back(std::thread([&](){ transferir(medellin, cali, "laptop", 3); }));
    
    for(auto& t: hilos){
        t.join();
    }

    bogota.mostrarInv();
    medellin.mostrarInv();
    cali.mostrarInv();



    return 0;
}