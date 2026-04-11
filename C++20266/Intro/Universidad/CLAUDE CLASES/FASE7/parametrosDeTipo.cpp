#include <iostream>

template <typename T, int N> // Tipo dato variable es T, de N enteros
// toca definirlo en el template
class Arreglo {
protected:
    T datos [N];
public:
    T& operator[](int i) { 
        return datos[i];
    }
    int tamanio() {
        return N;
    }
};

int main() {
    Arreglo<int, 5> arr1;
    Arreglo<double, 25> arr2;

    return 0;
} 