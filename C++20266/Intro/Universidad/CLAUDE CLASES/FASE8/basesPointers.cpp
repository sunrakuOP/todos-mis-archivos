/*
con new creo el objeto en el heap, se reserva un bloque en la memoria ram
yo mismo debo liberar la memoria con delete porque sino memory leak

otro problema, usar el objeto despues de liberar memoria (informacion erronea)
*/  
#include <iostream>
#include <vector>

class Libro {
protected:
    std::string titulo, autor;
public:
    Libro(const std::string& t, const std::string& au): titulo(t), autor(au) {}

    void info() const {
        std::cout<<"Titulo: "<<titulo <<", autor: "<<autor<<std::endl;
    }
};

class Bibiblioteca {
protected:
    std::vector<Libro*> bibiblioteca;
public:
    Bibiblioteca() {}
    // hacer el destructor de el vector
    ~Bibiblioteca() {
        for(const auto& l: bibiblioteca) {
            delete l;
        }
        bibiblioteca.clear();
    }

    Bibiblioteca& agregarNuevo(const std::string& titulo, const std::string& autor) {
        // crear el libro internamente 
        Libro* libroAgr = new Libro(titulo, autor);
        bibiblioteca.push_back(libroAgr);
        return *this;
    }

    Bibiblioteca& agregarCreado(const Libro& obj) {
        for(const auto& l: bibiblioteca) {
            if(l == &obj) {
                std::cout<<"Libro ya en biblioteca"<<std::endl;
                return *this;
            }
        }
        // debo copiar el obj en el heap
        bibiblioteca.push_back(new Libro(obj)); // copiar al heap
        return *this;
    }

    void mostrarTodo() const {
        std::cout<<"Libros en bibblioteca: "<<std::endl;
        for(const auto& l: bibiblioteca) {
            l->info();
        }
    }
};

int main() {
    Bibiblioteca bib;

    // agregar con new interno
    bib.agregarNuevo("1984", "Orwell")
       .agregarNuevo("Don Quijote", "Cervantes")
       .agregarNuevo("El Principito", "Saint-Exupery");

    bib.mostrarTodo();

    // agregar libro ya creado (copia al heap)
    Libro externo("Cien años de soledad", "Garcia Marquez");
    bib.agregarCreado(externo);
    bib.agregarCreado(externo); // duplicado, debe detectarlo

    std::cout<<"\nDespues de agregar externo:"<<std::endl;
    bib.mostrarTodo();

    // al salir del scope el destructor libera todo
    return 0;
}