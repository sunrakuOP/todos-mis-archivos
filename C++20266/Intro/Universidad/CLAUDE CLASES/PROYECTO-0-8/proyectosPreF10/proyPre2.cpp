#include <iostream>
#include <string>
#include <map>

/*
Proyecto B: Inventario de componentes electrónicos (medio-fácil)
Practica: map, búsqueda, operadores, menú robusto
Gestionar un inventario para tu kit de electrónica:

Componente: nombre, categoría, cantidad, precio unitario
Almacenar en map<string, Componente> (nombre → componente)
Menú: agregar, buscar por nombre, listar por categoría, mostrar con stock bajo (< 5), calcular valor total del inventario, eliminar
operator<< para imprimir componentes
Validar entrada (no permitir cantidad negativa, precio cero)
*/
enum class Categoria{
    resistencia,
    capacitador,
    transistor,
    led,
    sensor, 
    microcontrolador
};

class Componente {
protected:
    Categoria categoria;
    int cantidad;
    double precio;
public:
    Componente() = default;

    Componente(Categoria c, int ct, double p):
        categoria(c), cantidad(ct), precio(p) {}

    Categoria getCategoria() const { return categoria;}
    int getCantidad() const { return cantidad; }
    double getPrecio() const { return precio; }

    // Enum no se puede usar con cout directo

    std::string categoriaTexto() const {
        switch (categoria)
        {
        case Categoria::resistencia: return "Resistencia";
        case Categoria::capacitador: return "Capacitador";
        case Categoria::transistor: return "Transistor";
        case Categoria::led: return "Led";
        case Categoria::sensor: return "Sensor";
        case Categoria::microcontrolador: return "Microcontrolador";
        
        default:
            return "No catalogado";
        }
    }

    void info() const {
        std::cout<<"Categoria: "<<categoriaTexto()<<", cantidad: "
            <<cantidad<<", precio: "<<precio<<std::endl;
    }
};

class Tienda {
protected:
    std::map<std::string, Componente> componentes;
public:
    Tienda() = default;

    Tienda& agregar(const std::string& n, Categoria c, int ct, double p) {
        // agregar al map con insert ignora si ya esta, pero igual busquemos
        auto it = componentes.find(n);
        if(it != componentes.end()){
            std::cout<<"Producto ya agregado..."<<std::endl;
            return *this;
        }
        componentes.insert({n, Componente(c,ct,p)});
        return *this;
    }

    Componente* buscarPorNombre(const std::string& nombre){
        auto it = componentes.find(nombre);
        if(it == componentes.end()){
            std::cout<<"Componente no encontrado.."<<std::endl;
            return nullptr;
        }
        componentes[nombre].info();
        return &it->second; // retorna puntero del Componente
    }

    void listarPorCategoria(Categoria cat) {
        if(componentes.empty()){
            std::cout<<"Lista vacia"<<std::endl;
            return;
        }
        for(auto it = componentes.begin(); it != componentes.end(); ++it) {
            if(it->second.getCategoria() == cat) {
                it->second.info();
            }
        }
    }

    void mostrarConStockBajo() const {
        if(componentes.empty()){
            std::cout<<"Lista vacia"<<std::endl;
        }
        int cuenta = 0;
        for(auto it = componentes.begin(); it != componentes.end(); ++it){
            if(it->second.getCantidad() < 5) {
                cuenta++;
                std::cout<<it->first<<" con stock bajo: "<<it->second.getCantidad()<<std::endl;
            }
        } if(cuenta == 0) {
            std::cout<<"Ningun componente con stock bajo"<<std::endl;
        }
    }

    double valorTotal() const {
        if(componentes.empty()){
            std::cout<<"Inventario vacio, sin precio..."<<std::endl;
            return 0.0;
        }
        double sumatoria = 0;
        for(auto it = componentes.begin(); it != componentes.end(); ++it){
            sumatoria += it->second.getPrecio() * it->second.getCantidad(); 
            // multiplica precio por cantidad
        }
        std::cout<<"Valor total del inventario: "<<sumatoria<<std::endl;
        return sumatoria;
    }

    Tienda& eliminarComponente(const std::string& nombre){
        if(componentes.empty()){
            std::cout<<"Componente no encontrado"<<std::endl;
            return *this;
        }
        for(auto it = componentes.begin(); it != componentes.end();){
            if(nombre == it->first) {
                it = componentes.erase(it);
                // asigna al siguiente valido
            } else {
                ++it;
            }
        }
        return *this;
    }

    void menu() {
        int opcion;
        do {
            std::cout<<"========MENU========"<<std::endl;
            std::cout<<"1. Agregar componente"<<std::endl;
            std::cout<<"2. Buscar por nombre"<<std::endl;
            std::cout<<"3. Listar por categoria"<<std::endl;
            std::cout<<"4. Mostrar con stock bajo"<<std::endl;
            std::cout<<"5. Calcular total del inventario"<<std::endl;
            std::cout<<"6. Eliminar componente"<<std::endl;
            std::cout<<"Digite una opcion: "<<std::endl;
            std::cin>>opcion;

            switch (opcion)
            {
            case 1: {
                std::string n;
                int catInt, cant;
                double pre;
                std::cout<<"Digite nombre: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, n);
                std::cout << "0=Resistencia, 1=Capacitador, 2=Transistor, 3=Led, 4=Sensor, 5=Microcontrolador: "<<std::endl;
                std::cout<<"Digite categoria: "<<std::endl;
                std::cin>>catInt;
                std::cout<<"Digite cantidad: "<<std::endl;
                std::cin>>cant;
                std::cout<<"Digite precio: "<<std::endl;
                std::cin>>pre;

                Categoria cat = static_cast<Categoria>(catInt);
                agregar(n,cat,cant,pre);
                break;
            }
            case 2: {
                std::string n;
                std::cout<<"Digite el nombre a buscar: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, n);
                buscarPorNombre(n);
                break;
            }
            case 3: {
                int catInt;
                std::cout << "0=Resistencia, 1=Capacitador, 2=Transistor, 3=Led, 4=Sensor, 5=Microcontrolador: "<<std::endl;
                std::cout<<"Digite categoria: "<<std::endl;
                std::cin>>catInt;

                Categoria cat = static_cast<Categoria>(catInt);
                listarPorCategoria(cat);
                break;
            }
            case 4: {
                mostrarConStockBajo();
                break;
            }
            case 5: {
                valorTotal();
                break;
            }
            case 6: {
                std::string nombre;
                std::cout<<"Digite el nombre a eliminar: "<<std::endl;
                std::cin.ignore();
                std::getline(std::cin, nombre);
                
                eliminarComponente(nombre);
                break;
            }        
            default:
                break;
            }
        } while(opcion != 0);
    } 
    
};

int main() {
    Tienda t;

    t.menu();


    return 0;
}