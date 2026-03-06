import json
filename = 'agendajson.json'

print("MENU")
print("1. Agregar contacto: ")
print("2. Ver todos los contactos")
print("3. Bucar contacto")
print("4. Eliminar contacto")
print("5. Salir")

# cargar lista para que se guarden los datos en el archivo
def cargar():
    try:
        with open(filename, 'r') as f:
            return json.load(f)   # siempre return en funciones
    except FileNotFoundError:
        return []
    except json.JSONDecodeError:
        return []

def guardar(lista):     # se usa funcion para agregar los contactos a la lista y no tener que hacerlos funcion por funcion
    with open(filename, 'w') as f:
        json.dump(lista, f)

def agregar():
    lista = cargar()    
    nombre = input("Digite nombre: ").strip()
    for contacto in lista:
        if contacto["nombre"] == nombre:
            print("Contacto ya existente")
            return
    telefono = input("Digite telefono: ").strip()
    correo = input("Digite correo: ").strip()
    agregar = {"nombre": nombre, "telefono": telefono, "correo": correo} # con json se debe usar listas o diccionarios
    lista.append(agregar)
    guardar(lista)
    print("Contacto agregado")     

def mostrar():
    print("Lista de contactos")
    lista = cargar() 
    if lista: 
        for contacto in lista: 
            print(contacto)
    else: 
        print("No hay contactos disponibles")

def buscar():
    lista = cargar()
    buscar = input("Digite contacto a buscar: ")
    for contacto in lista:
        if buscar == contacto["nombre"]:
            print(contacto)
            return
    print("Contacto no encontrado")

def eliminar():
    lista = cargar()
    eliminar = input("Digite contacto a eliminar")
    for contacto in lista:
        if eliminar == contacto["nombre"]:
            lista.remove(contacto)
        else:
            print("Contacto no encontrado")
    guardar(lista)

while True:
    opcion = input("Digite opcion: ").strip()
    if opcion == '1':
        agregar()  
    elif opcion == '2':
        mostrar()    
    elif opcion == '3':
        buscar()    
    elif opcion == '4':
        eliminar()    
    elif opcion == '5':
        break


        








