#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void append_pokemon(pokemon_names *head, char new_name[NAME_SIZE]);
void print_pokemon_list(pokemon_names *head);
void free_pokemon_list(pokemon_names *head);

#endif