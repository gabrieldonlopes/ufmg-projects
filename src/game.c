#include "game.h"

int check_type_advantage(Pokemon p1, Pokemon p2){
    switch (p1.type){
        case ELETRIC:
            if (p2.type == WATER) return 1;
            else if (p2.type == ROCK) return -1;
            else return 0;
        case WATER:
            if (p2.type == FIRE) return 1;
            else if (p2.type == ELETRIC) return -1;
            else return 0;        
        case FIRE:
            if (p2.type == ICE) return 1;
            else if (p2.type == WATER) return -1;
            else return 0;        
        case ICE:
            if (p2.type == ROCK) return 1;
            else if (p2.type == FIRE) return -1;
            else return 0;        
        case ROCK:
            if (p2.type == ELETRIC) return 1;
            else if (p2.type == ICE) return -1;
            else return 0;        
    }
}

void check_battle_result(Pokemon *p1, Pokemon *p2){
    float attack_mod = 1.0;

    if (check_type_advantage(*p1, *p2)==1) 
        attack_mod = 1.2;
    else if(check_type_advantage(*p1,*p2)==-1) 
        attack_mod = 0.8;

    if(p1->attack > p2->defense)
        p2->hp -= (p1->attack*attack_mod)  - p2->defense;
    else
        p2->hp -= 1.0;
    
}

void simulate_battle(
    Pokemon p1_pokemon_list[MAX_POKEMONS],
    Pokemon p2_pokemon_list[MAX_POKEMONS],
    int p1_pokemon_quant,
    int p2_pokemon_quant
){
    int i = 0;
    int c = 0;

    while (i < p1_pokemon_quant && c < p2_pokemon_quant){

        // P1 ataca P2
        check_battle_result(&p1_pokemon_list[i], &p2_pokemon_list[c]);

        if (p2_pokemon_list[c].hp <= 0){
            printf("%s venceu %s\n",
                p1_pokemon_list[i].name,
                p2_pokemon_list[c].name
            );

            c++;

            // evita contra-ataque de pokemon morto
            if (c >= p2_pokemon_quant)
                break;
        }

        // P2 ataca P1
        check_battle_result(&p2_pokemon_list[c], &p1_pokemon_list[i]);

        if (p1_pokemon_list[i].hp <= 0){
            printf("%s venceu %s\n",
                p2_pokemon_list[c].name,
                p1_pokemon_list[i].name
            );

            i++;

            // evita contra-ataque de pokemon morto
            if (c >= p2_pokemon_quant)
                break;
        }
    }

    if (i >= p1_pokemon_quant)
        printf("Jogador 2 venceu!\n");
    else
        printf("Jogador 1 venceu!\n");
}