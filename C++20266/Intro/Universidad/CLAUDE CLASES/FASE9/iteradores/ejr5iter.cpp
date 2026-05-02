#include <iostream>
#include <vector>
#include <algorithm>

class Datos{
protected:
    std::vector<int> datos;
public:
    Datos() = default;

    // reemplazar vector con otro
    Datos& cargar(const std::vector<int>& vector) {
        datos = vector;
        return *this;
    }
    Datos& moverAlFrente(int valor) {
        auto it = std::find(datos.begin(), datos.end(), valor);
        if(it == datos.end()) {
            std::cout<<"Dato no encontrado.."<<std::endl;
            return *this;
        }
        datos.erase(it); // elimino el dato de su posicion
        datos.insert(datos.begin(), valor); // lo inserto al inicio
        return *this;
    }
    
    int contarMayores(int valor) {
        if(datos.empty()){
            std::cout<<"Vector vacio, nada que contar"<<std::endl;
            return 0;
        }
        int contador = 0;
        for(auto it = datos.begin(); it != datos.end(); ++it){
            if(*it > valor) {
                contador++;
            }
        }
        return contador;
    } 

    void mostrar() const {
        if(datos.empty()){
            std::cout<<"Vector vacio.."<<std::endl;
            return;
        }
        std::cout<<"Datos: "<<std::endl;
        for(const auto& d: datos) {
            std::cout<<d<<" ";
        }
        std::cout<<std::endl;
    }
};

int main() {
    Datos d;

    d.cargar({5, 3, 8, 1, 9, 2, 7});
    d.mostrar(); // 5 3 8 1 9 2 7

    d.moverAlFrente(9);
    d.mostrar(); // 9 5 3 8 1 2 7

    d.moverAlFrente(99); // no existe

    std::cout << "Mayores a 5: " << d.contarMayores(5) << std::endl; // 3 (7,8,9)

    return 0;
}
