#ifndef STUCTS_H
#define STRUCTS_H

typedef enum {
    FIRE,
    ICE,
    ROCK,
    ELETRIC,
    WATER    
} pokemon_type;

typedef struct {
    char name[50];
    int attack;
    int defense;
    int hp;
    pokemon_type type;
} Pokemon;

#endif