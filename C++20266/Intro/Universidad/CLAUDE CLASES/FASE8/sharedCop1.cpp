#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Cancion {
protected:
    std::string titulo;
    std::string artista;
    int duracion;
public: 
    Cancion(const std::string& tit, const std::string& art, int d): 
        titulo(std::move(tit)), artista(std::move(art)), duracion(d) {}

    const std::string& getTitulo() const { return titulo; }
    const std::string& getArtista() const { return artista; }
    int getDuracion() const { return duracion; }


    void mostrarInfo() const {
        std::cout<<"Titulo: "<<titulo<<", artista: "
            <<artista<<", duracion: "<<duracion<<std::endl;
    }
};

class Playlist {
protected:
    std::string nombre;
    std::vector<std::shared_ptr<Cancion>> canciones; // posee varias canciones
public:
    Playlist () = default;
    // no necesito destructor
    
    // agregar una cancion como tal en shared
    Playlist& agregarCancion(const std::shared_ptr<Cancion>& cancion) {
        for(const auto& c: canciones) {
            if(c == cancion) {
                std::cout<<"Cancion ya agregada (misma direccion)"<<std::endl;
                return *this;
            }
            if(c->getTitulo() == cancion->getTitulo() &&c->getArtista() == cancion->getArtista()) {
                std::cout<<"Cancion igual ya agregada (diferentes objetos mismo contenido)"<<std::endl;
                return *this;
            }
        }
        canciones.push_back(cancion);
        return *this;
    }

    Playlist& eliminarCancion(const std::shared_ptr<Cancion>& cancion) { 
        // iterar con punteros
        for(auto it = canciones.begin(); it != canciones.end(); ++it) {
            if(*it == cancion) {
                canciones.erase(it);
                return *this;
            }
        }
        std::cout << "Cancion no encontrada" << std::endl;
        return *this;
    }

    void mostrarCanciones() const {
        std::cout<<"Playlist: "<<nombre<<std::endl;
        for(const auto& c: canciones) {
            if(canciones.empty()) {
                std::cout<<"Playlist vacia..."<<std::endl;
                return;
            }
            c->mostrarInfo();
        }
    }
    // mostrar cuantos obj apuntan a mismo objeto
    void mostrarCuenta(const std::shared_ptr<Cancion>& cancion) {
        std::cout<<"Cuenta: "<<cancion.use_count() <<std::endl;

    } 


};



int main() {
    auto cancion1 = std::make_shared<Cancion>("Imagine", "John Lennon", 183);
    auto cancion2 = std::make_shared<Cancion>("One", "U2", 276);
    auto cancion3 = std::make_shared<Cancion>("Hallelujah", "Leonard Cohen", 240);

    Playlist rock;
    Playlist chill;

    std::cout << "use_count cancion1 al crearla: " << cancion1.use_count() << std::endl;

    rock.agregarCancion(cancion1);
    std::cout << "use_count cancion1 despues de agregarla a rock: " << cancion1.use_count() << std::endl;

    chill.agregarCancion(cancion1);
    std::cout << "use_count cancion1 despues de agregarla a chill: " << cancion1.use_count() << std::endl;

    rock.agregarCancion(cancion2);
    chill.agregarCancion(cancion3);

    rock.eliminarCancion(cancion1);
    std::cout << "use_count cancion1 despues de quitarla de rock: " << cancion1.use_count() << std::endl;

    chill.eliminarCancion(cancion1);
    std::cout << "use_count cancion1 despues de quitarla de chill: " << cancion1.use_count() << std::endl;

    return 0;
}