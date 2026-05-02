#include <iostream>
#include <thread>

void saludar() {
    std::cout<<"Hola con hilos"<<std::endl;
}
// saludar n numero de veces
void saludar2(std::string nombre, int veces){
    for(int i=0; i<veces;++i){
        std::cout<<"Hola, "<<nombre<<std::endl;
    }
}

int main() {
    /*
    std::thread t(saludar);
    t.join();
    std::cout<<"Hilo terminado"<<std::endl;
    */
    // pasarle argumentos al hilo
    std::thread t(saludar2, "Nicolas", 3);
    t.join();  // hilos copian argumento por defecto


    return 0;
}