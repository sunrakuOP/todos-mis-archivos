filename = 'perros.txt'

try: 
    with open(filename, 'r') as f:
        archivo = f.read()
        print(archivo + "\n")
        num_a = archivo.count("a")
        print(f"En texto 'a' aparece {num_a} veces")

        
except FileNotFoundError:
    print("Archivo inexistente")


