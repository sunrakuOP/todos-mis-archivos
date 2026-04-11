#include <iostream>
#include <vector>
#include <cmath>

// intefaces, clases que no se necesitan crear objetos (solo es una capa)
class Figura { // solo para crear modelos
// solo usa metodos virtuales puros, no tiene atributos
public:
    virtual double area() = 0;
    virtual double perimetro() = 0;
    virtual void describir() = 0;
    virtual ~Figura() = default;
};

class Circulo: public Figura {
protected:
    double radio;
    static double pi;
public:
    Circulo(double r): radio(r) {}
    
    double getRadio() const { return radio; }

    double area() {
        std::cout<<"Area del circulo: "<<pi*radio*radio<<std::endl;
        return pi*radio*radio;
    }
    double perimetro() {
        std::cout<<"Perimetro del circulo: "<<2*pi*radio<<std::endl;
        return 2*pi*radio;
    }
    void describir() {
        std::cout<<"Radio del circulo: "<<radio<<std::endl;
    }
}; 
double Circulo::pi = 3.1415;

class Rectangulo: public Figura {
protected:
    double base, altura;
public:
    Rectangulo(double b, double a): base(b), altura(a) {}

    double getBase() const { return base; }
    double getAltura() const { return altura; }

    double area() {
        std::cout<<"Area del rectangulo: "<<base*altura<<std::endl;
        return base*altura;
    }
    double perimetro() {
        std::cout<<"Perimetro del circulo: "<<2*(base+altura)<<std::endl;
        return 2*(base+altura);
    }
    void describir() {
        std::cout<<"Base: "<<base<<", altura: "<<altura<<std::endl;
    }
};

class Triangulo: public Figura {
protected:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3): lado1(l1), lado2(l2), lado3(l3) {}

    double area() {
        double s = (lado1+lado2+lado3)/2;
        std::cout<<"Area triangulo usando heron: "<< sqrt(s * (s-lado1) * (s-lado2) * (s-lado3))<<std::endl;
        return sqrt(s * (s-lado1) * (s-lado2) * (s-lado3));
    }
    double perimetro() {
        std::cout<<"Perimetro: "<<lado1+lado2+lado3<<std::endl;
        return lado1+lado2+lado3;
    }
    void describir() {
        std::cout<<"Lado1: "<<lado1<<", lado2: "<<lado2<<", lado3"<<lado3<<std::endl;
    }
};

int main() {
    std::vector<Figura*> figuras;

    figuras.push_back(new Circulo(5));
    figuras.push_back(new Rectangulo(4,6));
    figuras.push_back(new Triangulo(3,4,5));

    for(const auto& f: figuras) {
        f->describir();
        f->area();
        f->perimetro();
    }
    // debo hacerle getters a los atributos
    for(const auto& f: figuras) {
        Circulo* c = dynamic_cast<Circulo*>(f);
        if(c != nullptr) {
            std::cout<< c->getRadio()<<std::endl;
        }
        Rectangulo* r = dynamic_cast<Rectangulo*>(f);
        if(r != nullptr) {
            std::cout<<r->getBase()<<std::endl;
            std::cout<<r->getAltura()<<std::endl;
        }
    }

    for(const auto& f: figuras) {
        delete f;
    }
    figuras.clear();


    return 0;
}