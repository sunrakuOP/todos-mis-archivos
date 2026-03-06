#include <iostream>
#include <vector>
#include <cctype>

// ESTUDIAR VECTORES PARES O CONJUNTOS
void pedirNombres(std::vector<std::string>& alumnos, int numAlmmunos) {
    std::string nombreTemp;
    float notaTemp;

    for (size_t i = 0; i < numAlmmunos; ++i) {
        std::cout<<"Digite nombre del almuno "<< i+1 <<": "<<std::endl;
        std::getline(std::cin, nombreTemp);
        alumnos.push_back(nombreTemp);
    }
}

void pedirNotas(std::vector<float>& notas, int numAlumnos) {
    float notaTemp;

    for (size_t i = 0; i < numAlumnos; ++i) {
        std::cout<<"Digite nota del almuno "<< i+1 <<": "<<std::endl;
        std::cin>>notaTemp;
        notas.push_back(notaTemp);
    }
    std::cin.ignore();
}

float promedioNotas(std::vector<float>& notas) {
    float sumatoria = 0;
    for(size_t i = 0; i < notas.size(); i++) {
        sumatoria += notas.at(i);
    }

    return sumatoria / notas.size();
}

float mayorNota(std::vector<float>& notas) {
    float mayorAct = notas.at(0);

    for(size_t i = 1; i < notas.size(); ++i) {  // inicializar en 1 porque ya iguale a 0 mayoorAct, ahorrar iteraciones
        if (notas.at(i) > mayorAct) {
            mayorAct = notas.at(i);
        }
    }

    return mayorAct;
}

float menorNota(std::vector<float>& notas) {
    float menorAct = notas.at(0);

    for(size_t i = 1; i < notas.size(); ++i) {  // inicializar en 1 porque ya iguale a 0 mayoorAct, ahorrar iteraciones
        if (notas.at(i) < menorAct) {
            menorAct = notas.at(i);
        }
    }
    return menorAct;
}

int numeroAprobados(std::vector<float>& notas) {
    int aprobados = 0;
    for (size_t i = 0; i < notas.size(); i++) {
        if (notas.at(i) >= 3.0) {
            aprobados++;
        }
    }
    return aprobados;
}

bool encotrarEstudiante(std::vector<std::string>& alumnos) {
    bool encontrado = false; 
    std::string nombreBusc;
    std::cout<<"Digite el nombre a buscar: "<<std::endl;
    std::getline(std::cin, nombreBusc);

    for(size_t i = 0; i < alumnos.size() ; i++) {
        if(nombreBusc == alumnos.at(i)) {
            encontrado = true;
            break;  // sale del ciclo porque ya lo hayo, para no seguir iterando
        }
    }
    return encontrado;
}

void mayusculas(std::vector<std::string>& alumnos) {
    for (size_t i = 0; i < alumnos.size(); i++) {
        for (char& c: alumnos.at(i)) {    // se manda como una referencia 
            c = toupper(c);
        }      
    }

}

int main() {
    int numAlmunos;
    std::cout<<"Digite el numero de estudiantes: "<<std::endl;
    std::cin>>numAlmunos;
    std::cin.ignore();

    std::vector<std::string> alumnos;
    std::vector<float> notas;

    pedirNombres(alumnos, numAlmunos);
    pedirNotas(notas, numAlmunos);

    std::cout<<"Listado: "<<std::endl;
// mostrar nombres y notas a la par
    for (size_t i = 0; i < numAlmunos; ++i) {
        std::cout<< i+1 <<". "<< alumnos.at(i) <<" : "<< notas.at(i) <<std::endl;
    }

    float prom = promedioNotas(notas);
    std::cout<<"Promedio de las notas es: "<< prom << std::endl;

    float notaMayor = mayorNota(notas);
    std::cout<<"La nota mas alta es: "<< notaMayor <<std::endl;
    float notaMenor = menorNota(notas);
    std::cout<<"La nota mas baja es: "<< notaMenor <<std::endl;

    int pasaron = numeroAprobados(notas);
    std::cout<<"Cantidad de aprobados es: "<<pasaron<<std::endl;

    bool hallar = encotrarEstudiante(alumnos);
    if (hallar) {
        std::cout<<"El estudiante ha sido encontrado"<<std::endl;
    }
    else{
        std::cout<<"El estudiante NO ha sido encontrado"<<std::endl;
    }

    mayusculas(alumnos);
    std::cout<<"Listado en mayusculas: "<<std::endl;
    for (size_t i = 0; i < alumnos.size(); i++) {
        std::cout << i+1 << ". " << alumnos.at(i) << " : " << notas.at(i) << std::endl;
    }
    
    return 0;
}