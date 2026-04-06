#include <iostream>
#include <vector>
#include <string>
#include <memory>

/*
auto nombre = std::make_unique<Tipo>(valores);

auto es para no escribit std::unique_ptr<Tipo>, que es el tipo que retorna
std::unique_ptr<Tipo> es el tipo puntero inteligente

este puntero se asigna solo a un objeto a la vez, no hay copia, toca std::move

Operaciones:
Puede usar la sintaxis de puntero con ptr-> 
o usar la sintaxis con punto metodo dewsreferenciando.  (*ptr).

obtener el puntero crudo
    .get()
    Tipo* crudo = ptr.get(), eso devuelve el puntero crudo


por que ptr usa . ?? sus metodos propios usan . (.get, .reset, .release)
operaciones del puntero interno usan -> como se usan normalmente

repasar el uso del .get para saber como usar
*/
enum class TipoAnimal {
    perro, 
    gato,
    leon
};
class Animal {
protected:
    std::string nombre;
    int edad;
    double peso;
public:
    Animal(const std::string& n, int e, double p): nombre(n), edad(e), peso(p) {}
    // metodo virtual necesita destructor default
    virtual ~Animal() = default;

    virtual std::string sonido() = 0;
    virtual std::string especie() = 0;

    virtual void info() {
        std::cout<<"Nombre: "<<nombre<<", edad: "<<edad<<", peso: "<<peso<< std::endl;
    }
};

class Perro: public Animal {
protected:
    std::string raza;
public:
    Perro(const std::string& n, int e, double p, const std::string& r): 
        Animal(n,e,p), raza(r) {}
    // solo se crea el constructor de clase base
    std::string sonido() override {
        return "Guau";
    }
    std::string especie() override {
        return "Perro";
    }

    void info() override {
        Animal::info();
        std::cout<<"Raza: "<<raza<<std::endl;
    }
};

class Gato: public Animal {
protected:
    bool callejero;
public:
    Gato(const std::string& n, int e, double p): Animal(n,e,p), callejero(false) {}

    std::string sonido() override {
        return "Miau";
    }
    std::string especie() override {
        return "Gato";
    }

    bool esCallejero() {
        callejero = true;
        return callejero;
    }

    void info() override {
        Animal::info();
        if(callejero) {
            std::cout<<"Gato es callejero"<<std::endl;
        }
        else{
            std::cout<<"Gato no es callejero"<<std::endl;
        }
    }
};
class Leon: public Animal {
protected:
    bool melena;
public:
    Leon(const std::string& n, int e, double p): Animal(n,e,p), melena(false) {}

    std::string sonido() override {
        return "Roar";
    }
    std::string especie() override {
        return "Leon";
    }

    bool tieneMelena() {
        melena = true;
        return melena;
    }

    void info() override {
        Animal::info();

        if(melena) {
            std::cout<<"Leon con melena"<<std::endl;
        }
        else {
            std::cout<<"Leon sin melena"<<std::endl;
        }
    }
};

class Zoo {
protected:
    std::vector<std::unique_ptr<Animal>> animales;
    std::string nombreZoo;
public:     
    Zoo(const std::string& nz): nombreZoo(nz) {}

    // usar el enum class para el if de agregar, pasar el tipo y saber que hacer
    Zoo& agregar(TipoAnimal tipo, const std::string& n, int e, double p, const std::string& extra="") {
        // el extra es para el perro, tengo que llamar el tipo porque no hereda
        if (tipo == TipoAnimal::perro) { 
            animales.push_back(std::make_unique<Perro>(n,e,p));
        } else if (tipo == TipoAnimal::gato) {
            animales.push_back(std::make_unique<Gato>(n,e,p));
        } else if (tipo == TipoAnimal::leon) {
            animales.push_back(std::make_unique<Leon>(n,e,p));
        }
        return *this;
    }




};



int main() {
    // como Animal es abstracta no deja inicializar
    // Animal a1("Nicolas", 23, 88);



    return 0;
}