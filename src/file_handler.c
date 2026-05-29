#include "file_handler.h"

// todo: adicionar print dos dados lidos
int load_pokemons(FILE *file,int pokemon_quant, Pokemon pokemons_list[MAX_POKEMONS]){
    // populando vetor com pokemons do jogador
    for (int i = 0; i < pokemon_quant; i++){
        
        // lendo dados do pokemon
        char name[50];
        int attack, defense, hp;
        char type[20];
        pokemon_type type_enum;

        // testando se a entrada do fscanf está correta
        if (fscanf(file, "%s %d %d %d %s",
                   name,
                   &attack,
                   &defense,
                   &hp,
                   type) != 5) return 1;
                   
        // nota: estou usando strcmp do string.h para facilitar comparações entre strings
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
        else
            return 1; // se entrada for diferente do esperado retorna erro

        
        strcpy(pokemons_list[i].name, name);
        pokemons_list[i].attack = attack;
        pokemons_list[i].defense = defense;
        pokemons_list[i].hp = hp;
        pokemons_list[i].type = type_enum;
    }

    return 0;
}

int read_file(char* file_name,
              int *p1_pokemon_quant,
              int *p2_pokemon_quant,
              Pokemon p1_pokemons[MAX_POKEMONS],
              Pokemon p2_pokemons[MAX_POKEMONS])
    {

    FILE *file = fopen(file_name,"r"); 
    if (file == NULL) return 1; // caso encontre problemas ao abrir arquivo

    // lendo quantidade de pokemons de cada jogador
    fscanf(file, "%d %d", p1_pokemon_quant, p2_pokemon_quant);

    // garantindo que dados passados sejam válidos
    if(*p1_pokemon_quant == 0 || *p2_pokemon_quant == 0) return 1;
    if(*p1_pokemon_quant > MAX_POKEMONS || *p2_pokemon_quant > MAX_POKEMONS) return 0;

    // carregando pokemons dos players
    if(load_pokemons(file, *p1_pokemon_quant, p1_pokemons))
        return 1;
    if (load_pokemons(file, *p2_pokemon_quant, p2_pokemons)){//
        return 1;
    }

    fclose(file);

    return 0;
}
