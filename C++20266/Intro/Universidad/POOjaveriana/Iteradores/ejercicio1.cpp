#include <iostream>
#include <vector>

std::vector<int> pedirValores(int cantidadDatos) {
    std::vector<int> listaValores;
    int datoActual;
    
    for (int i = 0; i < cantidadDatos; i++) {
        std::cout<<"Digite el valor "<<i+1<<": "<<std::endl;
        std::cin>>datoActual;
        listaValores.push_back(datoActual);
    }

    return listaValores;
}

int pares(const std::vector<int>& listado) {
    int contadorPares = 0;
 
    for (int c: listado) {
        if (c % 2 == 0) {
            contadorPares++;
        }
    }

    return contadorPares;
}

int numEspecifico(const std::vector<int>& listado,
                  int numero) {
    int contadorNum = 0;
    
    for (int c: listado) {
        if (c == numero) {
            contadorNum++;
        }
    }


    return contadorNum;
}

int main (){
    int numDatos, buscar;
    std::cout<<"Digite cantidad de datos de la lista: "<<std::endl;
    std::cin>>numDatos;
    std::vector listado = pedirValores(numDatos);
    std::cout<<"El listado es: "<<std::endl;
    
    for (int c: listado){
        std::cout<<c<<std::endl;
    }

    int paresTot = pares(listado);
    std::cout<<"Numero de pares en listado es: "<<paresTot<<std::endl;

    std::cout<<"Que numero quieres contar: "<<std::endl;
    std::cin>>buscar;
    int contado = numEspecifico(listado, buscar);
    std::cout<<"Numero: "<<buscar<<" aparece, "<< contado <<" veces"<<std::endl;

    


    return 0;
}