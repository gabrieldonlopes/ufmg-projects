#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <string.h> 
#include "defs.h"
#include "structs.h"

FILE *read_file(char *file_name,
                int *p1_pokemon_quant,
                int *p2_pokemon_quant);
                
int load_pokemons(FILE *file, int pokemon_quant, Pokemon pokemons_list[MAX_POKEMONS]);

#endif