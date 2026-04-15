#ifndef THREE_TEST_H
#define THREE_TEST_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "/workspaces/CProgramming2/functions/time-struct.h"
char white_3x3[3][3]={{'W','W','W'},{'W','W','W'},{'W','W','W'}};
char red_3x3[3][3]={{'R','R','R'},{'R','R','R'},{'R','R','R'}};
char blue_3x3[3][3]={{'B','B','B'},{'B','B','B'},{'B','B','B'}};
char yellow_3x3[3][3]={{'Y','Y','Y'},{'Y','Y','Y'},{'Y','Y','Y'}};
char orange_3x3[3][3]={{'O','O','O'},{'O','O','O'},{'O','O','O'}};
char green_3x3[3][3]={{'G','G','G'},{'G','G','G'},{'G','G','G'}};
char whiteCheck_3x3[3][3]={{'W','W','W'},{'W','W','W'},{'W','W','W'}};
char redCheck_3x3[3][3]={{'R','R','R'},{'R','R','R'},{'R','R','R'}};
char blueCheck_3x3[3][3]={{'B','B','B'},{'B','B','B'},{'B','B','B'}};
char yellowCheck_3x3[3][3]={{'Y','Y','Y'},{'Y','Y','Y'},{'Y','Y','Y'}};
char orangeCheck_3x3[3][3]={{'O','O','O'},{'O','O','O'},{'O','O','O'}};
char greenCheck_3x3[3][3]={{'G','G','G'},{'G','G','G'},{'G','G','G'}};
void scramble_3x3(void);
int startTime_3x3;
int endTime_3x3;
int totalTime_3x3;
int recordTime_3x3;
int moveCnt_3x3=0;
int rngside_3x3;
int rngdir_3x3;
bool sideCheck_3x3(char face1_3x3[3][3], char face2_3x3[3][3]);
int test_3x3;
char storage_3x3;
void rotation_3x3(void);
void rotationsingle_3x3(char *side_3x3);
char sideChoice_3x3;
int dirAmt_3x3;
void printRules_3x3(void);
void printCube_3x3(void);
char ruleChoice_3x3;
char solveChoice_3x3;
void threeXthree(void){
    printRules_3x3();
    printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
    scanf(" %c", &solveChoice_3x3);
    while(solveChoice_3x3!='S'&&solveChoice_3x3!='M'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Would you like to attempt to solve the cube (S), or to simply mess around with it (M)?");
        scanf(" %c", &solveChoice_3x3);
    }
    if(solveChoice_3x3=='S'){
        scramble_3x3();
        printf("\n");
        printCube_3x3();
        printf("\n");
        startTime_3x3=time(0);
        while(!sideCheck_3x3(white_3x3, whiteCheck_3x3)||!sideCheck_3x3(red_3x3, redCheck_3x3)||!sideCheck_3x3(blue_3x3, blueCheck_3x3)||!sideCheck_3x3(yellow_3x3, yellowCheck_3x3)||!sideCheck_3x3(orange_3x3, orangeCheck_3x3)||!sideCheck_3x3(green_3x3, greenCheck_3x3)){
            rotation_3x3();
            printf("\n");
            printCube_3x3();
            printf("\n");
            moveCnt_3x3++;
        }
        endTime_3x3=time(0);
        totalTime_3x3=endTime_3x3-startTime_3x3;
        makeTime(totalTime_3x3);
        printf("Congradulations! You've solved it in %d moves!\n", moveCnt_3x3);
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
    else if (solveChoice_3x3=='M'){
        printf("When you wish to finish, type 'E'\n");
        printCube_3x3();
        printf("\n");
        while(true){
            rotation_3x3();
            if(sideChoice_3x3=='E'){
                break;
            }
            printf("\n");
            printCube_3x3();
            printf("\n");
        }
    }
    return;
}
void printRules_3x3(void){
    puts("Hello, and welcome to the 3x3 Rubik's cube.");
    puts("Would you like to learn how this works? Y/N");
    scanf(" %c", &ruleChoice_3x3);
    while(ruleChoice_3x3!='Y'&&ruleChoice_3x3!='N'){
        puts("Sorry, that is unrecognized, please try again.");
        puts("Would you like to learn how this works? Y/N");
        scanf(" %c", &ruleChoice_3x3);
    }
    if(ruleChoice_3x3=='Y'){
        puts("To solve the 3x3 Rubik's cube, the goal is to have each side containing only one color.");
        puts("At each move, you will be asked which face you would like to rotate and if it is to rotate clockwise or counterclockwise, using the notation of Upper, Down, Front, Back, Right, and Left.");
        puts("Good luck solving!");
    }
    else if(ruleChoice_3x3=='N'){
        puts("It seems like you already know what you're doing! Good luck!");
    }
}
void rotation_3x3(void){
    if(solveChoice_3x3=='S'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_3x3);
        while(sideChoice_3x3!='U'&&sideChoice_3x3!='D'&&sideChoice_3x3!='F'&&sideChoice_3x3!='B'&&sideChoice_3x3!='R'&&sideChoice_3x3!='L'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_3x3);
        }
        printf("How many 90 degree rotations would you like to rotate by? ");
        scanf("%d", &dirAmt_3x3);
        for(int i=0;i<dirAmt_3x3;i++){
            rotationsingle_3x3(&sideChoice_3x3);
        }
    }
    else if(solveChoice_3x3=='M'){
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice_3x3);
        while(sideChoice_3x3!='U'&&sideChoice_3x3!='D'&&sideChoice_3x3!='F'&&sideChoice_3x3!='B'&&sideChoice_3x3!='R'&&sideChoice_3x3!='L'&&sideChoice_3x3!='E'){
            puts("Sorry, that is unrecognized, please try again.");
            printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
            scanf(" %c", &sideChoice_3x3);
        }
        if(sideChoice_3x3!='E'){
            printf("How many 90 degree rotations would you like to rotate by? ");
            scanf("%d", &dirAmt_3x3);
            for(int i=0;i<dirAmt_3x3;i++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
    }
}
void rotationsingle_3x3(char *side_3x3){
    if(*side_3x3=='F'){
        storage_3x3=green_3x3[0][0];
        green_3x3[0][0]=green_3x3[2][0];
        green_3x3[2][0]=green_3x3[2][2];
        green_3x3[2][2]=green_3x3[0][2];
        green_3x3[0][2]=storage_3x3;
        storage_3x3=green_3x3[0][1];
        green_3x3[0][1]=green_3x3[1][0];
        green_3x3[1][0]=green_3x3[2][1];
        green_3x3[2][1]=green_3x3[1][2];
        green_3x3[1][2]=storage_3x3;
        storage_3x3=white_3x3[2][0];
        white_3x3[2][0]=orange_3x3[2][2];
        orange_3x3[2][2]=yellow_3x3[0][2];
        yellow_3x3[0][2]=red_3x3[0][0];
        red_3x3[0][0]=storage_3x3;
        storage_3x3=white_3x3[2][1];
        white_3x3[2][1]=orange_3x3[1][2];
        orange_3x3[1][2]=yellow_3x3[0][1];
        yellow_3x3[0][1]=red_3x3[1][0];
        red_3x3[1][0]=storage_3x3;
        storage_3x3=white_3x3[2][2];
        white_3x3[2][2]=orange_3x3[0][2];
        orange_3x3[0][2]=yellow_3x3[0][0];
        yellow_3x3[0][0]=red_3x3[2][0];
        red_3x3[2][0]=storage_3x3;
    }
    else if(*side_3x3=='U'){
        storage_3x3=white_3x3[0][0];
        white_3x3[0][0]=white_3x3[2][0];
        white_3x3[2][0]=white_3x3[2][2];
        white_3x3[2][2]=white_3x3[0][2];
        white_3x3[0][2]=storage_3x3;
        storage_3x3=white_3x3[0][1];
        white_3x3[0][1]=white_3x3[1][0];
        white_3x3[1][0]=white_3x3[2][1];
        white_3x3[2][1]=white_3x3[1][2];
        white_3x3[1][2]=storage_3x3;
        storage_3x3=blue_3x3[0][2];
        blue_3x3[0][2]=orange_3x3[0][2];
        orange_3x3[0][2]=green_3x3[0][2];
        green_3x3[0][2]=red_3x3[0][2];
        red_3x3[0][2]=storage_3x3;
        storage_3x3=blue_3x3[0][1];
        blue_3x3[0][1]=orange_3x3[0][1];
        orange_3x3[0][1]=green_3x3[0][1];
        green_3x3[0][1]=red_3x3[0][1];
        red_3x3[0][1]=storage_3x3;
        storage_3x3=blue_3x3[0][0];
        blue_3x3[0][0]=orange_3x3[0][0];
        orange_3x3[0][0]=green_3x3[0][0];
        green_3x3[0][0]=red_3x3[0][0];
        red_3x3[0][0]=storage_3x3;
    }
    else if(*side_3x3=='L'){
        storage_3x3=orange_3x3[0][0];
        orange_3x3[0][0]=orange_3x3[2][0];
        orange_3x3[2][0]=orange_3x3[2][2];
        orange_3x3[2][2]=orange_3x3[0][2];
        orange_3x3[0][2]=storage_3x3;
        storage_3x3=orange_3x3[0][1];
        orange_3x3[0][1]=orange_3x3[1][0];
        orange_3x3[1][0]=orange_3x3[2][1];
        orange_3x3[2][1]=orange_3x3[1][2];
        orange_3x3[1][2]=storage_3x3;
        storage_3x3=white_3x3[0][0];
        white_3x3[0][0]=blue_3x3[2][2];
        blue_3x3[2][2]=yellow_3x3[0][0];
        yellow_3x3[0][0]=green_3x3[0][0];
        green_3x3[0][0]=storage_3x3;
        storage_3x3=white_3x3[1][0];
        white_3x3[1][0]=blue_3x3[1][2];
        blue_3x3[1][2]=yellow_3x3[1][0];
        yellow_3x3[1][0]=green_3x3[1][0];
        green_3x3[1][0]=storage_3x3;
        storage_3x3=white_3x3[2][0];
        white_3x3[2][0]=blue_3x3[0][2];
        blue_3x3[0][2]=yellow_3x3[2][0];
        yellow_3x3[2][0]=green_3x3[2][0];
        green_3x3[2][0]=storage_3x3;
    }
    else if(*side_3x3=='R'){
        storage_3x3=red_3x3[0][0];
        red_3x3[0][0]=red_3x3[2][0];
        red_3x3[2][0]=red_3x3[2][2];
        red_3x3[2][2]=red_3x3[0][2];
        red_3x3[0][2]=storage_3x3;
        storage_3x3=red_3x3[0][1];
        red_3x3[0][1]=red_3x3[1][0];
        red_3x3[1][0]=red_3x3[2][1];
        red_3x3[2][1]=red_3x3[1][2];
        red_3x3[1][2]=storage_3x3;
        storage_3x3=white_3x3[2][2];
        white_3x3[2][2]=green_3x3[2][2];
        green_3x3[2][2]=yellow_3x3[2][2];
        yellow_3x3[2][2]=blue_3x3[0][0];
        blue_3x3[0][0]=storage_3x3;
        storage_3x3=white_3x3[1][2];
        white_3x3[1][2]=green_3x3[1][2];
        green_3x3[1][2]=yellow_3x3[1][2];
        yellow_3x3[1][2]=blue_3x3[1][0];
        blue_3x3[1][0]=storage_3x3;
        storage_3x3=white_3x3[0][2];
        white_3x3[0][2]=green_3x3[0][2];
        green_3x3[0][2]=yellow_3x3[0][2];
        yellow_3x3[0][2]=blue_3x3[2][0];
        blue_3x3[2][0]=storage_3x3;
    }
    else if(*side_3x3=='B'){
        storage_3x3=blue_3x3[0][0];
        blue_3x3[0][0]=blue_3x3[2][0];
        blue_3x3[2][0]=blue_3x3[2][2];
        blue_3x3[2][2]=blue_3x3[0][2];
        blue_3x3[0][2]=storage_3x3;
        storage_3x3=blue_3x3[0][1];
        blue_3x3[0][1]=blue_3x3[1][0];
        blue_3x3[1][0]=blue_3x3[2][1];
        blue_3x3[2][1]=blue_3x3[1][2];
        blue_3x3[1][2]=storage_3x3;
        storage_3x3=white_3x3[0][2];
        white_3x3[0][2]=red_3x3[2][2];
        red_3x3[2][2]=yellow_3x3[2][0];
        yellow_3x3[2][0]=orange_3x3[0][0];
        orange_3x3[0][0]=storage_3x3;
        storage_3x3=white_3x3[0][1];
        white_3x3[0][1]=red_3x3[1][2];
        red_3x3[1][2]=yellow_3x3[2][1];
        yellow_3x3[2][1]=orange_3x3[1][0];
        orange_3x3[1][0]=storage_3x3;
        storage_3x3=white_3x3[0][0];
        white_3x3[0][0]=red_3x3[0][2];
        red_3x3[0][2]=yellow_3x3[2][2];
        yellow_3x3[2][2]=orange_3x3[2][0];
        orange_3x3[2][0]=storage_3x3;
    }
    else if(*side_3x3=='D'){
        storage_3x3=yellow_3x3[0][0];
        yellow_3x3[0][0]=yellow_3x3[2][0];
        yellow_3x3[2][0]=yellow_3x3[2][2];
        yellow_3x3[2][2]=yellow_3x3[0][2];
        yellow_3x3[0][2]=storage_3x3;
        storage_3x3=yellow_3x3[0][1];
        yellow_3x3[0][1]=yellow_3x3[1][0];
        yellow_3x3[1][0]=yellow_3x3[2][1];
        yellow_3x3[2][1]=yellow_3x3[1][2];
        yellow_3x3[1][2]=storage_3x3;
        storage_3x3=green_3x3[2][0];
        green_3x3[2][0]=orange_3x3[2][0];
        orange_3x3[2][0]=blue_3x3[2][0];
        blue_3x3[2][0]=red_3x3[2][0];
        red_3x3[2][0]=storage_3x3;
        storage_3x3=green_3x3[2][1];
        green_3x3[2][1]=orange_3x3[2][1];
        orange_3x3[2][1]=blue_3x3[2][1];
        blue_3x3[2][1]=red_3x3[2][1];
        red_3x3[2][1]=storage_3x3;
        storage_3x3=green_3x3[2][2];
        green_3x3[2][2]=orange_3x3[2][2];
        orange_3x3[2][2]=blue_3x3[2][2];
        blue_3x3[2][2]=red_3x3[2][2];
        red_3x3[2][2]=storage_3x3;
    }
}
bool sideCheck_3x3(char face1_3x3[3][3], char face2_3x3[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(face1_3x3[i][j]!=face2_3x3[i][j]){
                return false;
            }
        }
    }
    return true;
}
void printCube_3x3(void){
    for(int i=0;i<3;i++){
        printf("        ");
        for(int j=0;j<3;j++){
            printf(" %c", white_3x3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c", orange_3x3[i][j]);
        }
        printf("  ");
        for(int j=0;j<3;j++){
            printf(" %c", green_3x3[i][j]);
        }
        printf("  ");
        for(int j=0;j<3;j++){
            printf(" %c", red_3x3[i][j]);
        }
        printf("  ");
        for(int j=0;j<3;j++){
            printf(" %c", blue_3x3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("        ");
        for(int j=0;j<3;j++){
            printf(" %c", yellow_3x3[i][j]);
        }
        printf("\n");
    }
}
void scramble_3x3(void){
    int scrambleSize_3x3;
    printf("How many steps long should the scramble be? (20-25 will be enough to sufficiently scramble the cube if that is what you wish) ");
    scanf("%d", &scrambleSize_3x3);
    srand(time(0));
    for(int i=0;i<scrambleSize_3x3;i++){
        rngside_3x3=rand()%6;
        if(rngside_3x3==0){
            sideChoice_3x3='U';
            for(int j=1;j<(rand()%4+1);j++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
        else if(rngside_3x3==1){
            sideChoice_3x3='R';
            for(int j=1;j<(rand()%4+1);j++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
        else if(rngside_3x3==2){
            sideChoice_3x3='B';
            for(int j=1;j<(rand()%4+1);j++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
        else if(rngside_3x3==3){
            sideChoice_3x3='L';
            for(int j=1;j<(rand()%4+1);j++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
        else if(rngside_3x3==4){
            sideChoice_3x3='D';
            for(int j=1;j<(rand()%4+1);j++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
        else if(rngside_3x3==5){
            sideChoice_3x3='F';
            for(int j=1;j<(rand()%4+1);j++){
                rotationsingle_3x3(&sideChoice_3x3);
            }
        }
    }
}
#endif