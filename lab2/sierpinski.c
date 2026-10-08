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

void grid_init(char* grid, char pixel){
    int cols1=nb_columns();
    int lines1=nb_lines();
    int chars1=cols1*lines1;
    for (int i=0; i<chars1; i++){
        grid[i]=pixel;
    }
}

void grid_display(char* grid){
    int cols2=nb_columns();
    int lines2=nb_lines();
    for (int i=0; i<lines2; i++){
        for (int j=0; j<cols2; j++){
            printf("%c", grid[i*cols2+j]);
        }
        printf("\n");
    }
}

void plot_point(char* grid, int x, int y, char pixel){
    int cols3=nb_columns();
    int lines3=nb_lines(); 
    int row=lines3-y-1;
    int col=x;
    grid[row*cols3+col]=pixel;
}

int main(void) {
    int cols=nb_columns();
    int lines=nb_lines();
    int chars=cols*lines;
    char grid[chars];
    grid_init(grid, '*');
    plot_point(grid, 3, 1, ' ');
    grid_display(grid);
    return 0;
}



