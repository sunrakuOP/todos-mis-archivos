#include <iostream>
#include <vector>

std::vector<std::vector<int>> guardarMatriz(int f, int c) {
    std::vector<std::vector<int>> matriz (f, std::vector<int> (c));
    int valorActual;
    for (size_t i=0; i<f; ++i) {
        for (size_t j=0; j<c; ++j) {
            std::cout<<"Digite valor fila "<<i<<" y columna "<<j<<": "<<std::endl;
            std::cin>>matriz.at(i).at(j);
        }
    }
    return matriz;
}
void recorrerMatriz(const auto& m, int f, int c) {
    for(size_t i=0; i < f; ++i) {
        for(size_t j=0; j< c; ++j) {
            std::cout<<m.at(i).at(j)<<" ";
        }
        std::cout<<std::endl;
    }
}
std::vector<int> vectorSumaFilas(const auto& m, int f, int c) {
    std::vector<int> sumas;
    for(size_t i=0; i < f; ++i) {
        int sumaFila=0;
        for(size_t j=0; j< c; ++j) {
            sumaFila += m.at(i).at(j);
        }
        sumas.push_back(sumaFila);  
    }
    return sumas;
}

int main(){
    std::vector<std::vector<int>> mat = guardarMatriz(3, 4);
    recorrerMatriz(mat, 3, 4);
    std::vector<int> vsf = vectorSumaFilas(mat, 3, 4);
    for(size_t i=0; i<vsf.size();++i) {
        std::cout<<"Suma fila "<<i+1<<": "<<vsf.at(i)<<std::endl;
    }
    

    return 0;
}