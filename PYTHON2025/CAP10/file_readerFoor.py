file = 'pi_digits.txt'

with open(file) as file_object:
    line = file_object.readlines()    # .readlines() guarda en listas cada linea del archivo
    for line in file_object:
        print(line.rstrip())   # se puede trabajar con el for dentro del bloque del with
    
# ahora si se puede trabajar con archivo fuera de la lista (por el .readlines())
for line2 in line:  # rchivo esta almacenado en lista line
    print(f"{line2.strip()} (repetido) ")