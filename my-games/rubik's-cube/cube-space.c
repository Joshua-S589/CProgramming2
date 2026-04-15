#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "/workspaces/CProgramming2/functions/time-struct.h"
#include "two-x-two.h"
#include "three-x-three.h"
#include "four-x-four.h"
#include "five-x-five.h"
char cubeChoice;
void main(void){
    printf("Welcome to the various Rubik's cube puzzles!\n");
    printf("Which cube would you like to play?\n");
    printf("2x2 (2), 3x3 (3), 4x4 (4), or 5x5 (5)? ");
    scanf(" %c", &cubeChoice);
    while(cubeChoice!='2'&&cubeChoice!='3'&&cubeChoice!='4'&&cubeChoice!='5'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Which cube would you like to play?\n");
        printf("2x2 (2), 3x3 (3), 4x4 (4), or 5x5 (5)? ");
        scanf(" %c", &cubeChoice);
    }
    if(cubeChoice=='2'){
        twoXtwo();
    }
    else if(cubeChoice=='3'){
        threeXthree();
    }
    // else if(cubeChoice=='4'){
    //     4x4();
    // }
    // else if(cubeChoice=='5'){
    //     5x5();
    // }
    return;
}