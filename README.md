# PARCIAL-TERCER-CORTE
Isabella Agudelo Rodríguez
Diany Kamila Guzmán Contreras

# Proyecto en C++
**Desarrollos innovadores:*
- Ventajas por tipo: es decir, el daño se irá modificando dependiendo del tipo de ataque y defensa
- Pantalla de estadísticas

# Explicación detallada del código en C++

# _Archivo tipos.h_
  1. Siguiendo la estructura enseñada en clase y utilizando las librerías <string> y <vector>
  ```cpp
  #ifndef TIPOS_H
  #define TIPOS_H
  #include <string>
  #include <vector>
  using namespace std;
  -
  -
  -
  #endif
  ```
2. Estructura movimiento
```cpp
 struct Movimiento {
   string nombre;
   int potencia;
   int costoPA; 
 };
```
Representa y dice las características de un ataque que un pokemon puede usar
nombre: nombre del movimiento, ejemplo si tomamos a pikachu 'impactrueno'
potencia: cuánto daño causa el ataque
cotoPA: el número de puntos de acción que gasta 

3. Estructura pokemon
```cpp
struct Pokemon {
    string nombre;
    string elemento;
    int salud;
    int puntos_accion; 
    vector<Movimiento> movimientos;
};
```
Igual que el caso anterior, representa las características que posee cada pokemon
vector<Movimiento> movimientos: definido como una lista de los ataques que el pokemon puede realizar

4. Funciones
```cpp
vector<Pokemon> obtener_catalogo();
```
es una función llamada obtener_catalogo() que retornara a la lista(vector) pokemon, lo que va a hacer es crear y devolver una lista con todos los pokemones que formarán parte del juego, esta función se incorporará más adelante en el archivo tipos.cpp

```cpp
float calcular_multiplicador(const string& tipo_atacante, const string& tipo_defensor);
```
en esta función la cual su tipo de retorno es float, const string& se usa como una referencia constante en busca de evitar copias innecesarias de memoria.
La función compara el tipo del atacante y el tipo del defensor para ver que multiplicador tendrá el ataque, se usará posteriormente en tipos.cpp




# Proyecto en Python
**Desarrollos innovadores:*
- Historial de vehiculos retirados, con el tiempo y la tarifa.
- Consulta de disponibilidad actual.
- Visualización de historial completo desde el menú
- Opcion para buscar un vehiculo por placa y ver su ubicacion actual

