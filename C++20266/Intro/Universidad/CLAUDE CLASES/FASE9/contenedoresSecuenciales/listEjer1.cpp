#include<iostream>
#include <list>

class ListaCanciones {
protected:
    std::string nombreLista;
    std::list<std::string> lista;
public:
    ListaCanciones(const std::string& nombre): nombreLista(std::move(nombre)) {}

    ListaCanciones& agregar(const std::string& nombre) {
        // lista puede agregar al inicio o al final
        if(lista.empty()) {
            lista.push_back(nombre);
            return *this;
        }
        for(const auto& l: lista) {
            if(l == nombre) { 
                std::cout<<"Cancion ya agregada"<<std::endl;
                return *this;
            }
        }
        lista.push_back(nombre);
        return *this;
    }

    ListaCanciones& agregarInicio(const std::string& nombre) {
        if(lista.empty()) {
            lista.push_back(nombre);
            return *this;
        }
        for(const auto& l: lista) {
            if(l == nombre) { 
                std::cout<<"Cancion ya agregada"<<std::endl;
                return *this;
            }
        }
        lista.push_front(nombre);
        return *this;
    }
    // eliminar por "indice" o numero de cancion
    ListaCanciones& eliminarPorNumero(int n) {
        if(lista.empty()) {
            std::cout<<"Lista vacia.."<<std::endl;
            return *this;
        }
        auto it = lista.begin();   // apunta al primer elemento
        if(n <=(int)lista.size()) {
            std::advance(it, n-1);
            lista.remove(*it);
            return *this;
        }
        std::cout<<"Numero de cancion mayor a tamano de lista"<<std::endl;
        return *this;
    }

    ListaCanciones& eliminarPorNombre(const std::string& nombre) {
        if(lista.empty()) {
            std::cout<<"Lista vacia, nada que eliminar"<<std::endl;
            return *this;
        }
        lista.remove(nombre);  // remove ya busca internamente
        return *this;
    }

    ListaCanciones& invertir() {
        if(lista.empty()) {
            std::cout<<"Lista vacia, nada que invertir"<<std::endl;
            return *this;
        }
        lista.reverse();
        return *this;
    }

    void mostrarPlaylist() {
        if(lista.empty()) {
            std::cout<<"Playlist vacia"<<std::endl;
            return;
        }
        std::cout<<"Playlist: "<<std::endl;
        for(const auto& l: lista) {
            std::cout<<l<<std::endl;
        }
    } 

    ListaCanciones& moverFrente(const std::string& nombre) {
        for(auto it = lista.begin(); it != lista.end(); ++it) {
            if(*it == nombre) {
                lista.splice(lista.begin(), lista, it);
                return *this;
            }
        }
        std::cout<<"Cancion no encontrada.."<<std::endl;
        return *this;
    }
};

int main() {

    return 0;
}