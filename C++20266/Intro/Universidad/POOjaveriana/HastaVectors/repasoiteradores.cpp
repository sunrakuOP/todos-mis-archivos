#include <iostream>
#include <vector>

std::vector<int> pedirValores(int numValores) {
    std::vector<int> lista;
    int datoActual;

    for (int i = 0; i < numValores; i++) {
    std::cout<<"Digite el valor "<<i+1<<std::endl;
    std::cin>>datoActual;
    lista.push_back(datoActual);
    }    
    return lista;
}

// mostrar arreglo como un array
void mostrarArrgelo(const std::vector<int>& lista) {
    for(int i=0; i < lista.size(); i++ ) {
        std::cout<< lista[i]; // se despliega sin salto de linea para hacerlo en un renglon
        if (i != lista.size()-1) {
            std::cout<<"' ";
        }
    }
    std::cout<<" ]"<<  std::endl;

}

int main() {
    int datos;
    std::cout<<"Digite el numero de elementos en la lista"<<std::endl;
    std::cin>>datos;
    std::vector<int> valores = pedirValores(datos);

    //mostrar valores
    std::cout<<"el vector es: "<<std::endl;
    for(int c: valores) {
        std::cout<<c<<std::endl;
    }
    std::cout<<"Otra forma de mostrar el vector: "<<std::endl;
    mostrarArrgelo(valores);


    return 0;
}