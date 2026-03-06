from practicaClases import Encuesta

pregunta = f"Que idiomas habla?"
mi_encuesta = Encuesta(pregunta)

print("Digite enter para salir")
mi_encuesta.question()
while True:
    idiomas = input("Digite los idiomas que habla: ")
    if idiomas == "":
        break
    mi_encuesta.agregar(idiomas)
    print("Agregado")
print("Mostrando resultados")
mi_encuesta.mostrar() 




