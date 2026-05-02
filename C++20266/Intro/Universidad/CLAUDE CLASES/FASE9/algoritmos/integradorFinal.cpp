#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
/*
class ListaNegra {
protected:  
    std::set<std::string> bloqueados;
public:
    ListaNegra() = default;

    ListaNegra& bloquear(const std::string& nombre){
        bloqueados.insert(nombre);
        // si ya esta dentro lo ignora, set solo acepta uno 
        return *this;
    }

    ListaNegra& desbloquear(const std::string& nombre){
        auto it = std::find(bloqueados.begin(), bloqueados.end(), nombre);
        if(it == bloqueados.end()){
            std::cout<<"Nombre no esta en la lista.."<<std::endl;
            return *this;
        }
        bloqueados.erase(it);
        return *this;
    }

    bool estaBloqueado(const std::string& nombre){
        auto it = std::find(bloqueados.begin(), bloqueados.end(), nombre);
        if(it == bloqueados.end()) {
            return false;
        }
        return true;
    }

    void mostrar() const {
        if(bloqueados.empty()){
            std::cout<<"Nada por mostrar"<<std::endl;
            return;
        }
        for(const auto& b: bloqueados){
            std::cout<<b<<std::endl;
        }
    }
    // set y map tienen su propio .find
    // .count() para saber si existe el elemento o no
};
*/

class Biblioteca {
protected:
    std::map<std::string, std::set<std::string>> coleccion;
public:
    Biblioteca() = default;

    Biblioteca& agregar(const std::string& autor, const std::string& libro) {
        auto it = coleccion.find(autor);
        if(it == coleccion.end()){
            std::cout<<"Agregando autor nuevo: "<<std::endl;
            coleccion[autor].insert(libro); // crea la clave autor e inserta el libro al set
            return *this;
        }
        auto itSet = it->second.find(libro);
        if(itSet != it->second.end()){
            std::cout<<"Libro ya agregado"<<std::endl;
            return *this;
        }
        it->second.insert(libro);
        return *this;
    }

    bool tieneLibro(const std::string& autor, const std::string& libro){
        auto it = coleccion.find(autor);
        if(it == coleccion.end()){
            std::cout<<"Autor inexsistente"<<std::endl;
            return false;
        }
        auto itSet = it->second.find(libro);
        if(itSet == it->second.end()){
            std::cout<<"Libro no esta en la coleccion"<<std::endl;
            return false;
        }
        std::cout<<"Libro existente"<<std::endl;
        return true;
    }

    int total() {
        if(coleccion.empty()){
            std::cout<<"Coleccion vacia"<<std::endl;
            return 0;
        }
        int sumatoria = 0;
        for(const auto&[autor, libros]: coleccion){
            sumatoria += libros.size();
        }
        return sumatoria;
    }

    Biblioteca& eliminarLibro(const std::string& autor, const std::string& libro){
        auto it = coleccion.find(autor);
        if(it == coleccion.end()){
            return *this;
        }
        auto itSet = it->second.find(libro);
        if(itSet == it->second.end()){
            std::cout<<"Libro no en coleccion"<<std::endl;
            return *this;
        }
        // importante saber como manejar esto de map y busqueda por clave y acceder al .first y .second
        coleccion[autor].erase(itSet);
        return *this; 
    }
};

int main() {
    Biblioteca b;

    b.agregar("Orwell", "1984")
     .agregar("Orwell", "Rebelion en la granja")
     .agregar("Marquez", "Cien años de soledad")
     .agregar("Marquez", "El amor en los tiempos del colera")
     .agregar("Orwell", "1984"); // duplicado


    std::cout << "Total: " << b.total() << std::endl;

    b.tieneLibro("Orwell", "1984");        // existe
    b.tieneLibro("Orwell", "Don Quijote"); // no existe

    b.eliminarLibro("Marquez", "1984");             // no existe
    b.eliminarLibro("Marquez", "Cien años de soledad");

    return 0;
}
