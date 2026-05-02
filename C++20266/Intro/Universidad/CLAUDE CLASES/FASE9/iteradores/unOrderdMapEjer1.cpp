#include <iostream>
#include <unordered_map>

class Registro{
protected:
    std::unordered_map<std::string, int> puntajes;
public:
    Registro() = default;

    Registro& agregarJugador(const std::string& jugador, int puntaje) {
        // map tiene busqueda propia, .find no necesito std::find
        // . find busca por clave, recordar eso
        // usa el .first y .second
        auto it = puntajes.find(jugador);
        if(it != puntajes.end()){
            std::cout<<"Jugador ya agregado"<<std::endl;
            return *this;
        }    
        // tambien podria ser puntajes[jugador]=puntaje, pero sobreescribe, insert no
        puntajes.insert({jugador, puntaje});
        return *this;
    }
    Registro& sumarPuntos(const std::string& jugador, int puntos){
        auto it = puntajes.find(jugador);
        if(it == puntajes.end()){
            std::cout<<"Jugador no encontrado"<<std::endl;
            return *this;
        }
        // modificar el puntaje
        puntajes[jugador] += puntos; // it->second += puntos;
        return *this;
    }
    Registro& eliminarJugador(const std::string& jugador){
        auto it = puntajes.find(jugador);
        if(it == puntajes.end()){
            std::cout<<"Jugador no encontrado"<<std::endl;
            return *this;
        }
        puntajes.erase(it);
        return *this;
    }

    bool existe(const std::string& jugador){
        auto it = puntajes.find(jugador);
        if(it == puntajes.end()){
            return false;
        }
        return true;
    }
    void mostrarMayoresA(int puntuacion){
        if(puntajes.empty()){
            std::cout<<"Mapa vacio"<<std::endl;
            return;
        }
        for(const auto&[nombre, puntos]: puntajes){
            if(puntuacion < puntos) {
                std::cout<<"Jugador: "<<nombre<<", puntos: "<<puntos<<std::endl;
            }
        }
    }
    // mostrar con la sintaxis vieja
    void mostrar() const {  
        if(puntajes.empty()){
            std::cout<<"Mapa vacio"<<std::endl;
            return;
        }
        for(const auto& p: puntajes){
            std::cout<<p.first<<", "<<p.second<<std::endl;
        }
    }

};


int main() {
    Registro r;

    r.agregarJugador("Carlos", 100)
     .agregarJugador("Ana", 250)
     .agregarJugador("Luis", 180)
     .agregarJugador("Maria", 320);

    r.mostrar();

    r.sumarPuntos("Carlos", 50);
    r.sumarPuntos("Pedro", 10); // no existe

    std::cout << r.existe("Ana") << std::endl;    // 1
    std::cout << r.existe("Pedro") << std::endl;  // 0

    r.mostrarMayoresA(200); // Ana(250), Maria(320)

    r.eliminarJugador("Luis");
    r.mostrar();

    return 0;
}
