#include <iostream>
#include <vector>

using Vector = std::vector<double>;

Vector pedirCelcius(int n) {
  Vector celcius;
  for(int i=0; i < n; i++) {
    double tempTemp;  // tiene que estar dentro del loop
    std::cout<<"Digite temperatura "<<i+1<<": ";
    std::cin>>tempTemp;
    celcius.push_back(tempTemp);
  }  // pushback para vectores vacios, std::cin>> cuando ya hay elementos

  return celcius;
}

Vector convertir(const Vector& celcius) { // porque no voy a modificar el parametro
  Vector farh(celcius.size());
  // ps usemos el auto y la referencia para modificar, y el const auto & para solo mostrar valores en el void
  for(size_t i=0; i < celcius.size(); ++i) {
    farh.at(i) = (celcius.at(i) * 9.0 / 5.0)+ 32.0;
  } 
  return farh;
}

void mostrarVectores(const Vector& celcius, const Vector& farhenheit) {
  std::cout<<"Temperaturas en Celcius"<<std::endl;
  for(const auto& temp: celcius) {
    std::cout<<temp<<" C" <<std::endl;
  }
  std::cout<<std::endl;
  std::cout<<"Temperaturas en Fahrenheit"<<std::endl;
  for(const auto&temp: farhenheit) {
    std::cout<<temp<<" F"<<std::endl;
  }
}
void estadisticas(const Vector& celcius, const Vector& farhenheit) {
  // promedios
  std::cout<<"Promedio temperaturas Celcius: "<<std::endl;
  double sumaCel = 0;
  for(const auto& temp: celcius) {
    sumaCel += temp;
  }
  std::cout<< sumaCel / celcius.size() <<std::endl;
  std::cout<<"Promedio temperaturas Farhenheit: "<<std::endl;
  double sumaFar = 0;
  for(const auto& temp: farhenheit) {
    sumaFar += temp;
  }
  std::cout<< sumaFar / farhenheit.size() <<std::endl;

  // max valores
  double maxCel = celcius.at(0);
  for(size_t i=1; i < celcius.size(); ++i) {
    if (celcius.at(i) > maxCel){
      maxCel = celcius.at(i);
    }
  }
  std::cout<<"Temperatura maxima en celcius: "<< maxCel <<"C "<<std::endl;

  double maxFar = farhenheit.at(0);
  for(size_t i=1; i < farhenheit.size(); ++i) {
    if (farhenheit.at(i) > maxFar){
      maxFar = farhenheit.at(i);
    }
  }
  std::cout<<"Temperatura maxima en farhenheit: "<< maxFar <<"F "<<std::endl;
}

int main () {
  int numero;
  std::cout<<"Digite numero de temperaturas a convertir: "<<std::endl;
  std::cin>> numero;

  Vector celcius = pedirCelcius(numero);
  Vector farhenheit =convertir(celcius);

  mostrarVectores(celcius, farhenheit);
  estadisticas(celcius, farhenheit);
  return 0;
}