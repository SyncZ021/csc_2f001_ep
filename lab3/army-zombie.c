#include <stdio.h>
#include <stdlib.h>
#include "army.h"

struct army{
    struct monster** monsters;
    int top;
    int capacity;
    int stars;
}

struct army* create_army(){
    struct army* a=malloc(sizeof(*a));
    a->monsters=NULL;
    a->top=0;
    a->capacity=0;
    a->stars=0;
    return a;
}

void add_monster_to_army(struct army* a, struct monster* m){
    if (a->top==a->capacity){ // if the array is full
        if (a->capacity==0){
            a->capacity=1;
        }
        else{
            a->capacity*=2;
        }
        struct monster** larger_array=malloc(a->capacity*sizeof(struct monster*));
        for (int i=0; i<a->top; i++){
            larger_array[i]=a->monsters[i];
        }
        free(a->monsters);
        a->monsters=larger_array;
    }
    a->monsters[a->top]=m;
    a->top+=1;
}

void display_army(struct army* a){
    for (int i=0; i<a->top; i++){
        display_monster(a->monsters[i]);
    }
    printf("This is a %d stars army\n", a->stars);
}

void delete_army(struct army* a){
    free(a->monsters);
    free(a);
}