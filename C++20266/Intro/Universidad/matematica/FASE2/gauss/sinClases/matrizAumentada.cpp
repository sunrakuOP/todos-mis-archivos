#include <iostream>
#include <vector>
#include <stdexcept>

using Matriz = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

Matriz pedirMatrCoef(int filas) {
    Matriz matrCoeficientes(filas, std::vector<double>(filas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas; ++j) {
            std::cout << "Digite elemento fila " << i+1 << " y columna " << j+1 << ": ";
            std::cin >> matrCoeficientes.at(i).at(j);
        }
    }
    return matrCoeficientes;
}

Vector pedirVectorResult(int filas) {
    Vector vectResultado(filas);
    for (int i = 0; i < filas; ++i) {
        std::cout << "Digite resultado " << i+1 << ": ";
        std::cin >> vectResultado.at(i);
    }
    return vectResultado;
}

Matriz matrizAumentada(int filas, const Matriz& coeficientes, const Vector& resultados) {
    Matriz aumentada(filas, std::vector<double>(filas + 1));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < filas; ++j)
            aumentada.at(i).at(j) = coeficientes.at(i).at(j);
        aumentada.at(i).at(filas) = resultados.at(i);
    }
    return aumentada;
}

Matriz elimHaciaAdelante(int filas, Matriz& aumentada) {
    for (int k = 0; k < filas; ++k) {
        if (aumentada.at(k).at(k) == 0)
            throw std::runtime_error("Pivote cero detectado.");
        for (int i = k+1; i < filas; ++i) {
            double factor = aumentada.at(i).at(k) / aumentada.at(k).at(k);
            for (int j = k; j < filas+1; ++j)
                aumentada.at(i).at(j) -= factor * aumentada.at(k).at(j);
        }
    }
    return aumentada;
}

Vector sustHaciaAtras(int filas, const Matriz& aumentada) {
    Vector x(filas);
    for (int i = filas-1; i >= 0; --i) {  // ✅ --i baja hacia 0
        double sumaFila = 0;
        for (int j = i+1; j < filas; ++j)
            sumaFila += aumentada.at(i).at(j) * x.at(j);
        if (aumentada.at(i).at(i) == 0)
            throw std::runtime_error("Pivote cero en sustitucion.");
        x.at(i) = (aumentada.at(i).at(filas) - sumaFila) / aumentada.at(i).at(i);
    }
    return x;
}

int main() {
    int numFilas;
    std::cout << "Digite el numero de filas: ";
    std::cin >> numFilas;

    if (numFilas <= 0) {
        std::cerr << "El numero de filas debe ser mayor que cero." << std::endl;
        return 1;
    }

    Matriz coeficientes = pedirMatrCoef(numFilas);
    Vector resultados = pedirVectorResult(numFilas);

    Matriz aumentada = matrizAumentada(numFilas, coeficientes, resultados);

    std::cout << "\nMatriz aumentada:" << std::endl;
    for (int i = 0; i < numFilas; ++i) {
        for (int j = 0; j < numFilas+1; ++j)
            std::cout << aumentada.at(i).at(j) << "\t";
        std::cout << std::endl;
    }

    try {
        Matriz reducida = elimHaciaAdelante(numFilas, aumentada);

        std::cout << "\nMatriz reducida:" << std::endl;
        for (int i = 0; i < numFilas; ++i) {
            for (int j = 0; j < numFilas+1; ++j)
                std::cout << reducida.at(i).at(j) << "\t";
            std::cout << std::endl;
        }

        Vector valores = sustHaciaAtras(numFilas, reducida);

        std::cout << "\nSolucion:" << std::endl;
        for (int i = 0; i < numFilas; ++i)
            std::cout << "x" << i+1 << " = " << valores.at(i) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}