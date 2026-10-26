#include <stdio.h>
#include "monster.h"

int main(){
    struct monster* pik=create_monster("Pikachu", 100);
    display_monster(pik);
    delete_monster(pik);
    return 0;
}