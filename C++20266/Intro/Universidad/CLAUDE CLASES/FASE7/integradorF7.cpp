#include <iostream>

template <typename T, typename P>
class Par {
protected:
    T primero; // tipo T
    P segundo; // tipo P
public:
    Par(T p, P s): primero(p), segundo(s) {}

    friend std::ostream& operator<<(std::ostream& os, const Par& obj) {
        os<<"("<< obj.primero <<","<<obj.segundo<<")\n";
        return os;
    }

    bool operator==(const Par& otro) {
        return (primero == otro.primero && segundo == otro.segundo);
    }
    bool operator!=(const Par& otro) {
        return !(*this == otro);
    }

    Par<P,T> intercambiar() { // intercambiar los tipos de datos
        return Par<P,T> (segundo, primero);
    }

    T mayorQue(T a, T b);
};


int main() {
    Par<int, int> p1(2,4);
    std::cout<<p1;

    return 0;
}