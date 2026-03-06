# pedir dos numeros y corregir que no cause error
print("Digite enter para terminar")
while True:
    try:
        num1 = input("Digite numero 1: ")   # si conviero de una a int nunca sera str entonces no guarda enter
        if num1 == "":
            break
        num2 = input("Digite numero 2: ")
        if num2 == "":
            break
        num1 = int(num1)
        num2 = int(num2)
    
    except ValueError:
        print("Digite numeros")
        
    else: 
        print(f"Suma es: {num1 + num2}")
    

    
