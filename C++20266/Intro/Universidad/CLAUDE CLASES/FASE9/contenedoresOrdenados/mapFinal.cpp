#include <iostream>
#include <map>
#include <vector>


class Eleccion {
protected:  
    std::map<std::string, int> votos;
public:
    Eleccion() = default;

    Eleccion& votar(const std::string& candidato) {
        votos[candidato]++; // si no existe lo crea
        return *this;
    }

    void ganador() const {
        if(votos.empty()) {
            std::cout<<"Mapa vacio, ni votos ni candidatos"<<std::endl;
            return;
        }
        int mayor = 0;
        std::string ganador;
        for(const auto&[nombre, numero]: votos) {
            if(numero > mayor){
                mayor = numero;
                ganador = nombre;
            }
        }
        std::cout<<"Ganador: "<<ganador<<" con "<<mayor<<" votos"<<std::endl;
    }

    Eleccion& eliminar(std::string candidato) {
        auto it = votos.find(candidato);
        if(it == votos.end()) {
            std::cout<<"Candidato no encontrado"<<std::endl;
            return *this;
        }
        votos.erase(it); // simplemente lo elimino asi y sale 
        return *this;
    }

    void ordenarPorVotos() const {
        std::vector<std::pair<std::string, int>> vectorPares;
        for(const auto&[nombre, numero]: votos) {
            vectorPares.push_back({nombre, numero});
        }
        
    }
};
// como ordena map? por orden alfabetico, 
/*
map guarda, pair<clave, valor>
it->first usa la clave, it->second usa el valor

// como copiar un mapa en otro???
*/

// std::vector<std::pair<std::string, int>> vectorPares;  
// v.push_back({"uno",1}); se agrega usando pushbak normal pero en pares

/*
como ordenar usando sort?
std::sort
*/




int main() {

    return 0;
}