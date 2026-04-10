#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Libro {
protected:
    std::string titulo;
    std::string autor;
public:
    Libro(const std::string& tit, const std::string& aut): titulo(tit), autor(aut) {}
    ~Libro () = default;

    // para devolver referencia entonces
    const std::string& getTitulo() const { return titulo; }
    const std::string& getAutor() const { return autor; }

    void mostrarInfo() const{
        std::cout<<"Titulo: "<<titulo<<", autor: "<<autor<<std::endl;
    }
};

class Biblioteca {
protected:  
    std::vector<std::unique_ptr<Libro>> libros; // punteros inteligentes
public:
    Biblioteca () = default;
    ~Biblioteca() = default; // porque no debe eliminar manual, compilador elimina

    Biblioteca& agregarLibroNuevo(const std::string& t, const std::string& au) {
        for(const auto& l: libros) {
            if(l->getTitulo() == t) {
                std::cout<<"Libro ya esta en biblioteca"<<std::endl;
                return *this;
            }
        }
        libros.push_back(std::make_unique<Libro>(t, au)); // agrego puntero a libro
        return *this;
    }

    Biblioteca& agregarLibroCreado(std::unique_ptr<Libro> libro) {
        for(const auto& l: libros) { 
            if(l->getTitulo() == libro->getTitulo()) {
                std::cout<<"Libro ya en biblioteca"<<std::endl;
                return *this;
            }
        }
        libros.push_back(std::move(libro));
        return *this;
    }

    void mostrarInfo() const {
        std::cout<<"Biblioteca: "<<std::endl;
        for(const auto& l: libros) {
            l->mostrarInfo();
        }
    }
};





int main() {

    return 0;
}