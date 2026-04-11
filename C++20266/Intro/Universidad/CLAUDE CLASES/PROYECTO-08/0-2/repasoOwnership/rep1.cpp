#include <iostream>
#include <vector>
#include <string>

class Libro {
protected:
    std::string titulo;
    std::string autor;
public:
    Libro(const std::string& tit, const std::string& aut): 
        titulo(std::move(tit)), autor(std::move(aut)) {}

    const std::string& getTitulo() const { return titulo; }
    const std::string& getAutor() const { return autor; }
    
    void infoLibro() const {
        std::cout<<"Titulo: "<<titulo<<", autor: "<<autor<<std::endl;
    }
    // como no crea el objeto no debe hacer delete
};

class Biblioteca {
protected:
    std::vector<Libro*> libros; // puede o no tener libros
public: 
    Biblioteca() = default;
    // como posee libros el debe destruir el objeto
    ~Biblioteca() {
        for(const auto& l: libros) {
            delete l;
        }
        libros.clear(); // elimino elementos y vacio el vector (nullprtr)
    }

    Biblioteca& agregarLibro(const std::string& tit, const std::string& aut) {
        for(const auto& l: libros) {
            if(l->getTitulo() == tit && l->getAutor() == aut) {
                std::cout<<"Libro ya en biblioteca"<<std::endl;
                return *this;
            }
        }
        libros.push_back(new Libro(tit, aut));
        return *this;
    }

    Biblioteca& agregarCreado(Libro* libro) {
        libros.push_back(libro);
        return *this;

    }

    // retorna el puntero al elemento buscado
    Libro* buscarLibro(const std::string& tit) {
        for(const auto& l: libros) {
            if(l->getTitulo() == tit) {
                std::cout<<"Libro encontrado.."<<std::endl;
                l->infoLibro();
                return l;
            }
        }
        std::cout<<"Libro no encontrado"<<std::endl;
        return nullptr;
    }

    void infoBiblio() const {
        if(libros.empty()) {
            std::cout<<"Biblioteca vacia.."<<std::endl;
            return;
        }
        std::cout<<"Biblioteca: "<<std::endl;
        for(const auto& l: libros) {
            l->infoLibro();
        }
    }
};




int main() {

    return 0;
}