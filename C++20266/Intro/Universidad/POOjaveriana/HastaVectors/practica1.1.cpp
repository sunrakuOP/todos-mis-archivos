#include <iostream>
#include <string>
#include <vector>

// do while es post condicional, se evalua al menos una vez antes de testear la condicion
// while se testea antes de ejecutar el bloque, pre condicional

void pedirDatos(int numDatos,
                std::vector<std::string>& productos,
                std::vector<double>& cantidades,
                std::vector<double>& precios) {  // void porque vamos a retornar varios vectores y no sabemos estructuras aun
    
    for (int i = 0; i < numDatos; i++) {
        std::string nombreTemp;
        double cantidadTemp;
        double precioTemp;

        std::cout<<"Digite el nombre del producto: "<<std::endl;
        std::cin>>nombreTemp;

        do {
            std::cout<<"Digite la cantidad de productos: "<<std::endl;
            std::cin>>cantidadTemp;
            if (cantidadTemp <= 0) {
                std::cout<<"Digite una cantidad valida"<<std::endl;
            }
        } while (cantidadTemp <= 0); // si escribe cantidad mayor a cero sale del ciclo y guarda el valor
        
        do {
            std::cout<<"Digite el precio del producto: "<<std::endl;
            std::cin>>precioTemp;
            if (precioTemp <= 0) {
                std::cout<<"Digite un precio valido"<<std::endl;
            }
        } while(precioTemp <= 0);

        productos.push_back(nombreTemp);
        cantidades.push_back(cantidadTemp);
        precios.push_back(precioTemp);

    }   
}


int main() {
    int numeroVentas;
    std::cout<<"Digite numero de ventas: "<<std::endl;
    std::cin>>numeroVentas;

    std::vector<std::string> productos;
    std::vector<double> cantidades;
    std::vector<double> precios;

// LLAMAR A LA FUNCION CON VARIOS PARAMETROS
    pedirDatos(numeroVentas, productos, cantidades, precios);



    return 0;
}