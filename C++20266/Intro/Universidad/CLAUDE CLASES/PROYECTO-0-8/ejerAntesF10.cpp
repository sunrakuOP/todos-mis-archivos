/*

Ejercicio: Fábrica de Componentes
Clases:

Componente: atributos nombre (string) y numSerie (int)
Ensamblaje: tiene vector<unique_ptr<Componente>> — es dueño de los componentes antes de ensamblar
Robot: tiene vector<unique_ptr<Componente>> — recibe los componentes ensamblados
Inspector: tiene vector<Componente*> — solo observa, no es dueño

En main():

Crear 4 componentes en Ensamblaje con make_unique
Inspector revisa los componentes (guarda punteros crudos con .get())
Transferir componentes de Ensamblaje a Robot con std::move
Verificar que Ensamblaje quedó vacío después de la transferencia
Imprimir qué componentes tiene el Robot
Imprimir qué componentes está revisando el Inspector

Restricciones: cero new/delete, solo make_unique y std::move.

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Componente {
protected:
    std::string nombre;
    int numSerie;
public:
    Componente(const std::string& n, int ns): nombre(std::move(n)), numSerie(ns) {}
};
class Ensamblaje{
protected:
    std::vector<std::unique_ptr<Componente>> componentes;
    // ensamblaje es dueno de los componentes, el decide cuando se destruye
public:
    Ensamblaje() = default;


    Ensamblaje& agregar(const std::string& n, int ns){
        componentes.push_back(std::make_unique<Componente>(n, ns));
        return *this;
    }
    // metodo transferir, que devuelva el vector
    std::vector<std::unique_ptr<Componente>> transferir() {
        return std::move(componentes);
    }
    
    const std::vector<std::unique_ptr<Componente>>& getComponentes() const {
        return componentes;
    }


};
// unique ptr no se puede copiar, solo mover
// recibe por referencia con movimiento

class Robot {
protected:
    std::string nombreRobot;
    std::vector<std::unique_ptr<Componente>> componentes;

public:
    Robot(const std::string& nr): nombreRobot(std::move(nr)) {}

    Robot& cargar(std::vector<std::unique_ptr<Componente>>&& vectCargar) {
        // unique no puede copiar, debe mover, con referencia por movimiento
        componentes = std::move(vectCargar); // transfiere ownership
        return *this;
    }   
};
// inspector, solo observa, no es el dueno
class Inspector {
protected:
    std::string nombreInsp;
    std::vector<Componente*> componentes;
public:
    Inspector(const std::string& ni): nombreInsp(std::move(ni)) {}

    Inspector& pasarComponentes(const std::vector<std::unique_ptr<Componente>>& vectorCargar) {
        for(const auto& c: vectorCargar){
            componentes.push_back(c.get());
            // .get() devuelve el puntero crudo
        }
        return *this;
    }   
};



int main(){
    Ensamblaje ensamblaje;
    ensamblaje.agregar("Motor", 1)
              .agregar("Rueda", 2)
              .agregar("Sensor", 3)
              .agregar("Bateria", 4);

    Inspector inspector("Juan");
    // inspector revisa ANTES de transferir (porque despues ensamblaje queda vacio)
    inspector.pasarComponentes( vector del ensamblaje );

    Robot robot("R2D2");
    robot.cargar(ensamblaje.transferir());

    // verificar que ensamblaje quedo vacio
    // mostrar componentes del robot
    // mostrar componentes del inspector

    return 0;
}
*/