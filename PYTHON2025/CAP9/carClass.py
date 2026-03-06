# parent class Car
class Car:
    def __init__(self, marca, modelo, año):
        self.marca = marca
        self.modelo = modelo
        self.año = año
        self.odometro = 0  # incializamos atriuto a 0
    
    def informacion_carro(self):
        long_name = f"Carro {self.marca} modelo {self.modelo} del año {self.año}"
        return long_name # para poder usar la cadena luego
    
    def odometro_uno(self):
        print(f"Este carro tiene {self.odometro} kilometros")

    def set_odometro(self, kilometraje):
        self.odometro = kilometraje
        print(f"Kilometraje nuevo es {self.odometro}")
    
    def incrementar_odometro(self, incremento):
        self.odometro += incremento
        print(f"Su carro tiene {self.odometro} al final del proceso")

mi_carro = Car('Nissan', 'Sentra', 2022)
mi_carro.informacion_carro()
mi_carro.odometro_uno()
mi_carro.set_odometro(1000)
mi_carro.incrementar_odometro(100)

# child class de clase Car
class Electric(Car):  # llama automaticamente el init de parent class
    def __init__(self, marca, modelo, año):
        super().__init__(marca, modelo, año)

mi_tesla = Electric('tesla','model s', 2019)
print(mi_tesla.informacion_carro())    # usamos metodo de la clase Car que despliega informacion
    



        