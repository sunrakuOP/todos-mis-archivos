#include <iostream>

// crear nuestra primera matriz
int main() {
    int m[2][3];    // matriz nombre m con 2 filas y 3 columnas
    int m2[2][3] {
        {1, 2, 3},
        {4, 5, 6}  // no se termina con ;
    };

    // int m[i][j], usar dos for (for anidado)
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout<< m2[i][j]<<" ";
        }
        std::cout<< std::endl;
    }

    return 0;
}