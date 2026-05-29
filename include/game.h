#ifndef GAME_H
#define GAME_H

#include <stdio.h>

#include "structs.h"
#include "defs.h"

void simulate_battle(Pokemon p1_pokemon_list[MAX_POKEMONS], Pokemon p2_pokemon_list[MAX_POKEMONS], int p1_pokemon_quant, int p2_pokemon_quant);

#endif