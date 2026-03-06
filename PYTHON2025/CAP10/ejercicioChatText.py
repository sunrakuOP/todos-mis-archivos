archivo_txt = 'ejerciciosChat.txt'

# 1ra con read
with open(archivo_txt) as file_object:
    string = file_object.read()
    print(string.rstrip())

# 2nda usando ciclo for dentro del wit
with open(archivo_txt) as file_object2:
    for line in file_object2:
        print(line.rstrip())
    

with open(archivo_txt) as file_obeject3:
    listas = file_obeject3.readlines()

for line in listas: 
    print(line.strip())

