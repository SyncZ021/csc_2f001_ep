#include <stdio.h>

int sort_get_index(float tab[], int top, float val){
    for (int i=0; i<top; i++){
        if (tab[i]>val){
            return i;
        }
    }
    return top;
}

int main(void) {
    float tab[5]={1, 3, 5, 7, 0};
    for (int i=0; i<5; i++){
        printf("%f\n", tab[i]);
    }
    int sort1=sort_get_index(tab, 4, 0);
    int sort2=sort_get_index(tab, 4, 3.5);
    int sort3=sort_get_index(tab, 4, 10);
    printf("Insert %d at %d, %.1f at %d, %d at %d\n", 0, sort1, 3.5, sort2, 10, sort3);
    return 0;
}

