#include <iostream>
#include <list>
#include <algorithm>

class Playlist{
protected:
    std::list<std::string> canciones;
public:
    Playlist() = default;

    Playlist& agregarCancion(const std::string& cancion) {
        auto it = std::find(canciones.begin(), canciones.end(), cancion);
        if(it != canciones.end()){
            std::cout<<"Cancion ya agregada..."<<std::endl;
            return *this;
        }
        canciones.push_back(cancion);
        return *this;
    }
    Playlist& eliminarPorNombre(const std::string& cancion){
        auto it = std::find(canciones.begin(), canciones.end(), cancion);
        if(it == canciones.end()){
            std::cout<<"Cancion no encontrada"<<std::endl;
            return *this;
        }
        canciones.erase(it);
        return *this;
    }
    Playlist& moverAposicion(int posicion, const std::string& cancion){
        auto it = std::find(canciones.begin(), canciones.end(), cancion);
        if(it == canciones.end()){
            std::cout<<"Cancion no encontrada"<<std::endl;
            return *this;
        }
        if((int)canciones.size() < posicion) {
            std::cout<<"Posicion invalida"<<std::endl;
            return *this;
        }
        // debo eliminar la cancion primero, luego insertarla en la posicion necesaria
        canciones.erase(it);

        // luego con advance moverla con respecto al inicio (.begin())
        auto destino = canciones.begin();
        std::advance(destino, posicion);
        canciones.insert(destino, cancion);
        return *this;
    }
    Playlist& reemplazarViejo(const std::string& cancion, const std::string& nueva){
        auto it = std::find(canciones.begin(), canciones.end(), cancion);
        if(it == canciones.end()) {
            std::cout<<"Cancion no encontrada"<<std::endl;
            return *this;
        }
        // no debo eliminar sino desreferenciando el iterador
        // para conservar la misma posicion
        *it = nueva;
        return *this;
    }

    void mostrar() const {
        if(canciones.empty()){
            std::cout<<"Playlist vacia..."<<std::endl;
            return;
        }
        std::cout<<"Playlist: "<<std::endl;
        for(const auto& c: canciones){
            std::cout<<c<<", ";
        }
        std::cout<<std::endl;
    }
};

int main() {
    Playlist p;

    p.agregarCancion("Bohemian Rhapsody")
     .agregarCancion("Stairway to Heaven")
     .agregarCancion("Hotel California")
     .agregarCancion("Smells Like Teen Spirit");

    p.mostrar();

    p.moverAposicion(0, "Hotel California"); // mover al inicio
    p.mostrar();

    p.reemplazarViejo("Stairway to Heaven", "Back in Black");
    p.mostrar();

    p.eliminarPorNombre("Smells Like Teen Spirit");
    p.mostrar();

    p.moverAposicion(99, "Back in Black"); // posición inválida

    return 0;
}

