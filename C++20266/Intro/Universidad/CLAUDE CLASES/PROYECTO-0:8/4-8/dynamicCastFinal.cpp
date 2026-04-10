#include <iostream>
#include <vector>

enum class Tipo {
    automovil,
    moto, 
    camion
};

class Vehiculo {
protected:
    std::string marca;
    int anio;
public:
    Vehiculo(const std::string& ma, int an): marca(std::move(ma)), anio(an) {}
    virtual ~Vehiculo() = default; // destructor virtual

    const std::string& getMarca() const { return marca; }
    int getAnio() const { return anio; }


    virtual double calcularImpuesto() = 0;
    virtual std::string tipo() = 0;
    virtual void info() {
        std::cout<<"Marca: "<<marca<<", anio: "<<anio<<std::endl;
    }
};

class Auto: public Vehiculo {
protected:
    int numPasajeros;
public:
    Auto(const std::string& ma, int an, int np): Vehiculo(ma,an), numPasajeros(np) {}

    double calcularImpuesto() override {
        return (Vehiculo::getAnio() < 2025 ? 200 : 500);
    }

    std::string tipo() override {
        return "Auto";
    }

    void info() override {
        Vehiculo::info();
        std::cout<<"Tipo: auto, con numero pasajeros: "<<numPasajeros<<std::endl;
    }
};

class Moto: public Vehiculo {
protected:
    int cilindrada;
public:
    Moto(const std::string& ma, int an, int c): Vehiculo(ma, an), cilindrada(c) {}

    double calcularImpuesto() override {
        return (cilindrada >600 ? 300 : 100);
    }
    std::string tipo() override {
        return "Moto";
    }

    void info() override {
        Vehiculo::info();
        std::cout<<"Tipo: moto, cilindraje: "<<cilindrada<<std::endl;
    }
};

class Camion: public Vehiculo {
protected:
    double capacidadToneladas;
public:
    Camion(const std::string& ma, int an, double ct): 
        Vehiculo(ma, an), capacidadToneladas(ct) {}
    
    double calcularImpuesto() override {
        return capacidadToneladas*150;
    }
    std::string tipo() override {
        return "Camion";
    }
    void info() override {
        Vehiculo::info();
        std::cout<<"Tipo camion, capac toneladas: "<<capacidadToneladas<<std::endl;
    }
};

class Concesionario {
protected:
    std::string nombreConc;
    std::vector<std::unique_ptr<Vehiculo>> vehiculos;
public:
    Concesionario(const std::string& nc): nombreConc(std::move(nc)) {}

    Concesionario& agregarVehiculo(Tipo t, const std::string& n, int a, double extra) {
        if(t == Tipo::automovil) {
            vehiculos.push_back(std::make_unique<Auto>(n, a, (int)extra));
            return *this;
        } else if(t == Tipo::moto) {
            vehiculos.push_back(std::make_unique<Moto>(n,a,(int)extra));
            return *this;
        } else if(t == Tipo::camion) {
            vehiculos.push_back(std::make_unique<Camion>(n,a,extra));
            return *this;
        }
        std::cout<<"Fallo al agregar.."<<std::endl;
        return *this;
    }
    double impuestoTotal() {
        if(vehiculos.empty()) {
            std::cout<<"Concesionario vacio.."<<std::endl;
            return 0;
        }
        double sumaTotal = 0;
        for(const auto&v: vehiculos) {
            sumaTotal += v->calcularImpuesto();
            // calcula el impuesto con virtual, sin dynamic cast
        }
        std::cout<<"Impuesto total: "<<sumaTotal<<std::endl;
        return sumaTotal;
    }
    void mostrarTodos() const {
        if(vehiculos.empty()) {
            std::cout<<"Vector vacio.."<<std::endl;
            return;
        }
        for(const auto& v: vehiculos) {
            v->info();
        }
    }

    void inspeccionar(size_t i) {
        // Dejar el vector base
        Vehiculo* ptr = vehiculos.at(i).get();
        if(Auto* a = dynamic_cast<Auto*>(ptr)) {
            a->info();
        } else if(Moto* m = dynamic_cast<Moto*>(ptr)) {
            m->info();
        } else if(Camion* c = dynamic_cast<Camion*>(ptr)) {
            c->info();
        }
    }

};


int main() {
    Concesionario c("AutoMax");

    c.agregarVehiculo(Tipo::automovil, "Toyota", 2010, 5)
     .agregarVehiculo(Tipo::moto, "Honda", 2020, 800)
     .agregarVehiculo(Tipo::camion, "Volvo", 2018, 12.5);

    c.mostrarTodos();
    c.impuestoTotal();

    c.inspeccionar(0); // Auto
    c.inspeccionar(1); // Moto
    c.inspeccionar(2); // Camion

    return 0;
}
