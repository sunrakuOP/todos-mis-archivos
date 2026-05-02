/*
Proyecto D: Sistema de sensores IoT (medio-difícil)
Practica: herencia, polimorfismo, STL completo, lambdas, algoritmos
Un sistema que monitorea sensores de un invernadero robótico:
Jerarquía:
      Sensor (abstracta)
     /      |       \
  SensorTemp  SensorHumedad  SensorLuz
Sensor (abstracta):

Atributos: id (int), ubicacion (string), activo (bool)
leer() virtual puro → retorna double (simular con rand en un rango realista)
tipo() virtual puro → retorna string
Almacena últimas 10 lecturas en un vector<double> interno

Cada derivada simula rangos diferentes (temp: 15-40°C, humedad: 30-90%, luz: 0-1000 lux)
EstacionMonitoreo:

vector<Sensor*> con todos los sensores
leerTodos() — lee todos los sensores y guarda la lectura
promedioGlobal() — promedio de la última lectura de todos
alertas() — usando std::any_of con lambda, detectar valores fuera de rango
filtrarPorTipo(string) — usando std::copy_if con lambda, retornar solo los de un tipo
sensorConMayorLectura() — usando std::max_element con lambda
estadisticas() — para cada sensor: promedio, mínimo, máximo de sus últimas 10 lecturas (usando std::accumulate, std::min_element, std::max_element)

Menú: leer sensores, ver alertas, ver estadísticas, filtrar por tipo, activar/desactivar sensor
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

enum class Tipo{
    temperatura,
    humedad,
    luz
};

class Sensor {
protected:
    std::string id;
    std::string ubicacion;
    
    bool activo;
public:
    // clase abstracta 
    Sensor(const std::string& i, const std::string& ubi): 
        id(std::move(i)), ubicacion(std::move(ubi)), activo(false) {}
    
    virtual ~Sensor() = default;

    bool activarSensor() {
        activo = true;
        return activo;
    }
    bool apagarSensor() {
        activo = false;
        return activo;
    }

    const std::string& getID() const { return id; }
    const std::string& getUbicacion() const { return ubicacion; }

    virtual double leer() = 0; // depende del tipo de sensor da un valor distinto
    virtual std::string tipo() = 0;
};

class SensorTemp: public Sensor {
public:
    SensorTemp(const std::string& i, const std::string& ubi): Sensor(i,ubi) {}

    double leer() override {
        int min = 15, max = 40;
        double valor = min + (std::rand() % (max - min + 1));
        return valor;
    }

    std::string tipo() override{
        return "Sensor Temperatura";
    }
};

class SensorHumedad: public Sensor {
public: 
    SensorHumedad(const std::string& i, const std::string& ubi): Sensor(i, ubi) {}

    double leer() override {
        int min = 30, max = 90;
        double valor = min + (std::rand() % (max - min + 1));
        return valor;
    }
    std::string tipo() override {
        return "Sensor Humedad";
    }
};

class SensorLuz: public Sensor {
public:
    SensorLuz(const std::string& i, const std::string& ubi): Sensor(i, ubi) {}

     double leer() override {
        int min = 0, max = 1000;
        double valor = min + (std::rand() % (max - min + 1));
        return valor;
    }
    std::string tipo() override {
        return "Sensor Luz";
    }

};


class EstacionMonitoreo {
protected:
    std::vector<Sensor*> sensores;
    std::map<std::string, std::vector<double>> lecturas;
public:
    EstacionMonitoreo() = default;

    ~EstacionMonitoreo() {
        for(const auto& s: sensores){
            delete s;
        }
        sensores.clear();
    }

    EstacionMonitoreo& agregarSensor(Tipo tipo, const std::string& i, const std::string& ubi) {
        for(const auto& s: sensores){
            if(s->getID() == i){
                std::cout<<"Sensor ya agregado"<<std::endl;
                return *this;
            }
        }
        switch (tipo)
        {
        case Tipo::temperatura: {
            sensores.push_back(new SensorTemp(i,ubi));
            break;
        }
        case Tipo::humedad: {   
            sensores.push_back(new SensorHumedad(i,ubi));
            break;
        }
        case Tipo::luz: {
            sensores.push_back(new SensorLuz(i,ubi));
            break;
        }
        default:
            std::cout<<"No hay sensores de ese tipo"<<std::endl;
            break;
        }
        return *this;
    }

    void leerTodos() {
        if(sensores.empty()){
            std::cout<<"Vector de sensores vacio"<<std::endl;
            return;
        }
        for(const auto& s: sensores) {
            double lectura = s->leer();
            std::cout<<"Sensor: "<<s->getID()<<" = "<<lectura<<std::endl;
            lecturas[s->getID()].push_back(lectura);
        }
    }

    void promGlobal() {
        if(lecturas.empty()){
            std::cout<<"No hay lecturas..."<<std::endl;
            return;
        }
        for(auto it = lecturas.begin(); it != lecturas.end(); ++it) {
            double suma = 0;
            for(const auto& l: it->second){
                suma += l;
            }
            std::cout<<"Sensor: "<<it->first<<", prom lecturas: "<<suma/(double)it->second.size()<<std::endl;
        }
    }

    void alertas() {
        if(lecturas.empty()){
            std::cout<<"No hay lecturas..."<<std::endl;
            return;
        }
        for(const auto&[id, valores]: lecturas){
            auto it = std::find_if(sensores.begin(), sensores.end(),
                [&id](const Sensor* s){return id == s->getID(); });
        std::string tipoSensor = (*it)->tipo();
        if(tipoSensor == "Sensor Temperatura"){
            for(const auto& l: valores){
                if(l > 35 || l < 18){
                    std::cout<<"Lectura atipica en: "<<l<<std::endl;
                }
            }
        } else if(tipoSensor == "Sensor Humedad") {
            for(const auto& l: valores){
                if(l > 80 || l < 40) {
                    std::cout<<"Lecutura atipica en: "<<l<<std::endl;
                }
            } 
        } else if(tipoSensor == "Sensor Luz"){ 
            for(const auto& l: valores){
                if(l > 800 || l < 50){
                    std::cout<<"Valor atipico en: "<<l<<std::endl;
                    }
                }
            }
        }
    }

    std::vector<Sensor*> filtrarPorTipo(const std::string& tipo){   
        std::vector<Sensor*> sensoresDeTipo;
        if(sensores.empty()){
            std::cout<<"Vector vacio..."<<std::endl;
            return sensoresDeTipo;
        }
        for(const auto& s: sensores){
            if(s->tipo() == tipo) {
                sensoresDeTipo.push_back(s);
            }
        }
        for(const auto& s: sensoresDeTipo){
            std::cout<<s->getID()<<std::endl;
        }
        return sensoresDeTipo;
    }

    void sensorConMayorLectura() {
    for(const std::string& t: {"Sensor Temperatura", "Sensor Humedad", "Sensor Luz"}) {
        auto filtrados = filtrarPorTipo(t);
        if(filtrados.empty()) continue;

        auto it = std::max_element(filtrados.begin(), filtrados.end(),
            [&](const Sensor* a, const Sensor* b){
                return lecturas[a->getID()].back() < lecturas[b->getID()].back();
            });

        std::cout << t << " mayor: " << (*it)->getID() 
                  << " = " << lecturas[(*it)->getID()].back() << "\n";
        }
    }


};


int main() {
    std::srand(std::time(nullptr));

    EstacionMonitoreo estacion;

    estacion.agregarSensor(Tipo::temperatura, "T1", "Zona A")
            .agregarSensor(Tipo::temperatura, "T2", "Zona B")
            .agregarSensor(Tipo::humedad,     "H1", "Zona A")
            .agregarSensor(Tipo::humedad,     "H2", "Zona C")
            .agregarSensor(Tipo::luz,         "L1", "Zona B")
            .agregarSensor(Tipo::luz,         "L2", "Zona C");

    // leer varias veces para acumular lecturas
    estacion.leerTodos();
    estacion.leerTodos();
    estacion.leerTodos();

    estacion.promGlobal();
    estacion.alertas();
    estacion.sensorConMayorLectura();

    auto temps = estacion.filtrarPorTipo("Sensor Temperatura");
    std::cout << "Sensores de temperatura: " << temps.size() << "\n";

    return 0;
}