#include <iostream>
#include <string>
#include <vector>

class Libro {
    private:
    std::string titulo, autor;
    int anio;
    bool prestado;

    public:
    Libro(std::string t, std::string aut, int a) {
        titulo = t;
        autor = aut;
        anio = a;
        prestado = false;
    }
    ~Libro() {}
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
    bool estaPrestado() {
        return prestado;
    }
    bool prestar() {
        if (prestado) {
            return false;
        } else {
            prestado = true;
            return true;
        }
    }
    bool devolver() {
        if (!prestado) {
            return false;
        } else {
            prestado = false;
            return true;
        }
    }
    void mostrarDatos() {
        std::cout << "Titulo: " << titulo << std::endl;
        std::cout << "Autor: " << autor << std::endl;
        std::cout << "Anio publicacion: " << anio << std::endl;
        std::cout << "Estado: " << (prestado ? "Prestado" : "Disponible") << std::endl;
    }
};

class Biblioteca {
    private:
    std::vector<Libro> biblioteca;
    
    public:
    void agregarLibro(const auto& libro) {
        biblioteca.push_back(libro);
    }
    void mostrarTodos() {
        for (auto& libro : biblioteca) {
            libro.mostrarDatos();
        }
    }
    bool buscarTitulo(std::string title) {
        for (auto& libro : biblioteca) {
            if (title == libro.getTitulo()) {
                std::cout << "Libro encontrado" << std::endl;
                return true;
            }
        }
        std::cout << "Libro no encontrado" << std::endl;
        return false;
    }
    // Métodos para préstamo y devolución
    void prestarLibro(const std::string& title) {
        for (auto& libro : biblioteca) {
            if (libro.getTitulo() == title) {
                if (libro.prestar()) {
                    std::cout << "Libro prestado exitosamente." << std::endl;
                } else {
                    std::cout << "El libro ya está prestado." << std::endl;
                }
                return;
            }
        }
        std::cout << "Libro no encontrado para préstamo." << std::endl;
    }
    void devolverLibro(const std::string& title) {
        for (auto& libro : biblioteca) {
            if (libro.getTitulo() == title) {
                if (libro.devolver()) {
                    std::cout << "Libro devuelto exitosamente." << std::endl;
                } else {
                    std::cout << "El libro no estaba prestado." << std::endl;
                }
                return;
            }
        }
        std::cout << "Libro no encontrado para devolución." << std::endl;
    }
    static int totalLibros(const Biblioteca& b) {
        return b.biblioteca.size();
    }
};


int main() {
    Libro l1("El extranjero", "Albert Camus", 1900);
    Libro l2("El tunel", "Ernesto Sabato", 2000);
    Libro l3("1984", "George Orwell", 1900);
    Biblioteca estanteria;

    estanteria.agregarLibro(l1);
    estanteria.agregarLibro(l2);
    estanteria.agregarLibro(l3);

    estanteria.mostrarTodos();

    // Prueba de préstamo y devolución
    estanteria.prestarLibro("El tunel");
    estanteria.prestarLibro("El tunel"); // Intentar prestar de nuevo
    estanteria.devolverLibro("El tunel");
    estanteria.devolverLibro("El tunel"); // Intentar devolver de nuevo
    estanteria.prestarLibro("Libro que no existe");
    estanteria.devolverLibro("Libro que no existe");

    // Mostrar estado actualizado
    estanteria.mostrarTodos();

    // Mostrar total de libros
    int total = Biblioteca::totalLibros(estanteria);
    std::cout << "Total de libros es: " << total << std::endl;
    return 0;
}