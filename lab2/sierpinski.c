#include <stdio.h>

int sort_get_index(float tab[], int top, float val){
    for (int i=0; i<top; i++){
        if (tab[i]>val){
            return i;
        }
    }
    return top;
}

void sort_insert_at(float tab[], int i, int top, float val){
    for (int j=top; j>i; j--){
        tab[j]=tab[j-1];
    }
    tab[i]=val;
}

void sort_insert(float tab[], int top, float val){
    int index=sort_get_index(tab, top, val);
    sort_insert_at(tab, index, top, val);
}

int nb_columns(){
    return 32;
}

int nb_lines(){
    return 16;
}

int main(void) {
    float tab[5]={1, 3, 5, 7, 0};
    int cols=nb_columns();
    int lines=nb_lines();
    int chars=cols*lines;
    char grid[chars];
    grid[0]='*';
    printf("%c\n", grid[0]);
    for (int i=0; i<5; i++){
        printf("%f\n", tab[i]);
    }
    return 0;
}



