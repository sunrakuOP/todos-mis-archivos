#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Lista {
protected:  
    std::vector<std::string> tareas;
public:
    Lista() = default;

    Lista& agregarTarea(){
        std::string tarea;
        std::cout<<"Digite tarea: "<<std::endl; // ignore para eliminar el buffer siempre antes del getline
        std::cin.ignore();
        std::getline(std::cin, tarea);
        for(const auto& t: tareas){
            if(t == tarea){
                std::cout<<"Tarea ya agregada.."<<std::endl;
                return *this;
            }
        }
        tareas.push_back(tarea);
        return *this;
    }

    void mostrar() const {
        if(tareas.empty()){
            std::cout<<"Vector vacio..."<<std::endl;
            return;
        }
        std::cout<<"Lista de tareas: "<<std::endl;
        for(const auto& t: tareas){
            std::cout<<t<<std::endl;
        }
    }

    Lista& eliminarTarea(const std::string& tarea){
        auto it = std::find(tareas.begin(), tareas.end(), tarea);
        if(it == tareas.end()){
            std::cout<<"Tarea no encontrada"<<std::endl;
            return *this;
        }
        tareas.erase(it);
        return *this;
    }

    void ejecutar() {
        int opcion;
        do {
            std::cout<<"======MENU======"<<std::endl;
            std::cout<<"0. Salir..."<<std::endl;
            std::cout<<"1. Agregar tarea"<<std::endl;
            std::cout<<"2. Eliminar tarea"<<std::endl;
            std::cout<<"3. Mostrar tareas"<<std::endl;
            std::cout<<"Digite una opcion: "<<std::endl;
            std::cin>>opcion;


            switch (opcion)
            {
            case 0:
                std::cout<<"Saliendo..."<<std::endl;
                break;
            case 1:
                agregarTarea();
                break;
            case 2: {
                std::string tarea;
                std::cout<<"Digite tarea a eliminar: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, tarea);
                eliminarTarea(tarea);
                break;
                }
            case 3:
                mostrar();
                break;

            default:
                std::cout<<"Opcion invalida.."<<std::endl;
                break;
            }
        } while(opcion != 0);
    }

};

int main() {
    Lista l;
    l.ejecutar();

    return 0;
}