#include <iostream>
#include <string>
#include <vector>

class Libro { // creamos una clase tipo libro (objetos libro)
    private:
    std::string titulo, autor;
    int anio;
    bool prestado;

    public:
    Libro(std::string t, std::string aut, int a) {
        titulo = t;
        autor = aut;
        anio = a;
    }
    ~Libro() {
    }
    // setters y getters
    Libro& setTiulo(std::string t) {
        titulo = t;
        return *this;
    }
    Libro& setAutor(std::string aut) {
        autor = aut;
        return *this;
    }
    Libro& setAnio(int a) {
        anio = a;
        return *this;
    }
    std::string getTitulo() {
        return titulo;
    }
    std::string getAutor() {
        return autor;
    }
    int getAnio() {
        return anio;
    }

    void mostrarDatos() {
        std::cout<<"Titulo: "<<titulo<<std::endl;
        std::cout<<"Autor: "<<autor<< std::endl;
        std::cout<<"Anio publicacion: "<<anio<< std::endl;
    }
};

class Biblioteca {
    private:
    std::vector<Libro> biblioteca; // vector almacena objetos tipo Libro 
    
    public:
    // no es necesario hacer un constructor, solo va a almacenar
    void agregarLibro(const auto& libro) {    // auto para que intuya el tipo de dato que pasamos
        biblioteca.push_back(libro);  // agregamos libro al vector
    }
    void mostrarTodos() {
        for(auto& libro: biblioteca) {
            libro.mostrarDatos();  // como libro es un objeto puede usar sus propios metodos
        }
    }
    bool buscarTitulo(std::string title) {
        for(auto& libro : biblioteca) {
            if (title == libro.getTitulo()) {    // comparar cadena con cadena, (libro es objeto, libro.getTitulo() devuelve string)
                std::cout<<"Libro encontrado"<<std::endl;
                return true;
            }
        }
        std::cout<<"Libro no encontrado"<<std::endl;
        return false; // sacarlo del for
    }
    
    // metodos estaticos. toca pasar el objeto como parametro para acceder a sus atributos
    static int totalLibros(const Biblioteca& b) {  // referenicia al objeto biblioteca
        return b.biblioteca.size();  // asi accedemos al vector
    }

};


int main() {
    Libro l1("El extranjero", "Albert Camus", 1900);
    Libro l2("El tunel", "Ernesto Sabato", 2000);
    Libro l3("1984", "George Orwell", 1900);
    Biblioteca estanteria;  // creo biblioteca donde guardar los libros

    l1.mostrarDatos();
    l2.mostrarDatos();
    l3.mostrarDatos();

    estanteria.agregarLibro(l1);
    estanteria.agregarLibro(l2);
    estanteria.agregarLibro(l3);

    estanteria.mostrarTodos();
    
    // llamar al metodo estatico
    int total = Biblioteca::totalLibros(estanteria);
    std::cout<<"Total de libros es: "<< total << std::endl;
    return 0;
}