#include <iostream>
// ultimo ejercicio para entender arreglo de punteros
class Imagen {
private:
  int alto, ancho;
  double** pixeles;
public:
//SOBRECARGA DE CONSTRUCTORES
  // constructor normal
  Imagen(int al, int an): alto(al), ancho(an), pixeles(nullptr) { // arreglo inicializado a vacio
    pixeles = new double *[alto]; // reservo el espacio del arreglo en memoria
    for(int i=0; i < alto; ++i) {
      pixeles[i] = new double[ancho]();
    }
  }
  // constructor por si solo da filas
  Imagen(int al) : Imagen(al,1) {}
  
  // destructor
  ~Imagen() {
    for(int i=0; i < alto; ++i) {
      delete[] pixeles[i];
    }
    delete[] pixeles;
  }
  // constructor de copia
  Imagen(const Imagen& otro): alto(otro.alto), ancho(otro.ancho), pixeles(nullptr) {  // se hace paso por referencia
    pixeles = new double *[alto];  // reservar espacio en memoria
    for(int i=0; i< alto; ++i) {
      pixeles[i] = new double[ancho];
      for(int j=0; j< ancho; ++j){
      pixeles[i][j] = otro.pixeles[i][j]; // copio elemento por elemento
      }
    }
  }
  // operador de asignacion
  Imagen& operator=(const Imagen& otro) {
    // comprobar que no sea el mimso objeto
    if(this == &otro) {
      return*this;
    }
    // eliminar memoria del anterior
    for(int i=0; i < alto; ++i) {
      delete[] pixeles[i];
    }
    delete[] pixeles;

    // copiar elementos
    alto = otro.alto;
    ancho = otro.ancho;
    pixeles = new double *[alto];
    for(int i=0; i < alto; i++) {
      pixeles[i] = new double[ancho];
      for(int j=0; j<ancho; ++j){
        pixeles[i][j] = otro.pixeles[i][j];
      }
    }
    return *this;
  }

// MOVE SEMANTICS
  // constructor de movimiento
  Imagen(Imagen&& otro) noexcept: alto(otro.alto), ancho(otro.ancho), pixeles(otro.pixeles) {
    // se copia en la inicializacion y ya despues solo se ponen los atributos en 0
    otro.pixeles = nullptr;
    otro.ancho = 0;
    otro.alto = 0;
  } 

  // operador de asignacion en movimiento
  Imagen& operator=(Imagen&& otro) noexcept {  // funciona casi que igual que el normal solo que al final deja los otros en 0
    if(this == &otro) {
      return *this;
    }
    for(int i=0; i < alto; ++i) {
      delete[] pixeles[i];
    }
    delete[] pixeles;

    // copio los datos
    alto = otro.alto;
    ancho = otro.ancho;
    pixeles = otro.pixeles;  // copio directamente (esa es la ventaja del move) no toca recorrer uno por uno

    otro.pixeles = nullptr;
    otro.ancho = 0;
    otro.alto = 0;

    return *this;
    }

    // metodos externos
    void pedirValores() {
      for(int i=0; i < alto; ++i){
        for(int j=0; j < ancho; ++j) {
          std::cout<<"Digite pixel ["<<i+1<<"]["<<j+1<<"]: ";
          std::cin>>pixeles[i][j];
        }
      }
    }

    Imagen& setPixel(int al, int an, double valor) {
      pixeles[al][an] = valor;
      return *this;
    }
    double getPixel(int al, int an) {
      std::cout<<"Pixel ["<<al<<"]["<<an<<"]: "<<pixeles[al][an];
      return pixeles[al][an];
    }
    void mostrar() const {
      for(int i=0; i < alto; ++i){
        for(int j=0; j < ancho; ++j) {
          std::cout<<"Pixel ["<<i+1<<"]["<<j+1<<"]: "<<pixeles[i][j]<<", ";
      }
      std::cout<<std::endl;
    }

  }

};

int main() {
    Imagen img1(3, 3);
    img1.setPixel(0, 0, 1.5);
    img1.setPixel(1, 1, 2.5);
    img1.setPixel(2, 2, 3.5);
    std::cout << "img1:" << std::endl;
    img1.mostrar();

    // constructor de copia
    Imagen img2 = img1;
    std::cout << "img2 (copia):" << std::endl;
    img2.mostrar();

    // operador de asignación por copia
    Imagen img3(2, 2);
    img3 = img1;
    std::cout << "img3 (asignado):" << std::endl;
    img3.mostrar();

    // constructor de movimiento
    Imagen img4 = std::move(img1);
    std::cout << "img4 (move de img1):" << std::endl;
    img4.mostrar();

    // operador de asignación por movimiento
    Imagen img5(3, 3);
    img5 = std::move(img2);
    std::cout << "img5 (move de img2):" << std::endl;
    img5.mostrar();

    return 0;
}