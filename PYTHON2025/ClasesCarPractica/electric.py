# Importamos la clase Car del file car
from car import Car

class Battery:
    def __init__(self, battery=40):
        self.battery = battery
    
    def bateria_tamaño(self):
        print(f"Auto electrico tiene una bateria de {self.battery}kwh")

class Electric_car(Car): # clase Electric_car hija de Car 
    def __init__(self, marca, modelo, año):
        super().__init__(marca, modelo, año) 
        self.battery = Battery()    # Creamos objeto de battery
 
    """
    Eso significa que cada auto eléctrico tiene un atributo llamado battery 
    y ese atributo es un objeto de la clase Battery.
    """
        
    # como hereda la funcion padre tiene los mismos atriutos y se llama de la misma forma
