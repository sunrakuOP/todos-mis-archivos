filename = 'usuarios_cap10.txt'


lista_nombres = []
print("Digite enter para terminar")

with open(filename, 'a+') as f:
    while True:
        usuario = input("Digite nombre de usuario: ").strip()
        if usuario == "":
            break
        if usuario in lista_nombres:
            print("Usuario ya esta en la lista")
        else:
            lista_nombres.append(usuario)
            cuenta = len(lista_nombres)
            despliegue = f.write(f"{cuenta}. {usuario}\n")
            print(f"{cuenta}. {usuario}")
            print(lista_nombres)
            cuenta += 1

with open(filename, 'r') as f:
    print("Contenido actual del archivo")
    print(f.read())




    
    