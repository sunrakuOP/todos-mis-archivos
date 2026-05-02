#include <iostream>
#include <map>

/*
map almacena pares ordenadados de CLAVE -> VALOR.  {clave, valor}
cada par puede ser un tipo de dato diferente
cada clave es unica
*/

int main() {
    // crear un map (Es como un diccionario en python)
    std::map<std::string, int> edades;
    // clave es el nombre (string), valor es edad(int)
    // map["clave"] = valor;      sintaxis de insertar

    // insert para insertar en vez de [], ambos sirven
    edades.insert({"Carlos", 28}); 

    edades["Nicolas"] = 23;
    edades["Isabella"] = 21;
    // para modificar solo repito la sintaxis
    edades["Isabella"] = 2;

    // acceder al valor
    std::cout<<edades["Nicolas"]<<std::endl; 

    // el problema es que si no esta la clave, la inserta en el map

    // VERFICAR SI EXISTE
    if(edades.count("Isabella")) {
        std::cout<<"Ana existe"<<std::endl; // si aparece mas de una vez
    }




    return 0;
}