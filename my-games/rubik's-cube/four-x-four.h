#ifndef FOUR_X_FOUR_H
#define FOUR_X_FOUR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "/workspaces/CProgramming2/functions/time-struct.h"
char white_4x4[4][4]={{'W','W','W','W'},{'W','W','W','W'},{'W','W','W','W'},{'W','W','W','W'}};
char red_4x4[4][4]={{'R','R','R','R'},{'R','R','R','R'},{'R','R','R','R'},{'R','R','R','R'}};
char blue_4x4[4][4]={{'B','B','B','B'},{'B','B','B','B'},{'B','B','B','B'},{'B','B','B','B'}};
char yellow_4x4[4][4]={{'Y','Y','Y','Y'},{'Y','Y','Y','Y'},{'Y','Y','Y','Y'},{'Y','Y','Y','Y'}};
char orange_4x4[4][4]={{'O','O','O','O'},{'O','O','O','O'},{'O','O','O','O'},{'O','O','O','O'}};
char green_4x4[4][4]={{'G','G','G','G'},{'G','G','G','G'},{'G','G','G','G'},{'G','G','G','G'}};
void scramble_4x4(void);
int startTime_4x4;
int endTime_4x4;
int totalTime_4x4;
int recordTime_4x4;
int moveCnt_4x4=0;
int rngside_4x4;
int rngdir_4x4;
int rnglayer_4x4;
bool sideCheck_4x4(char face1_4x4[4][4]);
int test_4x4;
char storage_4x4;
void rotation_4x4(void);
void rotationsingle_4x4(char *side_4x4, int *layers_deep);
char sideChoice_4x4;
int layerChoice_4x4;
int dirAmt_4x4;
void printRules_4x4(void);
void printCube_4x4(void);
char ruleChoice_4x4;
char solveChoice_4x4;
void rotationFace_4x4(char face[4][4]);
void fourXfour(void){
    printRules_4x4();
    printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
    scanf(" %c", &solveChoice_4x4);
    while(solveChoice_4x4!='S'&&solveChoice_4x4!='M'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
        scanf(" %c", &solveChoice_4x4);
    }
    if(solveChoice_4x4=='S'){
        scramble_4x4();
        printf("\n");
        printCube_4x4();
        printf("\n");
        startTime_4x4=time(0);
        while(!sideCheck_4x4(white_4x4)||!sideCheck_4x4(red_4x4)||!sideCheck_4x4(blue_4x4)||!sideCheck_4x4(yellow_4x4)||!sideCheck_4x4(orange_4x4)||!sideCheck_4x4(green_4x4)){
            rotation_4x4();
            printf("\n");
            printCube_4x4();
            printf("\n");
            moveCnt_4x4++;
        }
        endTime_4x4=time(0);
        totalTime_4x4=endTime_4x4-startTime_4x4;
        makeTime(totalTime_4x4);
        printf("Congradulations! You've solved it in %d moves!\n", moveCnt_4x4);
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
    else if (solveChoice_4x4=='M'){
        printf("When you wish to finish, type 'E'\n");
        printCube_4x4();
        printf("\n");
        while(true){
            rotation_4x4();
            if(sideChoice_4x4=='E'){
                break;
            }
            printf("\n");
            printCube_4x4();
            printf("\n");
        }
    }
    return;
}
void printRules_4x4(void){
    puts("Hello, and welcome to the 4x4 Rubik's cube.");
    puts("Would you like to learn how this works? Y/N");
    scanf(" %c", &ruleChoice_4x4);
    while(ruleChoice_4x4!='Y'&&ruleChoice_4x4!='N'){
        puts("Sorry, that is unrecognized, please try again.");
        puts("Would you like to learn how this works? Y/N");
        scanf(" %c", &ruleChoice_4x4);
    }
    if(ruleChoice_4x4=='Y'){
        puts("To solve the 4x4 Rubik's cube, the goal is to have each side containing only one color.");
        puts("At each move, you will be asked which face you would like to rotate and if it is to rotate clockwise or counterclockwise, using the notation of Upper, Down, Front, Back, Right, and Left.\nYou will also be asked which layer to rotate, starting with 0 for the face and going up for each layer until the middle.");
        puts("Good luck solving!");
    }
    else if(ruleChoice_4x4=='N'){
        puts("It seems like you already know what you're doing! Good luck!");
    }
}
void rotation_4x4(void){
    if(solveChoice_4x4=='S'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_4x4);
        while(sideChoice_4x4!='U'&&sideChoice_4x4!='D'&&sideChoice_4x4!='F'&&sideChoice_4x4!='B'&&sideChoice_4x4!='R'&&sideChoice_4x4!='L'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_4x4);
        }
        printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
        scanf(" %d", &layerChoice_4x4);
        while(layerChoice_4x4!='0'&&layerChoice_4x4!='1'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
            scanf(" %d", &layerChoice_4x4);
        }
        printf("How many 90 degree rotations would you like to rotate by? ");
        scanf("%d", &dirAmt_4x4);
        for(int i=0;i<dirAmt_4x4;i++){
            rotationsingle_4x4(&sideChoice_4x4, &layerChoice_4x4);
        }
    }
    else if(solveChoice_4x4=='M'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_4x4);
        while(sideChoice_4x4!='U'&&sideChoice_4x4!='D'&&sideChoice_4x4!='F'&&sideChoice_4x4!='B'&&sideChoice_4x4!='R'&&sideChoice_4x4!='L'&&sideChoice_4x4!='E'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_4x4);
        }
        if(sideChoice_4x4!='E'){
            printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
            scanf(" %d", &layerChoice_4x4);
            while(layerChoice_4x4!=0&&layerChoice_4x4!=1){
                puts("Sorry, that is unrecognized, please try again.");
                printf("Which layer would you like to rotate? (0 for outer layer, 1 for inner layer) ");
                scanf(" %d", &layerChoice_4x4);
            }
            printf("How many 90 degree rotations would you like to rotate by? ");
            scanf("%d", &dirAmt_4x4);
            for(int i=0;i<dirAmt_4x4;i++){
                rotationsingle_4x4(&sideChoice_4x4, &layerChoice_4x4);
            }
        }
    }
}
void rotationsingle_4x4(char *side_4x4, int *layers_deep){
    if(*side_4x4=='F'){
        if(*layers_deep==0){
            rotationFace_4x4(green_4x4);
        }
        for(int i=0;i<4;i++){
            storage_4x4=white_4x4[3-*layers_deep][i];
            white_4x4[3-*layers_deep][i]=orange_4x4[3-i][3-*layers_deep];
            orange_4x4[3-i][3-*layers_deep]=yellow_4x4[*layers_deep][3-i];
            yellow_4x4[*layers_deep][3-i]=red_4x4[i][*layers_deep];
            red_4x4[i][*layers_deep]=storage_4x4;
        }
    }
    if(*side_4x4=='U'){
        if(*layers_deep==0){
            rotationFace_4x4(white_4x4);
        }
        for(int i=0;i<4;i++){
            storage_4x4=green_4x4[*layers_deep][i];
            green_4x4[*layers_deep][i]=red_4x4[*layers_deep][i];
            red_4x4[*layers_deep][i]=blue_4x4[*layers_deep][i];
            blue_4x4[*layers_deep][i]=orange_4x4[*layers_deep][i];
            orange_4x4[*layers_deep][i]=storage_4x4;
        }
    }
    if(*side_4x4=='L'){
        if(*layers_deep==0){
            rotationFace_4x4(orange_4x4);
        }
        for(int i=0;i<4;i++){
            storage_4x4=white_4x4[i][*layers_deep];
            white_4x4[i][*layers_deep]=blue_4x4[3-i][3-*layers_deep];
            blue_4x4[3-i][3-*layers_deep]=yellow_4x4[i][*layers_deep];
            yellow_4x4[i][*layers_deep]=green_4x4[i][*layers_deep];
            green_4x4[i][*layers_deep]=storage_4x4;
        }
    }
    if(*side_4x4=='R'){
        if(*layers_deep==0){
            rotationFace_4x4(red_4x4);
        }
        for(int i=0;i<4;i++){
            storage_4x4=white_4x4[3-i][3-*layers_deep];
            white_4x4[3-i][3-*layers_deep]=green_4x4[3-i][3-*layers_deep];
            green_4x4[3-i][3-*layers_deep]=yellow_4x4[3-i][3-*layers_deep];
            yellow_4x4[3-i][3-*layers_deep]=blue_4x4[i][*layers_deep];
            blue_4x4[i][*layers_deep]=storage_4x4;
        }
    }
    if(*side_4x4=='B'){
        if(*layers_deep==0){
            rotationFace_4x4(blue_4x4);
        }
        for(int i=0;i<4;i++){
            storage_4x4=white_4x4[*layers_deep][3-i];
            white_4x4[*layers_deep][3-i]=red_4x4[3-i][3-*layers_deep];
            red_4x4[3-i][3-*layers_deep]=yellow_4x4[3-*layers_deep][i];
            yellow_4x4[3-*layers_deep][i]=orange_4x4[i][*layers_deep];
            orange_4x4[i][*layers_deep]=storage_4x4;
        }
    }
    if(*side_4x4=='D'){
        if(*layers_deep==0){
            rotationFace_4x4(yellow_4x4);
        }
        for(int i=0;i<4;i++){
            storage_4x4=green_4x4[3-*layers_deep][i];
            green_4x4[3-*layers_deep][i]=orange_4x4[3-*layers_deep][i];
            orange_4x4[3-*layers_deep][i]=blue_4x4[3-*layers_deep][i];
            blue_4x4[3-*layers_deep][i]=red_4x4[3-*layers_deep][i];
            red_4x4[3-*layers_deep][i]=storage_4x4;
        }
    }
}
bool sideCheck_4x4(char face1_4x4[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(face1_4x4[i][j]!=face1_4x4[0][0]){
                return false;
            }
        }
    }
    return true;
}
void printCube_4x4(void){
    for(int i=0;i<4;i++){
        printf("          ");
        for(int j=0;j<4;j++){
            printf(" %c", white_4x4[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf(" %c", orange_4x4[i][j]);
        }
        printf("  ");
        for(int j=0;j<4;j++){
            printf(" %c", green_4x4[i][j]);
        }
        printf("  ");
        for(int j=0;j<4;j++){
            printf(" %c", red_4x4[i][j]);
        }
        printf("  ");
        for(int j=0;j<4;j++){
            printf(" %c", blue_4x4[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<4;i++){
        printf("          ");
        for(int j=0;j<4;j++){
            printf(" %c", yellow_4x4[i][j]);
        }
        printf("\n");
    }
}
void rotationFace_4x4(char face[4][4]){
    char temp=face[0][0];
    face[0][0]=face[3][0];
    face[3][0]=face[3][3];
    face[3][3]=face[0][3];
    face[0][3]=temp;
    temp=face[0][1];
    face[0][1]=face[2][0];
    face[2][0]=face[3][2];
    face[3][2]=face[1][3];
    face[1][3]=temp;
    temp=face[0][2];
    face[0][2]=face[1][0];
    face[1][0]=face[3][1];
    face[3][1]=face[2][3];
    face[2][3]=temp;
    temp=face[1][1];
    face[1][1]=face[2][1];
    face[2][1]=face[2][2];
    face[2][2]=face[1][2];
    face[1][2]=temp;
}
void scramble_4x4(void){
    int scrambleSize_4x4;
    printf("How many steps long should the scramble be? (>40 is recommended) ");
    scanf("%d", &scrambleSize_4x4);
    srand(time(0));
    for(int i=0;i<scrambleSize_4x4;i++){
        rngside_4x4=rand()%6;
        rngdir_4x4=(rand()%3)+1;
        rnglayer_4x4=rand()%2;
        if(rngside_4x4==0){
            sideChoice_4x4='U';
            for(int j=1;j<(rngdir_4x4);j++){
                rotationsingle_4x4(&sideChoice_4x4, &rnglayer_4x4);
            }
        }
        else if(rngside_4x4==1){
            sideChoice_4x4='R';
            for(int j=1;j<(rngdir_4x4);j++){
                rotationsingle_4x4(&sideChoice_4x4, &rnglayer_4x4);
            }
        }
        else if(rngside_4x4==2){
            sideChoice_4x4='B';
            for(int j=1;j<(rngdir_4x4);j++){
                rotationsingle_4x4(&sideChoice_4x4, &rnglayer_4x4);
            }
        }
        else if(rngside_4x4==3){
            sideChoice_4x4='L';
            for(int j=1;j<(rngdir_4x4);j++){
                rotationsingle_4x4(&sideChoice_4x4, &rnglayer_4x4);
            }
        }
        else if(rngside_4x4==4){
            sideChoice_4x4='D';
            for(int j=1;j<(rngdir_4x4);j++){
                rotationsingle_4x4(&sideChoice_4x4, &rnglayer_4x4);
            }
        }
        else if(rngside_4x4==5){
            sideChoice_4x4='F';
            for(int j=1;j<(rngdir_4x4);j++){
                rotationsingle_4x4(&sideChoice_4x4, &rnglayer_4x4);
            }
        }
    }
}
#endif