#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Contendedor {
protected:
    std::vector<int> numeros;
public:
    Contendedor() = default;

    Contendedor& agregarNumero(int numero) {
        numeros.push_back(numero);
        return *this;
    }
    Contendedor& cargar(std::vector<int> vectCargar) {
        numeros = vectCargar;
        return *this;
    }
    // de mayor a contar cuantos, se hace con lambdas

    int cuantosTiene(int num) {
        // count devuelve un entero
        int cuenta = std::count(numeros.begin(), numeros.end(), num);
        return cuenta;
    }

    int suma() {
        // usar accomulate pero usando #include <numeric>
        int suma = std::accumulate(numeros.begin(), numeros.end(), 0);
        return suma;
    }

    double promedio() {
        if(numeros.empty()){
            std::cout<<"Vector vacio.."<<std::endl;
            return 0;
        }
        double prom = suma()/(double)numeros.size();
        return prom;
    }

    // ahora encontrar mayor/menor elemento
    int mayor() {
        if(numeros.empty()){
            std::cout<<"No hay elementos"<<std::endl;
            return 0;
        }
        auto it = std::max_element(numeros.begin(), numeros.end());
        return *it;
    } 
    int menor() {
        if(numeros.empty()){
            std::cout<<"No hay elementos"<<std::endl;
            return 0;
        }
        auto it = std::min_element(numeros.begin(), numeros.end());
        return *it;
    }

    Contendedor& menorAmayor() {
        if(numeros.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return *this;
        }
        std::sort(numeros.begin(), numeros.end(), std::greater<int>());
        return *this;
    }

    Contendedor& invertir() {
        if(numeros.empty()){
            std::cout<<"Vector vacio"<<std::endl;
            return *this;
        }
        std::reverse(numeros.begin(), numeros.end());
        return *this;
    }


    void mostrar() const {
        if(numeros.empty()){
            std::cout<<"Vector vacio.."<<std::endl;
            return;
        }
        std::cout<<"Numeros: "<<std::endl;
        for(const auto& n: numeros){
            std::cout<<n<<", ";
        }
        std::cout<<std::endl;
    }


};

int main() {
    Contendedor c;

    c.cargar({3, 1, 4, 1, 5, 9, 2, 6, 5, 3});
    c.mostrar();

    std::cout << "Suma: " << c.suma() << std::endl;
    std::cout << "Promedio: " << c.promedio() << std::endl;
    std::cout << "Mayor: " << c.mayor() << std::endl;
    std::cout << "Menor: " << c.menor() << std::endl;
    std::cout << "Cuantos 5: " << c.cuantosTiene(5) << std::endl;

    c.invertir();
    c.mostrar();

    return 0;
}
