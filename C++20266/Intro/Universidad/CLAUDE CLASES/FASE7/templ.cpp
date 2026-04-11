#include <iostream>

template <typename T, typename U>
class Par {
    T primero; 
    U segundo;
};

int main() {
    Par<int, std::string> p1(23, "hola");

    return 0;
}