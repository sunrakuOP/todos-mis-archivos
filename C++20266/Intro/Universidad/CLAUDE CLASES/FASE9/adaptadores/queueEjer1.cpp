#include <iostream>
#include <queue>
#include <string>

class Soporte {
protected:
    std::queue<std::string> tickets;
public:
    Soporte& agregar(const std::string& cliente) {
        tickets.push(cliente);
        return *this;
    }
    Soporte& atender() {
        if(tickets.empty()) {
            std::cout<<"No hay nadie en la cola.."<<std::endl;
            return *this;
        }
        std::cout<<"Atendiendo a "<<tickets.front()<<std::endl;
        tickets.pop(); 
        return *this;
    }
    int cuantosEsperan() {
        std::cout<<"Numero de personas esperando: "<<(int)tickets.size()<<std::endl;
        return (int)tickets.size();
    }
    void mostrarCola() const {
        // copia del queue 
        std::queue<std::string> copia = tickets;
        while(!copia.empty()){
            std::cout<<copia.front()<<std::endl;
            copia.pop();
        }
    }
};


int main() {
    Soporte s;

    s.agregar("Carlos")
     .agregar("Ana")
     .agregar("Luis")
     .agregar("Maria");

    s.cuantosEsperan(); // 4

    s.mostrarCola();

    s.atender(); // Carlos
    s.atender(); // Ana

    s.cuantosEsperan(); // 2

    s.atender();
    s.atender();
    s.atender(); // cola vacía

    return 0;
}
