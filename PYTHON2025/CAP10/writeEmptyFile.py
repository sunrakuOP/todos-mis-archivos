archivo = 'probemos_1.txt'

# write mode
with open(archivo, 'w') as file_object:
    file_object.write("Primera linea de texto\n")
    file_object.write("Segunda linea de texto\n")
    file_object.write("Tercera linea de codigo\n\n")

# append mode
with open(archivo, 'a') as file_object2:
    file_object2.write("Append mode para escribir sobre el archivo\n")
    file_object2.write("Asi no sobreescribe sobre archivo original")




"""    'w' mode
Si el archivo no existe, modo 'w' lo crea y escribe sobre el
Si el archivo existe, reescribe sobre el

    multiples lineas
\n para hacer la linea bajar, si no escribe sobre misma linea multiples""" 

