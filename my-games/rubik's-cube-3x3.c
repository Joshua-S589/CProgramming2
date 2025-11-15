#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char white[3][3]={{'W','W','W'},{'W','W','W'},{'W','W','W'}};
char red[3][3]={{'R','R','R'},{'R','R','R'},{'R','R','R'}};
char blue[3][3]={{'B','B','B'},{'B','B','B'},{'B','B','B'}};
char yellow[3][3]={{'Y','Y','Y'},{'Y','Y','Y'},{'Y','Y','Y'}};
char orange[3][3]={{'O','O','O'},{'O','O','O'},{'O','O','O'}};
char green[3][3]={{'G','G','G'},{'G','G','G'},{'G','G','G'}};
char whiteCheck[3][3]={{'W','W','W'},{'W','W','W'},{'W','W','W'}};
char redCheck[3][3]={{'R','R','R'},{'R','R','R'},{'R','R','R'}};
char blueCheck[3][3]={{'B','B','B'},{'B','X','B'},{'B','B','B'}};
char yellowCheck[3][3]={{'Y','Y','Y'},{'Y','Y','Y'},{'Y','Y','Y'}};
char orangeCheck[3][3]={{'O','O','O'},{'O','O','O'},{'O','O','O'}};
char greenCheck[3][3]={{'G','G','G'},{'G','G','G'},{'G','G','G'}};
int moveCnt=0;
int rngside;
int rngdir;
int sideCheck(char face1[3][3], char face2[3][3]);
int test;
char storage;
void rotation(void);
void rotationsingle(char *side);
char sideChoice;
char dirChoice;
void printRules(void);
void printCube(void);
char ruleChoice;
int main(void){
    printRules();
    srand(time(0));
    for(int i=0;i<40;i++){
        rngside=rand()%6;
        if(rngside==0){
            sideChoice='U';
            for(int j=0;j<(rand()%4+1);j++){
                rotationsingle(&sideChoice);
            }
        }
        else if(rngside==1){
            sideChoice='R';
            for(int j=0;j<(rand()%4+1);j++){
                rotationsingle(&sideChoice);
            }
        }
        else if(rngside==2){
            sideChoice='B';
            for(int j=0;j<(rand()%4+1);j++){
                rotationsingle(&sideChoice);
            }
        }
        else if(rngside==3){
            sideChoice='L';
            for(int j=0;j<(rand()%4+1);j++){
                rotationsingle(&sideChoice);
            }
        }
        else if(rngside==4){
            sideChoice='D';
            for(int j=0;j<(rand()%4+1);j++){
                rotationsingle(&sideChoice);
            }
        }
        else if(rngside==5){
            sideChoice='F';
            for(int j=0;j<(rand()%4+1);j++){
                rotationsingle(&sideChoice);
            }
        }
    }
    printCube();
     while(!sideCheck(white, whiteCheck)||!sideCheck(red, redCheck)||!sideCheck(blue, blueCheck)||!sideCheck(yellow, yellowCheck)||!sideCheck(orange, orangeCheck)||!sideCheck(green, greenCheck)){
        rotation();
        printCube();
        moveCnt++;
    }
    printf("Congradulations! You've solved it in %d moves!", moveCnt);
}
void printRules(void){
    puts("Hello, and welcome to the Rubik's cube.");
    puts("Would you like to learn how this works? Y/N");
    scanf(" %c", &ruleChoice);
    while(ruleChoice!='Y'&&ruleChoice!='N'){
        puts("Sorry, that is unrecognized, please try again.");
        puts("Would you like to learn how this works? Y/N");
        scanf(" %c", &ruleChoice);
    }
    if(ruleChoice=='Y'){
        puts("To solve the Rubik's cube, the goal is to have each side containing only one color.");
        puts("At each move, you will be asked which face you would like to rotate and if it is to rotate clockwise or counterclockwise, using the notation of Upper, Down, Front, Back, Right, and Left.");
        puts("Good luck solving!");
    }
    else if(ruleChoice=='N'){
        puts("It seems like you already know what you're doing! Good luck!");
    }
}
void rotation(void){
    printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
    scanf(" %c", &sideChoice);
    while(sideChoice!='U'&&sideChoice!='D'&&sideChoice!='F'&&sideChoice!='B'&&sideChoice!='R'&&sideChoice!='L'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Which side would you like to rotate? (U/D/F/B/R/L)  ");
        scanf(" %c", &sideChoice);
    }
    printf("Rotate counterclockwise? Y/N ");
    scanf(" %c", &dirChoice);
    while(dirChoice!='Y'&&dirChoice!='N'){
        puts("Sorry, that is unrecognized, please try again.");
        printf("Rotate counterclockwise? Y/N ");
        scanf(" %c", &dirChoice);
    }
    if(dirChoice=='Y'){
        for(int i=0;i<3;i++){
            rotationsingle(&sideChoice);
        }
    }
    else if(dirChoice=='N'){
        rotationsingle(&sideChoice);
    }
}
void rotationsingle(char *side){
    if(*side=='F'){
        storage=green[0][0];
        green[0][0]=green[2][0];
        green[2][0]=green[2][2];
        green[2][2]=green[0][2];
        green[0][2]=storage;
        storage=green[0][1];
        green[0][1]=green[1][0];
        green[1][0]=green[2][1];
        green[2][1]=green[1][2];
        green[1][2]=storage;
        storage=white[2][0];
        white[2][0]=orange[2][2];
        orange[2][2]=yellow[0][2];
        yellow[0][2]=red[0][0];
        red[0][0]=storage;
        storage=white[2][1];
        white[2][1]=orange[1][2];
        orange[1][2]=yellow[0][1];
        yellow[0][1]=red[1][0];
        red[1][0]=storage;
        storage=white[2][2];
        white[2][2]=orange[0][2];
        orange[0][2]=yellow[0][0];
        yellow[0][0]=red[2][0];
        red[2][0]=storage;
    }
    else if(*side=='U'){
        storage=white[0][0];
        white[0][0]=white[2][0];
        white[2][0]=white[2][2];
        white[2][2]=white[0][2];
        white[0][2]=storage;
        storage=white[0][1];
        white[0][1]=white[1][0];
        white[1][0]=white[2][1];
        white[2][1]=white[1][2];
        white[1][2]=storage;
        storage=blue[0][2];
        blue[0][2]=orange[0][2];
        orange[0][2]=green[0][2];
        green[0][2]=red[0][2];
        red[0][2]=storage;
        storage=blue[0][1];
        blue[0][1]=orange[0][1];
        orange[0][1]=green[0][1];
        green[0][1]=red[0][1];
        red[0][1]=storage;
        storage=blue[0][0];
        blue[0][0]=orange[0][0];
        orange[0][0]=green[0][0];
        green[0][0]=red[0][0];
        red[0][0]=storage;
    }
    else if(*side=='L'){
        storage=orange[0][0];
        orange[0][0]=orange[2][0];
        orange[2][0]=orange[2][2];
        orange[2][2]=orange[0][2];
        orange[0][2]=storage;
        storage=orange[0][1];
        orange[0][1]=orange[1][0];
        orange[1][0]=orange[2][1];
        orange[2][1]=orange[1][2];
        orange[1][2]=storage;
        storage=white[0][0];
        white[0][0]=blue[2][2];
        blue[2][2]=yellow[0][0];
        yellow[0][0]=green[0][0];
        green[0][0]=storage;
        storage=white[1][0];
        white[1][0]=blue[1][2];
        blue[1][2]=yellow[1][0];
        yellow[1][0]=green[1][0];
        green[1][0]=storage;
        storage=white[2][0];
        white[2][0]=blue[0][2];
        blue[0][2]=yellow[2][0];
        yellow[2][0]=green[2][0];
        green[2][0]=storage;
    }
    else if(*side=='R'){
        storage=red[0][0];
        red[0][0]=red[2][0];
        red[2][0]=red[2][2];
        red[2][2]=red[0][2];
        red[0][2]=storage;
        storage=red[0][1];
        red[0][1]=red[1][0];
        red[1][0]=red[2][1];
        red[2][1]=red[1][2];
        red[1][2]=storage;
        storage=white[2][2];
        white[2][2]=green[2][2];
        green[2][2]=yellow[2][2];
        yellow[2][2]=blue[0][0];
        blue[0][0]=storage;
        storage=white[1][2];
        white[1][2]=green[1][2];
        green[1][2]=yellow[1][2];
        yellow[1][2]=blue[1][0];
        blue[1][0]=storage;
        storage=white[0][2];
        white[0][2]=green[0][2];
        green[0][2]=yellow[0][2];
        yellow[0][2]=blue[2][0];
        blue[2][0]=storage;
    }
    else if(*side=='B'){
        storage=blue[0][0];
        blue[0][0]=blue[2][0];
        blue[2][0]=blue[2][2];
        blue[2][2]=blue[0][2];
        blue[0][2]=storage;
        storage=blue[0][1];
        blue[0][1]=blue[1][0];
        blue[1][0]=blue[2][1];
        blue[2][1]=blue[1][2];
        blue[1][2]=storage;
        storage=white[0][2];
        white[0][2]=red[2][2];
        red[2][2]=yellow[2][0];
        yellow[2][0]=orange[0][0];
        orange[0][0]=storage;
        storage=white[0][1];
        white[0][1]=red[1][2];
        red[1][2]=yellow[2][1];
        yellow[2][1]=orange[1][0];
        orange[1][0]=storage;
        storage=white[0][0];
        white[0][0]=red[0][2];
        red[0][2]=yellow[2][2];
        yellow[2][2]=orange[2][0];
        orange[2][0]=storage;
    }
    else if(*side=='D'){
        storage=yellow[0][0];
        yellow[0][0]=yellow[2][0];
        yellow[2][0]=yellow[2][2];
        yellow[2][2]=yellow[0][2];
        yellow[0][2]=storage;
        storage=yellow[0][1];
        yellow[0][1]=yellow[1][0];
        yellow[1][0]=yellow[2][1];
        yellow[2][1]=yellow[1][2];
        yellow[1][2]=storage;
        storage=green[2][0];
        green[2][0]=orange[2][0];
        orange[2][0]=blue[2][0];
        blue[2][0]=red[2][0];
        red[2][0]=storage;
        storage=green[2][1];
        green[2][1]=orange[2][1];
        orange[2][1]=blue[2][1];
        blue[2][1]=red[2][1];
        red[2][1]=storage;
        storage=green[2][2];
        green[2][2]=orange[2][2];
        orange[2][2]=blue[2][2];
        blue[2][2]=red[2][2];
        red[2][2]=storage;
    }
}
int sideCheck(char face1[3][3], char face2[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(face1[i][j]!=face2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void printCube(void){
    for(int i=0;i<3;i++){
        printf("        ");
        for(int j=0;j<3;j++){
            printf(" %c", white[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c", orange[i][j]);
        }
        printf("  ");
        for(int j=0;j<3;j++){
            printf(" %c", green[i][j]);
        }
        printf("  ");
        for(int j=0;j<3;j++){
            printf(" %c", red[i][j]);
        }
        printf("  ");
        for(int j=0;j<3;j++){
            printf(" %c", blue[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<3;i++){
        printf("        ");
        for(int j=0;j<3;j++){
            printf(" %c", yellow[i][j]);
        }
        printf("\n");
    }
}