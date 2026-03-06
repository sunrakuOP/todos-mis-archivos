"""Banco Virtual 🏦

Clase Account con titular y saldo.

Métodos: deposit() y withdraw().

Subclases: SavingsAccount (con intereses) y CheckingAccount (sobregiro)."""

class Account:
    def __init__(self, titular, saldo): # datos que digita usuario
        self.titular = titular
        self.saldo = saldo
    
    def __str__(self):
        return f"Dinero en cuenta de {self.titular} es {self.saldo}"
    
    def deposit(self):
        deposito = input("Cuanto va a depositar?: ")
        if deposito.isdigit():
            dep = int(deposito)
            self.saldo += dep
            print(f"Saldo es: {self.saldo}")
        else:
            print("Digite valor numerico")
    
    def withdraw(self):
        retiro = input("Digite dinero a retirar: ")
        if retiro.isdigit():
            ret = int(retiro)
            if ret <= self.saldo:
                self.saldo -= ret
                print(f"Saldo es: {self.saldo}")
            else:
                print("No hay suficiente dinero en cuenta")

class Saving_account(Account):
    def __init__(self, titular, saldo, interes = 0.05):
        super().__init__(titular, saldo)
        self.interes = interes
    
    def aplicar_interes(self):
        print("Aplicando interes")
        self.saldo = self.saldo + (self.saldo*self.interes)
        print(f"Saldo despues de interes es {self.saldo}")

class Checking_account(Account):
    def __init__(self, titular, saldo, limite_sobre = -500):
        super().__init__(titular, saldo)
        self.limite_sobre = limite_sobre
    
    def withdraw(self, cantidad):   # Se llaman igual pero si corro esta subclase python toma este metodo
        if self.saldo - cantidad >= self.limite_sobre:
            self.saldo -= cantidad
            print(f"Saldo actual en negativo: {self.saldo}")
        else: 
            print("Supero el limite, no se puede retirar esa cantidad")

        

cuenta1 = Account('nicolas', 1000)
print(cuenta1)
cuenta1.withdraw()
cuenta1.deposit()
cuenta2 = Checking_account('juan',1000)
cuenta2.withdraw(2600)
        

        