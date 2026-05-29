#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list {
    char name[50];
    struct linked_list *next;
} pokemon_list;

void append_pokemon(pokemon_list *head, char new_name[50]);
void print_pokemon_list(pokemon_list *head);
void free_pokemon_list(pokemon_list *head);

#endif