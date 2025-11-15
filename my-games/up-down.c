#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../functions.h"
void rules(void);
char readRules;
int myDie1;
int myDie2;
int myDieTotal;
int dealerDie1;
int dealerDie2;
int dealerDieTotal;
char prediction;
int myBet;
int myMoney=100;
int main(void){
    srand((unsigned)time(NULL));
    rules();
    for(int i=0;i<1000;i++){
        myDieTotal=0;dealerDieTotal=0;
        printf("How much do you bet this round? $");
        scanf("%d", &myBet);
        while(!(myBet>0&&myBet<=myMoney)){
            printf("Sorry, that amount is outside of the limit of how much you can bet\n");
            printf("How much do you bet this round? $");
            scanf("%d", &myBet);
        }
        usleep(1000000);
        dieRoll6(&dealerDie1);
        dealerDieTotal=dealerDie1;
        printf("The dealer's first die is [%d]; do you og higher (H) or lower (L)? ", dealerDie1);
        scanf(" %c", &prediction);
        usleep(1000000);
        while(prediction!='H'&&prediction!='L'){
            printf("Sorry, that is unrecognized, please try again\n");
            printf("Do you go higher (H) or lower (L)? ");
            scanf(" %c", &prediction);
            usleep(1000000);
        }
        dieRoll6(&myDie1);dieRoll6(&myDie2);
        myDieTotal=myDie1+myDie2;
        printf("Your die roll total is [%d]\n", myDie1+myDie2);
        usleep(1000000);
        dieRoll6(&dealerDie2);
        dealerDieTotal+=dealerDie2;
        printf("The dealer's second die is [%d], totaling to [%d]\n", dealerDie2, dealerDie1+dealerDie2);
        usleep(1000000);
        if((prediction=='H'&&myDieTotal>dealerDieTotal)||(prediction=='L'&&myDieTotal<dealerDieTotal)){
            printf("Congratulations! You won $%d this round!\n", myBet);
            myMoney+=myBet;
            usleep(1000000);
            printf("Current money: $%d\n", myMoney);
            usleep(1000000);
        }
        else{
            printf("Sorry, you lost $%d this round\n", myBet);
            usleep(1000000);
            myMoney-=myBet;
            printf("Current money: $%d\n", myMoney);
            usleep(1000000);
        }
        if(myMoney<=0){
            i+=1000;
        }
        if(i==999){
            printf("WOW! YOU STAYED IN FOR 1000 ROUNDS!!!\n");
            usleep(1000000);
            printf("You ended with an outstading $%d\n", myMoney);
            usleep(1000000);
        }
    }
}
void rules(void){
    printf("Welcome to Up Down; would you like a reading of the rules? Y/N ");
    scanf(" %c", &readRules);
    usleep(1000000);
    while(readRules!='Y'&&readRules!='N'){
        printf("Sorry, that is unrecognized. Please try again.");usleep(1000000);
        printf("Welcome to Up Down; would you like a reading of the rules? Y/N");usleep(1000000);
        scanf(" %c", &readRules);
    }
    if(readRules=='Y'){
        printf("In this game, your goal is to accurately predict whether your combined roll of two dice is going to be higher or lower than the dealer's, and to roll that outcome.\n");sleep(3);
        printf("First, the dealer will roll one die, to which you will make your prediction followed by the rolling of your dice.\n");sleep(3);
        printf("After you roll both of your dice, the dealer will roll their second die.\n");sleep(3);
        printf("If your combined roll is higher or lower than the dealer's (depending on your prediction), then you win a 2x payout.\n");sleep(3);
        printf("If it is either in the opposite direction, OR a tie, then you unfortunately lose your bet :(\n");sleep(3);
        printf("You will start with $100\n");sleep(3);
    }
}