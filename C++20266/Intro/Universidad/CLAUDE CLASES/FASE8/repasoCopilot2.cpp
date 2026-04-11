#include <iostream>
#include <vector>
#include <string>

class Libro {
protected:
    std::string titulo;
    std::string autor;
public:
    Libro(const std::string& tit, const std::string& aut): titulo(tit), autor(aut) {}
    ~Libro () = default;

    // para devolver referencia entonces
    const std::string& getTitulo() { return titulo; }
    const std::string& getAutor() { return autor; }

    void mostrarInfo() const{
        std::cout<<"Titulo: "<<titulo<<", autor: "<<autor<<std::endl;
    }
};
class Biblioteca {
protected:
    std::vector<Libro*> libros; // puede o no puede tener 
public:
    Biblioteca() = default;
    ~Biblioteca () {
        // responsabilidad de ownership exclusiva del vector
        for(const auto* l: libros){
            delete l; // elimina cada elemento del vector
        }
        libros.clear(); // limpia el vector
    }

    Biblioteca& agregarLibro(const std::string& tit, const std::string& aut) {
        for(const auto& l: libros) {
            if(l->getTitulo() == tit) {
                std::cout<<"Libro ya esta en biblioteca.."<<std::endl;
                return *this;
            }
        }
        libros.push_back(new Libro(tit, aut));
        return *this;
    }

    void mostrarLibros() const {
        if(libros.empty()) {
            std::cout<<"Biblioteca vacia.."<<std::endl;
            return;
        }
        std::cout<<"Biblioteca: "<<std::endl;
        for(const auto* l: libros) {
            l->mostrarInfo();
        }
    }
};


int main() {
    // los libros se crean desde el vector para no compartir responsabilidad
    Biblioteca biblioteca;
    biblioteca.agregarLibro("1984","George Orwell");
    biblioteca.agregarLibro("El extranjero","Albert Camus");
    biblioteca.agregarLibro("La metamorfosis","Frank Kafka");
    
    biblioteca.mostrarLibros();

    return 0;
}