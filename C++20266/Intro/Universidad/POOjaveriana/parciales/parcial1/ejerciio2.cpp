#include <iostream>
#include <vector>

int main() {
    double temperatura;
    std::vector<double> temperaturas;
    while (true) {
        std::cout<<"Digite temperatura(0 para terminar): "<<std::endl;
        std::cin>>temperatura;
        if (temperatura == 0) {
            if (temperaturas.empty()) {
                std::cout<<"El vector esta vacio"<<std::endl;
                return 0;
            }
            double max = temperaturas.at(0);
            for (size_t i=1; temperaturas.size(); ++i) {
                if (temperaturas.at(i)> max) {
                    max = temperaturas.at(i);
                }
            }
            std::cout<<"Maxima temperatura: "<<max<<std::endl;
            return 0;
        }
        else {
            temperaturas.push_back(temperatura);
            if (temperatura < 10) {
                std::cout<<"Frio"<<std::endl;
            }
            else if (temperatura >= 10 && temperatura <= 25) {
                std::cout<<"Templado"<<std::endl;
            }
            else if (temperatura > 25) {
                std::cout<<"Calido"<<std::endl;
            }
        }
    }

    return 0;
}