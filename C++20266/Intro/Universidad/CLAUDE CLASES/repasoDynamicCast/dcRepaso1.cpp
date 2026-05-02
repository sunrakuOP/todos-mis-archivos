#include <iostream>
#include <vector>
#include <string>

class Animal{
    // clase abstracta pura
protected:
    std::string nombre;
public:
    Animal(const std::string& no): nombre(std::move(no)) {}
    ~Animal() = default;

    virtual void hacerSonido() = 0;
};

class Perro: public Animal { 
protected:
    std::string raza;
public:
    Perro(const std::string& no, const std::string& ra): Animal(no), raza(std::move(ra)) {}

    void hacerSonido() override {
        std::cout<<"Guauu"<<std::endl;
    }
    // metodo propio
    void traer() const {
        std::cout<<nombre<<" trajo la pelota"<<std::endl;
    }
};
class Gato: public Animal {
public:
    Gato(const std::string& no): Animal(no) {}

    void hacerSonido() override {
        std::cout<<"Miauu"<<std::endl;
    }
};
class Pajaro: public Animal {
public:
    Pajaro(const std::string& no): Animal(no) {}

    void hacerSonido() override {
        std::cout<<"Piooo"<<std::endl;
    }
};


int main() {
    // hacerlo ahora pero usando uniqueptr
    std::vector<std::unique_ptr<Animal>> animales;

    animales.push_back(std::make_unique<Perro>("Mariscal","pastor"));
    animales.push_back(std::make_unique<Gato>("Titi"));
    animales.push_back(std::make_unique<Pajaro>("Piolin"));

    // recorrer el vector y buscar metodo propio de perro
    for(const auto& a: animales){
        a->hacerSonido(); // hace el sonido propio usando virtual
        // mirar si es perro para hacerle metodo traer

        // el dynamic cast necesita el puntero crudo . get lo entrega
        Perro* ptr = dynamic_cast<Perro*>(a.get());
        if(ptr != nullptr){
            ptr->traer();
        }
    }
    // no le hago el delete manual y ya

    /*
    std::vector<Animal*> animales;
    // guardo perro en puntero de animal (derivado en base)
    animales.push_back(new Perro("Mariscal", "pastor aleman"));
    animales.push_back(new Gato("Titi"));
    animales.push_back(new Pajaro("Piolin"));

    // recorrer el vector y mostrar el polimorifismo usando virtual
    for(const auto& a: animales){
        a->hacerSonido();

        // tratar de encontrar ptr a la derivada
        Perro* ptrp = dynamic_cast<Perro*>(a);
        if(ptrp != nullptr){
            ptrp->traer();
        }
    }
    // hacerle el delete manual
    for(const auto& a: animales){
        delete a;
    }
    animales.clear();
    */


    return 0;
}