// puntero con dueno unico
#include <iostream>
#include <vector>

// envuelve al puntero crudo y hace el delete el mismo (cuando sale del scope)
// no necesito hacerle destructor
// facilita demasiado la vida

class Libro {
protected:
    std::string titulo, autor;
public:
    Libro(const std::string& t, const std::string& a): titulo(t), autor(a) {}

    void mostrarInfo() const {
        std::cout<<"Titulo: "<<titulo<<", autor: "<<autor<<std::endl;
    }
};

class BibibliotecaVieja {
protected:
    std::vector<Libro*> bibblioteca1;
public:
    BibibliotecaVieja() {}
    // debo hacerle destructor porque es punteros crudos
    ~BibibliotecaVieja() {
        for(const auto& l: bibblioteca1){
            delete l;
        }
        bibblioteca1.clear();
    }

    BibibliotecaVieja& agrearNew(const std::string& titulo, const std::string& autor) {
        // llama al constructor de libro
        Libro* nuevo = new Libro(titulo, autor);
        bibblioteca1.push_back(nuevo);
        return *this;
    }

    void mostrarTodos() const {
        for(const auto& l: bibblioteca1) {
            l->mostrarInfo();
        }
    }
};

class BibliotecaNew {
protected:  
    std::vector<std::unique_ptr<Libro>> bibiblioteca2; // crea un vector de ptrs
public:
    // no debo crear constructor, ningun atr nuevo

    // tampoco debo hacerle destructor, cuando vector termina se destruyen

    BibliotecaNew& agregarPtr(const std::string& titulo, const std::string& autor) {
        // creo el objeto usando uniqueptr
        auto nuevo = std::make_unique<Libro>(titulo, autor);
        // lo meto al vector
        bibiblioteca2.push_back(std::move(nuevo));
        // uniqueptr solo es para un puntero a la vez, no puede copiar
        return *this;
    }
    
};


int main() {
    // crear un libro en el stack
    Libro libro1("La metamorfosis","Frank Kafka");

    // crear objeto usando puntero crudo
    Libro* libro2 = new Libro("1984", "George Orwell"); //debo eliminarlo al final

    // crear objeto usando unique ptr
    auto libro3 = std::make_unique<Libro>("Kamasutra","Anonimo");
    // libro 3 esta en el heap, pero maneja su memoria el solo


    delete libro2; 
    
    return 0;
}