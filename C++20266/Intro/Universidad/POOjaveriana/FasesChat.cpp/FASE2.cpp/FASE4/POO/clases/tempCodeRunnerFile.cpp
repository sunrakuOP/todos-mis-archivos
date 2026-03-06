#include <iostream>
#include <string>

class Libro {
    // datos privados
    private: 
    std::string titulo, autor;
    int anioPublicacion;
    bool prestado = false;

    public:
    // metodos publicos
        // constructor, recibe los alias de los nombres de los datos para incializar
    Libro (std::string ttl, std::string aut, int ap, bool prs) {
        // primero variable luego alias
        titulo = ttl;
        autor = aut;
        anioPublicacion = ap;
        prestado = prs;
    }
    // setters
    void setTitulo(std::string ttl) {
        titulo = ttl;
    }
    void setAutor(std::string aut) {
        autor = aut;
    }
    void setAnioPub(int ap) {
        anioPublicacion = ap;
    }
    void prestado(bool prs) {
        prestado = prs;
    }
    // getters, devuelven la variable del private
    std::string getTitulo() {
        return titulo;
    }
    std::string getAutor() {
        return autor;
    }
    int getAnioPub() {
        return anioPublicacion;
    }
    bool getPrestado() {
    return prestado;
    }
    // metodos adicionales
    void prestar() {
        if (!prestado) {
            prestado = true;
            std::cout<<"Estado cambiado a prestado, disfrute el libro"<<std::endl;
        }
        else {
            std::cout<<"El libro esta prestado" <<std::endl;
        }
    }
    void devolver() {
        if (prestado) {
            prestado = false;
            std::cout<<"Gracias por devolver el libro"<<std::endl;
        }
        else {
            std::cout<<"El libro esta disponible" <<std::endl;
        }
    }
    // devolver informacion
    void info() {
        std::cout<<"Informacion del libro: "<<std::endl;
        std::cout<<"Titulo del libro: "<< titulo <<std::endl;
        std::cout<<"Autor del libro: "<< autor <<std::endl;
        std::cout<<"AP del libro: "<< anioPublicacion <<std::endl;
        std::cout<<"Estado del libro: "<< prestado <<std::endl;
    }

};

int main() {
    std::string t, a;
    int ap;
    std::cout << "Digite el titulo del libro: " << std::endl;
    std::getline(std::cin, t);
    std::cout << "Digite el autor del libro: " << std::endl;
    std::getline(std::cin, a);
    std::cout << "Digite el anio de publicacion del libro: " << std::endl;
    std::cin >> ap;
    std::cin.ignore(); // Limpiar buffer 

    // El libro siempre inicia como no prestado
    Libro libro1(t, a, ap, false);
    libro1.info();

    // Probar prestar el libro
    libro1.prestar();
    libro1.info();

    // Probar devolver el libro
    libro1.devolver();
    libro1.info();

    return 0;
}