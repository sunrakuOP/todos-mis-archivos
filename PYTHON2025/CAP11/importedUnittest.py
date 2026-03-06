from unitttest1 import lugar_suave
import unittest

class ProbarLugar(unittest.TestCase): # creamos una clase 

    def test_lugar(self):
        lugar = lugar_suave("bogota","colombia")
        self.assertEqual(lugar, "Bogota,Colombia,")  # argumentos de assertEqual variable y valor esperado
    
    def test_poblacion(self):
        poblacion =  lugar_suave("santiago","chile","10000")
        self.assertEqual(poblacion, "Santiago,Chile,10000")

if __name__ == '__main__':
    unittest.main()

        

