archivo = 'peliculas.txt'

with open(archivo, 'a') as file_object:
    print("Digite enter para finalizar")
    while True:
        pelicula = input("Digite su pelicula favorita: ")
        if pelicula == "":
            break
        file_object.write(pelicula + "\n")   # para que si esta vacio no lo escriba
        print(f"Buena eleccion {pelicula}")

