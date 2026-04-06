#include <iostream>

class Celda {
protected:
    int id;
    bool ocupada;
public:
    Celda(int i): id(i), ocupada(false) {}

    Celda& ocupar() {
        ocupada = true;
        return *this;
    }

    void mostrar() const {
        std::cout<<"ID de la celda: "<<id<<std::endl;
        if(ocupada) {
            std::cout<<"Celda ocupada"<<std::endl;
        }
        else{
            std::cout<<"Celda disponible"<<std::endl;
        }
    }
};

class Grilla {
protected:
    std::vector<std::vector<Celda>> celdas; // vector de vectores de celdas
public:
    Grilla(int filas, int columnas) {
        for(int i=0; i<filas; ++i){
            std::vector<Celda> fila; // creo una fila vacia
            for(int j=0; j<columnas;++j) {
                fila.push_back(Celda(j));
            }
            celdas.push_back(fila);
        }
    }

};



int main() {
    Celda c1(101124);
    c1.mostrar();

    c1.ocupar();
    c1.mostrar();
    return 0;
}