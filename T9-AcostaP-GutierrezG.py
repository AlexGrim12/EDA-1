import math as math
 
def pedir_dato():
    dato = -1
    while dato < 0:
        dato = int(input("-> "))
    return dato

def leer_datos(i):
    print(f"Ingrese el valor de x{i}: ")
    x = pedir_dato()
    print(f"Ingrese el valor de y{i}: ")
    y = pedir_dato()
    punto = (x, y)
    return punto

def calcular_distancia(tupla):
    return math.sqrt((tupla[1][0]-tupla[0][0])**2 + (tupla[1][1]-tupla[0][1])**2)

def calcular_pendiente(tupla):
    return (tupla[1][1]-tupla[0][1])/(tupla[1][0]-tupla[0][0])


def actividad_1():
    while True: 
        tupla = (leer_datos(1), leer_datos(2))
        
        print("\nLa distancia entre los puntos es: ", calcular_distancia(tupla))
        
        pendiente = calcular_pendiente(tupla)
        print("\nLa pendiente de la recta es: ", pendiente)
        if pendiente == 0:
            print("La pendiente es horizontal")
        elif tupla[0][0] == tupla[1][0]:
            print("La pendiente es vertical")
        else:
            print("La pendiente es inclnada")
        
        tupla_dos = (tupla[0], tupla[1], leer_datos(3))

        perimetro = calcular_distancia(tupla_dos) + calcular_distancia((tupla_dos[1], tupla_dos[2])) + calcular_distancia((tupla_dos[0], tupla_dos[2]))
        print("\nEl perimetro del triangulo es: ", perimetro)

        lista = [tupla[0], tupla[1], tupla_dos[2]]
        print(f"Lista de puntos: {lista}")

        print("\nDesea continuar? (s/n)")
        if input() == "n":
            break

def actividad_2():
    print("Ingrese un numero entero positivo: ")
    n = str(pedir_dato())

    numeros = {"0":"cero", "1":"uno", "2":"dos", "3":"tres", "4":"cuatro", "5":"cinco", "6":"seis", "7":"siete", "8":"ocho", "9":"nueve"}
    for i in range(0, len(n)):
        for j in range(0, 10):
            if n[int(i)] == str(j):
                digitos = [numeros[str(j)]]
    
    print(digitos)
    
def main():
    print("*********** Tarea 9 ***********")
    print("Desea realizar la actividad 1 o actividad 2? (1/2)")
    if input() == "1":
        actividad_1()
    else:
        actividad_2()

if __name__ == "__main__":
    main()