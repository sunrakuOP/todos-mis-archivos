#include <iostream>

double sumar(double a, double b) {
    std::cout<<"Resultado: "<<a+b<<std::endl;
    return a+b;
}
double restar(double a, double b){
    std::cout<<"Resultado: "<<a-b<<std::endl;
    return a-b;
}
double multiplicar(double a, double b){
    std::cout<<"Resultado: "<<a*b<<std::endl;
    return a*b;
}
double dividir(double a, double b){
    if(b == 0.0){
        std::cout<<"Division invalida"<<std::endl;
        return 0.0;
    }
    std::cout<<"Resultado: "<<a/b<<std::endl;
    return a/b;
}

void ejecutar() {
    int opcion;
    do {
        std::cout<<"========MENU========"<<std::endl;
        std::cout<<"Opcion 0: Salir..."<<std::endl;
        std::cout<<"Opcion 1: Sumar"<<std::endl;
        std::cout<<"Opcion 2: Restar"<<std::endl;
        std::cout<<"Opcion 3: Multiplicar"<<std::endl;
        std::cout<<"Opcion 4: Division"<<std::endl;
        std::cin>>opcion;

        if(opcion == 0){
            std::cout<<"Saliendo..."<<std::endl;
            break;
        }
        
        double a, b;
        std::cout<<"Digite los valores a operar: "<<std::endl;
        std::cin>>a>>b;

        switch (opcion)
        {
        case 0:
            break;
        case 1: 
            sumar(a,b);
            break;
        case 2:
            restar(a,b);
            break;
        case 3:
            multiplicar(a,b);
            break;
        case 4:
            dividir(a,b);
            break;
        default:
            std::cout<<"Opcion invalida.."<<std::endl;
            break;
        }
    } while(opcion != 0);
}

int main() {
    ejecutar();

    return 0;
}