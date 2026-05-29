#include "linked_list.h"



// função para adicionar um novo valor no final da lista dinâmica
void append_pokemon(pokemon_list * head, char new_name[50]){
    pokemon_list *current = head;
    while (current->next != NULL){
        current = current->next; // percorrer toda lista até o final
    }

    // alocando espaço para novo item
    current->next = (pokemon_list *) malloc(sizeof(pokemon_list));
    
    // adicionando ele na lista
    strcpy(current->next->name, new_name);
    current->next->next = NULL;
}

void print_pokemon_list(pokemon_list *head){
    pokemon_list *current = head;

    while(current!=NULL){
        printf("%s\n", current->name);
        current = current->next;
    }
}

void free_pokemon_list(pokemon_list *head){
    pokemon_list *current = head, *next = head;

    while(current){
        next = current->next;
        free(current); // liberando memória do elemento
        current = next;
    }
}