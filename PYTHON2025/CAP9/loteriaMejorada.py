"""Lotería mejorada
Haz una clase Loteria que:
Genere un boleto ganador de 4 símbolos (números/letras).
Permita que el usuario cree su propio boleto (ej. "123a").
Ejecute intentos hasta que el boleto del usuario sea igual al ganador, mostrando cuántos intentos tomó.
👉 Aquí el reto es guardar valores en atributos y compararlos en distintos métodos."""
import random

class Loteria: 
    def __init__(self, lista=[1,2,3,4,5,6,7,8,9,0,'a','b','c','d','e']):
        self.lista = lista

    def crear_boleto(self):
        self.numero = input("Digite numero de simbolos: ")
        if self.numero.isdigit():
            valores = []
            for i in range(int(self.numero)):
                dato = random.choice(self.lista)
                valores.append(str(dato))
            self.boleto = "".join(valores)
            print(self.boleto)
            return self.boleto
        else: 
            print("Digite numero")
    
    def bol_usuario(self):
        usuario = input("Digite su boleto: ")
        if len(usuario) == 4:
            self.ganador = self.crear_boleto()
            print(f"ganador es {self.boleto}")
            conteo = 0
            while usuario != self.boleto:
                conteo += 1
            print(f"Ganador en intento {conteo}")
            return conteo
        else:
            print("Boleto no valido")

    
boleto = Loteria()
boleto.bol_usuario()

