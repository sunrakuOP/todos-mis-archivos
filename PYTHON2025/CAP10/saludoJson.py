import json 
filename = 'jsonData2.json'

def usuario_antiguo():
    try:
        with open(filename, 'r') as f:
            usuario = json.load(f)
    except FileNotFoundError: 
        return None
    else:
        return usuario


def saludar_usuario():
    usuario = usuario_antiguo()
    if usuario:
        print(f"Hola de nuevo {usuario}")
    else:
        with open(filename, 'w') as f:
            usuario = input("Digite usuario: ")
            json.dump(usuario, f)
            print(f"Te recordaremos {usuario}")

saludar_usuario()
