#include <iostream>
#include <vector>

struct Estudiante {
    // no debo poner public porque ya lo es por defecto
    std::string nombre;
    int edad;
    double promedio;

    Estudiante (const std::string& n, int e, double p): nombre(n), edad(e), promedio(p) {}
    // no hago getters porque es public, puedo acceder a los atributos

};

int main() {
    Estudiante e1("Nicolas", 23, 5.0);
    Estudiante e2("Isabella", 21, 5.0);
    Estudiante e3("Carlos", 21, 5.0);

    std::vector<Estudiante*> estudiantes;
    // desde el vector imprimir datos, atributos
    estudiantes.push_back(&e1);
    estudiantes.push_back(&e2);
    estudiantes.push_back(&e3);

    double mejor = 0;
    int indice = 0;

    for(size_t i=0; i < estudiantes.size(); ++i) {
        std::cout<<"Estudiante num: "<<i+1<<std::endl;
        std::cout<<estudiantes[i]->edad<<std::endl;
        std::cout<<estudiantes[i]->nombre<<std::endl;
        
        if (estudiantes[i]->promedio > mejor) { 
            indice = i;
            mejor = estudiantes[i]->promedio; 
        }
    }
    // solucion usando punteros
    // inicializar el primer estudiante a puntero llamado mejor
    
    
    Estudiante* mejorr;
    for(const auto& e: estudiantes){
        if(e->promedio > mejorr->promedio) {
            mejorr = e;
        }
    }
    std::cout<<"Mejor promedio es: "<<mejorr->promedio<<" con nombre: "<<mejorr->nombre<<std::endl;


    // sin necesidad de metodos externos ni nada, acceso directo
        // usarlo cuando no se necesite de logica x
    std::cout<<"Mejor promedio: "<<mejor<<", de estudiante: "<<estudiantes[indice]->nombre<<std::endl;

    return 0;
}