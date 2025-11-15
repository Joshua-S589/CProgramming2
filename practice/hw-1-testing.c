#include <stdio.h>
int w[99];
int min;
int max;
int main(void){
    for(int i=0;i<99;i++){
        w[i]=(i+1)*(i+1);
    }
    min=w[1];
    max=w[1];
    for(int i=0;i<99;i++){
        if(w[i]<min){
            min=w[i];
        }
        else if(w[i]>max){
            max=w[i];
        }
    }
    printf("The min is %d, and the max is %d\n", min, max);
}