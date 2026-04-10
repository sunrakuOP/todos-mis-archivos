#include<iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

class Contacto {
protected:
    std::string nombreContacto;
    int numeroTel;
    std::string email;
public:
    Contacto(const std::string& nc, int nt, const std::string& e):
        nombreContacto(std::move(nc)), numeroTel(nt), email(std::move(e)) {}

    const std::string& getNom() const { return nombreContacto;}
    const int getNum() const { return numeroTel; }
    const std::string& getEmail() const { return email; }

    void infoConct() const {
        std::cout<<"Nombre: "<<nombreContacto<<", numero: "
            <<numeroTel<<", email: "<<email<<std::endl;
    }

    bool operator==(const Contacto& otro) const {
        return (nombreContacto == otro.nombreContacto && numeroTel == otro.numeroTel);
    }

    friend std::ostream& operator<<(std::ostream& os, const Contacto& obj) {
        os<<"Nombre: "<<obj.getNom()<<", numero: "<<obj.getNum()
            <<", email: "<<obj.getEmail()<<"\n";
        return os;
    }
};

class Grupo {
protected:
    std::string nombreGrupo;
    std::vector<std::shared_ptr<Contacto>> contactos;
public:
    Grupo(const std::string& ng): nombreGrupo(std::move(ng)) {}

    Grupo& agregarContactoNuevo(const std::string& nc, int nt, const std::string& e) {
        for(const auto& c: contactos) {
            if(c->getNom() == nc && c->getNum() == nt) {
                std::cout<<"Contacto ya agregado.."<<std::endl;
                return *this;
            }
        }
        contactos.push_back(std::make_shared<Contacto>(nc,nt,e));
        return *this;
    }

    Grupo& agregarContactoExistente(std::shared_ptr<Contacto> contacto) {
        for(const auto& c: contactos) {
            if(c == contacto) {
                std::cout<<"Contacto ya existente.."<<std::endl;
                return *this;
            } else if(c->getNum() == contacto->getNum()) {
                std::cout<<"Numero ya agregado.."<<std::endl;
                return *this;
            }
        }
        contactos.push_back(contacto);
        return *this;
    }

    Contacto* buscarNombre(const std::string& nombre) {
        if(contactos.empty()) {
            std::cout<<"Grupo vacio.."<<std::endl;
            return nullptr;
        }
        for(const auto& c: contactos) {
            if(c->getNom().find(nombre) != std::string::npos) {
                c->infoConct();
                return c.get();
            }
        }
        std::cout<<"Contacto no encontrado.."<<std::endl;
        return nullptr;
    }

    Grupo& eliminarContacto(int num) {
        if(contactos.empty()) {
            std::cout<<"Grupo vacio"<<std::endl;
            return *this;
        }
        for(auto it = contactos.begin(); it != contactos.end(); ++it) {
            if((*it)->getNum() == num) {
                contactos.erase(it);
                std::cout<<"Contacto eliminado.."<<std::endl;
                return *this;
            }
        }
        std::cout<<"Contacto no encontrado.."<<std::endl;
        return *this;
    }

    Grupo copiarGrupo(const Grupo& grupo, const std::string& nuevoNombre) {
        Grupo nuevo(nuevoNombre);
        if(grupo.contactos.empty()) {
            std::cout<<"Grupo vacio"<<std::endl;
            return nuevo;
        }
        for(const auto& c: grupo.contactos) {
            nuevo.contactos.push_back(std::make_shared<Contacto>(*c));
        }
        return nuevo;
    }

    void mostrarOrdenado() const {
        if(contactos.empty()) {
            std::cout<<"Grupo vacio.."<<std::endl;
            return;
        }
        std::vector<std::shared_ptr<Contacto>> copia = contactos;
        std::sort(copia.begin(), copia.end(), [](const auto& a, const auto& b){
            return a->getNom() < b->getNom();
        });
        std::cout<<"Grupo ["<<nombreGrupo<<"] ordenado:"<<std::endl;
        for(const auto& c: copia) {
            std::cout<<*c;
        }
    }

    std::shared_ptr<Contacto>& operator[](int i) {
        return contactos.at(i);
    }

    Grupo operator+(const Grupo& otro) const {
        Grupo fusionado(nombreGrupo + "+" + otro.nombreGrupo);
        for(const auto& c: contactos) {
            fusionado.contactos.push_back(c);
        }
        for(const auto& c: otro.contactos) {
            bool duplicado = false;
            for(const auto& f: fusionado.contactos) {
                if(f->getNum() == c->getNum()) {
                    duplicado = true;
                    break;
                }
            }
            if(!duplicado) fusionado.contactos.push_back(c);
        }
        return fusionado;
    }

    friend std::ostream& operator<<(std::ostream& os, const Grupo& g) {
        os<<"Grupo: "<<g.nombreGrupo<<"\n";
        if(g.contactos.empty()) {
            os<<"  (sin contactos)\n";
            return os;
        }
        for(const auto& c: g.contactos) {
            os<<"  "<<*c;
        }
        return os;
    }

    void menu() {
        int op;
        std::string nombre, email;
        int num;
        do {
            std::cout<<"\n--- Grupo: "<<nombreGrupo<<" ---\n";
            std::cout<<"1. Agregar contacto\n";
            std::cout<<"2. Buscar por nombre\n";
            std::cout<<"3. Eliminar contacto\n";
            std::cout<<"4. Mostrar ordenado\n";
            std::cout<<"5. Mostrar grupo\n";
            std::cout<<"0. Salir\n";
            std::cout<<"Opcion: ";
            std::cin>>op;
            switch(op) {
                case 1:
                    std::cout<<"Nombre: "; std::cin>>nombre;
                    std::cout<<"Numero: "; std::cin>>num;
                    std::cout<<"Email: "; std::cin>>email;
                    agregarContactoNuevo(nombre, num, email);
                    break;
                case 2:
                    std::cout<<"Buscar (parcial): "; std::cin>>nombre;
                    buscarNombre(nombre);
                    break;
                case 3:
                    std::cout<<"Numero a eliminar: "; std::cin>>num;
                    eliminarContacto(num);
                    break;
                case 4:
                    mostrarOrdenado();
                    break;
                case 5:
                    std::cout<<*this;
                    break;
                case 0:
                    std::cout<<"Saliendo.."<<std::endl;
                    break;
                default:
                    std::cout<<"Opcion invalida"<<std::endl;
            }
        } while(op != 0);
    }
};


int main() {
    Grupo familia("Familia");
    Grupo trabajo("Trabajo");

    familia.agregarContactoNuevo("Carlos", 111, "carlos@mail.com")
           .agregarContactoNuevo("Ana", 222, "ana@mail.com")
           .agregarContactoNuevo("Maria", 333, "maria@mail.com");

    trabajo.agregarContactoNuevo("Juan", 444, "juan@mail.com")
           .agregarContactoNuevo("Ana", 222, "ana@mail.com"); // mismo numero — duplicado

    // operator<<
    std::cout<<familia;
    std::cout<<trabajo;

    // busqueda parcial
    familia.buscarNombre("Car"); // encuentra Carlos

    // ordenado alfabéticamente
    familia.mostrarOrdenado();

    // operator[]
    std::cout<<"Primero del grupo: "<<*familia[0];

    // operator+ fusión
    Grupo fusion = familia + trabajo;
    std::cout<<fusion;

    // deep copy
    Grupo copia = familia.copiarGrupo(familia, "FamiliaCopia");
    std::cout<<copia;

    // menú interactivo
    // familia.menu();

    return 0;
}
