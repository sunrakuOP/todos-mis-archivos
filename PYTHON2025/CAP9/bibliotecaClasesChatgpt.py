"""Biblioteca 📚

Clase Book con título y autor.

Clase Library que guarde varios libros en una lista.

Métodos: add_book(), show_books()."""

class Book: 
    def __init__(self, titulo, autor):
        self.titulo = titulo
        self.autor = autor
    
    def __str__(self):
        return f"Libro {self.titulo} de {self.autor}"

class Library:
    def __init__(self):
        self.lista = []
    
    def add_book(self):
        print("Digite quit para salir")
        while True: 
            titulo = input("Digite libros: ")
            if titulo.lower() == 'quit':
                break
            autor = input(f"Digite el autor: ")
            # CREAR OBJETO
            libro = Book(titulo,autor)   # creo objeto de clase Book
            self.lista.append(libro)

    
    def show_book(self):
        if not self.lista:
            print("Biblioteca vacia")
        else:
            # para cada objeto book me crea una cadena de texto
            for libro in self.lista:  # busca cada elemento en book
                print(f"{libro}")  # como hay un str en book lo busca y la aplica

biblioteca = Library()  # creo objeto/instancia
biblioteca.add_book()
biblioteca.show_book()




        