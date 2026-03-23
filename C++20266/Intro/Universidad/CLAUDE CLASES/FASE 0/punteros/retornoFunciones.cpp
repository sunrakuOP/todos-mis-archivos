#include <iostream>

// ✅ seguro — retorna copia, el 42 se copia antes de que x muera
int uno() {
    int x = 42;
    return x;
}

// ✅ seguro — x vive en heap, tú controlas cuándo muere
int* dos() {
    int* x = new int(42);
    return x;
    // ojo: quien llame debe hacer delete
}

// ❌ peligroso — x muere al terminar, referencia queda colgante
int& tres() {
    int x = 42;
    return x;
}

// ✅ versión correcta de tres usando static
int& tres_bien() {
    static int x = 42;
    return x;  // x nunca muere
}

int main() {
    int a = uno();
    std::cout << a << std::endl;  // 42 ✅

    int* b = dos();
    std::cout << *b << std::endl; // 42 ✅
    delete b;                     // liberas el heap
    b = nullptr;

    int& c = tres_bien();
    std::cout << c << std::endl;  // 42 ✅

    return 0;
}