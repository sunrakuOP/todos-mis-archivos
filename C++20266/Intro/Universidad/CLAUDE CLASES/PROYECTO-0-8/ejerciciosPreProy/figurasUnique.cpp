#include <iostream>
#include <vector>

class Figura {
protected:
    std::string nombre, color;
public:
    Figura(const std::string& n, const std::string& c): nombre(std::move(n)), color(std::move(c)) {}
    virtual ~Figura() = default;

    virtual double area() = 0;
    virtual double perimetro() = 0;
    virtual void describir() = 0;
    virtual void dibujar() = 0;
    // hacerle polimorfismo a cada cosa
};

class Poligono: public Figura {
protected:
    int numLados;
public:
    Poligono(const std::string& n, const std::string& c, int nl):
        Figura(n,c), numLados(nl) {}
    // solo el destructor de la base virtual

    const std::string& getNombre() const {return nombre; }
    int getLados() const { return numLados; }  
};

class Rectangulo: public Poligono {
protected:
    double ancho, alto;
public:
    Rectangulo(const std::string& n, const std::string& c, int an, int al):
        Poligono(n,c,4), ancho(an), alto(al) {}
    
    double area() override {
        std::cout<<"Area rectangulo: "<<alto*ancho<<std::endl;
        return ancho*alto;
    }

    double perimetro() override {
        std::cout<<"Perimetro rectangulo: "<<2*(alto+ancho)<<std::endl;
        return 2*(ancho+alto);
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

int main() {
    // ahora si va lo diferente, hacerle el vector usando unique_ptr
    std::vector<std::unique_ptr<Figura>> figuras;

    figuras.push_back(std::make_unique<Rectangulo> ("Rectangulo", "azul", 5, 4));
    figuras.push_back(std::make_unique<Triangulo>("Triangulo", "rojo", 3, 4, 3, 4, 5));
    figuras.push_back(std::make_unique<Circulo>("Circulo", "amarillo", 5));
    figuras.push_back(std::make_unique<Cuadrado>("Cuadrado", "verde", 3));

    // hacerle el dynamic cast para hacer el uso del polimorfismo


    return 0;
}