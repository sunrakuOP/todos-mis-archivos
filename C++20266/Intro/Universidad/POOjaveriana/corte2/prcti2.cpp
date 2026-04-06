#include <iostream>
#include <vector>

class Motor{
protected:
    int cilindros;
    double caballosFuerza;
public:
    Motor(int c, double cf): cilindros(c), caballosFuerza(cf) {}

    void mostrar() const {
        std::cout<<"Cilindros: "<<cilindros<<", Caballos de fuerza: "<<caballosFuerza<<std::endl;
    }
};

class Carro {
protected:
    std::string marca;
    Motor* motor; // para que pueda existir o no
public:
    Carro(const std::string& ma): marca(ma), motor(nullptr) {}
    // inicializo el objeto Carro sin motor

    Carro& instalarMotor(Motor *m) {
        motor = m;
        return *this; // creo un motor y selo instalo al Carro
    }

    void mostrar() const {
        std::cout<<"Marca: "<<marca<<std::endl;
        if (motor != nullptr) {
            motor->mostrar();
        } 
        else {
            std::cout<<"Carro no tiene motor"<<std::endl;
        }
    }

};




int main() {
    Motor motor(8, 300);
    Carro ferrari("Ferrari");
    ferrari.mostrar();

    ferrari.instalarMotor(&motor);
    ferrari.mostrar();

    return 0;
}