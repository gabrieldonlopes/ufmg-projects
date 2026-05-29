#include "game.h"
/* 
--------------------------------------------------------
# game.c
#
# Description: funções para simulação de batalha
# Autor: gdon - gabriellopes.zip@gmail.com
# Version: 1.0
# Data: 
--------------------------------------------------------
*/

// nota: talvez exista uma abordagem forma melhor utilizando os inteiros
// associados aos enums
/*
    1=ataques com vantagem
   -1=ataques com desvantagem
    0=ataques normais
*/
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

/* 
    nota: no jogo orignal ataque super efetivos dão o 200% de dado
    ataques pouco efetivos dão 50% de dano
*/
void check_battle_result(Pokemon *attacker, Pokemon *deffender){
    float attack_mod = 1.0;

    if (check_type_advantage(*attacker, *deffender)==1) 
        attack_mod = 1.2;
    else if(check_type_advantage(*attacker,*deffender)==-1) 
        attack_mod = 0.8;

    if(attacker->attack*attack_mod > deffender->defense)
        deffender->hp -= attacker->attack*attack_mod - deffender->defense;
    else
        deffender->hp -= 1.0;
}

void check_surviving_pokemons(Pokemon p_pokemon_list[MAX_POKEMONS],int p_pokemon_quant,pokemon_list *surviving_pokemon){
    for (int i = 0; i < p_pokemon_quant; i++){
        if(p_pokemon_list[i].hp > 0) // adicionando na lista pokemons que não foram desmaiados (mortos)
            append_pokemon(surviving_pokemon, p_pokemon_list[i].name);
    }
}

void simulate_battle(
    Pokemon p1_pokemon_list[MAX_POKEMONS],
    Pokemon p2_pokemon_list[MAX_POKEMONS],
    int p1_pokemon_quant,
    int p2_pokemon_quant,
    pokemon_list *defeated_pokemon,
    pokemon_list *surviving_pokemon
){
    int p1_index = 0, p2_index = 0;
    int attacker_player = 1; // player 1 começa atacando

    printf("\n"); // pulando uma linha para separar saídas

    // loop até o index alcançar a quantidade de pokemons, ou seja todos pokemons
    // de um jogador forem derrotados
    while (p1_index < p1_pokemon_quant && p2_index < p2_pokemon_quant){
        Pokemon *attacker;
        Pokemon *defender;

        // determinando quem vai atacar baseado no turmo
        if (attacker_player == 1){ 
            attacker = &p1_pokemon_list[p1_index];
            defender = &p2_pokemon_list[p2_index];
        } else {
            attacker = &p2_pokemon_list[p2_index];
            defender = &p1_pokemon_list[p1_index];
        }

        check_battle_result(attacker, defender); // simulando um turno da batalha
        
        // avaliando resultados da batalha
        if (defender->hp <= 0){
            printf(
                "%s venceu %s\n",
                attacker->name,
                defender->name
            );

            // adicionando pokemon na lista dos derrotados
            append_pokemon(defeated_pokemon, defender->name);

            // quando o pokemon é derrotado o próximo a entrar vai atacar primeiro
            if (attacker_player == 1){
                p2_index++;
                attacker_player = 0;
            } else {
                p1_index++;
                attacker_player = 1;
            }
        } else {
            attacker_player = !attacker_player; // inverte o atacante caso o golpe não seja fatal
        }
    }
    
    if (p1_index >= p1_pokemon_quant){
        printf("Jogador 2 venceu\n");
        check_surviving_pokemons(p2_pokemon_list, p2_pokemon_quant, surviving_pokemon);
    } else {
        printf("Jogador 1 venceu\n");
        check_surviving_pokemons(p1_pokemon_list, p1_pokemon_quant, surviving_pokemon);
    }
}