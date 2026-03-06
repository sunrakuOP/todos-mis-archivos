#include <iostream>
#include <vector>

// Función para pedir la matriz de coeficientes
std::vector<std::vector<int>> matrizCoeficientes(int filas) {
    std::vector<std::vector<int>> matrizC(filas, std::vector<int>(filas));
    std::cout << "Matriz coeficientes:" << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas; ++j) {
            std::cout << "Fila " << i + 1 << ", columna " << j + 1 << ": ";
            std::cin >> matrizC[i][j];
        }
    }
    return matrizC;
}

// Función para pedir la matriz de constantes
std::vector<std::vector<int>> matrizConstantes(int filas) {
    std::vector<std::vector<int>> matrizConst(filas, std::vector<int>(1));
    std::cout << "Matriz constantes:" << std::endl;
    for (int i = 0; i < filas; ++i) {
        std::cout << "Fila " << i + 1 << ", columna 1: ";
        std::cin >> matrizConst[i][0];
    }
    return matrizConst;
}

// Función para crear la matriz aumentada
std::vector<std::vector<int>> matrizAumentada(int filas,
    const std::vector<std::vector<int>>& matrizCoef,
    const std::vector<std::vector<int>>& matrizConstant) {
    std::vector<std::vector<int>> matrizAumen(filas, std::vector<int>(filas + 1));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas; ++j) {
            matrizAumen[i][j] = matrizCoef[i][j];
        }
        matrizAumen[i][filas] = matrizConstant[i][0];
    }
    return matrizAumen;
}

// Función para triangular la matriz aumentada
std::vector<std::vector<double>> matrizTriangular(int filas, std::vector<std::vector<double>> matrizAumen) {
    for (int k = 0; k < filas - 1; ++k) {
        double pivote = matrizAumen[k][k];
        if (pivote == 0) {
            std::cerr << "Error: pivote cero en la fila " << k << std::endl;
            continue;
        }
        for (int i = k + 1; i < filas; ++i) {
            double factor = matrizAumen[i][k] / pivote;
            for (int j = k; j < filas + 1; ++j) {
                matrizAumen[i][j] -= factor * matrizAumen[k][j];
            }
        }
    }
    return matrizAumen;
}

int main() {
    int filas;
    std::cout << "Digite el numero de ecuaciones: " << std::endl;
    std::cin >> filas;

    std::vector<std::vector<int>> matrizCoef = matrizCoeficientes(filas);
    std::vector<std::vector<int>> matrizConstant = matrizConstantes(filas);

    std::vector<std::vector<int>> matrizAumenInt = matrizAumentada(filas, matrizCoef, matrizConstant);
    std::cout << "\nMatriz aumentada:" << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas + 1; ++j) {
            std::cout << matrizAumenInt[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Convertir matrizAumenInt a double para el método de Gauss
    std::vector<std::vector<double>> matrizAumen(filas, std::vector<double>(filas + 1));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas + 1; ++j) {
            matrizAumen[i][j] = static_cast<double>(matrizAumenInt[i][j]);
        }
    }

    // Triangular la matriz
    std::vector<std::vector<double>> matrizTriang = matrizTriangular(filas, matrizAumen);

    std::cout << "\nMatriz triangular superior:" << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas + 1; ++j) {
            std::cout << matrizTriang[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}