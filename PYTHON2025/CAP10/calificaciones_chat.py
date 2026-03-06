filename = 'calificaciones_chat.txt'

lista = []
lista_notas = []
print("Digite enter para salir")

with open(filename, 'a+') as f:
    while True:        
        estudiante = input("Digite nombre del estudiante: ").strip()
        if estudiante == "":
            print("Hasta luego")
            uso = f.write("\n")
            break
        if estudiante in lista:
            print("Estudiante ya esta en datos")
        else:
            try: 
                nota = float(input("Digite su calificacion (numero 1 al 5): "))
            except ValueError:
                print("Digite un numero")
                continue
            
            lista.append(estudiante)
            lista_notas.append(nota)
            cuenta = len(lista)
            despliegue = f.write(f"{estudiante}: {nota}\n")
            cuenta += 1

    promedio = sum(lista_notas)/len(lista_notas)
    reporte = f.write(f"Promedio de notas de los {len(lista_notas)} estudiantes: {promedio}")

with open(filename, 'r') as f:
    print("Datos actualizados: ")
    print(f.read())



