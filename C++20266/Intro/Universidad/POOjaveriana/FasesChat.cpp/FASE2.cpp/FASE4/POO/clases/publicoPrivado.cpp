// datos privados y funciones publicas

#include <iostream>
#include <string>

// crear clase tipo persona con datos privados y funciones publicas
class Persona {
private:  
    std::string nombre;  // hacemos privados 
    int edad;

public: 
// uso del constructor
    Persona(std::string n, int e) {
        nombre = n;
        edad = e;
    }

// uso de getters y setters
    // SETTERS piden los datos, tienen un parametro
    void setEdad (int e) {
        if(edad >= 0) edad = e;
    }

    void setNombre(const std::string& n) {
        nombre = n;
    }

    // GETTERS piden los datos
    int getEdad() const {   // funcion solo va a leer datos, no modificarlos
        return edad;  // devuelven el valor
    }

    std::string getNombre() const {
        return nombre;
    }

    void saludar() const {
        std::cout<<"Hola soy: "<< nombre <<std::endl;
    }

};

int main() {

    Persona p1("", 0);  // si ya uso el constructor cambia la forma de crear objetos
    p1.setEdad(23);
    p1.setNombre("Nicolas");  // los setters guardan el dato (tienen parametro)

    std::cout<<"Edad de: "<< p1.getNombre() <<" es: "<< p1.getEdad() <<std::endl;
    // para buscar el dato uso el getter, que lo lee y retorna

    // crear persona usando el contructor
    Persona p2("Juan", 23); // objeto inicializado
    std::cout<<"Nombre persona 2: "<< p2.getNombre() <<" y edad: "<< p2.getEdad()<< std::endl;

    p2.setEdad(30); // cambiamos la edad

    std::cout<<"Nueva edad de persona 2: "<< p2.getEdad()<< std::endl;
    
    return 0;
}