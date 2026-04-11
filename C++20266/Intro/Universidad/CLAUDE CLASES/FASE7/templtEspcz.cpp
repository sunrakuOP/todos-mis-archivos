#include <iostream>
#include <vector>
// hacerlo declarando y definiendo por separado

template <typename T>
class Caja {
protected:
    std::vector<T> valores;
public:
    void guardar(T valor);
    T obtener(int i);
    void mostrar();

};

template <typename T>
void Caja<T>::guardar(T valor) {
    valores.push_back(valor);
}

template <typename T>
T Caja<T>::obtener(int i) {
    if((int)valores.size() <= i) {
        std::cout<<"Indice fuera de rango"<<std::endl;
        return T{};
    }
    return valores.at(i);
}

template <typename T>
void Caja<T>::mostrar() {
    std::cout<<"Lista de valores: "<<std::endl;
    for(const auto& v: valores) {
        std::cout<<v<<", ";
    }
    std::cout<<std::endl;
}
// especializacion de mostrar si es string
template <>
void Caja<std::string>::mostrar() {
    std::cout<<"Lista de cadenas: "<<std::endl;
    for(const auto& v: valores) {
        std::cout<<v<<", logitud: "<<v.size()<<std::endl;
    }
}
template <>
void Caja<bool>::mostrar() {
    for(const auto& v: valores) {
        std::cout<<(v ? "verdadero":"falso")<<", ";
    }
    std::cout<<std::endl;
}


int main() {
    Caja<int> cajaInt;
    cajaInt.guardar(10);
    cajaInt.guardar(20);
    cajaInt.guardar(30);
    cajaInt.mostrar();
    std::cout<<"Elemento 1: "<<cajaInt.obtener(1)<<std::endl;

    Caja<std::string> cajaStr;
    cajaStr.guardar("hola");
    cajaStr.guardar("mundo");
    cajaStr.guardar("cpp");
    cajaStr.mostrar();

    Caja<bool> cajaBool;
    cajaBool.guardar(true);
    cajaBool.guardar(false);
    cajaBool.guardar(true);
    cajaBool.mostrar();

    return 0;
}