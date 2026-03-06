filename = "100 cosas antes de morir.txt"

# funcion lee el texto pasado y lo guarda en una lista que usaremos en el prgrama
def leer_pasado():
    lista = []
    with open(filename, 'r') as f: 
        lines = f.readlines()
        for line in lines:
            limpiar = line.strip()
            lista.append(limpiar)
    return lista

lista2 = leer_pasado()
for index, elemento in enumerate(lista2, 1):
    print(f"{index}. {elemento}")

print("Digite enter para salir")
while True:
    cosa = input("Digite cosa por hacer: ").strip()
    if cosa == "":
        print("Saliendo...")
        break
    if cosa in lista2:
        print("La cosa ya está en la lista.")
    else:
        lista2.append(cosa)

# reescribir el archivo con la numeracion correcta
with open(filename, 'w') as f:
    for idx, elemento in enumerate(lista2, 1):
        f.write(f"{idx}. {elemento}\n")

print("Lista actualizada")
for inx, elemento in enumerate(lista2, 1):
    print(f"{inx}. {elemento}")

# ennmuerate recorre la lista y enumera los elemento empenzando en el valor asignado
