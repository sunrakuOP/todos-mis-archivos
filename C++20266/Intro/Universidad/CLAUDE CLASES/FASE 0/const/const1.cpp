#include <iostream>
#include <vector>

int main() {
  // punteros
    // puntero a const int (no puedo cambiar el valor de variable) 
    int x = 10;
    const int *p = &x;  // p es puntero a x (pero no puedo alterar valor de x despues)

    // const puntero a variable (no puedo cambiar su direccion)
    int * const p = &x; // p es puntero a x con direccion de memoria constante

    // cont puntero a const variable
    const int * const p = &x; // ni el valor ni la referencia pueden cambiar

    // referencias
    int &ref = x;  // ref es referencia a x (misma direccion, mismo nombre a misma cosa)
    const int &ref = x; // referencia no puede cambiar

  return 0;
}