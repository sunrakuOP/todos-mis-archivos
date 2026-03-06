filename = 'prestamos.txt'

# LECTURA DE LOS DATOS
prestamos = []
try:
    with open(filename, 'a+') as f:
        f.seek(0)
        lines = f.readlines() 
        linea_limpia = lines.strip()
        for line in lines:    # cada linea del archivo la guarda en la variable    
            prestamos.append(lines)   # añade la linea a la lista

    print("Registro existente")    # muestra registro datos en el archivo ya guardados
    for i in prestamos:
        print(i)   # imprimimos cada linea EN EL PROGRAMA
except FileNotFoundError:
    pass


# INTRODUCIR DATOS
registro = []
print("Digite enter para salir")

with open(filename, 'a') as f:
    while True:
        nombre = input("Digite su nombre: ").strip()
        if nombre == "":
            break
        libro = input("Digite libro: ")
        if libro == "":
            break

        mostrar = f"{nombre}: {libro}"

        if mostrar in prestamos: # chequeamos que cadena a introducir no estuviera ya en archivo
            print("Libro ya fue prestado por usted")
        else:
            registro.append(mostrar)
            f.write(f"{mostrar}\n")

# MOSTRAR
with open(filename, 'r') as f:
    print("Registro actualizado")
    print(f.read())

    # muestra todos los datos


