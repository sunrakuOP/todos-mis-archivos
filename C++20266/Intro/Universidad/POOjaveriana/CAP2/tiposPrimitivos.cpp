// datos primitivos en c++
/*

(1)
TIPOS ENTEROS  
* valores sin decimales
    1. short: valores muy pequeños (ahorrar memoria)
    2. int: normal: mas rapido en mayoria de cpu's
    3. long: para numeros demasiado grandes 

VALORES UNSIGNED
    unsigned int: solo para valores positivos (mayor capacidad de memoria)
    !!! Nunca mezclar unsigned y signed en operaciones

CHAR
    char: para guardar 1 solo caracter

BOOL 
    solo cabe true o false

FLOAT y DOUBLE
    !!!!!!
    usar double por defecto
    usar float solo en casos especificos para ahorrar memoria
    !! no comparar valores decimales con (==) porque puede generar problemas


(2)
CONVERSIONES ENTRE TIPOS
    JERARQUIA DE CONVERSION
bool -> char -> short -> int -> unsigned -> long -> long long -> float -> double

! cambiar un tipo de dato a otro

int x = 4;
double x2 = x; // ahora es double 4.0
    se convierten internamente al pasar argumentos, o condiciones 


(3)
LITERALES
    Es lo que escribo directamente en el codigo,      int x = 42;  (42 es el literal)

(4)
VARIABLES
    


*/