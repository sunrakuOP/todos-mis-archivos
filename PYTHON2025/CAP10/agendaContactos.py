filename = 'agendachat.txt'

print("MENU:") 
print("1. Ver todos los contactos")
print("2. Agregar un nuevo contacto")
print("3. Buscar un contacto por nombre")
print("4. Eliminar un contacto")
print("5. Salir")

while True:     
        opcion = input("Digite opcion: ")
        if opcion.isdigit():
            opcion = int(opcion)
        else: 
            print("Digite un numero")
            continue

        if opcion == 1:
            print("Ver todos los contactos")
            with open(filename, 'r') as f:
                f.seek(0)
                lista = []
                lines = f.readlines()
                for line in lines:
                    limpiar = line.strip()
                    lista.append(limpiar)
                print(lista)
                    
        
        if opcion == 2:
            print("Agregar un nuevo contacto")
            print("Digite enter para salir")
            
            with open(filename, 'a') as f:
                while True:
                    nombre = input("Digite el nombre del contacto: ").strip()
                    if nombre == "":
                        break
                    telefono = input("Digite el telefono del contacto: ").strip()
                    if telefono == "":
                        break
                    correo = input("Digite el correo del contacto: ").strip()
                    if correo == "":
                        break
                    f.write(f"{nombre}, {telefono}, {correo}\n")

                    print(f"Contacto {nombre} agregado")

        if opcion == 3:
            with open(filename, 'r') as f:
                f.seek(0)
                lista = []
                buscar = input("Digite el nombre a buscar: ").strip()
                lines = f.readlines()
                for line in lines:
                    limpia = line.strip()
                    lista.append(limpia)
                
                for elemento in lista:
                    if buscar in elemento:
                        print("Contacto encontrado")
                        print(elemento)


        if opcion == 4:
            with open(filename, 'r') as f:
                eliminar = input("Digite el nombre del contacto a eliminar: ").strip()
                f.seek(0)
                lista = []
                lines = f.readlines()    # redlines me devuelve LISTA

                for line in lines:
                    limpiar = line.strip()
                    lista.append(limpiar)
                
                for i in lista:
                    if eliminar in i:
                        lista.remove(i)
                        print(f"Contacto {eliminar} eliminado")
                
                with open(filename, 'w') as f:
                    for item in lista:
                        f.write(f"{item}\n")
                

# USAR WRITE CON CADENAS Y WITELINES CON LISTAS
# USAR READLINE PARA LEER LINEA A LINEA Y READLINES PARA LEER TODAS LAS LINEAS Y GUARDARLAS EN UNA LISTA
        
        if opcion == 5:
            with open(filename, 'r') as f:
                f.seek(0)
                print("Listado final de contactos:")
                print(f.read())   # lee el archivo me lo muestra en el editor
            break
            

            

