#include <iostream>

class Rectangulo {
    private:
    int base, altura;

    public: 
        // constructor
    Rectangulo(int b, int a){
        base = b;
        altura = a;
    }
    // posar objeto como parametro al metodo para hacer verificaciones
    bool esIgual(Rectangulo obj) {
        // pasamos objeto como referencia para comparar atributos
        return base*altura == obj.altura*obj.base;
    } // objetoParametro.atributo

};

int main() {
    Rectangulo r1(3,4);
    Rectangulo r2(3,4);

    if (r1.esIgual(r2)) std::cout<<"Iguales medidas"<<std::endl;
    else std::cout<<"No son iguales"<<std::endl;

    return 0;
}