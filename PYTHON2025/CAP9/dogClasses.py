"""
Mascotas 🐶
Crea una clase Dog con atributos name y age.
Agrega un método sit() y otro roll_over().
Crea un par de perros e imprime qué hacen.

class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def sit(self):
        print(f"Perro {self.name} se sento")
    
    def roll_over(self):
        print(f"Perro {self.name} rodo")

mariscal = Dog('Mariscal',9)
mariscal.sit()
mariscal.roll_over()
"""

"""
Círculos ⚪

Clase Circle con atributo radius.

Método area() que calcule el área.

Método circumference() que calcule el perímetro.
"""

""" FORMA 1

class Circle:
    def __init__(self, radius):
        self.radius = radius
        self.areaa = 3.14*(self.radius**2)  # no dejar operaciones en el init() metodo externo


    def area(self):
        print(f"Area del circulo con radio {self.radius} cm es {self.areaa} cm2")
        return self.areaa
        
    
circulo = Circle(2)
circulo.area()        
"""

"""
import math 

class Circle:
    def __init__(self, radio):
        self.radio = radio

    def area(self):
        return math.pi*(self.radio**2) #retorna el valor al metodo area(), para usar valor llamarlo
        
    
    def mostrar(self):
        print(f"Circulo de radio {self.radio}cm tiene area de {self.area():.2}")
        # {variable:.2} en f string formatea a dos decimales

circulo = Circle(2)
circulo.area()
circulo.mostrar()
"""

"""
Cuenta de Usuario 👤

Clase User con nombre y correo.

Método greet_user() que imprima un saludo personalizado.

class User:
    def __init__(self, nombre, correo):
        self.nombre = nombre
        self.correo = correo

    def greet_user(self):
        print(f"Buenas {self.nombre} con correo {self.correo}, tenga un buen dia")
    
    # si quiero añadir saludo personal podria hacerlo asi, recibir argumento (el metodo)
    def saludo_personalizado(self, saludo = "Buenas"):
        # Aca creamos un valor por defecto, si usario no ingresa argumento al metodo usa el defecto
        print(f"{saludo}, {self.nombre} con correo {self.correo}, tenga un buen dia")
        # los atributos creados en el metodo no necesitan el self.


usuario = User('Nicolas', 'juann.arizar@gmail.com')
usuario.greet_user()
usuario.saludo_personalizado()   # aca saludara con "Buenas" por default (no argmento)
usuario.saludo_personalizado("Hola, ¿como esta?")  # aca se digita argumento de como quiere saludar
"""

"""
Auto simple 🚗

Clase Car con marca y modelo.

Método drive() que imprima “El carro está en movimiento”.

class Car: 
    def __init__(self, marca, modelo):
        self.marca = marca
        self.modelo = modelo

    def drive(self):
        print(f"El carro marca {self.marca} y modelo {self.modelo} esta en movimiento")

    def __str__(self):   # para que se imprima bonito
        return f"{self.marca} ({self.modelo})"
        #retorna valor al str method
    
algun_dia = Car("Nissan","GTR")
algun_dia.drive()
print(algun_dia)
"""

"""Gestión de Estudiantes 🎓

Clase Student con nombre y notas.

Método para calcular promedio.

Imprime si pasa o no."""

class Student:
    def __init__(self, nombre):
        self.nombre = nombre
        self.notas = []
    
    def solicitar_notas(self):
        print("quit para terminar")
        while True:
            notas = input("Digite notas: ")
            if notas.lower() == 'quit':
                break
            elif notas.isdigit():
                nota = int(notas)
                self.notas.append(nota)
            else:
                print("Digite un numero")
                continue                

    def prome(self):
        if not self.notas:
            print(f"El estudiante {self.nombre} no tiene notas registradas")
            return  # para salir del metodo y que no ejecute lo siguiente (como break)
        
        num = len(self.notas)
        suma = sum(self.notas)
        prom = suma/num
        print(f"Promedio del estudiante {self.nombre} de sus notas {self.notas} es: {prom:.2}")
        if prom >= 3:
            print(f"{self.nombre} aprobado")
        else:
            print(f"{self.nombre} desaprobado")
    
estudiante = Student('Nicolas')
estudiante.solicitar_notas()
estudiante.prome()
    
