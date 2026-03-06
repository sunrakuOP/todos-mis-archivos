filename = 'chatGpt_te_quiero.txt'

lista = []
with open(filename, 'a+') as f:
    f.seek(0)
    lines = f.readlines()
    for line in lines:
        linea_limpia = line.strip()
        lista.append(linea_limpia)

    
    print("Registro actual")
    if len(lista) == 0:
        print("Lista vacia")
    else:
        print(lista)


print("Digite enter para terminar de escribir")
cuenta = 0
with open(filename, 'a') as f:
    while True:
        text = input("Digite linea: ").strip()
        if text == "":
            break
        cuenta += 1
        f.write(f"{cuenta} {text}\n")
        
        
            
                

    
with open(filename, 'r') as f:
    print(f.read())

        


