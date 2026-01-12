 // Yahtzee
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "/workspaces/CProgramming2/functions/die-roller.h"
int diceHold(void);
int diecount(void);
int score(void);
int readScore(void);
int yahtzeeBonus(void);
int rules(void);
char rollOrScore;
int die1;
char diea;
int die2;
char dieb;
int die3;
char diec;
int die4;
char died;
int die5;
char diee;
char reroll;
int onesCount=0;
int twosCount=0;
int threesCount=0;
int foursCount=0;
int fivesCount=0;
int sixesCount=0;
int acesScore=0;
int acesScoreO=1;
int twosScore=0;
int twosScoreO=1;
int threesScore=0;
int threesScoreO=1;
int foursScore=0;
int foursScoreO=1;
int fivesScore=0;
int fivesScoreO=1;
int sixesScore=0;
int sixesScoreO=1;
int totalUpperScore=0;
int finalTotalUpperScore=0;
int threeOfAKindScore=0;
int threeOfAKindScoreO=1;
int fourOfAKindScore=0;
int fourOfAKindScoreO=1;
int fullHouseScore=0;
int fullHouseScoreO=1;
int smallStraightScore=0;
int smallStraightScoreO=1;
int largeStraightScore=0;
int largeStraightScoreO=1;
int yahtzeeScore=0;
int yahtzeeScoreO=1;
int chanceScore=0;
int chanceScoreO=1;
int totalLowerScore=0;
int grandTotalScore=0;
char nextTurn;
char scoreSelect;
int scoreDoCheck=0;
int yahtzeeCheck=0;
int record=0;
int pastRecord=0;
char newGameCheck;
char readRules;
int main(void){
    for(int k=1;k<=1000;k++){
        srand(time(0));
        rules();
        for(int i=1;i<=13;i++){
            scoreDoCheck=0;
            dieRoll6(&die1);dieRoll6(&die2);dieRoll6(&die3);dieRoll6(&die4);dieRoll6(&die5);
            printf("Your first dice rolls:\n[%d] [%d] [%d] [%d] [%d]\n", die1, die2, die3, die4, die5);
            diecount();
            usleep(500000);
            for(int j=1;j<=2;j++){
                printf("Choose whether you would like to roll again (R) or to end this round and score points (S)\n");
                scanf(" %c", &rollOrScore);
                while(!(rollOrScore=='R'||rollOrScore=='S')){
                    printf("Sorry, that is an unrecognized command. Please try again.\n");
                    printf("Choose whether you would like to roll again (R) or to end this round and score points(S)\n");
                    scanf(" %c", &rollOrScore);
                    usleep(500000);
                }
                usleep(500000);
                if(rollOrScore=='R'){
                    diceHold();
                    usleep(500000);
                    diecount();
                }
                else if(rollOrScore=='S'){
                    score();
                    j+=2;
                    scoreDoCheck+=1;
                }
            }
            usleep(500000);
            if(scoreDoCheck==0){
                printf("You have rolled the maximum amount in one turn, please score points.\n");
                usleep(500000);
                score();
            }
            readScore();
            printf("Select next (N) when ready for next turn\n");
            scanf(" %c", &nextTurn);
            usleep(500000);
        }
        usleep(500000);
        if(!(grandTotalScore<=record)){
            pastRecord=record;
            record=grandTotalScore;
            printf("Congratulations! You've beaten your previous record of %d. Your new record is %d.\n", pastRecord, record);
        }
        else{
            printf("Too bad, you could beat your record of %d. You can always try again though!", record);
        }
        usleep(500000);
        printf("Would you like to play another game of YAHTZEE? Y/N ");
        scanf(" %c", &newGameCheck);
        usleep(500000);
        if(newGameCheck=='Y'){
            printf("Good luck on your next game!\n\n\n\n");
            usleep(1000000);
        }
        else if(newGameCheck=='N'){
            k+=1000;
        }
    }
}
int diceHold(void){
    printf("Select whether to hold (H) or reroll (R) for each die\n");
    usleep(500000);
    printf("Die 1: ");
    scanf(" %c", &diea);
    printf("Die 2: ");
    scanf(" %c", &dieb);
    printf("Die 3: ");
    scanf(" %c", &diec);
    printf("Die 4: ");
    scanf(" %c", &died);
    printf("Die 5: ");
    scanf(" %c", &diee);
    if(diea=='R'){
        dieRoll6(&die1);
    }
    if(dieb=='R'){
        dieRoll6(&die2);
    }
    if(diec=='R'){
        dieRoll6(&die3);
    }
    if(died=='R'){
        dieRoll6(&die4);
    }
    if(diee=='R'){
        dieRoll6(&die5);
    }
    usleep(500000);
    printf("Your next dice rolls:\n[%d] [%d] [%d] [%d] [%d]\n", die1, die2, die3, die4, die5);
}
int diecount(void){
    onesCount=0;
    twosCount=0;
    threesCount=0;
    foursCount=0;
    fivesCount=0;
    sixesCount=0;
    if(die1==1){
        onesCount+=1;
    }
    else if(die1==2){
        twosCount+=1;
    }
    else if(die1==3){
        threesCount+=1;
    }
    else if(die1==4){
        foursCount+=1;
    }
    else if(die1==5){
        fivesCount+=1;
    }
    else if(die1==6){
        sixesCount+=1;
    }
    if(die2==1){
        onesCount+=1;
    }
    else if(die2==2){
        twosCount+=1;
    }
    else if(die2==3){
        threesCount+=1;
    }
    else if(die2==4){
        foursCount+=1;
    }
    else if(die2==5){
        fivesCount+=1;
    }
    else if(die2==6){
        sixesCount+=1;
    }
    if(die3==1){
        onesCount+=1;
    }
    else if(die3==2){
        twosCount+=1;
    }
    else if(die3==3){
        threesCount+=1;
    }
    else if(die3==4){
        foursCount+=1;
    }
    else if(die3==5){
        fivesCount+=1;
    }
    else if(die3==6){
        sixesCount+=1;
    }
    if(die4==1){
        onesCount+=1;
    }
    else if(die4==2){
        twosCount+=1;
    }
    else if(die4==3){
        threesCount+=1;
    }
    else if(die4==4){
        foursCount+=1;
    }
    else if(die4==5){
        fivesCount+=1;
    }
    else if(die4==6){
        sixesCount+=1;
    }
    if(die5==1){
        onesCount+=1;
    }
    else if(die5==2){
        twosCount+=1;
    }
    else if(die5==3){
        threesCount+=1;
    }
    else if(die5==4){
        foursCount+=1;
    }
    else if(die5==5){
        fivesCount+=1;
    }
    else if(die5==6){
        sixesCount+=1;
    }
    printf("You currently have %d ones, %d twos, %d threes, %d fours, %d fives, and %d sixes\n", onesCount, twosCount, threesCount, foursCount, fivesCount, sixesCount);
}
int score(void){
    puts("Here are your available opporotunities to score points:");
    usleep(500000);
    if(acesScoreO==1){
        printf("Aces (1)");
        if(twosScoreO==1||threesScoreO==1||foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
            printf(", ");
        }
    }
    if(twosScoreO==1){
        printf("Twos (2)");
        if(threesScoreO==1||foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
            printf(", ");
        }
    }
    if(threesScoreO==1){
        printf("Threes (3)");
        if(foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
            printf(", ");
        }
    }
    if(foursScoreO==1){
        printf("Fours (4)");
        if(fivesScoreO==1||sixesScoreO==1){
            printf(", ");
        }
    }
    if(fivesScoreO==1){
        printf("Fives (5)");
        if(sixesScoreO==1){
            printf(", ");
        }
    }
    if(sixesScoreO==1){
        printf("Sixes (6)");
    }
    if(acesScoreO==1||twosScoreO==1||threesScoreO==1||foursScore==1||fivesScoreO==1||sixesScoreO==1){
        printf("\n");
        usleep(500000);
    }
    if(threeOfAKindScoreO==1){
        printf("3 of a Kind (T)");
        if(fourOfAKindScoreO==1||fullHouseScoreO==1||smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
            printf(", ");
        }
    }
    if(fourOfAKindScoreO==1){
        printf("4 of a Kind (F)");
        if(fullHouseScoreO==1||smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
            printf(", ");
        }
    }
    if(fullHouseScoreO==1){
        printf("Full House (H)");
        if(smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
            printf(", ");
        }
    }
    if(smallStraightScoreO==1){
        printf("Small Straight (S)");
        if(largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
            printf(", ");
        }
    }
    if(largeStraightScoreO==1){
        printf("Large Straight (L)");
        if(yahtzeeScoreO==1||chanceScoreO==1){
            printf(", ");
        }
    }
    if(yahtzeeScoreO==1||yahtzeeCheck==1){
        if(yahtzeeScoreO==1){
            printf("YAHTZEE (Y)");
        }
        if(yahtzeeCheck==1){
            printf("YAHTZEE Bonus (Y)");
        }
        if(chanceScoreO==1){
            printf(", ");
        }
    }
    if(chanceScoreO==1){
        printf("Chance (C)");
    }
    if(threeOfAKindScoreO==1||fourOfAKindScoreO==1||fullHouseScore==1||smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
        printf("\n");
        usleep(500000);
    }
    puts("Which would you like to score points under?");
    scanf(" %c", &scoreSelect);
    usleep(500000);
    while((!(scoreSelect=='1'||scoreSelect=='2'||scoreSelect=='3'||scoreSelect=='4'||scoreSelect=='5'||scoreSelect=='6'||scoreSelect=='T'||scoreSelect=='F'||scoreSelect=='H'||scoreSelect=='S'||scoreSelect=='L'||scoreSelect=='Y'||scoreSelect=='C'))||(scoreSelect=='1'&&acesScoreO==0)||(scoreSelect=='2'&&twosScoreO==0)||(scoreSelect=='3'&&threesScoreO==0)||(scoreSelect=='4'&&foursScoreO==0)||(scoreSelect=='5'&&fivesScoreO==0)||(scoreSelect=='6'&&sixesScoreO==0)||(scoreSelect=='T'&&threeOfAKindScoreO==0)||(scoreSelect=='F'&&fourOfAKindScoreO==0)||(scoreSelect=='H'&&fullHouseScoreO==0)||(scoreSelect=='S'&&smallStraightScoreO==0)||(scoreSelect=='L'&&largeStraightScoreO==0)||(scoreSelect=='Y'&&yahtzeeScoreO==0)||(scoreSelect=='C'&&chanceScoreO==0)){
        puts("Sorry, that selection either doesn't correspond to a scoring option, or its option has already been used this game. Please choose again.");
        scanf(" %c", &scoreSelect);
        usleep(500000);
    }
    if(scoreSelect=='1'&&acesScoreO==1){
        totalUpperScore+=onesCount;
        acesScoreO=0;
    }
    else if(scoreSelect=='2'&&twosScoreO==1){
        totalUpperScore+=(twosCount*2);
        twosScoreO=0;
    }
    else if(scoreSelect=='3'&&threesScoreO==1){
        totalUpperScore+=(threesCount*3);
        threesScoreO=0;
    }
    else if(scoreSelect=='4'&&foursScoreO==1){
        totalUpperScore+=(foursCount*4);
        foursScoreO=0;
    }
    else if(scoreSelect=='5'&&fivesScoreO==1){
        totalUpperScore+=(fivesCount*5);
        fivesScoreO=0;
    }
    else if(scoreSelect=='6'&&sixesScoreO==1){
        totalUpperScore+=(sixesCount*6);
        sixesScoreO=0;
    }
    else if(scoreSelect=='T'&&threeOfAKindScoreO==1){
        if(onesCount>=3||twosCount>=3||threesCount>=3||foursCount>=3||fivesCount>=3||sixesCount>=3){
            totalLowerScore+=die1+die2+die3+die4+die5;
        }
        threeOfAKindScoreO=0;
    }
    else if(scoreSelect=='F'&&fourOfAKindScoreO==1){
        if(onesCount>=4||twosCount>=4||threesCount>=4||foursCount>=4||fivesCount>=4||sixesCount>=4){
            totalLowerScore+=die1+die2+die3+die4+die5;
        }
        fourOfAKindScoreO=0;
    }
    else if(scoreSelect=='H'&&fullHouseScoreO==1){
        if((onesCount==3&&(twosCount==2||threesCount==2||foursCount==2||fivesCount==2||sixesCount==2))||(twosCount==3&&(onesCount==2||threesCount==2||foursCount==2||fivesCount==2||sixesCount==2))||(threesCount==3&&(twosCount==2||onesCount==2||foursCount==2||fivesCount==2||sixesCount==2))||(foursCount==3&&(twosCount==2||threesCount==2||onesCount==2||fivesCount==2||sixesCount==2))||(fivesCount==3&&(twosCount==2||threesCount==2||foursCount==2||onesCount==2||sixesCount==2))||(sixesCount==3&&(twosCount==2||threesCount==2||foursCount==2||fivesCount==2||onesCount==2))){
            totalLowerScore+=25;
        }
        fullHouseScoreO=0;
    }
    else if(scoreSelect=='S'&&smallStraightScoreO==1){
        if((threesCount>=1&&foursCount>=1)&&((onesCount>=1&&twosCount>=1)||(twosCount>=1&&fivesCount>=1)||(fivesCount>=1&&sixesCount>=1))){
            totalLowerScore+=30;
        }
        smallStraightScoreO=0;
    }
    else if(scoreSelect=='L'&&largeStraightScoreO==1){
        if((twosCount>=1&&threesCount>=1&&foursCount>=1&&fivesCount>=1)&&(onesCount>=1||sixesCount>=1)){
            totalLowerScore+=40;
        }
        largeStraightScoreO=0;
    }
    else if(scoreSelect=='Y'&&yahtzeeScoreO==1){
        if(onesCount==5||twosCount==5||threesCount==5||foursCount==5||fivesCount==5||sixesCount==5){
            if(yahtzeeScoreO=1){
                totalLowerScore+=50;
                yahtzeeCheck+=1;
            }
            else if(yahtzeeScoreO=0&&yahtzeeCheck==1){
                yahtzeeBonus();
            }
        }
        yahtzeeScoreO=0;
    }
    else if(scoreSelect=='C'&&chanceScoreO==1){
        totalLowerScore+=die1+die2+die3+die4+die5;
        chanceScoreO=0;
    }
    if(totalUpperScore>=63){
        grandTotalScore=totalUpperScore+totalLowerScore+35;
    }
    else{
        grandTotalScore=totalUpperScore+totalLowerScore;
    }
    scoreDoCheck+=1;
}
int readScore(void){
    if(totalUpperScore>=63){
        printf("Current upper section score: %d\nCurrent lower section score: %d\nCurrent total score: %d\n", (totalUpperScore+35), totalLowerScore, grandTotalScore);
    }
    else{
        printf("Current upper section score: %d\nCurrent lower section score: %d\nCurrent total score: %d\n", totalUpperScore, totalLowerScore, grandTotalScore);
    }
    usleep(500000);
}
int yahtzeeBonus(void){
    totalLowerScore+=100;
    puts("In addition to the 100 points for an additional YAHTZEE, select which option you would like to recieve points for");
    usleep(500000);
    if(acesScoreO==1||twosScoreO==1||threesScoreO==1||foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
        if(acesScoreO==1){
            printf("Aces (1)");
            if(twosScoreO==1||threesScoreO==1||foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
                printf(", ");
            }
        }
        if(twosScoreO==1){
            printf("Twos (2)");
            if(threesScoreO==1||foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
                printf(", ");
            }
        }
        if(threesScoreO==1){
            printf("Threes (3)");
            if(foursScoreO==1||fivesScoreO==1||sixesScoreO==1){
                printf(", ");
            }
        }
        if(foursScoreO==1){
            printf("Fours (4)");
            if(fivesScoreO==1||sixesScoreO==1){
                printf(", ");
            }
        }
        if(fivesScoreO==1){
            printf("Fives (5)");
            if(sixesScoreO==1){
                printf(", ");
            }
        }
        if(sixesScoreO==1){
            printf("Sixes (6)");
        }
        printf("\n");
        scanf(" %c", &scoreSelect);
        usleep(500000);
        while((scoreSelect=='1'&&acesScoreO==0)||(scoreSelect=='2'&&twosScoreO==0)||(scoreSelect=='3'&&threesScoreO==0)||(scoreSelect=='4'&&foursScoreO==0)||(scoreSelect=='5'&&fivesScoreO==0)||(scoreSelect=='6'&&sixesScoreO==0)){
            puts("Sorry, that selection either doesn't correspond to a scoring option, or its option has already been used this game. Please choose again.");
            scanf(" %c", &scoreSelect);
            usleep(500000);
        }
        if(scoreSelect=='1'&&acesScoreO==1){
            totalUpperScore+=onesCount;
            acesScoreO=0;
        }
        else if(scoreSelect=='2'&&twosScoreO==1){
            totalUpperScore+=(twosCount*2);
            twosScoreO=0;
        }
        else if(scoreSelect=='3'&&threesScoreO==1){
            totalUpperScore+=(threesCount*3);
            threesScoreO=0;
        }
        else if(scoreSelect=='4'&&foursScoreO==1){
            totalUpperScore+=(foursCount*4);
            foursScoreO=0;
        }
        else if(scoreSelect=='5'&&fivesScoreO==1){
            totalUpperScore+=(fivesCount*5);
            fivesScoreO=0;
        }
        else if(scoreSelect=='6'&&sixesScoreO==1){
            totalUpperScore+=(sixesCount*6);
            sixesScoreO=0;
        }
    }
    else{
        if(threeOfAKindScoreO==1){
            printf("3 of a Kind (T)");
            if(fourOfAKindScoreO==1||fullHouseScoreO==1||smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
                printf(", ");
            }
        }
        if(fourOfAKindScoreO==1){
            printf("4 of a Kind (F)");
            if(fullHouseScoreO==1||smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
                printf(", ");
            }
        }
        if(fullHouseScoreO==1){
            printf("Full House (H)");
            if(smallStraightScoreO==1||largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
                printf(", ");
            }
        }
        if(smallStraightScoreO==1){
            printf("Small Straight (S)");
            if(largeStraightScoreO==1||yahtzeeScoreO==1||chanceScoreO==1){
                printf(", ");
            }
        }
        if(largeStraightScoreO==1){
            printf("Large Straight (L)");
            if(yahtzeeScoreO==1||chanceScoreO==1){
                printf(", ");
            }
        }
        if(chanceScoreO==1){
            printf("Chance (C)");
        }
        printf("\n");
        usleep(500000);
        while((scoreSelect=='T'&&threeOfAKindScoreO==0)||(scoreSelect=='F'&&fourOfAKindScoreO==0)||(scoreSelect=='H'&&fullHouseScoreO==0)||(scoreSelect=='S'&&smallStraightScoreO==0)||(scoreSelect=='L'&&largeStraightScoreO==0)||(scoreSelect=='C'&&chanceScoreO==0)){
            puts("Sorry, that selection either doesn't correspond to a scoring option, or its option has already been used this game. Please choose again.");
            scanf(" %c", &scoreSelect);
            usleep(500000);
        }
        if(scoreSelect=='T'){
            totalLowerScore+=die1+die2+die3+die4+die5;
            threeOfAKindScoreO=0;
        }
        else if(scoreSelect=='F'){
            totalLowerScore+=die1+die2+die3+die4+die5;
            fourOfAKindScoreO==0;
        }
        else if(scoreSelect=='H'){
            totalLowerScore+=25;
            fullHouseScoreO==0;
        }
        else if(scoreSelect=='S'){
            totalLowerScore+=30;
            smallStraightScoreO==0;
        }
        else if(scoreSelect=='L'){
            totalLowerScore+=40;
            largeStraightScoreO==0;
        }
        else if(scoreSelect=='C'){
            totalLowerScore+=die1+die2+die3+die4+die5;
            chanceScoreO==0;
        }
    }
}
int rules(void){
    printf("Would you like to have an explanation of the rules of YAHTZEE? Y/N: ");
    scanf(" %c", &readRules);
    puts("");
    if(!(readRules=='Y'||readRules=='N')){
        puts("That is an unrecognized command, please try again");
        scanf(" %c", &readRules);
        puts("");
    }
    if(readRules=='Y'){
        usleep(500000);
        printf("Hello, and welcome to YAHTZEE, a game about rolling dice and scoring points\n\n");
        usleep(500000);
        printf("In YAHTZEE, you have 5 6-sided dice that are rolled each turn.\n");
        usleep(500000);
        printf("Within a turn you can 'hold' individual dice to roll all the others for a better score, with a total of 3 dice rolls each turn.\n");
        usleep(500000);
        printf("After the third roll, or any time prior if you want to, you may then score points in one of multiple categories based off of your dice rolls.\n\n");
        usleep(500000);
        printf("These scoring categories are split up into the Upper and Lower sections.\n");
        usleep(500000);
        printf("The Upper section consists of scoring for the total of one die face, from ones to sixes. The amount of dice with that value is multiplied by the number of the side rolled, and that is whats recorded for that score.\n");
        usleep(500000);
        printf("If the total value of the Upper section is 63 or higher, which is equal to rolling 3 or more of each number, then you earn a bonus 35 points for the Upper section.\n\n");
        usleep(500000);
        printf("The Lower section contains a larger variety of scoring opportunities, this includes the following:\n");
        usleep(500000);
        printf(" -Three and Four of a kind which scores the total value of all dice added up, requiring that you have at least 3 or 4 of the same dice value, respectively\n");
        usleep(500000);
        printf(" -Full House for 25 points requiring a seperate 3 of a kind and pair\n");
        usleep(500000);
        printf(" -Small and Large straights for 30/40 points needing 4/5 dice in a row (consecutive numbers, such as rolling [4], [2], [3], [5] for small straight)\n");
        usleep(2000000);
        printf("\n\n\n");
    }
}