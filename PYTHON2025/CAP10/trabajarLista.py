file3 = 'pi_digits.txt'

with open(file3) as file_object:
    lines = file_object.readlines() # creamos lista por cada linea

cadena = ""  # creamos string vacia que va a contener lista 
for line in lines:
    cadena += line.strip()   # strip para eliminar los espacios vacios
print(cadena)   