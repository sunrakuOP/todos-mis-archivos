#include <iostream>
#include <string>

class Estudiante {
    private:
    std::string nombre, codigo;
    int edad;
    double promedio;

    public:
    // constructor normal
    Estudiante(std::string n, std::string c, int e, double p) : nombre(n), codigo(c), edad(e), promedio(p) {
        std::cout<<"Estudiante "<<nombre<<" registrado con codigo "<<codigo<<std::endl;
    }
    // constructor de copia
    Estudiante(const Estudiante& otro) {
        nombre = otro.nombre;
        codigo  = otro.codigo;
        edad = otro.edad;
        promedio = otro.promedio;
        std::cout<<"Copia creada del estudiante: "<<otro.nombre<<std::endl;
    }
    // operador de asignacion
    Estudiante& operator=(const Estudiante& otro) {
        if (this == &otro) {
            std::cout<<"Autoasignacion detectada"<<std::endl;
            return *this;
        }
        std::cout<<"Datos actualizados: "<<nombre<<" ahora es "<<otro.nombre<<std::endl;
        nombre = otro.nombre;
        codigo  = otro.codigo;
        edad = otro.edad;
        promedio = otro.promedio;
        return *this;
    }
    void mostrar() const {
        std::cout<<"Nombre: "<<nombre<<", Edad: "<<edad<<", Promedio: "<<promedio<<", Codigo: "<<codigo<<std::endl;
    }
};

int main() {
    std::cout<<"=== 1. Constructor normal ==="<<std::endl;
    Estudiante e1("Nicolas", "1000232", 23, 5.0);
    e1.mostrar();
    
    std::cout<<"\n=== 2. Constructor de copia ==="<<std::endl;
    Estudiante e2 = e1;
    e2.mostrar();
    
    std::cout<<"\n=== 3. Operador de asignacion ==="<<std::endl;
    Estudiante e3("Maria", "1000555", 20, 4.5);
    e3.mostrar();
    e3 = e1;
    e3.mostrar();
    
    std::cout<<"\n=== 4. Autoasignacion ==="<<std::endl;
    e1 = e1;
    
    return 0;
}