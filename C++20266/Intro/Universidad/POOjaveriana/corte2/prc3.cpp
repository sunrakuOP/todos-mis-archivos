#include <iostream>
#include <vector>

class Asiento {
protected:
    int fila, columna;
    bool reservado;
public:
    Asiento(int f, int c): fila(f), columna(c), reservado(false) {}

    bool getReservado() const { return reservado; }

    Asiento& reservar() {
        if(reservado == true) {
            std::cout<<"Asiento reservado..."<<std::endl;
            return *this;
        }
        else{
            std::cout<<"Reservando asiento..."<<std::endl;
            reservado = true;
            return *this;
        }
    }
    void mostrar() {
        if(reservado == true) {
            std::cout<<"[X]";
        }
        else{
            std::cout<<"[ ]";
        }
    }
};

class Sala {
protected:
    std::vector<std::vector<Asiento>> asientos;
    int filas, columnas;
public:
    Sala(int f, int c): filas(f), columnas(c) {
        // llenar manualmente la matriz 
        for(int i=0; i<f; ++i) {
            std::vector<Asiento> fila;
            for(int j=0; j<c; ++j) {
                fila.push_back(Asiento(i,j)); // se crea el objeto Asiento aca
            }
            asientos.push_back(fila);
        }
    }

    // siempre construir de lo pequeno a lo grande 
    void mostrarMapa() {
        for(int i=0; i<filas; ++i) {
            for(int j=0; j<columnas; ++j) {
                asientos.at(i).at(j).mostrar();
            }
        std::cout<<std::endl;
        }
    }
    // llamar los metodos de la clase anterior, si no pa que papi
    Sala& reservarAsiento(int f, int c) {
        asientos.at(f).at(c).reservar();
        return *this;
    }


};



int main() {
    // sala de 4 filas y 5 columnas
    Sala sala1(4, 5);
    sala1.mostrarMapa();

    sala1.reservarAsiento(1,1);
    sala1.reservarAsiento(2,2);
    sala1.reservarAsiento(1,3);
    sala1.reservarAsiento(3,1);
    sala1.mostrarMapa();

    return 0;
}