#include <iostream>
#include <unordered_set>
#include <string>



int main() {
  std::unordered_set<char> caracteres;
  std::string frase;

  std::cout<<"Digite una  frase: "<<std::endl;
  std::getline(std::cin, frase);

  for(const auto& c: frase) {
    // solo guarda uno de cada tipo
    // para filtrar que no salga espacio en output
    if(c != ' ') {
      caracteres.insert(c); // si esta repetido lo ignora
    }
  }
  // mostrar en pantalla
  for(const auto& c: caracteres){ 
    std::cout<<c<<", ";
  }
  std::cout<<std::endl;

  return 0;
}