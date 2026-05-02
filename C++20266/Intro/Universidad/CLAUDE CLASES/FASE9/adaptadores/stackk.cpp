#include <iostream>
#include <stack>
#include <string>

class Navegador{
protected:
    std::stack<std::string> historial;
    std::stack<std::string> siguiente;
public:
    Navegador() = default;

    Navegador& visitar(const std::string& url) {
        while(!siguiente.empty()) {
            siguiente.pop();
        }
        historial.push(url); // agrego sitios a historial
        return *this;
    }

    std::string pagActual() const { return historial.top(); }

    Navegador& atras() {
        if(historial.empty()) {
            std::cout<<"No hay historial"<<std::endl;
            return *this;
        }
        siguiente.push(historial.top());
        historial.pop();
        return *this;
    }

    Navegador& adelante() {
        if(siguiente.empty()) {
            std::cout<<"No hay paginas adelante"<<std::endl;
            return *this;
        }
        historial.push(siguiente.top());
        siguiente.pop();
        return *this;
    }
    // hacer una copia del stack historial para recorrer ese y borrarlo
    void mostrarHistorial() {
        std::stack<std::string> copia = historial;
        std::cout<<"Historial: "<<std::endl;
        while(!copia.empty()) {
            std::cout<<copia.top();
            copia.pop();
        }
    }
};


int main() {
    Navegador nav;

    nav.visitar("google.com")
       .visitar("youtube.com")
       .visitar("twitter.com");

    std::cout << "Actual: " << nav.pagActual() << std::endl; // twitter

    nav.atras();
    std::cout << "Actual: " << nav.pagActual() << std::endl; // youtube

    nav.atras();
    std::cout << "Actual: " << nav.pagActual() << std::endl; // google

    nav.adelante();
    std::cout << "Actual: " << nav.pagActual() << std::endl; // youtube

    nav.visitar("github.com"); // borra el siguiente
    nav.adelante(); // no hay páginas adelante

    nav.mostrarHistorial();

    return 0;
}
