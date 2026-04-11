/*
puntero crudo vs unique_ptr
*/
#include <iostream>
#include <vector>
#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
public: 
    Vehiculo(const std::string& ma, const std::string& mo): marca(ma), modelo(mo) {
        
    }
    ~Vehiculo () = default;

    void mostrarInfo() const {
        std::cout<<"Marca: "<<marca<<", modelo: "<<modelo<<std::endl;
    }
};

// taller compone Vehiculos (tiene vehiculos)
class TallerCrudo {
protected:
    std::vector<Vehiculo*> vehiculos; // taller crudo de vehiculos
public:
    // no necesito hacer constructor
    ~TallerCrudo () {
        for(const auto& v: vehiculos) {
            delete v;
        }
        vehiculos.clear();
    }

    TallerCrudo& agregarVehiculoNuevo(const std::string& ma, const std::string& mo) {
        vehiculos.push_back(new Vehiculo(ma, mo));
        return *this;
    }
    /*
    TallerCrudo& agregarVehiculoCreado(Vehiculo* veh) {
        for(const auto& v: vehiculos) {
            if(v == veh) {
                std::cout<<"Vehiculo ya en el taller.."<<std::endl;
                return *this;
            }
        }
        vehiculos.push_back(veh);
        return *this;
    }
    */
    void mostrarVehiculos() const {
        std::cout<<"Mostrando vehiculos del taller: "<<std::endl;
        for(const auto& v: vehiculos) {
            v->mostrarInfo();
        }
    }

};


int main() {
    TallerCrudo taller;
    // crear directamente en el new
    Vehiculo* v1 = new Vehiculo("Ford", "fiesta");
    Vehiculo* v2= new Vehiculo("Ferrari","roma");
    Vehiculo* v3 = new Vehiculo("Tesla","serie s");

    v1->mostrarInfo();
    v2->mostrarInfo();
    v3->mostrarInfo();

    // crear vehiculo nuevo y agregar
    taller.agregarVehiculoNuevo("Kia","picanto");
    taller.agregarVehiculoNuevo("Nissan","versa");
    taller.mostrarVehiculos();

    return 0;
}