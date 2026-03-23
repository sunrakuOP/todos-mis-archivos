#include <iostream>
#include <vector>
#include <string>

// Pedir nombres — vector simple
std::vector<std::string> pedirNombres(int n) {
    std::vector<std::string> nombres;
    for (int i = 0; i < n; i++) {
        std::string nombre;
        std::cout << "Nombre estudiante " << i+1 << ": ";
        std::cin >> nombre;
        nombres.push_back(nombre);
    }
    return nombres;
}

// Pedir materias — vector simple
std::vector<std::string> pedirMaterias(int n) {
    std::vector<std::string> materias;
    for (int i = 0; i < n; i++) {
        std::string materia;
        std::cout << "Nombre materia " << i+1 << ": ";
        std::cin >> materia;
        materias.push_back(materia);
    }
    return materias;
}

// Pedir notas
std::vector<std::vector<double>> pedirNotas(int filas, int cols,
                                            const std::vector<std::string>& nombres,
                                            const std::vector<std::string>& materias) {
    std::vector<std::vector<double>> notas;
    for (int i = 0; i < filas; i++) {
        std::vector<double> fila;
        for (int j = 0; j < cols; j++) {
            double nota;
            std::cout << nombres[i] << " — " << materias[j] << ": ";
            std::cin >> nota;
            fila.push_back(nota);
        }
        notas.push_back(fila);
    }
    return notas;
}

// Promedio de un estudiante
double promedio(const std::vector<double>& notas) {
    double suma = 0;
    for (double n : notas) suma += n;
    return suma / notas.size();
}

// Mostrar promedios y aprobados
void mostrarResultados(const std::vector<std::string>& nombres,
                       const std::vector<std::vector<double>>& notas) {
    int mejorIdx = 0;
    double mejorProm = 0;
    int aprobados = 0;

    for (size_t i = 0; i < nombres.size(); i++) {
        double prom = promedio(notas[i]);
        std::cout << nombres[i] << " — promedio: " << prom;

        if (prom >= 3.0) {
            std::cout << " ✅ Aprobado";
            aprobados++;
        } else {
            std::cout << " ❌ Reprobado";
        }
        std::cout << "\n";

        if (prom > mejorProm) {
            mejorProm = prom;
            mejorIdx = i;
        }
    }

    std::cout << "\nMejor estudiante: " << nombres[mejorIdx]
              << " con " << mejorProm << "\n";
    std::cout << "Aprobados: " << aprobados
              << "/" << nombres.size() << "\n";
}

// Buscar nota específica
void mostrarNota(const std::string& nombre, const std::string& materia,
                 const std::vector<std::string>& nombres,
                 const std::vector<std::string>& materias,
                 const std::vector<std::vector<double>>& notas) {

    int fila = -1, col = -1;

    for (size_t i = 0; i < nombres.size(); i++)
        if (nombres[i] == nombre) { fila = i; break; }

    for (size_t j = 0; j < materias.size(); j++)
        if (materias[j] == materia) { col = j; break; }

    if (fila == -1) { std::cout << "Estudiante no encontrado\n"; return; }
    if (col == -1)  { std::cout << "Materia no encontrada\n";    return; }

    std::cout << nombre << " en " << materia
              << ": " << notas[fila][col] << "\n";
}

int main() {
    int numEst, numMat;

    std::cout << "Estudiantes: "; std::cin >> numEst;
    std::cout << "Materias: ";    std::cin >> numMat;

    auto nombres  = pedirNombres(numEst);
    auto materias = pedirMaterias(numMat);
    auto notas    = pedirNotas(numEst, numMat, nombres, materias);

    mostrarResultados(nombres, notas);

    std::string nombre, materia;
    std::cout << "\nBuscar — Estudiante: "; std::cin >> nombre;
    std::cout << "Buscar — Materia: ";     std::cin >> materia;
    mostrarNota(nombre, materia, nombres, materias, notas);

    return 0;
}