# importar clase Electric_car que a su vez importo clase Car
from car import Car
from electric import Electric_car, Battery
# Como Car fue importado en electric se puede importar directamente de ahi
# Por eso es bueno tener orden

tesla = Electric_car("tesla","model s",2025)

my_carro = Car("nissan","sentra",2022)
tesla.describir_carro()
my_carro.describir_carro()
# usar battery module
tesla.battery.bateria_tamaño()

