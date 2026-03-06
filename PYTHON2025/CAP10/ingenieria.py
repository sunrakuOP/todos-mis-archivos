archivo = 'ejerciciosChat.txt'

with open(archivo) as file_object:
    for line in file_object:
        new_line = line.replace("programacion", "ingenieria")
        print(new_line.strip())
        