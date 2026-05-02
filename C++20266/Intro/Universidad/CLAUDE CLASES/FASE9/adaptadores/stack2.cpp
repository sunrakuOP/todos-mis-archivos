#include <iostream>
#include <stack>
#include <string>

class Editor {
protected:
    std::stack<std::string> acciones;
    std::stack<std::string> papelera;
public:
    Editor() = default;

    // recordar que stack es invertido, es como apilar cosas 
    // lo primero que entra es lo ultimo que sale

    Editor& escribir(const std::string& texto) {
        acciones.push(texto);
        return *this;
    }
    Editor& deshacer() {
        papelera.push(acciones.top());
        acciones.pop();
        return *this;
    }
    Editor& rehacer(){
        acciones.push(papelera.top());
        papelera.pop();
        return *this;
    }
    std::string textoActual() { return acciones.top();} 
    
    void mostrarTexto() {
        // hacerle copia porque no hay forma de recorrerlo
        std::stack<std::string> copia = acciones;
        std::cout<<"Texto: "<<std::endl;
        while(!copia.empty()) {
            std::cout<<copia.top()<<" ";
            copia.pop();
        }
        std::cout<<std::endl;

    } 

    Editor& vaciarPapelera() {
        while(!papelera.empty()){
            papelera.pop();
        }
        return *this;
    }
};


int main() {
    Editor ed;

    ed.escribir("Hola")
      .escribir("mundo")
      .escribir("como estas");

    ed.mostrarTexto();
    std::cout << "Actual: " << ed.textoActual() << std::endl;

    ed.deshacer();
    std::cout << "Actual: " << ed.textoActual() << std::endl;

    ed.rehacer();
    std::cout << "Actual: " << ed.textoActual() << std::endl;

    return 0;
}
