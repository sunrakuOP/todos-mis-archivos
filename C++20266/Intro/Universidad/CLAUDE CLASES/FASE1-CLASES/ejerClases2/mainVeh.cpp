#include <iostream>
#include "vehiculos1.h"

int main() {
  Vehiculo v1("Ford", "fiesta", 2022, 1000);
  Vehiculo v2("Nissan", "march", 2020, 10239);
  Vehiculo v3("Volvswagen", "jetta", 2005, 145000);

  v1.conducir(1000).conducir(2000).conducir(2000);

  v1.mostrarInfo();
}