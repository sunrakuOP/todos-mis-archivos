#include <iostream>
#include <vector>
#include <set>

class Contenedor {
protected:  
    std::vector<int> numeros;
public:
    Contenedor() = default;

    Contenedor& agregar(int num) {
        numeros.push_back(num);
        return *this;
    }

    Contenedor& eliminarPares() {
        if(numeros.empty()) {
            std::cout<<"Contenedor vacio.."<<std::endl;
            return *this;
        }
        for(auto it = numeros.begin(); it != numeros.end();){
            if((*it)%2 == 0) {
                it = numeros.erase(it); // erase invalida el iterador, no puedo seguir con el
                // reasigno el iterador al siguiente valido
            }
            else {
                ++it; // sino elimino avanzo manualmente
            }
        }
        return *this;
    }
    Contenedor& eliminarMayores(int num) {
        if(numeros.empty()) {
            std::cout<<"Contenedor vacio.."<<std::endl;
            return *this;
        }
        for(auto it = numeros.begin(); it != numeros.end();){
            if((*it) > num) {
                it = numeros.erase(it); // erase con iterador
            }
            else {
                ++it;
            }
        }
        return *this;
    }

    void mostrar() const {
        if(numeros.empty()) {
            std::cout<<"Contenedor vacio.."<<std::endl;
            return;
        }
        std::cout<<"Vector: "<<std::endl;
        for(const auto n: numeros) {
            std::cout<<n<<", ";
        }
        std::cout<<std::endl;

    }
    // eliminar duplicados
    Contenedor& eliminarDuplicados() {
        std::set<int> vistos; // los guarda una vez
        for(auto it = numeros.begin(); it != numeros.end();) {
            // si ya esta, lo elimina
            if(vistos.count(*it)) {
                it = numeros.erase(it);
            }
            else{
                // si no esta, lo agrega a vistos y avanza
                vistos.insert(*it); // si ya esta lo ignora
                ++it;
            }
        }
        return *this;
    }
    /*
        // eliminar pares, usando erase
    // recordar que siempre que se va a modificar un vector usar iterador
    Contenedor& eliminarPares() {
        std::set<int> solos;
        if(numeros.empty()) {
            std::cout<<"Contenedor vacio.."<<std::endl;
            return *this;
        }
        // para eliminar duplicados pasarlo a un set
        for(auto it = numeros.begin(); it != numeros.end(); ++it) {
            solos.insert(*it); // descarta duplicados    
        }
        return *this;
    }
    */
};


int main() {
    Contenedor c;

    c.agregar(1).agregar(2).agregar(3).agregar(4)
     .agregar(5).agregar(6).agregar(7).agregar(8);

    c.mostrar(); // 1,2,3,4,5,6,7,8
    c.eliminarPares();
    c.mostrar(); // 1,3,5,7

    Contenedor c2;
    c2.agregar(10).agregar(3).agregar(7).agregar(15).agregar(2);
    c2.eliminarMayores(7);
    c2.mostrar(); // 3,7,2

    Contenedor c3;
    c3.agregar(1).agregar(3).agregar(1).agregar(5).agregar(3).agregar(7);
    c3.eliminarDuplicados();
    c3.mostrar(); // 1,3,5,7

    return 0;
}
