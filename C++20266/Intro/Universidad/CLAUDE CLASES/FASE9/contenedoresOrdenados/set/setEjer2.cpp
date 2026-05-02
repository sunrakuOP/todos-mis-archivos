#include <iostream>
#include <vector>
#include <set>
#include <string>

int main() {
  std::string nombre;
  std::set<std::string> nombres;
  do {
    std::cout<<"Digite nombres (fin para acabar): "<<std::endl;
    std::cin>>nombre;
    if(nombre != "fin") { 
      for(const auto& n: nombres) {
        if(n == nombre) {
        std::cout<<"Nombre ya agregado"<<std::endl;
        continue;
        }
      }
      nombres.insert(nombre);
    }
  } while(nombre != "fin");

  for(const auto& n: nombres) {
    std::cout<<n<<", ";
  }
  std::cout<<std::endl;

  // forma limpia de hacerlo aprovechando .insert() en set
  /*
  .insert() devuelve un pair set de valor y double, 
  .first es el valor, .second es true si ya esta agregado
  */
  do{
    std::cout<<"Digite nombres (fin para acabar): "<<std::endl;
    std::cin>>nombre;
    if(nombre != "fin") {
      auto agregar = nombres.insert(nombre); // agregar.first = valor, agregar.second = true or false
      // true si se inserto, false si ya existia y no se inserto
      if(!agregar.second) {
        std::cout<<"Nombre ya agregado"<<std::endl;
      }
    }

  } while(nombre != "fin");



  return 0;
}