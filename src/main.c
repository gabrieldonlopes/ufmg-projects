#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "structs.h"
#include "file_handler.h"
#include "game.h"
#include "linked_list.h"

int main(){
    // vetores que vão guardar pokemons
    Pokemon p1_pokemons[MAX_POKEMONS];
    Pokemon p2_pokemons[MAX_POKEMONS];
    
    // listas dinâmicas para guardar pokemons derrotados e sobreviventes
    pokemon_list *defeated_pokemon = (pokemon_list *) malloc(sizeof(pokemon_list));
    defeated_pokemon->next = NULL;

    pokemon_list *surviving_pokemon = (pokemon_list *) malloc(sizeof(pokemon_list));
    surviving_pokemon->next = NULL;

    int p1_pokemons_quant;
    int p2_pokemons_quant;

    if(read_file(
        "test.txt",
        &p1_pokemons_quant,
        &p2_pokemons_quant,
        p1_pokemons,
        p2_pokemons)){
        printf("erro abrir e carregar dados!\n");
        return 1;
    }

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