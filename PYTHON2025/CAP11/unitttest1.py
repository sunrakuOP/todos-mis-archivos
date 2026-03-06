def lugar_suave(ciudad, pais, poblacion=""):
    formateado = f"{ciudad},{pais},{poblacion}"
    print(formateado.title())
    return formateado.title()

lugar_suave("bogota","colombia")
lugar_suave("santiago","chile",100000)

    






    