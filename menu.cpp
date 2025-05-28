#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void mostrar_menu_inicio() {
    bool continuar = true;
    int opcion;

    do {
        system("cls"); 

        cout << "\t\t\t" << endl;
        cout << "\t\t\t POKEMON " << endl;
        cout << "\t\t\t" << endl;

        cout << "\n\t1. Iniciar Duelo" << endl;
        cout << "\t2. Salir" << endl;

        cout << "\n\tElija una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = -1;
        }

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
    } while (continuar);
}

vector<Pokemon> seleccionar_equipo(const string& nombre_jugador) {
    vector<Pokemon> seleccionados;
    vector<Pokemon> catalogo = obtener_catalogo();

    while (seleccionados.size() < 5) {
        system("cls");

        cout << "\t\t\t----------------------------------" << endl;
        cout << "\t\t\t|           " << nombre_jugador << "           |" << endl;
        cout << "\t\t\t|     SELECCIONA TUS POKEMON    |" << endl;
        cout << "\t\t\t----------------------------------" << endl;
        cout << "\nPokemons disponibles:\n\n";

        for (size_t i = 0; i < catalogo.size(); ++i) {
            cout << i + 1 << ". " << catalogo[i].nombre
                << " (Elemento: " << catalogo[i].elemento << ")\n";
        }
        cout << "0. Salir (NO permitido hasta seleccionar 5)\n";

        cout << "\nSeleccion #" << seleccionados.size() + 1 << ": ";
        int opcion;
        cin >> opcion;

        if (cin.fail() || opcion < 1 || opcion > static_cast<int>(catalogo.size())) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Opción inválida. Intenta de nuevo.\n";
            system("pause");
            continue;
        }

        bool ya_seleccionado = false;
        for (int i = 0; i < seleccionados.size(); i++) {
            if (seleccionados[i].nombre == catalogo[opcion - 1].nombre) {
                ya_seleccionado = true;
                break;
            }
        }

        if (ya_seleccionado) {
            cout << "Ya seleccionaste ese Pokemon. Elige otro.\n";
            system("pause");
        }
        else {
            seleccionados.push_back(catalogo[opcion - 1]);
            cout << catalogo[opcion - 1].nombre << " agregado a tu equipo.\n";
            system("pause");
        }
    }
    return seleccionados;
}

bool tiene_pa_para_atacar(Pokemon p) {
    for (int i = 0; i < p.movimientos.size(); i++) {
        if (p.puntos_accion >= p.movimientos[i].costoPA) {
            return true;
        }
    }
    return false;
}


void regenerar_pa(Pokemon& p) {

    int perderVida = 10;
    int ganarPA = 5;

    if (p.salud > perderVida) {
        p.salud -= perderVida;
        p.puntos_accion += ganarPA;
        cout << p.nombre << " perdió " << perderVida << " de vida y ganó " << ganarPA << " de PA.\n";
    }
    else {
        cout << p.nombre << " no tiene suficiente vida para hacer eso.\n";
    }
}


void iniciar_duelo(vector<Pokemon>& equipoA, vector<Pokemon>& equipoB) {
    int turno = 1;
    int iA = 0, iB = 0;

    while (iA < equipoA.size() && iB < equipoB.size()) {
        system("cls");
        auto& pA = equipoA[iA];
        auto& pB = equipoB[iB];

        cout << "TURNO #" << turno << endl;
        cout << "---------------------------\n";
        cout << "JUGADOR 1: " << pA.nombre << " (HP: " << pA.salud << ", PA: " << pA.puntos_accion << ")\n";
        cout << "JUGADOR 2: " << pB.nombre << " (HP: " << pB.salud << ", PA: " << pB.puntos_accion << ")\n";
        cout << "---------------------------\n";

        Pokemon& atacante = (turno % 2 != 0) ? pA : pB;
        Pokemon& defensor = (turno % 2 != 0) ? pB : pA;
        string jugador = (turno % 2 != 0) ? "JUGADOR 1" : "JUGADOR 2";

        cout << "\nTurno de " << jugador << " (" << atacante.nombre << ")\n";
        cout << "MOVIMIENTOS:\n";
        for (int j = 0; j < atacante.movimientos.size(); ++j) {
            cout << j + 1 << ". " << atacante.movimientos[j].nombre
                << " (Potencia: " << atacante.movimientos[j].potencia
                << ", PA: " << atacante.movimientos[j].costoPA << ")\n";
        }
        cout << atacante.movimientos.size() + 1 << ". Regenerar PA (pierdes 10 HP, recuperas 5 PA)\n";

        int eleccion;
        do {
            cout << "\nElige una opción (1-" << atacante.movimientos.size() + 1 << "): ";
            cin >> eleccion;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                eleccion = -1;
            }
        } while (eleccion < 1 || eleccion > atacante.movimientos.size() + 1 ||
            (eleccion != atacante.movimientos.size() + 1 &&
                atacante.movimientos[eleccion - 1].costoPA > atacante.puntos_accion));

        if (eleccion == atacante.movimientos.size() + 1) {
            regenerar_pa(atacante);
        }
        else {
            Movimiento mov = atacante.movimientos[eleccion - 1];
            atacante.puntos_accion -= mov.costoPA;

            float multiplicador = calcular_multiplicador(atacante.elemento, defensor.elemento);
            int danio = static_cast<int>(mov.potencia * multiplicador);

            if (multiplicador > 1.0)
                cout << "¡Es super efectivo!\n";
            else if (multiplicador < 1.0 && multiplicador > 0.0)
                cout << "No es muy efectivo...\n";
            else if (multiplicador == 0.0)
                cout << "No tiene efecto.\n";

            defensor.salud -= danio;
            if (defensor.salud < 0) defensor.salud = 0;

            cout << atacante.nombre << " usó " << mov.nombre
                << " y causó " << danio << " de daño.\n";
        }

        if (pA.salud <= 0) {
            cout << pA.nombre << " fue derrotado!\n";
            iA++;
        }
        if (pB.salud <= 0) {
            cout << pB.nombre << " fue derrotado!\n";
            iB++;
        }

        turno++;
        system("pause");
    }

    if (iA >= equipoA.size())
        cout << "\n¡Jugador 2 gana el duelo!\n";
    else
        cout << "\n¡Jugador 1 gana el duelo!\n";
}
