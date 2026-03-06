archivo = 'pi_digits.txt'

with open(archivo) as file_object:
    archivo_texto = file_object.read()
    print(archivo_texto)

# metodo .read() copia el archivo en una cadena y la almacena en la variable