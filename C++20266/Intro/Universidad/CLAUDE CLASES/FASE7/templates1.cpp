#include <iostream>

template <typename T>
T mayor(T a, T b) {
    return (a>b) ? a:b;
}

// puedo usar T con cualquier tipo de dato
int main() {
    std::cout<<mayor(2,4)<<std::endl;  // tipo int

    std::cout<<mayor(4.5, 3.4)<<std::endl;  // tipo double

    std::cout<< mayor("hola", "chaosss") <<std::endl;


    return 0;
}