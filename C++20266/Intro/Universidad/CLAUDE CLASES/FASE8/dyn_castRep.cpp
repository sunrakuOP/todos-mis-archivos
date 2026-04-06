#include <iostream>
#include <vector>

enum class TipoFigura {
    Circulo,
    Rectangulo, 
    Triangulo
};

class Figura { // abstracta
protected:  
    std::string color;
public:
    Figura(const std::string& col):color(col) {}
    virtual ~Figura() = default;

    virtual double area() = 0;
    virtual std::string tipo() = 0;

    virtual void info() {
        std::cout<<"Color de figura: "<<color<<std::endl;
    }
};
// si no implemento todos los metodos de la interfaz en la derivada, no la puedo instanciar tampoco
// clase derivada seguiria siendo abstracta, no podria crear 


class Circulo: public Figura {
protected:
    double radio;
    static double pi;
public:
    Circulo(const std::string& col, double r): Figura(col), radio(r) {}

    double area() override {
        return pi*radio*radio;
    }
    std::string tipo() override {
        return "Circulo";
    }
    void info() override {
        Figura::info();
        std::cout<<"Tipo: "<<Circulo::tipo()<<", radio: "<<radio
            <<", area: "<<Circulo::area()<<std::endl;
    }
};
double Circulo::pi = 3.141516;

class Rectangulo: public Figura {
protected:
    double base, altura;
public:
    Rectangulo(const std::string& col, double b, double al):Figura(col), base(b), altura(al) {}

    double area() override {
        return base*altura;
    }
    std::string tipo() override {
        return "Rectangulo";
    }
    void info() override {
        Figura::info();
        std::cout<<"Tipo: "<<Rectangulo::tipo()<<", base: "<<base
            <<", altura: "<< altura<<", area: "<<Rectangulo::area()<<std::endl;
    }
};

class Triangulo: public Figura {
protected:
    double base, altura;
public:
    Triangulo(const std::string& col, double b, double al): Figura(col), base(b), altura(al) {}

    double area() override {
        return (base*altura)/2;
    }
    std::string tipo() override {
        return "Triangulo";
    }
    void info() override {
        Figura::info();
        std::cout<<"Tipo: "<<Triangulo::tipo()<<", base: "<<base
            <<", altura: "<< altura<<", area: "<<Triangulo::area()<<std::endl;
    }
};


int main() {

    return 0;
}