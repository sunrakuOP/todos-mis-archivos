import json
filename =  'librosjson.json'

print("MENU")
print("1. Agregar libro")
print("2. Buscar libro")
print("3. Eliminar libro")
print("4. Mostrar libros almacenados")
print("5. Salir")

def cargar_datos():
    try:
        with open(filename, 'r') as f:
            return json.load(f)    # siempre retornar un valor en las funciones 
    except FileNotFoundError:
        return []    # return none = [] ????????
    except json.JSONDecodeError:
        return []

def guardar_datos(lista):
    with open(filename, 'w') as f:
        return json.dump(lista, f)

def agregar():
    lista = cargar_datos()
    titulo = input("Digite titulo del libro: ").strip()
    ya = False
    for line in lista:
        if titulo == line["titulo"]:
            ya = True
            break
    if ya:
        print("Libro ya en biblioteca")
        return 
    
    autor = input("Digite autor del libro: ").strip()
    book = {"titulo": titulo, "autor": autor}
    lista.append(book)
    guardar_datos(lista)
    print("Libro agregado exitosamente.")

# prestar atencion en lista que me estoy equivocando
def buscar():
    lista = cargar_datos()
    buscar = input("Digite libro a buscar: ").strip()
    encontrado = False
    for line in lista:
        if buscar == line["titulo"]:
            encontrado = True

def eliminar():
    lista = cargar_datos()
    eliminar = input("Digite libro a eliminar").strip()
    encontrado = False
    for line in lista[:]:     # Hacer una copia de la lista para no alterar la original
        if eliminar == line["titulo"]:
            encontrado = True
            lista.remove(line)
            guardar_datos(lista)
            break
        
    if not encontrado:
        print("Libro no encontrado")  # usar el if not que lo hace mas corto

# Tener en cuenta que puede que no haya libros en la biblioteca
def mostrar():
    lista = cargar_datos()
    if not lista:
        print("No hay libros en la biblioteca")
        return
    else:
        print("Biblioteca")
        for elemento in lista:
            print(elemento)


while True:
    opcion = input("Digite opcion(1-5): ").strip()
    if not opcion.isdigit():
        print("Digite un numero")
        continue
    
    if opcion == '1':
        agregar()
    elif opcion == '2':
        buscar()
    elif opcion == '3':
        eliminar()
    elif opcion == '4':
        mostrar()
    elif opcion == '5':
        print("Saliendo...")
        break



