#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/beyblade-x-parts-list.h"
void main(void){
    srand(time(0));
    // printf(" %c", blade_bx[13]);
    for(int i=0;i<50;i++){
        printf("%c", blade_bx[13][i]);
    }
    puts("");
}