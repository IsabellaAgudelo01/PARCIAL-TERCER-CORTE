#ifndef TIPOS_H
#define TIPOS_H

#include <string>
#include <vector>
using namespace std;

struct Movimiento {
    string nombre;
    int potencia;
    int costoPA; 
};

struct Pokemon {
    string nombre;
    string elemento;
    int salud;
    int puntos_accion; 
    vector<Movimiento> movimientos;
};


vector<Pokemon> obtener_catalogo();
float calcular_multiplicador(const string& tipo_atacante, const string& tipo_defensor);

#endif
