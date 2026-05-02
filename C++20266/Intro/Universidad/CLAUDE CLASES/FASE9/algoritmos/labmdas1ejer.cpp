#include <iostream>
#include <vector>
#include <algorithm>

// no hay que aprenderse de memoria bien los algoritmos pero hay que entender bien la sintaxis

class Caja {
protected:
    std::vector<int> numeros;
public:
    Caja() = default;

    Caja& cargar(const std::vector<int>& vectCargar) {
        numeros = vectCargar;
        return *this;
    }
    // contar mayores a usando lambdas
    int contarMayorA(int numero){
        int cuenta = std::count_if(numeros.begin(), numeros.end(), [numero](int x){ return x > numero; });
        return cuenta;
    } // dentro de los [ ] para usar variable dentro del scope

    Caja& eliminarNegativos() {
        // con remove reorganizar vector (basura al final) y apunta al 1er elemnto a eliminar
        auto it = std::remove_if(numeros.begin(), numeros.end(), [](int x){return x < 0; });
        // eliminar con erase desde el it hasta el final
        numeros.erase(it, numeros.end());
        return *this;
    }
    // si todos son positivos
    bool todosPositivos() {
        return std::all_of(numeros.begin(), numeros.end(),[](int x){ return x > 0; });
    }

    // alguno es mayor al valor dado ??
    bool mayorA(int num){
        return std::any_of(numeros.begin(), numeros.end(), [num](int x){ return x > num;});
    }

    // alterar cada elemento del vector (int & x)
    Caja& duplicarTodos() {
        std::for_each(numeros.begin(), numeros.end(), [](int& x){return x*= 2; });
        return *this;
    }
};


int main() {
    Caja c;

    c.cargar({3, -1, 7, -5, 2, 8, -3, 4});
    
    std::cout << "Mayores a 5: " << c.contarMayorA(5) << std::endl; // 2
    std::cout << "Todos positivos: " << c.todosPositivos() << std::endl; // 0
    std::cout << "Hay mayor a 6: " << c.mayorA(6) << std::endl; // 1

    c.eliminarNegativos();
    std::cout << "Todos positivos: " << c.todosPositivos() << std::endl; // 1

    c.duplicarTodos();
    // mostrar

    return 0;
}
