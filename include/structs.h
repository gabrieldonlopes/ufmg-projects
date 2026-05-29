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

#endif