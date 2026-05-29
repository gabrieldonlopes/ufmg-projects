#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#include "structs.h"
#include "file_handler.h"
#include "game.h"
#include "linked_list.h"

/* 
--------------------------------------------------------
# main.c
#
# Description: programa de inicializacao
# Autor: gdon - gabriellopes.zip@gmail.com
# Version: 1.0
# Data: 
--------------------------------------------------------
*/

/*
    para compilar e rodar:
    gcc src/*.c -Iinclude -o pokemon && ./pokemon
*/

int main(){
    // Inicializando listas
    Pokemon p1_pokemons[MAX_POKEMONS];
    Pokemon p2_pokemons[MAX_POKEMONS];
    
    // listas dinâmicas para guardar pokemons derrotados e sobreviventes
    pokemon_list *defeated_pokemon = (pokemon_list *) malloc(sizeof(pokemon_list));
    defeated_pokemon->next = NULL;
    pokemon_list *surviving_pokemon = (pokemon_list *) malloc(sizeof(pokemon_list));
    surviving_pokemon->next = NULL;

    // index de cada lista
    int p1_pokemons_quant;
    int p2_pokemons_quant;

    // abrindo o arquivo com dados
    FILE *file = (read_file(
        "test.txt",
        &p1_pokemons_quant,
        &p2_pokemons_quant,
        p1_pokemons,
        p2_pokemons));
    if(file == NULL){
        fclose(file);
        return 1;       
    }

    // populando vetores com pokemons
    if(
        load_pokemons(file, p1_pokemons_quant, p1_pokemons) ||
        load_pokemons(file, p2_pokemons_quant, p2_pokemons)
    ){
        fclose(file);
        return 1; // caso houve algum erro encerra o programa
    }
    
    fclose(file);

    simulate_battle(
        p1_pokemons, 
        p2_pokemons, 
        
        p1_pokemons_quant, 
        p2_pokemons_quant,
        
        defeated_pokemon,
        surviving_pokemon
    );

    printf("\n");
    printf("Pokémons sobreviventes:");
    print_pokemon_list(surviving_pokemon);

    printf("\n");
    printf("Pokémons derrotados:");
    print_pokemon_list(defeated_pokemon);

    // liberando lista de pokemons
    free_pokemon_list(surviving_pokemon);
    free_pokemon_list(defeated_pokemon);

    return 0;
}