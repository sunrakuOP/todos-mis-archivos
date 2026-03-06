"""
Make a class called Restaurant. The __init__() method for
Restaurant should store two attributes: a restaurant_name and a cuisine_type.
Make a method called describe_restaurant() that prints these two pieces of
information, and a method called open_restaurant() that prints a message indicating
that the restaurant is open.
Make an instance called restaurant from your class. Print the two attributes
individually, and then call both methods



class Restaurant:
    def __init__(self, restaurant_name, cusine_type):
        self.restaurant_name = restaurant_name
        self.cusine_type = cusine_type
        self.number_served = 0 
        print(f"Numero de clientes atendidos: {self.number_served}")  # mejor definirlo en el __init()__

    def describe_restaurant(self):
        print(f"Nombre del restaurante es: {self.restaurant_name}")
        print(f"y su tipo de concina es: {self.cusine_type}")
    
    def open_restaurant(self):
        print("El restaurante esta abierto")

    # def number_served(self): # crear metodo que muestre numero de servicios, incializandolo en 0
        # self.number_served = 0 
        # print(f"Numero de clientes atendidos: {self.number_served}")

    def set_number_served(self, number):
        self.number_served = number
        print(f"Cantidad de clientes atendidos actualizada es: {self.number_served}")
    
    def increment_number_served(self, increment):
        self.number_served += increment
        print(f"Nuevo numero de clientes incrementado es: {self.number_served}")
    


el_paisa = Restaurant('EL PAISA', 'comida rapida')
el_paisa.describe_restaurant()   # ninguno de los dos necesita argumentos
el_paisa.open_restaurant()

el_bochinche = Restaurant('EL BOCHINCHE', 'Tipica Caleña')
tdt = Restaurant('TDT', 'Hamburguesas')

el_paisa.number_served()
el_paisa.set_number_served(10)
el_paisa.increment_number_served(3)

"""



"""
Make a class called User. Create two attributes called first_name
and last_name, and then create several other attributes that are typically stored
in a user profile. Make a method called describe_user() that prints a summary
of the user’s information. Make another method called greet_user() that prints
a personalized greeting to the user.
Create several instances representing different users, and call both methods
for each user.
"""

class User:
    def __init__(self, nombre, apellido, edad, pais, genero, login_attemps):
        self.nombre = nombre
        self.apellido = apellido
        self.edad = edad
        self.pais = pais
        self.genero = genero
        self.login_attemps = 0  # incializamos a 0

    
    def describe_user(self):
        print(f"Su nombre es: {self.nombre},{self.apellido}")
        print(f"Usted tiene: {self.edad} años")
        print(f"Nacio en: {self.pais}")
        print(f"Y es del genero: {self.genero}")

    def increment_login_attemps(self, numero):
        self.login_attemps += 1     # sumar de uno en uno los intentos de entrar
        print(f"Numero de intentos de entrar: {self.login_attemps}")
    
    def reset_login_attemps(self):
        self.login_attemps = 0 # nuevamente 0

mi_persona = User('Nicolas','Ariza','22','Colombia','Masculino')
mi_persona.describe_user()
mi_persona.increment_login_attemps(10)
mi_persona.reset_login_attemps()
