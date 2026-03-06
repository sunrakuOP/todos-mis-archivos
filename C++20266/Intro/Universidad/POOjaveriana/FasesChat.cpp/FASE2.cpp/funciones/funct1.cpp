#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrizCoeficientes(int filas) {
    std::vector<std::vector<int>> coeficientes (filas, std::vector<int> (filas+1));
    for(size_t i=0; i<filas; ++i) {
        for(size_t j=0; j<filas; ++j) {
            std::cout<<"Digite fila "<<i+1<<" y columna "<<j+1<<": "<<std::endl;
            std::cin>> coeficientes[i][j];
        }
    }

    return coeficientes;
}

std::vector<std::vector<int>> matrizConstantes(int filas) {
    std::vector<std::vector<int>> constantes(filas, std::vector<int> (1)); // es un vector columna, n filas 1 columna

    for(size_t i=0; i<filas; ++i) {
            std::cout<<"Digite fila "<<i+1<<" y columna 1: "<<std::endl;
            std::cin>> constantes[i][0];
    }

    return constantes;
}

std::vector<std::vector<int>> matrizAumentada(int filas,
    const std::vector<std::vector<int>>& coeficientes,
    const std::vector<std::vector<int>>& constantes) {   //pasar matrices como const y referencia
    
    std::vector<std::vector<int>> aumentada (filas, std::vector<int> (filas+1));
    
    for(size_t i=0; i<filas; ++i) {
        for(size_t j=0; j<filas; ++j) {
            aumentada[i][j] = coeficientes[i][j];
        }
    }
    for(size_t i=0; i < filas; ++i) {
        aumentada[i][filas] = constantes[i][0]; // copio vector constantes(es una columna) en ultima columna de matriz aumentada 
    } // es en [i][filas] porque filas es columna (#filas + 1) porque empieza en 0
    return aumentada;
}

bool solucionTrivial(int filas, const std::vector<std::vector<int>>& aumentada) {
    for(size_t i=0; i<filas; ++i){  
            if (aumentada[i][filas] == 0) { // solo necesito hacer un ciclo for
                return true;   
        }
    }

    return false; // no es necesario crear una variable, puedo retornar de una vez
}

std::vector<int> sumatoriaFilas(int filas, const std::vector<std::vector<int>>& aumentada){
    std::vector<int> vectorSumasFil;
    for(size_t i=0; i<filas; ++i) {
        int sumaFilaActual = 0;
        for(size_t j=0; j<filas+1; ++j) {
            sumaFilaActual += aumentada[i][j];
        }
        vectorSumasFil.push_back(sumaFilaActual);  // el pushback debe estar al final de la sumatoria por filas
    }

    return vectorSumasFil;
}

std::vector<int> sumatoriaColumnas(int filas, const std::vector<std::vector<int>>& aumentada) {
    std::vector<int> vectorSumasCol;
    for(size_t j=0; j<filas+1; ++j) {
        int sumaColActual = 0;
        for(size_t i=0; i<filas; ++i) {
            sumaColActual += aumentada[i][j];
        }
        vectorSumasCol.push_back(sumaColActual);
    }
    return vectorSumasCol;
}

int valorMax(int filas, const std::vector<std::vector<int>>& aumentada){
    int valorMaxAct = aumentada[0][0];
    for(size_t i=0; i<filas; ++i) {
        for(size_t j=0; j<filas+1; ++j) {
            if(aumentada[i][j] > valorMaxAct) {
                valorMaxAct = aumentada[i][j];
            }
        }
    }
    return valorMaxAct;
}

int main() {
    int filas;
    std::cout<<"Digite el numero de ecuaciones: "<<std::endl;
    std::cin>>filas;

    // mostrar matriz coeficientes
    std::vector<std::vector<int>> coeficientes = matrizCoeficientes(filas);
    std::cout<<"Matriz coeficientes: "<<std::endl;
    for(size_t i=0; i<filas; i++) {
        for(size_t j=0; j <filas; j++) {
            std::cout<< coeficientes[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    // mostrar vector constantes 
    std::vector<std::vector<int>> constantes = matrizConstantes(filas);
    std::cout<<"Matriz constantes: "<<std::endl;
    for(size_t i=0; i<filas; i++) {    // si solo tengo una columna no necesito dos for
        std::cout<< constantes[i][0];
        std::cout<<std::endl;
    }
    // mostrar matriz aumentada
    std::vector<std::vector<int>> aumentada = matrizAumentada(filas, coeficientes, constantes);
    std::cout<<"Matriz aumentada: "<<std::endl;
    for(size_t i=0; i<filas; ++i) {
        for(size_t j=0; j<filas+1; ++j) {
            std::cout<< aumentada[i][j] <<" ";
        }
        std::cout<<std::endl;
    }

    // solucion trivial
    bool trivial = solucionTrivial(filas, aumentada);
    if(trivial) {
        std::cout<<"El sistema tiene solucion trivial (0's en vector de ktes)"<<std::endl;
    }
    else {
        std::cout<<"El sistema no tiene soluciones triviales"<<std::endl;
    }

// ESTADISTICAS DE MATRIZ

    // sumatoria por filas
    std::vector<int> sumaFilas = sumatoriaFilas(filas, aumentada);
    std::cout<<"Sumatoria por filas"<<std::endl;
    for(size_t i=0; i <filas; ++i) {
        std::cout<<"Suma fila "<<i+1<<": "<< sumaFilas[i]<<std::endl;
    }
    // sumatoria por columnas
    std::vector<int> sumaColumnas = sumatoriaColumnas(filas, aumentada);
    std::cout<<"Sumatoria por columnas"<<std::endl;
    for(size_t i=0; i <filas+1; ++i) {
        std::cout<<"Suma columna "<<i+1<<": "<< sumaColumnas[i]<<std::endl;
    }
    // valor maximo 
    int valorMaximo = valorMax(filas, aumentada);
    std::cout<<"Valor maximo general es: "<< valorMaximo <<std::endl;

    return 0;
}