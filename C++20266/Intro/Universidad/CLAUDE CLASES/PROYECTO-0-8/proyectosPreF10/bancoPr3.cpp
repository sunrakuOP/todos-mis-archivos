#include <iostream>
#include <vector>
#include <string>

/*
Especificación de cada clase
Cuenta (abstracta, base de todo):

Atributos: titular (string), numeroCuenta (string), saldo (double)
Métodos virtuales puros: aplicarMensualidad() (cada tipo hace algo diferente cada mes), tipo() retorna string
Métodos virtuales: depositar(monto), retirar(monto) (cada tipo valida diferente)
Método: transferir(monto, Cuenta& destino) — retira de esta cuenta y deposita en la otra
Historial de transacciones: cada operación (depósito, retiro, transferencia, interés, cobro) queda registrada con descripción, monto, y saldo resultante
operator<< para imprimir info de la cuenta
Destructor virtual

CuentaAhorro:

Atributo extra: tasaInteres (double, ej: 0.005 = 0.5% mensual)
aplicarMensualidad(): suma interés al saldo (saldo × tasaInteres)
retirar(): no permite saldo negativo
depositar(): normal, sin restricciones

CuentaCorriente:

Atributos extra: costoMantenimiento (double, ej: 15000), limiteSobregiro (double, ej: 500000)
aplicarMensualidad(): cobra el mantenimiento mensual (resta del saldo)
retirar(): permite sobregiro hasta el límite (saldo puede ser negativo hasta -limiteSobregiro)
depositar(): normal

CDT (Certificado de Depósito a Término):

Atributos extra: tasaInteres (double, ej: 0.012 = 1.2% mensual), plazoMeses (int), mesesTranscurridos (int)
aplicarMensualidad(): suma interés y avanza un mes
retirar(): rechaza siempre hasta que mesesTranscurridos >= plazoMeses. Imprimir cuántos meses faltan.
depositar(): rechaza — un CDT no acepta depósitos después de crearse
*/

class Cuenta {
protected:
    std::string titular;
    std::string numeroCuenta;
    double saldo;
    std::vector<std::string> historial;
public:
    Cuenta(const std::string& t, const std::string& nc, double s):
        titular(std::move(t)), numeroCuenta(std::move(nc)), saldo(s) {}
    
    double getSaldo() const { return saldo; } 
    
    // destructor virtual obligatorio
    virtual ~Cuenta() = default;
        
    virtual double aplicarMensualidad() = 0;
    virtual std::string tipo() = 0;

    virtual double depositarMonto(double monto) {
        saldo += monto;
        return saldo;
    }

    virtual double retirarMonto(double monto) = 0;

    void transferirMonto(double m, Cuenta& destino) {
        retirarMonto(m);
        destino.depositarMonto(m);
    }
};

class CuentaAhorro: public Cuenta {
protected:
    double tasaInteres;
public:
    CuentaAhorro(const std::string& t, const std::string& nc, double s, double ti): Cuenta(t,nc,s), tasaInteres(ti) {}

    double aplicarMensualidad() override {
        double pInter = saldo*(tasaInteres/100);
        std::cout<<"Mensualidad: "<<saldo + pInter<<std::endl;
        saldo += pInter;
        return saldo;
    }

    std::string tipo() override {
        return "Cuenta ahorros";
    }

    double retirarMonto(double monto) override { 
        if(saldo - monto < 0){
            std::cout<<"Saldo insuficiente"<<std::endl;
            return saldo;
        }
        saldo -= monto;
        return saldo;
    }
};
class CuentaCorriente: public Cuenta {
protected:
    double costoMantenimiento;
    double limiteSobregiro;
public:
    CuentaCorriente(const std::string& t, const std::string& nc, double s, double cm, double ls):
        Cuenta(t,nc,s), costoMantenimiento(cm), limiteSobregiro(ls) {}
    
    double aplicarMensualidad() override {
        saldo -= costoMantenimiento;
        return saldo;
    }

    std::string tipo() override {
        return "Cuenta corriente";
    }

    double retirarMonto(double monto) override {
        if(saldo - monto < -limiteSobregiro){
            std::cout<<"Limite sobregiro alcanzado"<<std::endl;
            return saldo;
        }
        saldo -= monto;
        return saldo;
    }
};
class CDT: public Cuenta {
protected:
    double tasaInteres;
    int mesesTransc = 0;
    int nMeses;
public:
    CDT(const std::string& t, const std::string& nc, double s, double ti, int nm):
        Cuenta(t,nc,s), tasaInteres(ti), nMeses(nm) {}

    double aplicarMensualidad() override {
        if(nMeses <= 0) {
            std::cout<<"Plazo completado.."<<std::endl;
            return saldo;
        }
        saldo += saldo*(tasaInteres/100);
        nMeses--;
        mesesTransc++;
        return saldo;
    }

    std::string tipo() override {
        return "CDT";
    }

    double depositarMonto(double) override {
        std::cout<<"CDT no acepta depositos"<<std::endl;
        return saldo;
    }

    double retirarMonto(double monto) override {
        if(mesesTransc < nMeses){
            std::cout<<"No es posible retirar el dinero, plazo no cumplido"<<std::endl;
            return 0.0;
        }
        if((saldo - monto) < 0){
            std::cout<<"Saldo insuficiente"<<std::endl;
            return saldo;
        }
        saldo -= monto;
        return saldo;
    }
};

int main() {    
    std::vector<Cuenta*> cuentas;
    cuentas.push_back(new CuentaAhorro("Nicolas", "1000000", 50000, 5));
    cuentas.push_back(new CuentaCorriente("Carlos", "10000002", 50000, 10000, 20000));
    cuentas.push_back(new CDT("Fernando", "1000002", 50000, 10, 4));

    cuentas.at(0)->depositarMonto(10000);
    cuentas.at(1)->depositarMonto(15000);
    cuentas.at(2)->depositarMonto(20000);

    cuentas.at(0)->retirarMonto(20000);
    cuentas.at(2)->retirarMonto(100000);

    cuentas.at(2)->depositarMonto(10000);
    cuentas.at(0)->transferirMonto(20000, *cuentas.at(1));
    for(const auto& c: cuentas){
        c->aplicarMensualidad();
        std::cout<<c->getSaldo()<<std::endl;
    }

    // hacer el delete manual
    for(const auto& c: cuentas){
        delete c;
    }
    cuentas.clear();

    
    return 0;
}