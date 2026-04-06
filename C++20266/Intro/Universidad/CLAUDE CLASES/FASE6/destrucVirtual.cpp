#include <iostream>
#include <vector>

class Vehiculo {
protected:
    std::string marca;
public:
    Vehiculo(const std::string& ma): marca(ma) {}
    // destructor de base VIRTUAL
    virtual ~Vehiculo() {
        std::cout<<"Destruyendo vehiculo..."<<std::endl;
    }
    virtual void encender() = 0; // para hacer la clase abstracta

    virtual void modoEspecial() { // no abstracto para que no interfiera con los otros
        std::cout<<"Modo especial no disponible.."<<std::endl;
    }
};

class Carro: public Vehiculo {
public:
    Carro(const std::string& ma): Vehiculo(ma) {}
    ~Carro() {
        std::cout<<"Destruyendo carro.."<<std::endl; 
        // creo que solo se pone destructor, sin virtual en las derivadas
    }

    void encender() override  { 
        std::cout<<"Carro encendido.."<<std::endl;
    }
};

class Electrico: public Carro {
public: 
    Electrico(const std::string& ma): Carro(ma) {}

    ~Electrico() {
        std::cout<<"Destruyendo electrico.."<<std::endl;
    }

    void encender() override final { // para que no se pueda sobreescribir mas sus derivadas
        std::cout<<"Electrico encendido sin ruido.."<<std::endl;
    }
};
class Tesla: public Electrico {
public: 
    Tesla(const std::string& ma): Electrico(ma) {}

    void modoEspecial() override {
        std::cout<<"Autopilot encendido"<<std::endl;
    }
};


int main() {
    // trabajo con punteros
    // repaso de UPCASTING
    std::vector<Vehiculo*> vehiculos;

    vehiculos.push_back(new Carro("Mazda"));
    vehiculos.push_back(new Electrico("BYD"));
    vehiculos.push_back(new Tesla("Tesla"));

    // polimorfismo, recorrer el vector y como ya en virtual en el programa (VTABLE Y VPTR)
    for(const auto& v: vehiculos) {
        v->encender();   // compilador sabe que tipo es sin mirar el tipo de puntero sino el objeto
        v->modoEspecial();
    }

    // debo hacer el delete de cada elemento
    for(const auto& v: vehiculos) {
        delete v;
    }
    vehiculos.clear();   // limpiar el vector

    return 0;
}