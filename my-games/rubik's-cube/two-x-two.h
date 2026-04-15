#ifndef TWO_TEST_H
#define TWO_TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "/workspaces/CProgramming2/functions/time-struct.h"
char white_2x2[2][2]={{'W','W'},{'W','W'}};
char red_2x2[2][2]={{'R','R'},{'R','R'}};
char blue_2x2[2][2]={{'B','B'},{'B','B'}};
char yellow_2x2[2][2]={{'Y','Y'},{'Y','Y'}};
char orange_2x2[2][2]={{'O','O'},{'O','O'}};
char green_2x2[2][2]={{'G','G'},{'G','G'}};
void scramble_2x2(void);
int startTime_2x2;
int endTime_2x2;
int totalTime_2x2;
int recordTime_2x2;
int moveCnt_2x2=0;
int rngside_2x2;
int rngdir_2x2;
bool sideCheck_2x2(char face1_2x2[2][2]);
int test_2x2;
char storage_2x2;
void rotation_2x2(void);
void rotationsingle_2x2(char *side_2x2);
char sideChoice_2x2;
int dirAmt_2x2;
void printRules_2x2(void);
void printCube_2x2(void);
char ruleChoice_2x2;
char solveChoice_2x2;
void twoXtwo(void){
    printRules_2x2();
    printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
    scanf(" %c", &solveChoice_2x2);
    while(solveChoice_2x2!='S'&&solveChoice_2x2!='M'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
        scanf(" %c", &solveChoice_2x2);
    }
    if(solveChoice_2x2=='S'){
        scramble_2x2();
        printf("\n");
        printCube_2x2();
        printf("\n");
        startTime_2x2=time(0);
        while(!sideCheck_2x2(white_2x2)||!sideCheck_2x2(red_2x2)||!sideCheck_2x2(blue_2x2)||!sideCheck_2x2(yellow_2x2)||!sideCheck_2x2(orange_2x2)||!sideCheck_2x2(green_2x2)){
            rotation_2x2();
            printf("\n");
            printCube_2x2();
            printf("\n");
            moveCnt_2x2++;
        }
        endTime_2x2=time(0);
        totalTime_2x2=endTime_2x2-startTime_2x2;
        makeTime(totalTime_2x2);
        printf("Congradulations! You've solved it in %d moves!\n", moveCnt_2x2);
        if(t.hours==0){
            if(t.minutes==0){
                printf("Time elapsed: %2d seconds\n", t.seconds);
            }
            else{
                printf("Time elapsed: %2d minutes, %2d seconds\n", t.minutes, t.seconds);
            }
        }
        else{
            printf("Time elapsed: %2d hours, %2d minutes, %2d seconds\n", t.hours, t.minutes, t.seconds);
        }
    }
    else if (solveChoice_2x2=='M'){
        printf("When you wish to finish, type 'E'\n");
        printCube_2x2();
        printf("\n");
        while(true){
            rotation_2x2();
            if(sideChoice_2x2=='E'){
                break;
            }
            printf("\n");
            printCube_2x2();
            printf("\n");
        }
    }
    return;
}
void printRules_2x2(void){
    puts("Hello, and welcome to the 2x2 Rubik's cube.");
    puts("Would you like to learn how this works? Y/N");
    scanf(" %c", &ruleChoice_2x2);
    while(ruleChoice_2x2!='Y'&&ruleChoice_2x2!='N'){
        puts("Sorry, that is unrecognized, please try again.");
        puts("Would you like to learn how this works? Y/N");
        scanf(" %c", &ruleChoice_2x2);
    }
    if(ruleChoice_2x2=='Y'){
        puts("To solve the 2x2 Rubik's cube, the goal is to have each side containing only one color.");
        puts("At each move, you will be asked which face you would like to rotate and if it is to rotate clockwise or counterclockwise, using the notation of Upper, Down, Front, Back, Right, and Left.");
        puts("Good luck solving!");
    }
    else if(ruleChoice_2x2=='N'){
        puts("It seems like you already know what you're doing! Good luck!");
    }
}
void rotation_2x2(void){
    if(solveChoice_2x2=='S'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_2x2);
        while(sideChoice_2x2!='U'&&sideChoice_2x2!='D'&&sideChoice_2x2!='F'&&sideChoice_2x2!='B'&&sideChoice_2x2!='R'&&sideChoice_2x2!='L'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_2x2);
        }
        printf("How many 90 degree rotations would you like to rotate by? ");
        scanf("%d", &dirAmt_2x2);
        for(int i=0;i<dirAmt_2x2;i++){
            rotationsingle_2x2(&sideChoice_2x2);
        }
    }
    else if(solveChoice_2x2=='M'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_2x2);
        while(sideChoice_2x2!='U'&&sideChoice_2x2!='D'&&sideChoice_2x2!='F'&&sideChoice_2x2!='B'&&sideChoice_2x2!='R'&&sideChoice_2x2!='L'&&sideChoice_2x2!='E'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_2x2);
        }
        if(sideChoice_2x2!='E'){
            printf("How many 90 degree rotations would you like to rotate by? ");
            scanf("%d", &dirAmt_2x2);
            for(int i=0;i<dirAmt_2x2;i++){
                rotationsingle_2x2(&sideChoice_2x2);
            }
        }
    }
}
void rotationsingle_2x2(char *side_2x2){
    if(*side_2x2=='F'){
        storage_2x2=green_2x2[0][0];
        green_2x2[0][0]=green_2x2[1][0];
        green_2x2[1][0]=green_2x2[1][1];
        green_2x2[1][1]=green_2x2[0][1];
        green_2x2[0][1]=storage_2x2;
        storage_2x2=white_2x2[1][0];
        white_2x2[1][0]=orange_2x2[1][1];
        orange_2x2[1][1]=yellow_2x2[0][1];
        yellow_2x2[0][1]=red_2x2[0][0];
        red_2x2[0][0]=storage_2x2;
        storage_2x2=white_2x2[1][1];
        white_2x2[1][1]=orange_2x2[0][1];
        orange_2x2[0][1]=yellow_2x2[0][0];
        yellow_2x2[0][0]=red_2x2[1][0];
        red_2x2[1][0]=storage_2x2;
    }
    else if(*side_2x2=='U'){
        storage_2x2=white_2x2[0][0];
        white_2x2[0][0]=white_2x2[1][0];
        white_2x2[1][0]=white_2x2[1][1];
        white_2x2[1][1]=white_2x2[0][1];
        white_2x2[0][1]=storage_2x2;
        storage_2x2=blue_2x2[0][1];
        blue_2x2[0][1]=orange_2x2[0][1];
        orange_2x2[0][1]=green_2x2[0][1];
        green_2x2[0][1]=red_2x2[0][1];
        red_2x2[0][1]=storage_2x2;
        storage_2x2=blue_2x2[0][0];
        blue_2x2[0][0]=orange_2x2[0][0];
        orange_2x2[0][0]=green_2x2[0][0];
        green_2x2[0][0]=red_2x2[0][0];
        red_2x2[0][0]=storage_2x2;
    }
    else if(*side_2x2=='L'){
        storage_2x2=orange_2x2[0][0];
        orange_2x2[0][0]=orange_2x2[1][0];
        orange_2x2[1][0]=orange_2x2[1][1];
        orange_2x2[1][1]=orange_2x2[0][1];
        orange_2x2[0][1]=storage_2x2;
        storage_2x2=white_2x2[0][0];
        white_2x2[0][0]=blue_2x2[1][1];
        blue_2x2[1][1]=yellow_2x2[0][0];
        yellow_2x2[0][0]=green_2x2[0][0];
        green_2x2[0][0]=storage_2x2;
        storage_2x2=white_2x2[1][0];
        white_2x2[1][0]=blue_2x2[0][1];
        blue_2x2[0][1]=yellow_2x2[1][0];
        yellow_2x2[1][0]=green_2x2[1][0];
        green_2x2[1][0]=storage_2x2;
    }
    else if(*side_2x2=='R'){
        storage_2x2=red_2x2[0][0];
        red_2x2[0][0]=red_2x2[1][0];
        red_2x2[1][0]=red_2x2[1][1];
        red_2x2[1][1]=red_2x2[0][1];
        red_2x2[0][1]=storage_2x2;
        storage_2x2=white_2x2[0][1];
        white_2x2[0][1]=green_2x2[0][1];
        green_2x2[0][1]=yellow_2x2[0][1];
        yellow_2x2[0][1]=blue_2x2[1][0];
        blue_2x2[1][0]=storage_2x2;
        storage_2x2=white_2x2[1][1];
        white_2x2[1][1]=green_2x2[1][1];
        green_2x2[1][1]=yellow_2x2[1][1];
        yellow_2x2[1][1]=blue_2x2[0][0];
        blue_2x2[0][0]=storage_2x2;
    }
    else if(*side_2x2=='D'){
        storage_2x2=yellow_2x2[0][0];
        yellow_2x2[0][0]=yellow_2x2[1][0];
        yellow_2x2[1][0]=yellow_2x2[1][1];
        yellow_2x2[1][1]=yellow_2x2[0][1];
        yellow_2x2[0][1]=storage_2x2;
        storage_2x2=green_2x2[1][0];
        green_2x2[1][0]=orange_2x2[1][0];
        orange_2x2[1][0]=blue_2x2[1][0];
        blue_2x2[1][0]=red_2x2[1][0];
        red_2x2[1][0]=storage_2x2;
        storage_2x2=green_2x2[1][1];
        green_2x2[1][1]=orange_2x2[1][1];
        orange_2x2[1][1]=blue_2x2[1][1];
        blue_2x2[1][1]=red_2x2[1][1];
        red_2x2[1][1]=storage_2x2;
    }
    else if(*side_2x2=='B'){
        storage_2x2=blue_2x2[0][0];
        blue_2x2[0][0]=blue_2x2[1][0];
        blue_2x2[1][0]=blue_2x2[1][1];
        blue_2x2[1][1]=blue_2x2[0][1];
        blue_2x2[0][1]=storage_2x2;
        storage_2x2=white_2x2[0][0];
        white_2x2[0][0]=red_2x2[0][1];
        red_2x2[0][1]=yellow_2x2[1][1];
        yellow_2x2[1][1]=orange_2x2[1][0];
        orange_2x2[1][0]=storage_2x2;
        storage_2x2=white_2x2[0][1];
        white_2x2[0][1]=red_2x2[1][1];
        red_2x2[1][1]=yellow_2x2[1][0];
        yellow_2x2[1][0]=orange_2x2[0][0];
        orange_2x2[0][0]=storage_2x2;
    }
}
bool sideCheck_2x2(char face1_2x2[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(face1_2x2[i][j]!=face1_2x2[0][0]){
                return false;
            }
        }
    }
    return true;
}
void printCube_2x2(void){
    for(int i=0;i<2;i++){
        printf("      ");
        for(int j=0;j<2;j++){
            printf(" %c", white_2x2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf(" %c", orange_2x2[i][j]);
        }
        printf("  ");
        for(int j=0;j<2;j++){
            printf(" %c", green_2x2[i][j]);
        }
        printf("  ");
        for(int j=0;j<2;j++){
            printf(" %c", red_2x2[i][j]);
        }
        printf("  ");
        for(int j=0;j<2;j++){
            printf(" %c", blue_2x2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<2;i++){
        printf("      ");
        for(int j=0;j<2;j++){
            printf(" %c", yellow_2x2[i][j]);
        }
        printf("\n");
    }
}
void scramble_2x2(void){
    int scrambleSize_2x2;
    printf("How many steps long should the scramble be? (10-15 will be enough to sufficiently scramble the cube if that is what you wish) ");
    scanf("%d", &scrambleSize_2x2);
    srand(time(0));
    for(int i=0;i<scrambleSize_2x2;i++){
        rngside_2x2=rand()%6;
        if(rngside_2x2==0){
            sideChoice_2x2='U';
        }
        else if(rngside_2x2==1){
            sideChoice_2x2='R';
        }
        else if(rngside_2x2==2){
            sideChoice_2x2='B';
        }
        else if(rngside_2x2==3){
            sideChoice_2x2='L';
        }
        else if(rngside_2x2==4){
            sideChoice_2x2='D';
        }
        else if(rngside_2x2==5){
            sideChoice_2x2='F';
        }
        for(int j=1;j<(rand()%4+1);j++){
            rotationsingle_2x2(&sideChoice_2x2);
        }
    }
}
#endif