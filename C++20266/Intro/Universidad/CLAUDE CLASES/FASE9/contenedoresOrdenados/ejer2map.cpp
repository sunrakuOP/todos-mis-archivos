#include <iostream>
#include <map>
#include <string>


class Persona {
protected:
    std::map<std::string, int> edades;
public:
    Persona() = default;

    Persona& agregarPersona(const std::string& n, int e) {
        edades.insert({n,e});
        return *this;
    }

    void mostrarMayores() const {
        std::cout<<"Imprimiendo mayores a 25"<<std::endl;
        for(const auto&[nombre, edad]: edades) {
            if(edad > 25) {
                std::cout<<nombre<<", ";
            }
        }
        std::cout<<std::endl;
    }

    void mostrarTodo() const {
        std::cout<<"Imprimiendo todos forma antigua"<<std::endl;
        for(const auto& par: edades) {
            std::cout<< par.first <<", "<<par.second<<". ";
        }
        std::cout<<std::endl;
    }

};

class Dado{
protected:
    std::string nombreDado;
    std::map<std::string, int> ocurrencias;
public: 
    Dado(const std::string& nd): nombreDado(std::move(nd)) {}

    Dado& agregarCadena(const std::string& elemento) {
        // []++ no agrega nueva entrada, modifica el anterior
        ocurrencias[elemento]++; // lo agrega como 1 vez (int 1)
        return *this;
    } // ya si agrego un elemento igual aunmenta contador

    // para contar se hace con el .find()
    int contarOcurrencias(const std::string& palabra) {
        auto it = ocurrencias.find(palabra); // iterador al inicio
        if(it != ocurrencias.end()) {
            std::cout<<it->second; // muestra el valor
            return it->second;
        }
        return 0;
    }

    void mostrarOcurrencias() const {
        if(ocurrencias.empty()) {
            std::cout<<"Mapa vacio"<<std::endl;
            return;
        }
        for(const auto&[palabra, veces]: ocurrencias) {
            std::cout<<palabra<<", "<<veces<<" veces"<<std::endl;
        }
    }
};

// map siempre tiene una sola entrada por clave IMOPORTANTE !!!!
// la verificacion si ya existe lo maneja solo

class Agenda {
protected:
    std::string nombreAgenda;
    std::map<std::string, std::string> contactos;
public: 
    Agenda(const std::string& n): nombreAgenda(std::move(n)) {}

    Agenda& agregarContacto(const std::string& nombre, const std::string& numero) {
        if(contactos.count(nombre)){ // si ya existe, no sobre escribir
            std::cout<<"Contacto ya existente.."<<std::endl;
            return *this;
        }
        contactos.insert({nombre, numero});
        return *this;   
    }

    Agenda& modificarTelefono(const std::string& nombre, const std::string& nuevoNumero) {
        auto it = contactos.find(nombre); // apunta al elemento, o a end si no esta
        if(it == contactos.end()) {
            std::cout<<"Contacto no existente"<<std::endl;
            return *this;
        }
        // si existe, sobre escribir con operador [] = nuevo
        contactos[nombre] = nuevoNumero;
        return *this;
    }

    void buscarContacto(const std::string nombre) {
        if (contactos.count(nombre) == 0) { 
            std::cout<<"Contacto no existente.."<<std::endl;
            return;
        }
        auto it = contactos.find(nombre);
        if(it != contactos.end()) {
            std::cout<<"Telefeono: "<<it->second;
        }
    }
 

};




int main() {
    Persona p;

    p.agregarPersona("Nicolas", 23).agregarPersona("Isabella", 21)
        .agregarPersona("Carlos", 58).agregarPersona("Libia", 55);
    
    p.mostrarMayores();
    p.mostrarTodo();

    Dado d("frutas");
    d.agregarCadena("manzana")
    .agregarCadena("pera")
    .agregarCadena("manzana")
    .agregarCadena("manzana")
    .agregarCadena("pera");

    d.mostrarOcurrencias();
    // manzana: 3 veces
    // pera: 2 veces

    std::cout << d.contarOcurrencias("manzana"); // 3


    return 0;
}