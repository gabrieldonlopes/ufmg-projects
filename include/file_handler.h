#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <string.h> 
#include "defs.h"
#include "structs.h"

int read_file(char *file_name,
              int *p1_pokemon_quant,
              int *p2_pokemon_quant,
              Pokemon p1_pokemons[MAX_POKEMONS],
              Pokemon p2_pokemons[MAX_POKEMONS]);

#endif