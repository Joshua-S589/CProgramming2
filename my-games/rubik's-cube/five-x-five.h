#ifndef FIVE_X_FIVE_H
#define FIVE_X_FIVE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "/workspaces/CProgramming2/functions/time-struct.h"
char white_5x5[5][5]={{'W','W','W','W','W'},{'W','W','W','W','W'},{'W','W','W','W','W'},{'W','W','W','W','W'},{'W','W','W','W','W'}};
char red_5x5[5][5]={{'R','R','R','R','R'},{'R','R','R','R','R'},{'R','R','R','R','R'},{'R','R','R','R','R'},{'R','R','R','R','R'}};
char blue_5x5[5][5]={{'B','B','B','B','B'},{'B','B','B','B','B'},{'B','B','B','B','B'},{'B','B','B','B','B'},{'B','B','B','B','B'}};
char yellow_5x5[5][5]={{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'}};
char orange_5x5[5][5]={{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'}};
char green_5x5[5][5]={{'G','G','G','G','G'},{'G','G','G','G','G'},{'G','G','G','G','G'},{'G','G','G','G','G'},{'G','G','G','G','G'}};
char whiteCheck_5x5[5][5]={{'W','W','W','W','W'},{'W','W','W','W','W'},{'W','W','W','W','W'},{'W','W','W','W','W'},{'W','W','W','W','W'}};
char redCheck_5x5[5][5]={{'R','R','R','R','R'},{'R','R','R','R','R'},{'R','R','R','R','R'},{'R','R','R','R','R'},{'R','R','R','R','R'}};
char blueCheck_5x5[5][5]={{'B','B','B','B','B'},{'B','B','B','B','B'},{'B','B','B','B','B'},{'B','B','B','B','B'},{'B','B','B','B','B'}};
char yellowCheck_5x5[5][5]={{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'},{'Y','Y','Y','Y','Y'}};
char orangeCheck_5x5[5][5]={{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'}};
char greenCheck_5x5[5][5]={{'G','G','G','G','G'},{'G','G','G','G','G'},{'G','G','G','G','G'},{'G','G','G','G','G'},{'G','G','G','G','G'}};
void scramble_5x5(void);
int startTime_5x5;
int endTime_5x5;
int totalTime_5x5;
int recordTime_5x5;
int moveCnt_5x5=0;
int rngside_5x5;
int rngdir_5x5;
int rnglayer_5x5;
bool sideCheck_5x5(char face1_5x5[5][5], char face2_5x5[5][5]);
int test_5x5;
char storage_5x5;
void rotation_5x5(void);
void rotationsingle_5x5(char *side_5x5, int *layers_deep);
char sideChoice_5x5;
int layerChoice_5x5;
int dirAmt_5x5;
void printRules_5x5(void);
void printCube_5x5(void);
char ruleChoice_5x5;
char solveChoice_5x5;
void rotationFace_5x5(char face[5][5]);
void fiveXfive(void){
    printRules_5x5();
    printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
    scanf(" %c", &solveChoice_5x5);
    while(solveChoice_5x5!='S'&&solveChoice_5x5!='M'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
        scanf(" %c", &solveChoice_5x5);
    }
    if(solveChoice_5x5=='S'){
        scramble_5x5();
        printf("\n");
        printCube_5x5();
        printf("\n");
        startTime_5x5=time(0);
        while(!sideCheck_5x5(white_5x5, whiteCheck_5x5)||!sideCheck_5x5(red_5x5, redCheck_5x5)||!sideCheck_5x5(blue_5x5, blueCheck_5x5)||!sideCheck_5x5(yellow_5x5, yellowCheck_5x5)||!sideCheck_5x5(orange_5x5, orangeCheck_5x5)||!sideCheck_5x5(green_5x5, greenCheck_5x5)){
            rotation_5x5();
            printf("\n");
            printCube_5x5();
            printf("\n");
            moveCnt_5x5++;
        }
        endTime_5x5=time(0);
        totalTime_5x5=endTime_5x5-startTime_5x5;
        makeTime(totalTime_5x5);
        printf("Congradulations! You've solved it in %d moves!\n", moveCnt_5x5);
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
    else if (solveChoice_5x5=='M'){
        printf("When you wish to finish, type 'E'\n");
        printCube_5x5();
        printf("\n");
        while(true){
            rotation_5x5();
            if(sideChoice_5x5=='E'){
                break;
            }
            printf("\n");
            printCube_5x5();
            printf("\n");
        }
    }
    return;
}
void printRules_5x5(void){
    puts("Hello, and welcome to the 5x5 Rubik's cube.");
    puts("Would you like to learn how this works? Y/N");
    scanf(" %c", &ruleChoice_5x5);
    while(ruleChoice_5x5!='Y'&&ruleChoice_5x5!='N'){
        puts("Sorry, that is unrecognized, please try again.");
        puts("Would you like to learn how this works? Y/N");
        scanf(" %c", &ruleChoice_5x5);
    }
    if(ruleChoice_5x5=='Y'){
        puts("To solve the 5x5 Rubik's cube, the goal is to have each side containing only one color.");
        puts("At each move, you will be asked which face you would like to rotate and if it is to rotate clockwise or counterclockwise, using the notation of Upper, Down, Front, Back, Right, and Left.\nYou will also be asked which layer to rotate, starting with 0 for the face and going up for each layer until the middle.");
        puts("Good luck solving!");
    }
    else if(ruleChoice_5x5=='N'){
        puts("It seems like you already know what you're doing! Good luck!");
    }
}
void rotation_5x5(void){
    if(solveChoice_5x5=='S'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_5x5);
        while(sideChoice_5x5!='U'&&sideChoice_5x5!='D'&&sideChoice_5x5!='F'&&sideChoice_5x5!='B'&&sideChoice_5x5!='R'&&sideChoice_5x5!='L'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_5x5);
        }
        printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
        scanf(" %d", &layerChoice_5x5);
        while(layerChoice_5x5!='0'&&layerChoice_5x5!='1'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
            scanf(" %d", &layerChoice_5x5);
        }
        printf("How many 90 degree rotations would you like to rotate by? ");
        scanf("%d", &dirAmt_5x5);
        for(int i=0;i<dirAmt_5x5;i++){
            rotationsingle_5x5(&sideChoice_5x5, &layerChoice_5x5);
        }
    }
    else if(solveChoice_5x5=='M'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_5x5);
        while(sideChoice_5x5!='U'&&sideChoice_5x5!='D'&&sideChoice_5x5!='F'&&sideChoice_5x5!='B'&&sideChoice_5x5!='R'&&sideChoice_5x5!='L'&&sideChoice_5x5!='E'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_5x5);
        }
        if(sideChoice_5x5!='E'){
            printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
            scanf(" %d", &layerChoice_5x5);
            while(layerChoice_5x5!=0&&layerChoice_5x5!=1){
                puts("Sorry, that is unrecognized, please try again.");
                printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
                scanf(" %d", &layerChoice_5x5);
            }
            printf("How many 90 degree rotations would you like to rotate by? ");
            scanf("%d", &dirAmt_5x5);
            for(int i=0;i<dirAmt_5x5;i++){
                rotationsingle_5x5(&sideChoice_5x5, &layerChoice_5x5);
            }
        }
    }
}
void rotationsingle_5x5(char *side_5x5, int *layers_deep){
    if(*side_5x5=='F'){
        if(*layers_deep==0){
            rotationFace_5x5(green_5x5);
        }
        for(int i=0;i<5;i++){
            storage_5x5=white_5x5[4-*layers_deep][i];
            white_5x5[4-*layers_deep][i]=orange_5x5[4-i][4-*layers_deep];
            orange_5x5[4-i][4-*layers_deep]=yellow_5x5[*layers_deep][4-i];
            yellow_5x5[*layers_deep][4-i]=red_5x5[i][*layers_deep];
            red_5x5[i][*layers_deep]=storage_5x5;
        }
    }
    if(*side_5x5=='U'){
        if(*layers_deep==0){
            rotationFace_5x5(white_5x5);
        }
        for(int i=0;i<5;i++){
            storage_5x5=green_5x5[*layers_deep][i];
            green_5x5[*layers_deep][i]=red_5x5[*layers_deep][i];
            red_5x5[*layers_deep][i]=blue_5x5[*layers_deep][i];
            blue_5x5[*layers_deep][i]=orange_5x5[*layers_deep][i];
            orange_5x5[*layers_deep][i]=storage_5x5;
        }
    }
    if(*side_5x5=='L'){
        if(*layers_deep==0){
            rotationFace_5x5(orange_5x5);
        }
        for(int i=0;i<5;i++){
            storage_5x5=white_5x5[i][*layers_deep];
            white_5x5[i][*layers_deep]=blue_5x5[4-i][4-*layers_deep];
            blue_5x5[4-i][4-*layers_deep]=yellow_5x5[i][*layers_deep];
            yellow_5x5[i][*layers_deep]=green_5x5[i][*layers_deep];
            green_5x5[i][*layers_deep]=storage_5x5;
        }
    }
    if(*side_5x5=='R'){
        if(*layers_deep==0){
            rotationFace_5x5(red_5x5);
        }
        for(int i=0;i<5;i++){
            storage_5x5=white_5x5[4-i][4-*layers_deep];
            white_5x5[4-i][4-*layers_deep]=green_5x5[4-i][4-*layers_deep];
            green_5x5[4-i][4-*layers_deep]=yellow_5x5[4-i][4-*layers_deep];
            yellow_5x5[4-i][4-*layers_deep]=blue_5x5[i][*layers_deep];
            blue_5x5[i][*layers_deep]=storage_5x5;
        }
    }
    if(*side_5x5=='B'){
        if(*layers_deep==0){
            rotationFace_5x5(blue_5x5);
        }
        for(int i=0;i<5;i++){
            storage_5x5=white_5x5[*layers_deep][4-i];
            white_5x5[*layers_deep][4-i]=red_5x5[4-i][4-*layers_deep];
            red_5x5[4-i][4-*layers_deep]=yellow_5x5[4-*layers_deep][4-i];
            yellow_5x5[4-*layers_deep][4-i]=orange_5x5[i][*layers_deep];
            orange_5x5[i][*layers_deep]=storage_5x5;
        }
    }
    if(*side_5x5=='D'){
        if(*layers_deep==0){
            rotationFace_5x5(yellow_5x5);
        }
        for(int i=0;i<5;i++){
            storage_5x5=green_5x5[4-*layers_deep][i];
            green_5x5[4-*layers_deep][i]=orange_5x5[4-*layers_deep][i];
            orange_5x5[4-*layers_deep][i]=blue_5x5[4-*layers_deep][i];
            blue_5x5[4-*layers_deep][i]=red_5x5[4-*layers_deep][i];
            red_5x5[4-*layers_deep][i]=storage_5x5;
        }
    }
}
bool sideCheck_5x5(char face1_5x5[5][5], char face2_5x5[5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(face1_5x5[i][j]!=face2_5x5[i][j]){
                return false;
            }
        }
    }
    return true;
}
void printCube_5x5(void){
    for(int i=0;i<5;i++){
        printf("            ");
        for(int j=0;j<5;j++){
            printf(" %c", white_5x5[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf(" %c", orange_5x5[i][j]);
        }
        printf("  ");
        for(int j=0;j<5;j++){
            printf(" %c", green_5x5[i][j]);
        }
        printf("  ");
        for(int j=0;j<5;j++){
            printf(" %c", red_5x5[i][j]);
        }
        printf("  ");
        for(int j=0;j<5;j++){
            printf(" %c", blue_5x5[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("            ");
        for(int j=0;j<5;j++){
            printf(" %c", yellow_5x5[i][j]);
        }
        printf("\n");
    }
}
void rotationFace_5x5(char face[5][5]){
    char temp=face[0][0];
    face[0][0]=face[4][0];
    face[4][0]=face[4][4];
    face[4][4]=face[0][4];
    face[0][4]=temp;
    temp=face[0][1];
    face[0][1]=face[3][0];
    face[3][0]=face[4][3];
    face[4][3]=face[1][4];
    face[1][4]=face[1][4];
    face[1][4]=temp;
    temp=face[0][2];
    face[0][2]=face[2][0];
    face[2][0]=face[4][2];
    face[4][2]=face[2][4];
    face[2][4]=temp;
    temp=face[0][3];
    face[0][3]=face[1][0];
    face[1][0]=face[2][2];
    face[2][2]=face[1][2];
    face[1][2]=temp;
    temp=face[1][1];
    face[1][1]=face[3][1];
    face[3][1]=face[3][3];
    face[3][3]=face[1][3];
    face[1][3]=temp;
    temp=face[2][1];
    face[2][1]=face[3][2];
    face[3][2]=face[2][3];
    face[2][3]=face[1][3];
    face[1][3]=temp;
}
void scramble_5x5(void){
    int scrambleSize_5x5;
    printf("How many steps long should the scramble be? (>60 is recommended) ");
    scanf("%d", &scrambleSize_5x5);
    srand(time(0));
    for(int i=0;i<scrambleSize_5x5;i++){
        rngside_5x5=rand()%6;
        rngdir_5x5=(rand()%3)+1;
        rnglayer_5x5=rand()%2;
        if(rngside_5x5==0){
            sideChoice_5x5='U';
            for(int j=1;j<(rngdir_5x5);j++){
                rotationsingle_5x5(&sideChoice_5x5, &rnglayer_5x5);
            }
        }
        else if(rngside_5x5==1){
            sideChoice_5x5='R';
            for(int j=1;j<(rngdir_5x5);j++){
                rotationsingle_5x5(&sideChoice_5x5, &rnglayer_5x5);
            }
        }
        else if(rngside_5x5==2){
            sideChoice_5x5='B';
            for(int j=1;j<(rngdir_5x5);j++){
                rotationsingle_5x5(&sideChoice_5x5, &rnglayer_5x5);
            }
        }
        else if(rngside_5x5==3){
            sideChoice_5x5='L';
            for(int j=1;j<(rngdir_5x5);j++){
                rotationsingle_5x5(&sideChoice_5x5, &rnglayer_5x5);
            }
        }
        else if(rngside_5x5==4){
            sideChoice_5x5='D';
            for(int j=1;j<(rngdir_5x5);j++){
                rotationsingle_5x5(&sideChoice_5x5, &rnglayer_5x5);
            }
        }
        else if(rngside_5x5==5){
            sideChoice_5x5='F';
            for(int j=1;j<(rngdir_5x5);j++){
                rotationsingle_5x5(&sideChoice_5x5, &rnglayer_5x5);
            }
        }
    }
}
#endif