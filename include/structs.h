#ifndef STRUCTS_H
#define STRUCTS_H

#include "defs.h"

// usei enum para poder facilitar calculos de vantagens
typedef enum {
    ELETRIC,
    WATER,
    FIRE,
    ICE,
    ROCK    
} pokemon_type;

typedef struct {
    char name[NAME_SIZE]; // fixando tamanho máximo do nome de um pokemon
    int attack;
    int defense;
    float hp;
    pokemon_type type;
} Pokemon;

// linked list para guardar dados dos pokemons derrotados e sobreviventes
typedef struct node {
    char name[NAME_SIZE];
    struct node *next; // guardando ponteiro para o próximo valor
} pokemon_names;

#endif