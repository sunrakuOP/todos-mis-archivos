#include <iostream>

class persona {   // creamos un nuevo tipo de dato llamado persona
public:
    std::string nombre;   // tipo dato persona tiene nombre y edad
    int edad;

    void saludar() {
        std::cout<<"Hola, soy " << nombre <<std::endl;
    } // tiene una funcion interna que saluda

};

int main() {
    persona p1; // creo OBJETO tipo de dato "persona"
    p1.nombre = "Nicolas";
    p1.edad = 23;
    p1.saludar();

    persona p2;
    p2.nombre = "Sebastian";
    p2.edad = 24;
    p2.saludar();


    return 0;
}