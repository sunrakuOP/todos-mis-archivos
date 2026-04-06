#include <iostream>
#include <vector>
class CuentaBancaria {
protected:
    std::string titular;
    double saldo;
public:
    CuentaBancaria(const std::string& t, double s): titular(t), saldo(s) {}

    virtual double calcularInteres() {
        std::cout<<"Impuesto base es 0"<<std::endl;
        return 0;
    }
};

class CuentaAhorro: public CuentaBancaria {
protected:
    double tasaAnual;
public:
    CuentaAhorro(const std::string& t, double s, double ta): CuentaBancaria(t,s), tasaAnual(ta) {}

    double calcularInteres() override {   // redefinir el metodo
        std::cout<<"Interes de cuenta de ahorros: "<< tasaAnual*saldo <<std::endl;
        return saldo*tasaAnual;
    }
};

class CuentaCorriente: public CuentaBancaria {
public:
    CuentaCorriente(const std::string& t, double s): CuentaBancaria(t,s) {}

    double calcularInteres() override {
        std::cout<<"Interes cuenta corriente: -15" <<std::endl;
        return -15;
    }
};

class CuentaPremium: public CuentaAhorro {
public:
    CuentaPremium(const std::string& t, double s, double ta): CuentaAhorro(t, s, ta) {}

    double calcularInteres() override {
        std::cout<<"Interes cuenta premium: "<<saldo*tasaAnual*2<<std::endl;
        return saldo*tasaAnual*2;
    }
};

int main() {
    std::vector<CuentaBancaria*> cuentas;

    // version con stack 
    CuentaBancaria c1("Nicolas", 1000);
    CuentaAhorro c2("Isabella", 2000, 0.06);
    CuentaCorriente c3("Carlos", 2000);
    CuentaPremium c4("No se",1000, 20);

    cuentas.push_back(&c1);
    cuentas.push_back(&c2);
    cuentas.push_back(&c3);
    cuentas.push_back(&c4);

    for(const auto& c: cuentas) {
        c->calcularInteres();
    }
    
    // version con heap (usando el new)
    // el new devuelve el puntero
    cuentas.push_back(new CuentaBancaria("Nicolas", 1000));
    cuentas.push_back(new CuentaAhorro("Isabella", 2000, 0.05));
    cuentas.push_back(new CuentaCorriente("Carlos", 2000));
    cuentas.push_back(new CuentaPremium("No se", 1000, 0.10));

    for(const auto& c: cuentas) {
        c->calcularInteres();
    }

    // Liberar memoria
    for(const auto& c: cuentas) {
        delete c;
    }


    

    return 0;
}