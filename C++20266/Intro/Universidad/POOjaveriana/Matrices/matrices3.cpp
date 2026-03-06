#include <iostream>
#include <vector>

void pedirMatriz(int filas, int columnas, int matriz[][100]){
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j){
            std::cout<<"Digite valor de fila "<<i+1<<" y columna "<<j+1<<": "<<std::endl;
            std::cin>>matriz[i][j];
        }
    }
}

void sumaFilas(int filas, int columnas, int matriz[][100]) {
    for (int i = 0; i < filas; ++i) {
            int sumatoriaFilas = 0; // creo la variable para las filas, se reinicia despues de cada ciclo
            for (int j = 0; j < columnas; ++j) {
                sumatoriaFilas += matriz[i][j];
            }
            std::cout<<"Suma fila "<<i+1<<": "<< sumatoriaFilas <<std::endl;
        }
}

// al llamar la funcion en 
void sumarColumnas(int filas, int columnas, int matriz[][100]) {   
    // primero recorrer columnas antes de filas
    for (int j =  0; j < columnas; ++j) {
        int sumaColumna = 0;
        for (int i = 0; i < filas; ++i) {
            sumaColumna += matriz[i][j];
        }
        std::cout<<"Suma columna "<<j+1<<": "<< sumaColumna <<std::endl;
    }
}

// DEVOLVER SUMA_FILAS COMO UN VECTOR PARA DEVOLVER DATO (no dejarlo en void)
    std::vector<int> sumaFilasVect(int filas, int columnas, int matriz[][100]) {
        std::vector<int> sumasFilas;

        for(int i = 0; i < filas; ++i)  {
            int sumaFila = 0;
            for(int j = 0; j < columnas; ++j){
                sumaFila += matriz[i][j];
            }
            sumasFilas.push_back(sumaFila);
        }
        return sumasFilas; // devuelvo el vector y lo muestro en el main
    }

    int sumaDiagonalPrincipal(int filas, int columnas, int matriz[][100]) {
        int sumaDiagonales = 0;

        if(filas == columnas) {
            std::cout<<"La matriz es cuadrada, se puede proceder"<<std::endl;
            for (size_t i =0; i < filas; ++i) {
                for(size_t j=0; j < columnas; ++j) {
                    if (i == j){
                        sumaDiagonales += matriz[i][j];
                    }   
                }
            }
        }
        else std::cout<<"La matriz no es cuadrada"<<std::endl;

        return sumaDiagonales; 
    }

    // se usa solo un for porque se recorre con un mismo indice que debe ser igual en fila y columna
    int sumaDiagonalPrincipal2(int filas, int columnas, int matriz[][100]){
        // sumar la diagonal principal usando solo un for
        int sumaD = 0;

        if (filas == columnas) {
            for (size_t i = 0; i < filas; ++i) {   // filas es igual a columnas, da igual
                sumaD += matriz[i][i];   // filas deben ser iguales a columnas
            }
        }
        return sumaD;
    }

int main() {
    int filas, columnas;
    std::cout<<"Digite el numero de filas: "<<std::endl;
    std::cin>>filas;
    std::cout<<"Digite el numero de columnas: "<<std::endl;
    std::cin>>columnas;
    

    int matriz[100][100];
    pedirMatriz(filas, columnas, matriz);
    std::cout<<std::endl; 

    for(int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            std::cout<< matriz[i][j] <<", ";
        }
        std::cout<<std::endl;
    }
    sumaFilas(filas, columnas, matriz);
    std::cout<<std::endl;
    sumarColumnas(filas, columnas, matriz);

    std::vector<int> sumaPorFilas = sumaFilasVect(filas, columnas, matriz);
    std::cout<<"Suma por filas (en vector): "<<std::endl;
    for(size_t i = 0; i < sumaPorFilas.size(); ++i){
        std::cout<<"La sumatoria de fila "<<i+1<<" es: "<<sumaPorFilas.at(i)<<std::endl;
    }

    int diagonalPrincipal = sumaDiagonalPrincipal(filas, columnas, matriz);
    std::cout<<"La suma de la diagonal principal (con dos for) es: "<< diagonalPrincipal<<std::endl;

    int diagonalPrincipal2 = sumaDiagonalPrincipal2(filas, columnas, matriz);
    std::cout<<"La suma de la diagonal principal (usando solo un for) es: "<<diagonalPrincipal2<<std::endl;


    return 0;  
}