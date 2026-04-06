#include <iostream>
#include <cmath>

// teoria de struct en c++
// es lo mimso que clases solo que publico por defecto, no private

struct Punto { // no pongo publico porque ya es publico por defecto
    int xp, yp;
};

// puedo tener constructores 
struct PuntoConstr {
    double x, y;

    PuntoConstr(double x1, double y1): x(x1), y(y1) {}

    // y metodos propios, pero todo publico
    double distancia() {
        return sqrt(x*x + y*y);
    }
};




int main() {
    // puedo acceder a sus atributos de forma publica
    // Punto p;
    // p.xp;
    // p.yp;

    PuntoConstr p2(2,2);
    std::cout<<p2.distancia()<<std::endl;

    return 0;
}