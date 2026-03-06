import json
filename = 'jsonData1.json'

lista = []
def pedir_num():
    print("Digite enter para finalizar")
    while True:
        numero = input("Digite su numero favorito: ")
        if numero == "":
            break      
        lista.append(numero)
    
    with open(filename, 'w') as f:
        json.dump(lista, f)

def mostrar_num():
    with open(filename, 'r') as f:
        json.load(f)
        print("Numeros favoritos: ")
        for elemento in lista:
            print(elemento)
            

        
pedir_num()
mostrar_num()
