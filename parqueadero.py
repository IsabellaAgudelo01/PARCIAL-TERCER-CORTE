filas = 7
columnas = 7

mapa = [["L" for _ in range(columnas)] for _ in range(filas)]  
placas = [[None for _ in range(columnas)] for _ in range(filas)]
tiempos = [[None for _ in range(columnas)] for _ in range(filas)]

def inicializar_mapa():
    for f in range(filas):
        mapa[f][1] = "."  
    for c in range(2, 6):
        mapa[6][c] = "."  
    mapa[0][1] = "E"  
    mapa[6][5] = "S"  
    for f in range(1, 6):
        for c in range(2, 6):
            mapa[f][c] = "L"  

def mostrar_mapa():
    print("\n Mapa del Parqueadero:")
    for fila in mapa:
        print(" ".join(fila))
    print()

def encontrar_espacio():
    for f in range(1, 6):
        for c in range(2, 6):
            if mapa[f][c] == "L":
                return (f, c)
    return None

def ingresar_vehiculo():
    espacio = encontrar_espacio()
    if not espacio:
        print(" No hay espacios disponibles.")
        return
    f, c = espacio
    placa = input("Ingrese la placa del vehículo: ").upper()
    try:
        entrada = int(input("Ingrese el minuto de entrada (simulado): "))
    except ValueError:
        print("Entrada inválida.")
        return
    mapa[f][c] = "X"
    placas[f][c] = placa
    tiempos[f][c] = entrada
    print(f" Vehículo {placa} parqueado en ({f}, {c})")

def retirar_vehiculo():
    placa = input("Ingrese la placa a retirar: ").upper()
    for f in range(1, 6):
        for c in range(2, 6):
            if placas[f][c] == placa:
                try:
                    salida = int(input("Ingrese el minuto actual (simulado): "))
                except ValueError:
                    print("Entrada inválida.")
                    return
                tiempo = salida - tiempos[f][c]
                if tiempo <= 0:
                    tiempo = 1
                valor = tiempo * 100
                mapa[f][c] = "L"
                placas[f][c] = None
                tiempos[f][c] = None
                print(f" Vehículo {placa} retirado. Tiempo: {tiempo} min. Valor a pagar: ${valor}")
                return
    print(" Vehículo no encontrado.")

def menu():
    inicializar_mapa()
    while True:
        mostrar_mapa()
        print("1. Ingresar vehículo")
        print("2. Retirar vehículo")
        print("3. Salir")
        op = input("Seleccione una opción: ")
        if op == "1":
            ingresar_vehiculo()
        elif op == "2":
            retirar_vehiculo()
        elif op == "3":
            print("Gracias por usar el sistema de parqueadero.")
            break
        else:
            print("Opción no válida.")

menu()
