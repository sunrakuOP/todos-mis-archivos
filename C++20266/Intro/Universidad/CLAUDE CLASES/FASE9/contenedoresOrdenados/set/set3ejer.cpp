#include <iostream>
#include <set>
#include <string>

int main() {
  std::set<int> notas = {45, 72, 88, 91, 60, 55, 78, 95, 33};

  // solo mostrar notas entre [60,85]
  for(auto it = notas.lower_bound(60); it != notas.upper_bound(85); it++) {
    std::cout<<*it<<",";  // desreferenciar el iterador
  }
  std::cout<<std::endl;


  return 0;
}