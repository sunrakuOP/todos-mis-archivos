#include <iostream>

double potencia(double num, int n) {
  if(n == 0) {
    return 1;
  }
  if (n < 0) {
    return 1.0 / potencia(num, -n);  // vuelve el numero porsitivo -*- da mas
  }
  return num* potencia(num, n-1);
}
int main() {
  double num;
  int n;
  std::cout<<"Digite numero a elevar: "<<std::endl;
  std::cin>>num;
  std::cout<<"Digite potencia a elevar: "<<std::endl;\
  std::cin>>n;
  
  std::cout<<"Resultado "<<num<<" elevado a "<<n<<": "<<std::endl;
  std::cout<< potencia(num, n);
  return 0;
}