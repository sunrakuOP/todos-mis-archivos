"""
Juego de Personajes ⚔️

Clase Character (vida y ataque).

Subclases Warrior y Mage.

Métodos: attack() y take_damage().

Simula una pelea por turnos.
"""
class Character:
    def __init__(self, vida, ataque):
        self.vida = 100
        self.ataque = 20 
    
    def __str__(self):
        return f"Vida de warrior {vida_mago}"

class Warrior(Character):
    def __init__(self, vida, ataque):
        super().__init__(vida, ataque)

    def attack_w(self):
        print("Ataque de Warriorr")
        vida_mago = self.vida - self.ataque
        print(f"Vida de mago es: {vida_mago}")
    
    def take_damage_w(self):
        print("Warrior recibe ataque")
        vida_warrior = self.vida - self.ataque
        print(f"Vida de warrior es: {vida_warrior}")


class Mage(Character):
    def __init__(self, vida, ataque):
        super().__init__(vida, ataque)

    def attack_m(self):
        print("Ataque de mago")
        vida_warrior = self.vida - self.ataque
        print(f"Vida de mago es: {vida_warrior}")
    
    def take_damage_m(self):
        print("Warrior recibe ataque")
        vida_mago = self.vida - self.ataque
        print(f"Vida de warrior es: {vida_mago}")

jugador = Character()

        