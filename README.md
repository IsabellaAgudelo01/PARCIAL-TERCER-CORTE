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
Función que le permitirá al jugador seleccionar su equipo, el nombre será constante y serán definidos más adelante entre JUGADOR 1 y JUGADOR 2

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
Es una librería que en general se enfoca en gestión de memoria, conversión de números, generación de números aleatorios, comandos del sistema operativo, etc
Se usa esta librería específicamente con fines de usar la función system().
system("cls"): Esta función limpia la pantalla de la consola
system("pause"): pausa el programa y espera que el usuario presione una tecla para continuar

2. Función mostrar_menu_inicio
```cpp
void mostrar_menu_inicio() {
    bool continuar = true;
    int opcion;

    do {
        system("cls"); // Limpia pantalla

        cout << "\t\t\t" << endl;
        cout << "\t\t\t POKEMON " << endl;
        cout << "\t\t\t" << endl;

        cout << "\n\t1. Iniciar Duelo" << endl;
        cout << "\t2. Salir" << endl;

        cout << "\n\tElija una opción: ";
        cin >> opcion;
```
Hace que el menú se siga repitiendo mientras continuar sea true, en cada repetición mediante la función system("cls") se limpia la pantalla
3. 
```cpp
                if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        }

 }
```
Evita que el programa se detenga si el usuario escribe letras en vez de números.
if(cin.fail()) se encarga de verificar si la entrada ha fallado, es decir cuando se ingresa por ejemplo una letra, para poder seguir se debe limpiar
cin.clear() limpia el cin para que deje de ser inválido
cin.ignore(100, '\n') elimina todo lo que quedó ingresado, hasta 1000 caracteres
opcion = -1 ya que la entrada es válida, se le da valor -1 a opcion para indicar que no es válida, esto luego será de ayuda para el switch
cabe recalcar esta parte del código fue apoyada con chatgpt para entender como se llevaría a cabo esta condición 

4. switch
```cpp
 switch (opcion) {
 case 1: {
     auto equipo1 = seleccionar_equipo("JUGADOR 1");
     auto equipo2 = seleccionar_equipo("JUGADOR 2");
     iniciar_duelo(equipo1, equipo2);
     system("pause");
     break;
 }
 case 2:
     cout << "\n\tSaliendo del juego..." << endl;
     continuar = false;
     break;
 default:
     cout << "\n\tOpción no válida. Intente de nuevo." << endl;
     system("pause");
     break;
 }
```
Maneja las opciones del menú dependiendo de lo que haya ingresado el usuario. 
el auto en este caso funciona como deducción automática, es decir que el compilador averigua qué tipo devuelve la función

5. Función seleccionar_equipo
```cpp
vector<Pokemon> seleccionar_equipo(const string& nombre_jugador) {
    vector<Pokemon> seleccionados;
    vector<Pokemon> catalogo = obtener_catalogo();
```
Anteriormente ya se ha escogido nombre_jugador como JUGADOR 1 o JUGADOR 2



# Proyecto en Python
**Desarrollos innovadores:*
- Historial de vehiculos retirados, con el tiempo y la tarifa.
- Consulta de disponibilidad actual.
- Visualización de historial completo desde el menú
- Opcion para buscar un vehiculo por placa y ver su ubicacion actual

