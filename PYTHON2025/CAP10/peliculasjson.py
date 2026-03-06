import json
filename = 'peliculasjson.json'

def cargar():
    try:
        with open(filename, 'r') as f:
            return json.load(f)   # retornar valor si no no sirve de nada
    except (FileNotFoundError, json.JSONDecodeError):
        return []
    
def guardar(lista):
    with open(filename, 'w') as f:
        json.dump(lista, f, indent=4)   # indent para que sea legible

def menu():
    print("Menu")
    print("1. Agregar pelicula")
    print("2. Ver catalogo")
    print("3. Buscar Pelicula")
    print("4. Eliminar pelicula")
    print("5. Volver a ver menu")
    print("6. Salir")

def agregar():
    lista = cargar()
    titulo = input("Digite titulo de la pelicula: ").strip()
    repetido = False
    for elemento in lista:
        if titulo == elemento["titulo"]:
            repetido = True
            break
    if repetido:
        print("Pelicula ya dentro catalogo")
        return  # termina la funcion si es repetido
    año = input("Digite el año de publicacion: ").strip()
    if not año.isdigit():
        print("El año debe ser un número")
        return  # termmina funcion si no es numero
    pelicula = {"titulo": titulo, "año": año}
    lista.append(pelicula)
    guardar(lista)  # reescribe cada vez que se escribe elemento

def mostrar():
    lista = cargar()
    if lista:
        print("Catalogo de peliculas")
        for idx, elemento in enumerate(lista, 1):
            print(f"{idx}. Titulo: {elemento['titulo']}, Año: {elemento['año']}")
    else:
        print("Lista vacia")


def buscar():
    lista = cargar()
    buscar = input("Digite pelicula a buscar: ").strip()
    flag = False
    for elemento in lista:
        if buscar == elemento['titulo']:
            flag = True
            print(f"Titulo: {elemento['titulo']}, Año: {elemento ['año']}")
            break
    if not flag:
        print("Pelicula no encontrada")

def eliminar():
    lista = cargar()
    eliminar = input("Digite pelicula a eliminar: ")
    flag = False
    for elemento in lista:
        if eliminar == elemento['titulo']:
            flag = True
            print(f"{elemento['titulo']} eliminada correctamente")
            lista.remove(elemento)
            guardar(lista)
            break
    if not flag:
        print("Pelicula no encontrada")

if __name__ == '__main__':
    while True:
        menu()
        opcion = input("Digite opcion (1-6): ")
        if not opcion.isdigit():
            print("Digite un numero")
            continue
        if opcion == '1':
            agregar()
        elif opcion == '2':
            mostrar()
        elif opcion == '3':
            buscar()
        elif opcion == '4':
            eliminar()
        elif opcion == '5':
            menu()
        elif opcion == '6':
            print("Saliendo...")
            break




    

