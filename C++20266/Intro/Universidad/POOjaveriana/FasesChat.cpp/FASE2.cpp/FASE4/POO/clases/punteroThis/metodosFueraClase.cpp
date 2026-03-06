#include <iostream>

class Estudiante {
    private:
    std::string nombre;
    int codigo;
    double promedio;

    public:    // declaramos los metodos
    void mostrarDatos() const;
    Estudiante& setNombre(std::string n);
    Estudiante& setCodigo(int c);
    Estudiante& setPromedio(double p);
    std::string getNombre() const;
    int getCodigo() const;
    double getPromedio() const;
};
// definimos los metodos fuera de la clase
void Estudiante::mostrarDatos() const{
    std::cout<<"Nombre: "<< nombre<< std::endl;
    std::cout<<"Codigo: "<< codigo <<std::endl;
    std::cout<<"Promedio: "<< promedio << std::endl;
}
// esta funcion no se puede encadenar, tener cuidado con eso

Estudiante& Estudiante::setNombre(std::string n) {
    nombre = n; 
    return *this;
}
Estudiante& Estudiante::setCodigo(int c) {
    codigo = c;
    return *this;
}
Estudiante& Estudiante::setPromedio(double p) {
    promedio = p; 
    return *this;
}
std::string Estudiante::getNombre() const {
    return nombre;
}
int Estudiante::getCodigo() const {
    return codigo;
}
double Estudiante::getPromedio() const {
    return promedio;
}


int main() {
    Estudiante e1;
    e1.setNombre("Nicolas").setCodigo(1029302).setPromedio(5.0);
    e1.mostrarDatos();

    return 0;
}