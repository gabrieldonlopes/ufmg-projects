#ifndef STRUCTS_H
#define STRUCTS_H

typedef enum {
    ELETRIC,
    WATER,
    FIRE,
    ICE,
    ROCK    
} pokemon_type;

typedef struct {
    char name[50];
    int attack;
    int defense;
    float hp;
    pokemon_type type;
} Pokemon;

// construindo uma linked list para guardar dados 
// dos pokemons derrotados e sobreviventes
typedef struct node{
    char name[50];
    struct node *next;
} pokemon_names;

#endif