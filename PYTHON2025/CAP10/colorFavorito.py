archivo = 'chatGpt_te_quiero.txt'

with open(archivo, 'a') as file_object:
    color_fav = input("Digite su color favorito: ").strip()
    file_object.write(color_fav, "\n")