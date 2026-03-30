#include <stdio.h>

void functionCollatz(int n);
int collatz;

void main(int n){
    int i = 10;
    while(i >= 1){
        printf("%d\n", i);
        i = i - 1;
    }
    puts("BOOM!!!!!!");
    scanf("%d", &collatz);
    functionCollatz(collatz);
}

void functionCollatz(int n){
    while(!collatz == 1){
        while(collatz % 2 == 0){
            printf("%d\n", collatz);
            collatz = collatz / 2;
        }
        while(!collatz % 2 == 0){
            printf("%d\n", collatz);
            collatz = (collatz * 3) + 1;
        }
    }
}