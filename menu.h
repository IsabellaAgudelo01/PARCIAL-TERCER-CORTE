#ifndef MENU_H
#define MENU_H

using namespace std;

#include "tipos.h"
#include <vector>
#include <string>

void mostrar_menu_inicio();

vector<Pokemon> seleccionar_equipo(const string& nombre_jugador);

void iniciar_duelo(vector<Pokemon>& equipoA, vector<Pokemon>& equipoB);

void mostrar_stats(const vector<Pokemon>& equipo, const string& jugador);

#endif
