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

# _Archivo tipo.cpp_
1. Función vector<Pokemon> obtener_catalogo()
```cpp
vector<Pokemon> obtener_catalogo(){
    return {
        {"Pikachu", "Eléctrico", 100, 5, {
            {"Impactrueno", 20, 2},
            {"Placaje", 10, 1}
        }},
-
-
-

```
Esta función como ya se había nombrado anteriormente, va a guardar en la lista un pokemon en este caso llamado pikachu de tipo electrico junto con las estadísticas, así mismo guarda los ataques disponibles con los efectos que tienen. Este proceso se repite con los otros pokemones en la lista.

2. Función float calcular_multiplicador(...)
```cpp
float calcular_multiplicador(const string& tipo_atacante, const string& tipo_defensor) {
    if (tipo_atacante == "Fuego") {
        if (tipo_defensor == "Planta") {
            return 1.5;
        }
        else if (tipo_defensor == "Agua") {
            return 0.5;
        }
        else {
            return 1.0;
        }
    }
```
Como ya se había mencionado anteriormente, la función compara el tipo del atacante y el tipo del defensor. Dependiendo del tipo de atacante y el tipo defensor, se añadirá un multiplicador. Ejemplo es si el atacante es de fuego y el defensor es de planta, entonces el de fuego tiene una ventaja y por tanto gana un multiplicador de 1.5 de daño por encime de la planta. En caso de no haber ventaja por ningún lado, el multiplicador de daño será de 1.0

# _Archivo menu.h_
1. Funciones
```cpp
void mostrar_menu_inicio();
```
no recibe ni retorna nada (void), simplemente declara una función llamada mostrar_menu_inicio

```cpp
vector<Pokemon> seleccionar_equipo(const string& nombre_jugador);
```
Función que le permitirá al jugador seleccionar su equipo, el nombre será constante y serán definidos más adelante entre jugador 1 y jugador 2

```cpp
void iniciar_duelo(vector<Pokemon>& equipoA, vector<Pokemon>& equipoB);
```
Declara una función que se encargará de manejar batalla entre dos equipos pokemon.
Las referencias & de los vectores pokemon indican que puede modificar los equipos, como por ejemplo cuando pierden vida.
Cabe recalcar que si no se pone el & entonces la función estaría trabajando sobre una copia de los pokemones y no afectaría directamente las estadísticas de estos

```cpp
void mostrar_stats(const vector<Pokemon>& equipo, const string& jugador);
```
Este declara las estadísticas, toma un jugador (por ejemplo jugador 1) y muestra la lista de su equipo guardada en vector<pokemon>, se pone const porque esta función tiene como único objetivo mostrar los valores mas no modificarlo

# _Archivo menu.cpp_
1. librería
```cpp
#include <cstdlib>
```
Es una librería que en general se enfoca en gestión de memoria, conversión de números


# Proyecto en Python
**Desarrollos innovadores:*
- Historial de vehiculos retirados, con el tiempo y la tarifa.
- Consulta de disponibilidad actual.
- Visualización de historial completo desde el menú
- Opcion para buscar un vehiculo por placa y ver su ubicacion actual

