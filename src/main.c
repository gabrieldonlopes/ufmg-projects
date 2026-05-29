#include <stdio.h>

#include "defs.h"
#include "structs.h"
#include "file_handler.h"
#include "game.h"

int main(){
    // vetores que vão guardar pokemons
    Pokemon p1_pokemons[MAX_POKEMONS];
    Pokemon p2_pokemons[MAX_POKEMONS];
    
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

    simulate_battle(p1_pokemons, p2_pokemons, p1_pokemons_quant, p2_pokemons_quant);

    return 0;
}