class Encuesta:
    def __init__(self, pregunta):
        self.pregunta = pregunta
        self.list = []
    
    def question(self):
        print(self.pregunta)

    def agregar(self, nueva_pregunta):
        self.list.append(nueva_pregunta)

    def mostrar(self):
        if not self.list:
            print("Lista vacia")
        else: 
            for idx, item in enumerate(self.list, 1):
                print(f"{idx}. {item}")
