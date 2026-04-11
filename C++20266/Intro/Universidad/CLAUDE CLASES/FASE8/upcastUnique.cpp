#include <iostream>
#include <vector>
#include <memory>

class Pago {
protected:
    double monto;
public:
    Pago(double m): monto(m) {} // necesario para las clases derivadas
    virtual ~Pago() = default;
    virtual void procesar() = 0; // metodo virtual
    virtual std::string tipo() = 0;

    double getMonto() const { return monto; }
};

class PagoTarjeta: public Pago {
protected:  
    int numTarjeta;
public: 
    PagoTarjeta(double m, int nt): Pago(m), numTarjeta(nt) {}

    void procesar() override {
        std::cout<<"Pago con tarjeta "<<numTarjeta<<" por "<<monto <<std::endl;
    } 

    std::string tipo() override { return "Tarjeta"; }

};
class PagoEfectivo: public Pago {
protected:
    int numBilletes;
public:
    PagoEfectivo(double m, int nb): Pago(m), numBilletes(nb) {}

    void procesar() override {
        std::cout<<"Pago en efectivo con "<<numBilletes<<" billetes por "
            <<monto<<" total"<<std::endl;
    }

    std::string tipo() override { return "Efectivo"; }

};
// usar enum para hacer upcast en unique
enum class TipoPago {
    pagoEfectivo,
    pagoTarjeta
};
class Caja {
protected:
    std::vector<std::unique_ptr <Pago>> pagos;
public:
    // ningun atributo, no creo constructor

    // metodo para agregar pagos al vector usando 
    Caja& agregarPago(TipoPago tp, double m, int extra) {
        if(tp == TipoPago::pagoEfectivo) {
            pagos.push_back(std::make_unique<PagoEfectivo>(m,extra));
        } else if (tp == TipoPago::pagoTarjeta) {
            pagos.push_back(std::make_unique<PagoTarjeta>(m,extra));
        }
        return *this;
    }

    // si tengo pago externo que no sea unique
    Caja& agregarPagoOtro(const Pago& pago) {
        // tengo que copiarlo al heap para meterlo al vector

        pagos.push_back(std::make_unique<Pago>(pago));


    }

    void procesarTodos() {
        for(const auto& p: pagos) {
            p->tipo();
            p->procesar();  // imprime el tipo de pago por objeto
        }
    }

    double totalRecaudado() {
        double suma = 0;
        for(const auto& p: pagos) {
            suma += p->getMonto();
        }
        std::cout<<"Total recaudado: "<<suma<<std::endl;
        return suma;
    }

    // practicar con std::move y .get
    // recordar que unique_ptr solo puede apuntar a 1 obj a la vez
    // debe recibir un unique ptr y agregarlp
    Caja& agregarExterno(std::unique_ptr<Pago> pago) {
        // agregar un pago ya creado al vector
        // no necesito comparar si ya esta porque unique no lo permite
        // si agrego un vector externo el puntero apuntaria a nullptr despues de moverlo
        // no se puede tener objeto en dos lugares con unique
        pagos.push_back(std::move(pago));
    }

    // si quiero agregar un objeto no creado con unique
    Caja& agregarExternOtro(const Pago& pago) {
        // usar dinamic cast para saber que tipo es
        if(const PagoTarjeta* t = dynamic_cast<const PagoTarjeta*>(&pago)) {
            pagos.push_back(std::make_unique<PagoTarjeta>(*t));
        } else if (const PagoEfectivo* e = dynamic_cast<const PagoEfectivo*>(&pago)){
            pagos.push_back(std::make_unique<PagoEfectivo>(*e));
        }
        return *this;
    } 

};

int main() {
    // debo construir la caja aunque no tenga constructor
    Caja caja;

    caja.agregarPago(TipoPago::pagoEfectivo, 1000, 10)
        .agregarPago(TipoPago::pagoEfectivo, 50000, 3)
        .agregarPago(TipoPago::pagoTarjeta, 30000, 2143)
        .agregarPago(TipoPago::pagoTarjeta, 3240, 4489);
        // agrego pagos al vector
    
    caja.procesarTodos();
    caja.totalRecaudado();

    return 0;
}