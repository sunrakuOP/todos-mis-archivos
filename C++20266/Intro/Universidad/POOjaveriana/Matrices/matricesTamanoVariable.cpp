#include <iostream>
#include <vector>

int main() {
    // debo darle variables al numero de filas y al numero de columnas]
    int filas, columnas;

    std::cout<<"Digite el nuemero de filas: "<<std::endl;
    std::cin>>filas; 
    std::cout<<"Digite el nuemero de columnas: "<<std::endl;
    std::cin>>columnas; 

    std::vector<std::vector<int>> vectorDeVectores(filas, std::vector<int> (columnas));
    // ahora la puedo usar como una matriz comun y corriente, solo cambia que no pierdo memoria al crearla sin saber tamano inicial

    for(int i = 0; i < filas; ++i) {
        for( int j = 0; j < columnas; ++j) {
            std::cout<<"Digite dato de fila "<<i+1<<" y columna "<<j+1<<": "<<std::endl;
            std::cin>> vectorDeVectores[i][j]; // se guarda como un arreglo, como un vector 
        }
    }
    // para mostrar el vector se hace de la misma manera
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            std::cout<< vectorDeVectores[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


    return 0;
}