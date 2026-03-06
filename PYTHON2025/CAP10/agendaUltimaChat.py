filename = "CAP10/agendaUltima.txt"

print("MENU:")
print("1. Ver todas las tareas")
print("2. Agregar una nueva tarea")
print("3. Eliminar una tarea")
print("4. Salir")


def cargar_lista():   # Funcion que carga la lista de tareas desde el archivo
    lista = []
    with open(filename, 'r') as f:
        lines = f.readlines()
        for line in lines:
            limpia = line.strip()
            lista.append(limpia)
        return lista 


while True:
    opcion = input("Digite una opcion (1-4): ")

    if opcion == "1":
        lista = cargar_lista()
        if not lista:
            print("Lista vacia")
        else:
            print("Tareas pendientes: ")
            for tarea in lista:
                print(tarea)
    
    
    if opcion == "2":
        lista = cargar_lista()
        cuenta = len(lista)
        with open(filename, 'a') as f:  
            print("Digite enter para salir")
            while True:
                tarea = input("Digite tarea: ")
                if tarea == "":
                    break
                lista.append(tarea)
                cuenta += 1
                f.write(f"Tarea {cuenta} : {tarea}\n")
                print("Tarea añadida")
                for elemento in lista:
                    print(elemento)

    if opcion == "3":
        lista = cargar_lista()
        with open(filename, 'w') as f:
            buscar = input("Digite la tarea que desea eliminar: ").strip().lower()
            if buscar in lista:
                lista.remove(buscar)
                print("Tarea eliminada")
                cuenta = 1  # reiniciar contador porque sobreescribimos el archivo
                for elemento in lista:
                    f.write(f"Tarea {cuenta}: {elemento}\n")
                    cuenta += 1
                print("Tareas actualizadas")
                for elemento in lista:
                    print(elemento)
                

               
    if opcion == "4":
        print("Saliendo del programa...")
        break



