#include <iostream>
#include <map>

/*
class Caja {
protected:
    std::vector<std::string> palabras;
    std::map<std::string, int> diccionario;
    static int count;
protected:
    Caja() = default;
    ~Caja() = default;

    Caja& agregarPalabra(const std::string& palabra) {
        palabras.push_back(palabra);
        for(const auto& p: palabras) {
            if(p == palabra) {
                ++count;
            }
        }
        diccionario.insert({palabra, count});
        return *this;
    } 
};
int Caja::count = 0;
*/
class Contador {
protected:      
    std::map<std::string, int> diccionario;
public:
    Contador() = default;
    ~Contador() = default;

/*
    Contador& agregar(const std::string& palabra) {
        diccionario[palabra]++; //se accede por clavew
        return *this;
    }
    int contar(const std::string& palabra) {
        for(const auto& d: diccionario) {
            if(d == palabra) {
                
            }
        }
    }
*/ 
// no existe, crea una y agrega valor 1
    Contador& agregarPalabra(const std::string& palabra) {
        // siempre se deben crear junto clave y valor
        diccionario[palabra]++;
        return *this;
    }


};

int main() {
    std::map<std::string, int> mapa1;
    // agregar elemento (par de valores)
    mapa1["nicolas"] = 23;
    mapa1.insert({"isabella", 21});
    // acceder al elemento (por clave)
    // sintaxis: nombre[clave] = valor;    variable para acceder al valor nombre[clave]
    std::cout<<mapa1["isabella"]<<std::endl;
        //peligro del operador [] es que si no esta lo anexa
    
    // FORMA SEGURA DE BUSCAR con . find() (RETORNA ITERADOR)
    auto it = mapa1.find("isabella");
    if(it != mapa1.end()) {
        it->first;  // clave
        it->second; // valor
    }





    return 0;
}