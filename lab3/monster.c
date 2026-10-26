#include <stdio.h>
#include "monster.h"
#include <stdlib.h> 
#include <string.h>

struct monster* create_monster(char* name, int hp){
    struct monster* m=malloc(sizeof(*m));
    strncpy(m->name, name, 256);
    m->hp=hp;
    return m;
}

void display_monster(struct monster* m){
    printf("Name: %s, HP: %d\n", m->name, m->hp);
}

void delete_monster(struct monster* m){
    free(m);
}