#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <random>
#include <chrono>
#include <condition_variable>

std::mutex mtx, mtx2;
std::condition_variable cv, cv2;
// cola compartida 
std::queue<int> cola1;
std::queue<double> cola2; // valores quen retorna el hilo procesador
bool terminado = false;
bool terminado2 = false;

void generador() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1,100);
    // generar 12 lecturas aleatorias
    for(int i=0; i<12; ++i){
        int valor = dist(gen);
        {
            std::lock_guard<std::mutex> guard(mtx);
            cola1.push(valor);
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    // cuando termina de llenar la cola, cambia a true el terminado
    // los {} son para que el lock solo aplique en ese momento
    {
        std::lock_guard<std::mutex> guard(mtx);
        terminado = true;
    }
    cv.notify_one();
}

void procesador() {
    while(!terminado || !cola1.empty()){
        // despertar el hilo con cv.wait(), pero antes hacer el lock con unique lock para hacer lock manual
        std::unique_lock<std::mutex> lock(mtx);
        // ponerle la condicion de cuando despierta
        cv.wait(lock, []{return terminado || !cola1.empty(); });
        if(!cola1.empty()){
            // guarda valor, elimina el daton de la cola, lo procesa y lo agrega a la nueva cola
            int valor = cola1.front();
            cola1.pop();
            {
                // para escribir de forma segura
                std::lock_guard<std::mutex> guard(mtx2);
                cola2.push(valor * 1.5 + 10);
            }
            cv2.notify_one();
        }
    }
    {
        std::lock_guard<std::mutex> guard(mtx2);
        terminado2 = true;
    }
    cv2.notify_one();
}
// se despierta cuando procesador le diga(es como otro paso mas)
void escritor() {
    while(!terminado2 || !cola2.empty()){
        std::unique_lock<std::mutex> lock(mtx2);
        cv2.wait(lock, []{ return terminado2 || !cola2.empty();});
        if(!cola2.empty()){
            std::cout<<"Valor procesado: "<<cola2.front()<<std::endl;
            cola2.pop();
        }
    }
}


int main() {
    // lanzar un hilo por funcion
    std::thread t1(generador);
    std::thread t2(procesador);
    std::thread t3(escritor);

    t1.join(); t2.join(); t3.join();
    
    return 0;
}