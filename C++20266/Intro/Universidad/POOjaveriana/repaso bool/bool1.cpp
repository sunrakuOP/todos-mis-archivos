#include <iostream>
#include <vector>

std::vector<int> pedirValores(int numValores) {
    std::vector<int> lista;
    int datoActual = 0;

    for (int i = 0; i < numValores; i++) {
        std::cout<<"Digite el valor "<<i+1<<": "<<std::endl;
        std::cin>>datoActual;
        lista.push_back(datoActual);
    }
    return lista;
}

bool buscarValor(const std::vector<int>& lista, int datoBuscar) {
    bool encontrado = false;

    for (int c: lista) {
        if (c == datoBuscar) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}

// si quiero contar cuantas veces aparece un valor no necesito usar banderas, crear otra funcion y ya 


int main() {
    int cantidadDatos, valorBuscar;
    std::cout<<"Digite la cantidad de datos de la lista: "<<std::endl;
    std::cin>>cantidadDatos;

    std::vector<int> arreglo = pedirValores(cantidadDatos);
    std::cout<<"La lista es: "<<std::endl;

    std::cout<<"Digite un valor a buscar: "<<std::endl;
    std::cin>>valorBuscar;
    
    for (int c: arreglo) {
        std::cout<<c<<std::endl;
    }
    bool dato = buscarValor(arreglo, valorBuscar);
    if (dato) {
        std::cout<<"El valor fue encontrado"<<std::endl;
    }
    else {
        std::cout<<"El valor no fue encontrado"<<std::endl;       
    }

    return 0;
}