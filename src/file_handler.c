#include "file_handler.h"

/* 
--------------------------------------------------------
# file_handler.c
#
# Description: funções de acesso e leitura arquivo de entrada
# Autor: gdon - gabriellopes.zip@gmail.com
# Version: 1.0
# Data: 
--------------------------------------------------------
*/

int load_pokemons(FILE *file,int pokemon_quant, Pokemon pokemons_list[MAX_POKEMONS]){
    for (int i = 0; i < pokemon_quant; i++){
        
        // lendo dados do pokemon
        char name[NAME_SIZE];
        int attack, defense, hp;
        char type[20]; // hardcodando o tamanho da string de tipo. não é uma boa prática, mas cumpre seu papel aqui
        pokemon_type type_enum;

        // testando se a entrada do fscanf está correta
        if (fscanf(file, "%s %d %d %d %s",
                   name,
                   &attack,
                   &defense,
                   &hp,
                   type) != 5){ // o valor de 5 é para garantir que entrada esteja de acordo com padrão

            printf("entrada de dados fora do padrão\n");
            return 1;
        }
        
        // printando dados lidos
        printf("%s %d %d %d %s\n",
                    name, 
                    attack,
                    defense,
                    hp,
                    type);
        
        // transformando a string recebida na enum 
        if (strcmp(type, "fogo") == 0)
            type_enum = FIRE;
        else if (strcmp(type, "gelo") == 0)
            type_enum = ICE;
        else if(strcmp(type,"pedra") == 0)
            type_enum = ROCK;
        else if(strcmp(type,"agua") == 0 || strcmp(type,"água") == 0)
            type_enum = WATER;
        else if(strcmp(type,"eletrico") == 0 || strcmp(type,"elétrico") == 0)
            type_enum = ELETRIC;
        else{
            printf("tipo de pokemon inválido\n");
            return 1; // se entrada for diferente do esperado retorna erro
        }
            

        // registrando dados na lista 
        strcpy(pokemons_list[i].name, name);
        pokemons_list[i].attack = attack;
        pokemons_list[i].defense = defense;
        pokemons_list[i].hp = hp;
        pokemons_list[i].type = type_enum;
    }
    return 0;
}

FILE* read_file(char* file_name,
              int *p1_pokemon_quant,
              int *p2_pokemon_quant)
    {

    FILE *file = fopen(file_name,"r"); 
    if (file == NULL){
        printf("Problema ao abrir arquivo\n");
        fclose(file);
        return NULL; // caso encontre problemas ao abrir arquivo
    }

    // lendo quantidade de pokemons de cada jogador
    if(fscanf(file, "%d %d", p1_pokemon_quant, p2_pokemon_quant)!=2){
        printf("entrada de dados fora do padrão\n");
        return NULL; 
    }

    printf("%d %d\n", *p1_pokemon_quant, *p2_pokemon_quant);

    // garantindo que dados passados sejam válidos (1 ≤ N ≤ 100)
    if(
        *p1_pokemon_quant == 0 || *p2_pokemon_quant == 0 ||
        *p1_pokemon_quant > MAX_POKEMONS || *p2_pokemon_quant > MAX_POKEMONS
    ){
        printf("Número de pokemons inválido. a entrada deve estar dentro do intervalo 1 ≤ N ≤ 100 \n");
        fclose(file);
        return NULL; // caso encontre problemas ao abrir arquivo
    }
    
    return file;
}