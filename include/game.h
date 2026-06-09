#ifndef GAME_H
#define GAME_H

#include <stdio.h>

#include "structs.h"
#include "defs.h"
#include "linked_list.h"

void simulate_battle(
    Pokemon p1_pokemon_list[MAX_POKEMONS],
    Pokemon p2_pokemon_list[MAX_POKEMONS],
    int p1_pokemon_quant,
    int p2_pokemon_quant,
    pokemon_names *defeated_pokemon,
    pokemon_names *surviving_pokemon);

#endif