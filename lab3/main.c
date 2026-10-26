#include <stdio.h>
#include "monster.h"
#include <stdlib.h>
#include "army.h"

int main(){
    struct army* pokemon=create_army();
    for (int i=0; i<10; i++){
        char temp_arr[10];
        snprintf(temp_arr, 10, "Pikachu-%d", i);
        struct monster* m=create_monster(temp_arr, 100);
        add_monster_to_army(pokemon, m);
    }
    display_army(pokemon);
    for (int i=0; i<pokemon->top; i++){
        delete_monster(pokemon->monsters[i]);
    }
    delete_army(pokemon);
    return 0;
}