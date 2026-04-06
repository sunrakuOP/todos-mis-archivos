#include <iostream>

class Vehiculo {
protected:
    std::string placa, marca;
public:
    Vehiculo(const std::string& pl, const std::string& ma): placa(pl), marca(ma) {}

    void mostrar() const {
        std::cout<<"Marca: "<<marca<<", placa: "<<placa<<std::endl;
    }
};

class Espacio {
protected:
    int id;
    Vehiculo* vehiculo;
    bool ocupado;
public:
    Espacio(int i): id(i), vehiculo(nullptr), ocupado(false) {}

    bool getOcupado() const { return ocupado; }

    Espacio& estacionar(Vehiculo* v) {
        if(ocupado == true) {
            std::cout<<"Espacio ocupado"<<std::endl;
            return *this;
        }
        ocupado = true;
        vehiculo = v; // asignar el puntero
        std::cout<<"Vehiculo estacionado"<<std::endl;
        return *this;
    }

    Espacio& retirar() {
        if(ocupado == false) {
            std::cout<<"Espacio ocupado"<<std::endl;
            return *this;
        }
        vehiculo = nullptr; // para que el puntero no apunte a nada
        ocupado = false;
        std::cout<<"Vehiculo retirado"<<std::endl;
        return *this;
    } 

    void mostrar() const {
        std::cout<<"ID de espacio: "<<id<<std::endl;
        if (vehiculo != nullptr) {
            std::cout<<"Espacio ocupado, info del vehiculo"<<std::endl;
            vehiculo->mostrar();
        }
        else {
            std::cout<<"Espacio no ocupado"<<std::endl;
        }

    }
};

class Estacionamiento {
protected:
    std::vector<std::vector<Espacio>> espacios;
    int filas, columnas;
public:
    Estacionamiento(int f, int c): filas(f), columnas(c) {
        for(int i=0; i<f; ++i){
            std::vector<Espacio> fila;
            for(int j=0; j<c; ++j) {
                // llenar cada columna de fila con Espacio (usando constructor)
                fila.push_back(Espacio(i*columnas+j));  // pasar el id manualmente
            }
        espacios.push_back(fila);
        }
    }

    void mostrarMapa() const {
        for(int i=0; i<filas; i++) {
            for(int j=0; j<columnas; ++j) {
                espacios.at(i).at(j).mostrar();
            }
        }
    }

    Estacionamiento& estacionar(int f, int c, Vehiculo* v) {
        if(f >= filas || c >= columnas) {
            std::cout<<"Espacio fuera de los parametros"<<std::endl;
            return *this;
        }
        espacios.at(f).at(c).estacionar(v);
        return *this;
    }
    Estacionamiento& retirar(int f, int c) {
        espacios.at(c).at(f).retirar(); // usar los metodos anteriores eghhhh   
    }
};


int main() {
    Vehiculo v1("ABC123", "Toyota");
    Vehiculo v2("XYZ789", "Honda");
    Vehiculo v3("DEF456", "Mazda");

    Estacionamiento est(3, 3);

    est.mostrarMapa();

    est.estacionar(0, 0, &v1);
    est.estacionar(1, 2, &v2);
    est.estacionar(2, 1, &v3);

    est.mostrarMapa();

    est.retirar(1, 2);

    est.mostrarMapa();

    return 0;
}
