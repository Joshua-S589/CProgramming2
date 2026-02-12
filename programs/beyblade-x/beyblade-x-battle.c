#include "/workspaces/CProgramming2/programs/beyblade-x/deck-randomizer-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/match-beyblade-x.h"
void deckOrderRandomizer(void);
char battleChoice;
char battleResultsType;
int battleResultsPlayer;
int deckChoice;
int matchBattleNum=0;
int matchBattleNumTotal=1;
int main(void){
    printf("Would you like to run deck battles (B) or simply generate decks (G)? ");
    scanf(" %c", &battleChoice);
    while(!(battleChoice=='B'||battleChoice=='G')){
        puts("Sorry, that is an invalid choice, please reenter");
        printf("Would you like to run deck battles (B) or simply generate decks (G)? ");
        scanf(" %c", &battleChoice);
    }
    if(battleChoice=='G'){
        playercnt=playerCount();
        userSelect1();
        if(playercnt==2){
            userSelect2();
        }
        for(int a=0;a<1;){
            makeTheCombos(playercnt);
            if(playercnt==1){
                printf("Deck:\n");
                for(int z=0;z<finalDeckSize;z++){
                    printf("%s\n", combo_list_player_1[z]);
                }
                puts("");
                printf("Generate another deck? Y/N\n");
                scanf(" %c", &nextDeck);
                if(nextDeck=='N'){
                    a++;
                }
            }
            if(playercnt==2){
                printf("Player 1 deck:\n");
                for(int z=0;z<finalDeckSize;z++){
                    printf("%s\n", combo_list_player_1[z]);
                }
                puts("");
                printf("Player 2 deck:\n");
                for(int z=0;z<finalDeckSize;z++){
                    printf("%s\n", combo_list_player_2[z]);
                }
                puts("");
                printf("Generate another deck? Y/N\n");
                scanf(" %c", &nextDeck);
                if(nextDeck=='N'){
                    a++;
                }
            }
        }
    }
    if(battleChoice=='B'){
        userSelect1();
        userSelect2();
        makeTheCombos(2);
        printf("How many points do you want to go to? ");
        scanf(" %d", &pointGoal);
        while(pointGoal>100){
            puts("Sorry, going to that many points will take too long, please reenter");
            printf("How many points do you want to go to? ");
            scanf(" %d", &pointGoal);
        }
        while(pointGoal<1){
            puts("Sorry, that is an invalid goal, please reenter");
            printf("How many points do you want to go to? ");
            scanf(" %d", &pointGoal);
            while(pointGoal>100){
                puts("Sorry, going to that many points will take too long, please reenter");
                printf("How many points do you want to go to? ");
                scanf(" %d", &pointGoal);
            }
        }
        greaterPoint=0;
        while(greaterPoint<pointGoal){
            if(greaterPoint==0){
                puts("Randomizing the deck orders for the begining of the match...");
            }
            else{
                puts("End of decks has been reached, and the match is not yet finished. Re-randomizing the deck orders.");
            }
            deckOrderRandomizer();
            do{
                printf("Beyblades for battle %d: \n\n%s\nvs\n%s\n\n", matchBattleNumTotal, deckOrder1[matchBattleNum], deckOrder2[matchBattleNum]);
                printf("Did player 1 or 2 win the battle? Player ");
                scanf(" %d", &battleResultsPlayer);
                while(!(battleResultsPlayer==1||battleResultsPlayer==2)){
                    puts("Sorry, that is an invalid player number. Please reenter");
                    printf("Did player 1 or 2 win the battle? Player ");
                    scanf(" %d", &battleResultsPlayer);
                }
                printf("What is the outcome of the battle? Spin Finish (S), Burst Finish (B), Over Finish (O), or Extreme Finish (E): ");
                scanf(" %c", &battleResultsType);
                while((!battleResultsType=='S')&&(!battleResultsType=='B')&&(!battleResultsType=='O')&&(!battleResultsType=='E')){
                    puts("Sorry, that is an invalid result, please reenter");
                    printf("What is the outcome of the battle? Spin Finish (S), Burst Finish (B), Over Finish (O), or Extreme Finish (E): ");
                    scanf(" %c", &battleResultsType);
                }
                if(battleResultsType=='S'){
                    if(battleResultsPlayer==1){
                        score1+=1;
                    }
                    if(battleResultsPlayer==2){
                        score2+=1;
                    }
                }
                if(battleResultsType=='B'){
                    if(battleResultsPlayer==1){
                        score1+=2;
                    }
                    if(battleResultsPlayer==2){
                        score2+=2;
                    }
                }
                if(battleResultsType=='O'){
                    if(battleResultsPlayer==1){
                        score1+=2;
                    }
                    if(battleResultsPlayer==2){
                        score2+=2;
                    }
                }
                if(battleResultsType=='E'){
                    if(battleResultsPlayer==1){
                        score1+=3;
                    }
                    if(battleResultsPlayer==2){
                        score2+=3;
                    }
                }
                printf("\nCurrent Scores:\nPlayer 1: %d\nPlayer 2: %d\n", score1, score2);
                matchBattleNum++;
                matchBattleNumTotal++;
                if(score1>score2){
                    greaterPoint=score1;
                }
                else{
                    greaterPoint=score2;
                }
            }while(greaterPoint<pointGoal&&matchBattleNum<finalDeckSize);
            matchBattleNum=0;
        }
        if(score1>score2){
            printf("Player 1 beat Player 2 with a final score of %d-%d\n", score1, score2);
        }
        else{
            printf("Player 2 beat Player 1 with a final score of %d-%d\n", score2, score1);
        }
    }
    return 0;
}
void deckOrderRandomizer(void){
    for(int j=0;j<finalDeckSize;j++){
        do{
            deckChoice=rand()%finalDeckSize;
            if(avbCombo1[deckChoice]==1){
                deckOrder1[j][0]='\n';
                sprintf(deckOrder1[j], "%s", combo_list_player_1[deckChoice]);
            }
        }while(avbCombo1[deckChoice]==0);
        avbCombo1[deckChoice]=0;
        do{
            deckChoice=rand()%finalDeckSize;
            if(avbCombo2[deckChoice]==1){
                deckOrder2[j][0]='\n';
                sprintf(deckOrder2[j], "%s", combo_list_player_2[deckChoice]);
            }
        }while(avbCombo2[deckChoice]==0);
        avbCombo2[deckChoice]=0;
    }
    for(int j=0;j<finalDeckSize;j++){
        avbCombo1[j]=1;
        avbCombo2[j]=1;
    }
}