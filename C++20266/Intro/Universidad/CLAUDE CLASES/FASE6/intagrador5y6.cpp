#include <iostream>
#include <vector>

class Figura {
protected:
    std::string nombre, color;
public:
    Figura(const std::string& no, const std::string& co): nombre(no), color(co) {}
    virtual ~Figura() = default;

    virtual double area() = 0;
    virtual double perimetro() = 0;
    virtual void describir() = 0;
    virtual void dibujar() = 0;
};

class Poligono: public Figura {
protected:
    int numLados;
public:
    Poligono(const std::string& no, const std::string& co, int nl): Figura(no, co), numLados(nl) {}

    int getNumLados() const { return numLados; }
    std::string getNombre() const { return nombre; }
};
class Rectangulo: public Poligono {
protected:
    double ancho, alto;
public:
    Rectangulo(const std::string& no, const std::string& co, double an, double al):
        Poligono(no,co,4), ancho(an), alto(al) {}
    
    double area() override {
        std::cout<<"Area de rect: "<<alto*ancho<<std::endl;
        return alto*ancho;
    }
    double perimetro() override {
        std::cout<<"Perimetro rect: "<<2*(alto+ancho)<<std::endl;
        return 2*(alto+ancho);
    }
    void describir() override {
        std::cout<<"Alto: "<<alto<<", ancho: "<<ancho<<std::endl;
    }
    void dibujar() override {
        for(int i=0; i < ancho; ++i) {
            for(int j=0; j < alto; ++j) {
                std::cout<<"*";
            }
            std::cout<<"\n";
        }
    }

};
class Triangulo: public Poligono{
protected:
    double base, altura, lado1, lado2, lado3;
public:
    Triangulo(const std::string& no, const std::string& co, double b, double a,
        double l1, double l2, double l3):
        Poligono(no, co, 3), base(b), altura(a), lado1(l1), lado2(l2), lado3(l3) {}

    double area() override {
        std::cout<<"Area triang: "<<(base*altura)/2<<std::endl;
        return (base*altura)/2;
    }
    double perimetro() override {
        std::cout<<"Perimetro: "<<lado1+lado2+lado3<<std::endl;
        return lado1+lado2+lado3;
    }
    void describir() override {
        std::cout<<"Base: "<<base<<", altura: "<<altura<<", lado1: "
        <<lado1<<", lado2: "<<lado2<<", lado3: "<<lado3<<std::endl;     
    }
    void dibujar() override {
        for (int i = 1; i <= base; ++i) {
            for (int j = 0; j < i; ++j) {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }
};
class Cuadrado final: public Rectangulo { // ya nadie puede heredar de cuadrado
public:
    Cuadrado(const std::string& no, const std::string& co, double l):
        Rectangulo(no, co, l, l) {}

    void describir() override {
        std::cout<<"Lado: "<<ancho<<std::endl;
    }
};


class Curva: public Figura {
public:
    Curva(const std::string& no, const std::string& co): Figura(no, co) {}
};

class Circulo: public Curva {
protected:
    double radio;
    static double pi;
public:
    Circulo(const std::string& no, const std::string& co, double r): Curva(no, co), radio(r) {}

    double area() override {
        std::cout<<"Area del circulo: "<<pi*radio*radio<<std::endl;
        return pi*radio*radio;
    }
    double perimetro() override {
        std::cout<<"Perimetro circ: "<<2*pi*radio<<std::endl;
        return 2*pi*radio;
    }
    void describir() override {
        std::cout<<"Radio: "<<radio<<std::endl;
    }
    void dibujar() override {
        std::cout<<"O"<<std::endl; 
    }

};

double Circulo::pi = 3.141516;

int main() {
    std::vector<Figura*> figuras;

    figuras.push_back(new Rectangulo("Rectangulo", "azul", 5, 4));
    figuras.push_back(new Triangulo("Triangulo", "rojo", 3, 4, 3, 4, 5));
    figuras.push_back(new Cuadrado("Cuadrado", "verde", 3));
    figuras.push_back(new Circulo("Circulo", "amarillo", 5));
    
    double suma = 0;
    for(const auto& f: figuras) {
        f->describir();
        f->dibujar();
        suma += f->area();
        f->perimetro();
        std::cout << "\n";

        Poligono* pol = dynamic_cast<Poligono*>(f);
        if(pol != nullptr) {
            std::cout<<pol->getNombre()<<" es un poligono."<<std::endl;
            std::cout<<"Numero de lados: "<<pol->getNumLados()<<std::endl;
        }
    }
    std::cout<<"Suma total de areas: "<<suma<<std::endl;

    for(const auto& f: figuras) {
        delete f;
    }

    return 0;
}
