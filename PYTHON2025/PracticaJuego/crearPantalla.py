import sys, pygame
from configuracionesPract import Conf

class ProbemosJuego():
    def __init__(self):
        pygame.init()   # incializamos modulos de pygame
        self.conf = Conf()  # llamar al metodo

        self.screen = pygame.display.set_mode((self.conf.screen_ancho, self.conf.screen_alto))  # creamos pantalla ancho por alto
        pygame.display.set_caption("Primer juego")  # caption de pantalla
        self.color = self.conf.color

    
    def correr(self):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:    # si le da a cerrar ventana
                    sys.exit()   # termina el programa

            pygame.display.fill(self.conf.color)
            pygame.display.flip()   # Muestra los cambios hechos en pantalla
        
if __name__ == '__main__':
    prueba = ProbemosJuego()
    prueba.correr()
