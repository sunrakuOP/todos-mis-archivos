#include <iostream>
#include <vector>
#include <algorithm>

class Frase {
protected:
    std::vector<std::string> palabras;
public:
    Frase() = default;

    Frase& cargar(const std::vector<std::string>& vectCargar) {
        palabras = vectCargar;
        return *this;
    }

    Frase& ordenar() {
        // sort ordena alfabeticamente por default
        std::sort(palabras.begin(), palabras.end());
        return *this;
    }

    int cuantasVeces(const std::string& buscar) {
        int cuenta = std::count(palabras.begin(), palabras.end(), buscar);
        return cuenta;
    }

    // usar mucho find, recordar que tambien es de algorthm
    bool existe(const std::string& buscar){
        auto it = std::find(palabras.begin(), palabras.end(), buscar);
        if(it == palabras.end()){
            std::cout<<"Palabra no esta dentro del vector.."<<std::endl;
            return false;
        }
        std::cout<<"Palabra encontrada.."<<std::endl;
        return true;
    }

    void mostrar() const {
        if(palabras.empty()){
            std::cout<<"Vector vacio.."<<std::endl;
            return;
        }
        std::cout<<"Vector: "<<std::endl;
        for(const auto& p: palabras){
            std::cout<<p<<", ";
        }     
        std::cout<<std::endl;
    }
};

int main() {
    Frase f;

    f.cargar({"manzana", "pera", "uva", "manzana", "kiwi", "pera", "manzana"});
    f.mostrar();

    f.ordenar();
    f.mostrar(); // alfabético

    std::cout << f.cuantasVeces("manzana") << std::endl; // 3
    std::cout << f.cuantasVeces("kiwi") << std::endl;    // 1

    f.existe("pera");    // encontrada
    f.existe("sandia");  // no encontrada

    return 0;
}
