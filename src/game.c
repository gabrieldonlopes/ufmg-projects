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

    if(p1->attack*attack_mod > p2->defense)
        p2->hp -= p1->attack*attack_mod - p2->defense;
    else
        p2->hp -= 1.0;
    
}

void simulate_battle(
    Pokemon p1_pokemon_list[MAX_POKEMONS],
    Pokemon p2_pokemon_list[MAX_POKEMONS],
    int p1_pokemon_quant,
    int p2_pokemon_quant
){
    int p1_index = 0;
    int p2_index = 0;
    int attacker_player = 1; // player 1 começa atacando

    while (p1_index < p1_pokemon_quant && p2_index < p2_pokemon_quant){
        Pokemon *attacker;
        Pokemon *defender;

        // quando o pokemon do p2 perde 
        if (attacker_player == 1){ 
            attacker = &p1_pokemon_list[p1_index];
            defender = &p2_pokemon_list[p2_index];
        }
        else{
            attacker = &p2_pokemon_list[p2_index];
            defender = &p1_pokemon_list[p1_index];
        }

        check_battle_result(attacker, defender);
        if (defender->hp <= 0){
            printf(
                "%s venceu %s\n",
                attacker->name,
                defender->name
            );

            if (attacker_player == 1){
                p2_index++;
                attacker_player = 0;
            }
            else{
                p1_index++;
                attacker_player = 1;
            }
        }
        else{
            attacker_player = !attacker_player; // inverte o atacante caso o golpe não seja fatal
        }
    }

    if (p1_index >= p1_pokemon_quant)
        printf("Jogador 2 venceu!\n");
    else
        printf("Jogador 1 venceu!\n");
}