// operaciones entre dos matrices
#include <iostream>
#include <vector>

std::vector<int> matrizVect1 (int filas1, int columnas1, int matriz1[][100]) {
    std::vector<int> vectMatriz1;

    for(size_t i =0; i < filas1; ++i) {
        for(size_t j = 0; j < columnas1; ++j) {
            std::cout<<"Digite elemento fila "<<i+1<<" y columna "<<j+1<<": "<<std::endl;
            std::cin>> matriz1[i][j];
            vectMatriz1.push_back(matriz1[i][j]);
        }
    }
    return vectMatriz1;
}

std::vector<int> matrizVect2 (int filas2, int columnas2, int matriz2[][100]) {
    std::vector<int> vectMatriz2;

    for(size_t i =0; i < filas2; ++i) {
        for(size_t j = 0; j < columnas2; ++j) {
            std::cout<<"Digite elemento fila "<<i+1<<" y columna "<<j+1<<": "<<std::endl;
            std::cin>> matriz2[i][j];
            vectMatriz2.push_back(matriz2[i][j]);
        }
    }
    return vectMatriz2;
}

std::vector<int> sumaMatrices(int filas1, int filas2, int columnas1, int columnas2,
                            std::vector<int>& matrizz1, 
                            std::vector<int>& matrizz2){
    std::vector<int> sumados;
    int sumaAct;

    if (filas1 == filas2 && columnas1 == columnas2) {
        for (size_t i=0; i < matrizz1.size(); ++i) {  // solo necesito un bucle porque son del mismo ttamano, representan la misma posicion
            sumaAct = matrizz1.at(i) + matrizz2.at(i);
            sumados.push_back(sumaAct);
        }
    }
    else {
        std::cout<<"Matrices no son del mismo tamano, no se pueden sumar"<<std::endl;
    }

    return sumados;
} 

std::vector<int> restaMatrices(int filas1, int filas2, int columnas1, int columnas2,
                            std::vector<int>& matrizz1, 
                            std::vector<int>& matrizz2) {
    std::vector<int> restados;
    int restaAct = 0;

    if (filas1 == filas2 && columnas1 == columnas2) {
        for(size_t i = 0; i < matrizz1.size(); ++i) {
            restaAct = matrizz1.at(i) - matrizz2.at(i);
            restados.push_back(restaAct);
        } 
    }
    else {
        std::cout<<"Matrices no son del mismo tamano, no se pueden restar"<<std::endl;
    }

    return restados;
}

std::vector<int> multipMatrices(int filas1, int filas2, int columnas1, int columnas2,
                            std::vector<int>& matrizz1, 
                            std::vector<int>& matrizz2) {
    std::vector<int> multiplicada;

    if (columnas1 == filas2) {
        for(size_t i = 0; i < filas1; ++i){
            for(size_t j = 0; j < columnas2; ++j) {
                // creo la variable suma que almacena suma de fila*columna
                int sumaMult = 0;
                for(size_t k = 0; k < columnas1; ++k) { // columnas1 == filas2 da lo mismo cual parametro
                    sumaMult += matrizz1[i* columnas1 + k]*matrizz2[k * columnas2 + j];
                }
                multiplicada.push_back(sumaMult);
            }
        }
    }
    else {
        std::cout<<"No es posible multiplicarlas por sus dimensiones."<<std::endl;
    }

    return multiplicada;
}

int main() {
    int filas1, columnas1, filas2, columnas2;
    int matriz1[100][100], matriz2[100][100];
    int opcion;
    std::cout<<"Digite el numero filas M1: "<<std::endl;
    std::cin>>filas1;
    std::cout<<"Digite el numero columnas M1: "<<std::endl;
    std::cin>>columnas1;
    std::cout<<"Digite el numero filas M2: "<<std::endl;
    std::cin>>filas2;
    std::cout<<"Digite el numero columnas M2: "<<std::endl;
    std::cin>>columnas2;

    std::vector<int> matrizz1 = matrizVect1(filas1, columnas1, matriz1);
    std::vector<int> matrizz2 = matrizVect2(filas2, columnas2, matriz2);

    std::cout<<"\nMatriz 1: "<<std::endl;
    for(size_t i = 0; i < filas1; ++i) {
        for(size_t j = 0; j < columnas1; ++j) {
            std::cout<< matriz1[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"\nMatriz 2: "<<std::endl;
    for(size_t i = 0; i < filas2; ++i) {
        for(size_t j = 0; j < columnas2; ++j) {
            std::cout<< matriz2[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"\nElija la operación a realizar:"<<std::endl;
    std::cout<<"1. Sumar matrices"<<std::endl;
    std::cout<<"2. Restar matrices"<<std::endl;
    std::cout<<"3. Multiplicar matrices"<<std::endl;
    std::cout<<"Opción: ";
    std::cin>>opcion;

    if(opcion == 1) {
        std::vector<int> sumaVector = sumaMatrices(filas1, filas2, columnas1, columnas2, matrizz1, matrizz2);
        std::cout<<"\nResultado suma (A+B):"<<std::endl;
        for(size_t i = 0; i < filas1; ++i) {
            for(size_t j = 0; j < columnas1; ++j) {
                std::cout<< sumaVector.at(i*columnas1 + j)<<" ";
            }
            std::cout<<std::endl;
        }
    } else if(opcion == 2) {
        std::vector<int> restaVector = restaMatrices(filas1, filas2, columnas1, columnas2, matrizz1, matrizz2);
        std::cout<<"\nResultado resta (A-B):"<<std::endl;
        for(size_t i = 0; i < filas1; ++i) {
            for(size_t j = 0; j < columnas1; ++j) {
                std::cout<< restaVector.at(i*columnas1 + j)<<" ";
            }
            std::cout<<std::endl;
        }
    } else if(opcion == 3) {
        std::vector<int> matrMult = multipMatrices(filas1, filas2, columnas1, columnas2, matrizz1, matrizz2);
        std::cout<<"\nResultado multiplicación (A*B):"<<std::endl;
        for (size_t i = 0; i < filas1; ++i) {
            for(size_t j = 0; j < columnas2; ++j) {
                std::cout<< matrMult.at(i*columnas2 + j)<<" ";
            }
            std::cout<<std::endl;
        }
    } else {
        std::cout<<"Opción no válida."<<std::endl;
    }
    return 0;
}