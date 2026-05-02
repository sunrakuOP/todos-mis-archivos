#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

/*
Siempre que trabajo con clases debo usar lambdas para saber a que comparar
*/

struct Jugador {
    std::string nombre;
    int puntos;

    Jugador(const std::string& n, int p): nombre(std::move(n)), puntos(p) {}
};
class Equipo { // equipo no hereda de jugador, solo lo compone
protected:
    std::string nombreEquipo;
    std::vector<Jugador*> jugadores;
public:
    Equipo(const std::string& ne): nombreEquipo(std::move(ne)) {}

    ~Equipo() {
        for(const auto& j: jugadores){
            delete j;
        }
        jugadores.clear();
    }
    // solo crear jugadores desde el equipo
    Equipo& agregarJugador(const std::string& n, int p) {
        auto it = std::find(jugadores.begin(), jugadores.end(), n);
        if(it != jugadores.end()){
            std::cout<<"Jugador ya agregado.."<<std::endl;
            return *this;
        }
        jugadores.push_back(new Jugador(n,p));
        return *this;
    }
    // retornar el puntaje maximo
    Jugador* maxPuntaje(){
        if(jugadores.empty()){
            std::cout<<"No hay jugadores por mostrar"<<std::endl;
            return nullptr;
        }
        auto it = std::max_element(jugadores.begin(), jugadores.end(), 
        [](const Jugador* a, const Jugador* b){return a->puntos < b->puntos;});
        return *it;
    }

    double promedioPuntos() {
        if(jugadores.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return 0.0;
        }
        int sumaPuntos = 0;
        for(const auto& j: jugadores){
            sumaPuntos += j->puntos;
        }
        return sumaPuntos /(int)jugadores.size();
    }

    void ordenarPorPuntos() {
        if(jugadores.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return;
        }
        std::sort(jugadores.begin(), jugadores.end(), 
        [](const Jugador* a, const Jugador* b){return a->puntos < b->puntos;});
    }

    // siempre se usa el remove_if junto al erase (recordar los pasos)
    Equipo& eliminarSinPuntos() {
        // recordar que si se altera el vector mientras re recorre (ITERADORES)
        for(auto it = jugadores.begin(); it != jugadores.end(); ) {
            if((*it)->puntos == 0){
                // si elimino el puntero lo debo reasignar al siguiente valido
                delete *it; // porque es en el heap
                it = jugadores.erase(it);
                return *this;
            }
            // si no elimina avanza ++it, si lo elimina avanza solo
            ++it;
        } 
        return *this;
    }
    
    void mostrar() const {
        if(jugadores.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return;
        }
        for(const auto& j: jugadores) {
            std::cout<<"Jugador: "<<j->nombre<<", puntaje: "<<j->puntos<<std::endl;
        }
    }
    
};


int main() {

    return 0;
}