#include <iostream>
#include <vector>

// almaceno cada elemento en una lista, para guardar valores
std::vector<int> pedirMatriz(int filas, int columnas, int matriz[][100]) {
    std::vector<int> matrizz;
    for(size_t i=0; i < filas; ++i) {
        for(size_t j=0; j < columnas; ++j) {
            std::cout<<"Digite elemento de fila "<<i+1<<" y columna"<<j+1<<": "<<std::endl;
            std::cin>>matriz[i][j];
            matrizz.push_back(matriz[i][j]);
        }
        std::cout<<std::endl;
    }

    return matrizz;
}

int sumaDiagonalPrincipal(int filas, int columnas, int matriz[][100]) {
    int sumaD = 0;
    if (filas == columnas) {
        for (size_t i = 0; i < filas; ++i) {
            sumaD += matriz[i][i];
        }
    }
    else {
        std::cout<<"La matriz no es cuadrada"<<std::endl;
    }

    return sumaD;
}

int sumaDiagonalSecundaria(int filas, int columnas, int matriz[][100]) {
    int sumaD2 = 0;
    if (filas == columnas) {
        for( size_t i=0; i < filas; ++i) {
            sumaD2 += matriz[i][filas-(i+1)];  // empieza en ultimo dato de 1ra fila y va sumando (i+1) para izquierda porque i empieza en 0
        }
    }
    else {
        std::cout<<"La matriz no es cuadrada"<<std::endl;
    }

    return sumaD2;
}

// ahora retornar vector que almacene en orden los valores de la transpuesta, porque en el main solo la mostramos
std::vector<int> matrizTranspuesta(int filas, int columnas, int matriz[][100]) {
    std::vector<int> transp;
    int datoActual;

    for(size_t i=0; i < filas; ++i) {
        for(size_t j = 0; j < columnas; ++j) {
            datoActual = matriz[j][i];
            transp.push_back(datoActual);
        }
    }

    return transp;
}

std::vector<int> multEscalar(int filas, int columnas, int matriz[][100], int constante) {
    std::vector<int> multiplicada;
    int datoActual;

    for(size_t i=0; i < filas; ++i) {
        for(size_t j=0; j < columnas; ++j){
            datoActual = constante*matriz[i][j];
            multiplicada.push_back(datoActual);
        }
    }

    return multiplicada;
}

    

int main() {
    int filas, columnas;
    int matriz[100][100];
    std::cout<<"Digite el numero de filas de la matriz: "<<std::endl;
    std::cin>>filas;
    std::cout<<"Digite el numero de columnas de la matriz: "<<std::endl;
    std::cin>>columnas;

    std::vector<int> datos = pedirMatriz(filas, columnas, matriz);
    
    //mostrar la matriz (no el vector)
    std::cout<<"La matriz tamano "<<filas<<"x"<<columnas<<" es: "<<std::endl;
    for(size_t i = 0; i < filas; ++i) {
        for(size_t j = 0; j < columnas; ++j) {
            std::cout<< matriz[i][j] <<" ";
        }
        std::cout<<std::endl;
    }

    int sumaDiagonal = sumaDiagonalPrincipal(filas, columnas, matriz);
    std::cout<<"La suma de la diagonal principal es: "<<sumaDiagonal<<std::endl;

    int sumaDiagonal2 = sumaDiagonalSecundaria(filas, columnas, matriz);
    std::cout<<"La suma de la diagonal secundaria es: "<<sumaDiagonal2<<std::endl;

    // mostrar la matriz transpuesta
    std::cout<<"Matriz transpuesta: "<<std::endl;
    for(size_t i = 0; i < filas; ++i) {
        for(size_t j = 0; j < columnas; ++j) {
            std::cout<< matriz[j][i] <<" ";
        }
        std::cout<<std::endl;
    }
    //mostrar el vector de la transpuesta
    std::vector matrTrasp = matrizTranspuesta(filas, columnas, matriz);
    std::cout<<"El vector de la matriz transpuesta es: "<<std::endl;
    for(size_t c=0; c < matrTrasp.size(); ++c) {
        std::cout<< matrTrasp.at(c)<<" ";
    }

    std::cout<<std::endl;
    int constante;
    std::cout<<"Digite constante a multiplicar por el escalar: "<<std::endl;
    std::cin>>constante;
    
    // matriz mult por constante
    std::cout<<"Matriz multiplicada: "<<std::endl;
    for(size_t i = 0; i < filas; ++i) {
        for(size_t j = 0; j < columnas; ++j) {
            std::cout<< constante * matriz[i][j] <<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}