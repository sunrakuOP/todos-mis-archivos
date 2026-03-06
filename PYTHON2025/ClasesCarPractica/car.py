# crear clase Car ára poder usarla en otras files

class Car:
    def __init__(self, marca, modelo, año):
        self.marca = marca 
        self.modelo = modelo
        self.año = año
    
    def describir_carro(self):
        print(f"Marca de su auto es: {self.marca}")
        print(f"El modelo de su auto es: {self.modelo}")
        print(f"El año de su auto es: {self.año}")

    def __str__(self):
        return f"Auto marca {self.marca} modelo {self.modelo} del año {self.año}"
        