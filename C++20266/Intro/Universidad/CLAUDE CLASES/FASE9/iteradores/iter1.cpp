#include <iostream>
#include <vector>




int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // imprimir el vector primero
    for(const auto n: numeros) {
        std::cout<<n<<", ";
    }
    std::cout<<std::endl;
        
    // con iteradores motrar cada elemento duplicado
    for(auto it = numeros.begin(); it != numeros.end(); ++it) {
        *it *= 2; // modificar le vector elemento por elemento
    }

    // motrar el vector ya modificado
    for(const auto n: numeros) {
        std::cout<<n<<", ";
    }
    std::cout<<std::endl;

    // revertir orden del vector usando RBEGIN Y REND
    std::cout<<"Orden inverso del vector: "<<std::endl;
    for(auto it = numeros.rbegin(); it != numeros.rend(); it++) {
        std::cout<<*it<<", ";
    } 

    


    return 0;
}