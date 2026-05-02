#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class ContLista {
protected:
    std::vector<std::string> lista;
public:
    ContLista() = default;

    ContLista& agregar(const std::string& texto) {
        lista.push_back(texto);
        return *this;
    }
    // insertar usando posiciones (std::advance)
    ContLista& agregarEn(int pos, const std::string& text) {
        if((int)lista.size() < pos) {
            std::cout<<"Posicion invalida.. "<<std::endl;
            return *this;
        }
        auto it = lista.begin();
        std::advance(it, pos); //vector permite auto it = l.begin()+pos;
        lista.insert(it, text);
        return *this;
    }
    // buscar por referencia e insertarlo ahi
    ContLista& agregarAntesDe(const std::string& ref, const std::string& text) {
        // repaso del std::find
        // std::find(v.begin(), v.end(), busqueda)
        // si esta retorna iterador a esa posicion, si no retorna v.end()
        auto it = std::find(lista.begin(), lista.end(), ref);
        if(it != lista.end()) {
            // insertar texto en esa posicion
            lista.insert(it, text);
        }
        return *this;
    }

    void mostrar() const {
        if(lista.empty()){
            std::cout<<"Lista vacia, nada que retornar"<<std::endl;
            return;
        }
        std::cout<<"Lista: "<<std::endl;
        for(const auto& l: lista) {
            std::cout<<l<<std::endl;
        }
    }
};

int main() {
    ContLista cl;

    cl.agregar("A").agregar("B").agregar("D").agregar("E");
    cl.mostrar(); // A B D E

    cl.agregarEn(2, "C"); // inserta C en posición 2
    cl.mostrar(); // A B C D E

    cl.agregarAntesDe("D", "nuevo");
    cl.mostrar(); // A B C nuevo D E

    cl.agregarEn(99, "X"); // posición inválida

    return 0;
}
