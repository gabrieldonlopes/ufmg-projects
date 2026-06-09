#include "linked_list.h"

/* 
--------------------------------------------------------
# linked_list.c
#
# Description: funções para manipular array dinâmica 
#              de pokemons derrotados e sobreviventes
# Autor: gdon - gabriellopes.zip@gmail.com
# Version: 1.0
# Data: 
--------------------------------------------------------
*/


// função para adicionar um novo valor no final da lista dinâmica
void append_pokemon(pokemon_names * head, char new_name[NAME_SIZE]){
    pokemon_names *current = head;
    while (current->next != NULL){
        current = current->next; // percorrer toda lista até o final
    }

    // alocando espaço para novo item
    current->next = (pokemon_names *) malloc(sizeof(pokemon_names));
    
    // adicionando ele na lista
    strcpy(current->next->name, new_name);
    current->next->next = NULL;
}

void print_pokemon_list(pokemon_names *head){
    pokemon_names *current = head;

    while(current!=NULL){ // circulando nodes até chegar num vazio
        printf("%s\n", current->name);
        current = current->next;
    }
}

void free_pokemon_list(pokemon_names *head){
    pokemon_names *current = head, *next = head;

    while(current){
        next = current->next;
        free(current); // liberando memória do elemento
        current = next;
    }
}