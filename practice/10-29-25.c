#include <stdio.h>
double arr[5][5];
double sumArr(int rows, int cols, double arr[rows][cols]);
double sum;
int main(void){
    for(int i=0;i<5;i++){
        for(int j=1;j<=5;j++){
            arr[(i+1)][j]=(i*5)+j;
        }
    }
    arr[1][2]=24;
    arr[3][3]=43;
    sumArr(5, 5, arr);
    arr[5][5]=sum;
    arr[4][5]=20;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            printf("%7.1f", arr[i][j]);
        }
        printf("\n");
    }
}
double sumArr(int rows, int cols, double arr[rows][cols]){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            sum+=arr[i][j];
        }
    }
}