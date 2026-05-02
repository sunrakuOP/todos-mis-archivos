#include <iostream>
#include <vector>
#include <string>

enum Prioridad {
    /* 
    enum muestra prioridad por orden de definicion
    */
    baja,   // 0
    media,  // 1
    alta,   // 2
    critica // 3
};

class Tarea {
protected:
    std::string nombre;
    Prioridad prioridad;
    bool completada;
public:
    Tarea(const std::string& no, Prioridad p): nombre(std::move(no)), prioridad(p), completada(false) {}

    const std::string& getNombre() const { return nombre; }
    const Prioridad& getPrioridad() const { return prioridad; }
    bool getCompletada() { return completada; }
    
    Tarea& completarTarea() {
        if(!completada){
            completada = true;
            std::cout<<"Tarea ya completada..."<<std::endl;
        }
        return *this;
    }

    void info() const {
        std::cout<<nombre<<", "<<prioridad<<", "<<std::endl;
        if(completada){
            std::cout<<"(Completada)"<<std::endl;
        } else{
            std::cout<<"(Incompleta)"<<std::endl;
        }
    }
};

class Contenedor {
protected:
    std::vector<Tarea*> tareas;
public:
    Contenedor() = default;

    ~Contenedor() {
        for(const auto& t: tareas){
            delete t;
        }
        tareas.clear();
    }

    Contenedor& agregarTarea(const std::string& n, Prioridad p) {
        for(const auto& t: tareas) {
            if(t->getNombre() == n) {
                std::cout<<"Tarea ya agregada.."<<std::endl;
                return  *this;
            }
        }
        tareas.push_back(new Tarea(n,p));
        return *this;
    }

    Contenedor& marcarCompletada(const std::string n){
        for(const auto& t: tareas){
            if(t->getNombre() == n){
                t->completarTarea();
                return *this;
            }
        }
        std::cout<<"No se encontro la tarea..."<<std::endl;
        return *this;
    } 

    void mostrarPrioridad(Prioridad p){
        if(tareas.empty()){
            std::cout<<"Lista de tareas vacia"<<std::endl;
            return;
        }
        for(const auto& t: tareas){
            if(t->getPrioridad() == p){
                t->info();
            }
        }
    }

    void mostrarTodas() const {
        if(tareas.empty()) {
            std::cout<<"La lista de tareas esta vacia"<<std::endl;
            return;
        }
        for(const auto& t: tareas){
            t->info();
        }
    }

    void mostrarPendientes() const {
       if(tareas.empty()) {
            std::cout<<"La lista de tareas esta vacia"<<std::endl;
            return;
        }
        for(const auto& t: tareas) {
            if(!t->getCompletada()){
                t->info();
            }
        } 
    } 


    Contenedor& eliminarCompletadas() {
        if(tareas.empty()){
            return *this;
        }
        for(auto it = tareas.begin(); it != tareas.end();){
            if((*it)->getCompletada()){
                delete *it;
                it = tareas.erase(it);
            } else {
                ++it;
            }
        }
        return *this;
    }

    /*
    Menú: agregar tarea, marcar como completada, mostrar todas, mostrar pendientes, 
    mostrar por prioridad, eliminar completadas
    */
    void menu() {
        int opcion; 
        do {
            std::cout<<"=======MENU========"<<std::endl;
            std::cout<<"1. Agregar Tarea"<<std::endl;
            std::cout<<"2. Marcar completada"<<std::endl;
            std::cout<<"3. Mostrar todas"<<std::endl;
            std::cout<<"4. Mostrar pendientes"<<std::endl;
            std::cout<<"5. Mostrar prioridad"<<std::endl;
            std::cout<<"6. Eliminar completadas"<<std::endl;
            std::cout<<"Digite una opcion: "<<std::endl;
            std::cin>>opcion;

            switch (opcion)
            {
            case 1: {
                std::string n;
                int pInt;
                std::cout<<"Digite el nombre: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, n);
                std::cout<<"Digite prioridad: "<<std::endl;
                std::cin>>pInt;
                Prioridad p = static_cast<Prioridad>(pInt);

                agregarTarea(n,p);
                break;
            }
            case 2: {
                std::string n;
                std::cout<<"Digite nombre del usuario: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, n);
                marcarCompletada(n);
                break;
            }
            case 3: {
                mostrarTodas();
                break;
            }
            case 4: {
                mostrarPendientes();
                break;
            }
            case 5: {
                int pInt;
                std::cout<<"Digite prioridad como entero (0-3): "<<std::endl;
                std::cin>>pInt;
                Prioridad p = static_cast<Prioridad>(pInt);
                mostrarPrioridad(p);
                break;
            }
            case 6: {
                eliminarCompletadas();
                break;
            }
         
            default:
                std::cout<<"Opcion invalida"<<std::endl;
                break;
            }



        } while(opcion != 0);
    }
};


int main() {
    Contenedor c;
    c.menu();

    return 0;
}