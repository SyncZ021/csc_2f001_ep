#include <stdio.h>
#include <stdlib.h>
#include "army.h"

struct node{
    struct monster* monster;
    struct node* next;
}

struct army{
    struct node* first;
    int stars;
}

struct army* create_army(){
    struct army* a=malloc(sizeof(*a));
    a->first=NULL;
    a->stars=0;
    return a;
}

void add_monster_to_army(struct army* a, struct monster* m){
    struct node* n=malloc(sizeof(*n));
    n->monster=m;
    n->next=NULL;
    if (a->first==NULL){
        a->first=n;
    }
    else{
        struct node* current=a->first;
        while (current->next!=NULL){
            current=current->next;
        }
        current->next=n;
    }
}

void display_army(struct army* a){
    struct node* current=a->first;
    while (current!=NULL){
        display_monster(current->monster);
        current=current->next;
    }
    printf("This is a %d stars army\n", a->stars);
}

void delete_army(struct army* a){
    struct node* current=a->first;
    while (current!=NULL){
        struct node* n=current->next;
        free(current);
        current=n;
    }
    free(a);
}