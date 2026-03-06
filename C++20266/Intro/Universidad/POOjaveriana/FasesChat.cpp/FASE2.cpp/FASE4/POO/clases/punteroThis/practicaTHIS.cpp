#include <iostream>
// crear clase rectangulo
class Rectangulo {
    private:
    double base, altura;

    public:
    // constructor (INICIALIZAR)
    Rectangulo(double b, double a) {   // parametros a y b
        base = b;
        altura = a;
    }
    // destructor (ELIMINAR VALORES DESPUES DE TERMINAR CON OBJETO)
    ~Rectangulo() {
    }

    // setters, usando *this como retorno para poder encadenar metodos (*this es referencia al objeto)
    Rectangulo& setBase(double b) {
        base = b;
        return *this;
    }
    Rectangulo& setAltura(double a) {
        altura = a;
        return *this;
    }
    // getters devuelven el tipo de valor del atributo
    double getBase() {
        return base;
    }
    double getAltura() {
        return altura;
    }

    double area() {
        return base*altura;
    }
};

int main() {
    // inicializar objeto 1 usando el constructor
    Rectangulo r1(10,11);
    std::cout<<"Objeto inicializado a altura "<<r1.getAltura() <<" y base "<<r1.getBase() <<std::endl;
    std::cout<<"Area del objeto 1: "<< r1.area() <<std::endl;

    // encadenar metodos para hallar el area de una cambiando valores de los atributos
    std::cout<<"Cambiando altura y base a (20,2)"<< std::endl;
    std::cout<<"Area objeto 2: "<< r1.setAltura(20).setBase(2).area() <<std::endl;  
    
    return 0;
}