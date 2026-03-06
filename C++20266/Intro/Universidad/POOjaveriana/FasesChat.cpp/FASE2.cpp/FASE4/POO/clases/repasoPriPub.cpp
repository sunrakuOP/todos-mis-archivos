#include <iostream>
#include <string>

class CuentaBancaria { 
private: 
    std::string titular;
    double saldo;
    std::string numeroCuenta;

    double cantidad;  // igual crear este tipo de dato en private

public:
// constructor
    CuentaBancaria(std::string t, double s, std::string NC) {
        titular = t;
        saldo = s; 
        numeroCuenta  = NC;
    }
// setters y getters
    void setTitular(std::string t) {
        titular = t;
    }
    void setSaldo(double s) {
        saldo = s;
    }
    void setNumeroCuenta(std::string NC) {
        numeroCuenta = NC;
    }

    std::string getTitular() const {
        return titular;
    }
    double getSaldo() const {
        return saldo;
    }
    std::string getNumeroCuenta() const {
        return numeroCuenta;
    }

    void depositar(double cantidad) {
        saldo += cantidad;
    }
    void retirar(double cantidad) {
        if(cantidad <= saldo) {
            saldo -= cantidad;
        }
        else {
            std::cout<<"Saldo insuficiente"<< std::endl;
        }
    }
};


int main() {
    std::string titularUser, cuentaUsuario;  // crear variable que almacene los datos en el main
    double saldoUser, depositar;


    std::cout<<"Crear cuenta bancaria"<< std::endl;

    std::cout<<"Digite nombre del titular: "<<std::endl;
    std::cin>>titularUser;
    std::cout<<"Digite saldo de la cuenta: "<<std::endl;
    std::cin>>saldoUser;
    std::cout<<"Digite numero de cuenta: "<<std::endl;
    std::cin>>cuentaUsuario;

    // creamos el objeto persona inicializado
    CuentaBancaria persona1(titularUser, saldoUser, cuentaUsuario);
    // mostrar la informacion de la cuenta
    std::cout<<"Titular de la cuenta: "<< persona1.getTitular() <<std::endl;
    std::cout<<"Saldo actual: " << persona1.getSaldo() <<std::endl;
    std::cout<<"Numero de cuenta: "<< persona1.getNumeroCuenta() <<std::endl;

    return 0;
}