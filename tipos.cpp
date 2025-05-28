#include "tipos.h"
using namespace std;

vector<Pokemon> obtener_catalogo() {
    return {
        {"Pikachu", "Eléctrico", 100, 5, {
            {"Impactrueno", 20, 2},
            {"Placaje", 10, 1}
        }},
        {"Charmander", "Fuego", 100, 5, {
            {"Ascuas", 25, 2},
            {"Arañazo", 15, 1}
        }},
        {"Squirtle", "Agua", 100, 5, {
            {"Pistola Agua", 22, 2},
            {"Placaje", 12, 1}
        }},
        {"Bulbasaur", "Planta", 100, 5, {
            {"Látigo Cepa", 18, 2},
            {"Gruñido", 8, 1}
        }},
        {"Eevee", "Normal", 100, 5, {
            {"Ataque Rápido", 20, 2},
            {"Mordisco", 15, 1}
        }},
        {"Meowth", "Normal", 100, 5, {
            {"Garra Metal", 30, 2},
            {"Golpe Furia", 22, 1}
        }}
    };
}

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
    else if (tipo_atacante == "Agua") {
        if (tipo_defensor == "Fuego") {
            return 1.5;
        }
        else if (tipo_defensor == "Planta") {
            return 0.5;
        }
        else {
            return 1.0;
        }
    }
    else if (tipo_atacante == "Planta") {
        if (tipo_defensor == "Agua") {
            return 1.5;
        }
        else if (tipo_defensor == "Fuego") {
            return 0.5;
        }
        else {
            return 1.0;
        }
    }
    else {
        return 1.0;
    }
}
