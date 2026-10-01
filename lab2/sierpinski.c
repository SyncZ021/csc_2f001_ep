#include <stdio.h>

int main(void) {
    float tab[]={1, 3, 5, 7, 0};
    for (int i=0; i<5; i++){
        printf("%f\n", tab[i]);
    }
    return 0;
}