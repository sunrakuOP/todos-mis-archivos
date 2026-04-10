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

    double getRadio() const {return radio; }

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

    double getBase() const { return base; }
    double getAltura() const { return altura; }
    
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

    double getBase() const { return base; }
    double getAltura() const { return altura; }
    
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

// metodo libre, hacerle getters
void inspeccionar(Figura* F) {
    if(Circulo* ptrCirc = dynamic_cast<Circulo*>(F)) { // si no da nullptr
        std::cout<<"Circulo con radio: "<<ptrCirc->getRadio()<<std::endl;
    } else if (Rectangulo* ptrRect = dynamic_cast<Rectangulo*>(F)) {
        std::cout<<"Rectangulo con base: "<<ptrRect->getBase()
            <<" y altura: "<<ptrRect->getAltura()<<std::endl;
    } else if (Triangulo* ptrTriang = dynamic_cast<Triangulo*>(F)) {
        std::cout<<"Triangulo con base: "<<ptrTriang->getBase()
            <<" y altura: "<<ptrTriang->getAltura()<<std::endl;
    }
}

// repasar unique_ptr en vez de new que ya es viejo
class Galeria {
protected:
    std::vector<std::unique_ptr<Figura>> figuras;
public:
    // no le debo hacer constructor

    // figura ya creada
    Galeria& agregar(std::unique_ptr<Figura> f){ // agrego una ya creada
        figuras.push_back(std::move(f)); // solo puede apuntar a un objeto
        return *this;
    }

    // usar el truco con enum class
    Galeria& crear(TipoFigura t, const std::string& col, double a, double b=0) { // b por defecto
        if(t == TipoFigura::Circulo) {
            figuras.push_back(std::make_unique<Circulo>(col, a));
        } else if(t == TipoFigura::Rectangulo) {
            figuras.push_back(std::make_unique<Rectangulo>(col, a, b));
        } else if(t == TipoFigura::Triangulo) {
            figuras.push_back(std::make_unique<Triangulo>(col, a, b));
        }
        return *this;
    }

    void inspeccionar(size_t i) {
        if(i >= figuras.size()) {
            std::cout<<"Indice invalido"<<std::endl;
            return;
        }
        Figura* ptrFig = figuras.at(i).get(); // obtener el puntero crudo del elemento
        if(Circulo* c = dynamic_cast<Circulo*>(ptrFig)) { // si no da nullptr
            std::cout<<"Circulo con radio: "<<c->getRadio()<<std::endl;
        } else if(Rectangulo* r = dynamic_cast<Rectangulo*>(ptrFig)) {
            std::cout<<"Rectangulo con base: "<<r->getBase()
            <<" y altura: "<<r->getAltura()<<std::endl;
        } else if(Triangulo* t = dynamic_cast<Triangulo*>(ptrFig)) {
            std::cout<<"Triangulo con base: "<<t->getBase()
                <<" y altura: "<<t->getAltura()<<std::endl;
        }
    }
};


int main() {
        /// ejercicio 2: Galeria con unique_ptr
    Galeria g;

    // agregar con move
    g.agregar(std::make_unique<Circulo>("rojo", 5.0))
    .agregar(std::make_unique<Rectangulo>("azul", 4.0, 3.0));

    // agregar con enum
    g.crear(TipoFigura::Triangulo, "verde", 6.0, 4.0)
    .crear(TipoFigura::Circulo, "amarillo", 2.0);

    // inspeccionar con dynamic_cast + .get()
    g.inspeccionar(0);
    g.inspeccionar(1);
    g.inspeccionar(2);
    g.inspeccionar(3);

    return 0;
}