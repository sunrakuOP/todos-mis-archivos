#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

/*
Ejercicio 2: Agenda con unordered_map
Usando std::unordered_map<std::string, std::vector<std::string>> (nombre → lista de teléfonos):

Menú con: agregar contacto, agregar teléfono a contacto existente, buscar por nombre, eliminar contacto, listar todos
Un contacto puede tener varios teléfonos
Buscar con find(), nunca con operator[] para búsqueda
*/

class Agenda {
protected:
    std::string nombreAgenda;
    std::unordered_map<std::string, std::vector<std::string>> agenda;
public:
    Agenda(const std::string& na): nombreAgenda(std::move(na)) {}
    
    Agenda& agregarContacto(const std::string& nombre){
        auto it = agenda.find(nombre);
        if(it != agenda.end()){
            std::cout<<"Contacto ya agregado"<<std::endl;
            return *this;
        }
        agenda[nombre];
        return *this;
    }
    
    Agenda& agregarTelefono(const std::string& nombre, const std::string& telefono) {
        auto it = agenda.find(nombre);
        if(it == agenda.end()){
            std::cout<<"Contacto no esta en agenda, agregandolo..."<<std::endl;
            agenda[nombre].push_back(telefono);
            return *this;
        }
        agenda[nombre].push_back(telefono);
        return *this;
    }

    void buscarPorNombre(const std::string& nombre){
        auto it = agenda.find(nombre);
        if(it == agenda.end()){
            std::cout<<"Contacto no encontrado"<<std::endl;
            return;
        }
        std::cout<<"Contacto encontrado: "<<it->first<<std::endl;
        if(it->second.empty()){
            std::cout<<"Lista de contactos vacia"<<std::endl;
            return;
        }
        for(const auto& c: it->second){
            std::cout<<c<<", ";
        }
        std::cout<<std::endl;
    }

    Agenda& eliminarContacto(const std::string& nombre){
        // hacer el for manual
        if(agenda.empty()){
            std::cout<<"Agenda vacia"<<std::endl;
            return *this;
        }
        for(auto it = agenda.begin(); it != agenda.end(); ) {
            if(it->first == nombre){
                // reasignar el iterador al siguiente elemento
                it = agenda.erase(it);
                return *this;
            }
            it++;
        }
        return *this;
    }

    void mostrarAgenda() const {
        if(agenda.empty()){
            std::cout<<"Agenda vacia"<<std::endl;
            return;
        }
        std::cout<<"Mostrando todos los contactos: "<<std::endl;
        for(const auto&[nombre, lista]: agenda){
            std::cout<<"Nombre: "<<nombre<<std::endl;
            for(const auto& l: lista){
                std::cout<<l<<", ";
            }
            std::cout<<std::endl;
        }

    }

    void ejecutar() {
        int opcion;
        do {
            std::cout<<"========MENU=========="<<std::endl;
            std::cout<<"0. Salir"<<std::endl;
            std::cout<<"1. Agregar Contacto"<<std::endl;
            std::cout<<"2. Agregar Telefono"<<std::endl;
            std::cout<<"3. Buscar por nombre"<<std::endl;
            std::cout<<"4. Eliminar Contacto"<<std::endl;
            std::cout<<"5. Mostrar Agenda"<<std::endl;
            std::cout<<"Digite una opcion: "<<std::endl;
            std::cin>>opcion;

            switch (opcion)
            {
            case 0:
                std::cout<<"Saliendo..."<<std::endl;
                break;
            case 1: {
                std::string nombre;
                std::cout<<"Digite nombre: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, nombre);
                agregarContacto(nombre);
                break;
            }
            case 2: {
                std::string nombre, telefono;
                std::cout<<"Digite nombre a buscar: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout<<"Digite telefono a agregar: "<<std::endl;
                std::cin>>telefono;
                agregarTelefono(nombre, telefono);
                break;
            }
            case 3: {   
                std::string nombre;
                std::cout<<"Digite nombre a buscar: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, nombre);
                buscarPorNombre(nombre);
                break;
            }
            case 4: {
                std::string nombre;
                std::cout<<"Digite nombre de contacto a eliminar: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, nombre);
                eliminarContacto(nombre);
                break;
            }
            case 5: 
                mostrarAgenda();
                break;
                
            default:
                std::cout<<"Opcion invalida.."<<std::endl;
                break;
            }

        } while(opcion != 0);
     
    } 
};



int main() {
    Agenda agenda1("Contactos");
    
    agenda1.ejecutar();

    return 0;
}