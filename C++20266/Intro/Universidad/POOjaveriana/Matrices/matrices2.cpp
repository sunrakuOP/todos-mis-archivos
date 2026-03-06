// ejercicio para pedir datos y crear una matriz
#include <iostream>

void pedirMatriz(int filas, int columnas, int matriz[][100]) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << "Digite el valor de la fila " << i+1 << " y columna " << j+1 << ": ";
            std::cin >> matriz[i][j];
        }
    }
}

int sumaTotal(int filas, int columnas, int matriz[][100]) {  // recordar dar el numero de columnas max (arrays)
    int sumaTot = 0;

    for(int i = 0; i < filas; ++i) {
        for ( int j = 0; j < columnas; ++j) {
            sumaTot += matriz[i][j];
        }
    }
// por cada iteracion suma el elemento a la sumatoria Total
    return sumaTot;
}

int main() {
    int filas, columnas;
    std::cout << "Digite el numero de filas: ";
    std::cin >> filas;
    std::cout << "Digite el numero de columnas: ";
    std::cin >> columnas;

    int matriz[100][100]; // tamaño máximo
    pedirMatriz(filas, columnas, matriz);

    std::cout << "La matriz es: " << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl; // para que lo muestre en formato matriz
    }
    std::cout<<"Es una matriz de tamano: "<<filas<<"x"<<columnas<<std::endl;

    int sumaFinal = sumaTotal(filas, columnas, matriz);
    std::cout<<"Sumatoria total de la matriz es: "<< sumaFinal <<std::endl;


    return 0;
}