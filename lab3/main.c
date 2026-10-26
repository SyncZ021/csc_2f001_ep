#include <stdio.h>
#include "monster.h"
#include <stdlib.h>

int main(){
    int num_monsters=10;
    // monster: array of pointers(**)
    struct monster** monsters=malloc(num_monsters*sizeof(struct monster));
    for (int i=0; i<num_monsters; i++){
        char temp_arr[10];
        snprintf(temp_arr, 10, "Pikachu-%d", i);
        monsters[i]=create_monster(temp_arr, 100);
    }
    for (int i=0; i<num_monsters; i++){
        display_monster(monsters[i]);
    }
    for (int i=0; i<num_monsters; i++){
        delete_monster(monsters[i]);
    }
    free(monsters);
    return 0;
}