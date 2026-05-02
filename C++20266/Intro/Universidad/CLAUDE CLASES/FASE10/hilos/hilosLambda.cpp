#include <iostream>
#include <thread>

int main() {
    std::thread t([]() {
        std::cout<<"Hola desde lambda: ";
    }); 
    t.join();
    // captura por valor (default)
    int x=10;
    std::thread t2([x]() {
        std::cout<<"Captura: "<<x<<std::endl;
    });
    t2.join();
    // captura por referencia
    std::thread t3([&x]() {
        x *= 2; // modifica realmente el valor que se pase
    });
    t3.join();

    return 0;
}