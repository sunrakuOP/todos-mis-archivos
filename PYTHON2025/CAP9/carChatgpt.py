"""
Vehículos 🏍️

Clase Vehicle con marca y velocidad.

Subclase Car y Bike.

Métodos: accelerate() y brake().
"""
class Vehicule:
    def __init__(self, marca, velocidad):
        self.marca = marca
        self.velocidad = velocidad
    
    def show_velocity(self):
        print(f"Carro de marca {self.marca} va a {self.velocidad}km/h")
    
class Car(Vehicule):
    def __init__(self, marca, velocidad):
        super().__init__(marca, velocidad)
    
    def accelerate(self):
        print(f"El carro marca {self.marca} a velocidad {self.velocidad}km/h esta acelerando")
        incremento = 10
        self.velocidad += incremento
        print(f"Nueva velocidad es {self.velocidad}km/h")
    
    def breaking(self):
        print(f"El carro marca {self.marca} a velocidad {self.velocidad}km/h esta frenando")
        decremento = 10
        self.velocidad -= decremento
        print(f"Nueva velocidad es {self.velocidad}km/h")

algun_dia = Car("nissan", 100)
algun_dia.show_velocity()
algun_dia.accelerate()
algun_dia.breaking()