#include <iostream>
#include <vector>

enum class Tamanio {
// solo defino los 3 tipos de tamano permitidos
    pequeno,
    mediano, 
    grande // ultimo elemento sin ;
};  

class Paquete {
protected:
    int codigoRastreo;
    double peso;
    Tamanio tamanio;
public:
    Paquete(int cr, double p, Tamanio t): codigoRastreo(cr), peso(p), tamanio(t) {}

    int getCodigo() const { return codigoRastreo; }
    double getPeso() const { return peso; }
    Tamanio getTamanio() const { return tamanio; }

};

class Casillero {
protected:
    int idCasillero;
    int contadorEntreg;
    Tamanio tamanioCas;
    Paquete* paquete = nullptr; // puntero a nullptr
    bool ocupado;
public:
    Casillero(int i, Tamanio t):
        idCasillero(i), contadorEntreg(0), tamanioCas(t), ocupado(false) {}
        // no puedo inicializar el paquete porque no existe 

    void recibirPaquete(Paquete* p) {
    if(ocupado) {
        std::cout << "Casillero ocupado" << std::endl;
        return;
    }
    if(tamanioCas >= p->getTamanio()) {
        paquete = p; // cambio el puntero de null a p (direccion)
        ocupado = true;
        std::cout << "Paquete recibido" << std::endl;
    } else {
        std::cout << "El paquete no cabe" << std::endl;
        }
    }


    void entregarPaquete() {
        if(ocupado == false) {
            std::cout<<"Casillero vacio"<<std::endl;
            return;
        }
        std::cout<<"Entregando paquete "<< paquete->getCodigo();
        paquete = nullptr;  // apunto a nada
        ocupado = false;
        ++contadorEntreg;
        if(contadorEntreg > 10) {
            std::cout<<"Casillero en mantenimiento.."<<std::endl;
        } 

    }

    bool estado() const { return ocupado; }
};

class Estacion {
protected:
    std::vector<std::vector<Casillero>> grilla;
    int nivel, columna;
public:



    void recibirPaquete(int nivel, int columna, Paquete p) {
        
    } 

};





int main() {

    return 0;
}