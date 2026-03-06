#include <iostream>
#include <vector>

int main() {
    int filas = 4, columnas = 4;
    int valor;
    std::vector<std::vector<int>> matriz (filas, std::vector<int> (columnas));
    for (int i=filas-1; i>=0; --i) {
        for (int j = columnas-1; j>=0; --j) {
            std::cout<<"Digite valor fila "<<i<<" y columna "<<j<<": "<<std::endl;
            std::cin>>matriz.at(i).at(j);
        }
    }
    for (size_t i=0; i < filas; ++i) {
        for (size_t j=0; j< columnas; ++j) {
            std::cout<< matriz.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}