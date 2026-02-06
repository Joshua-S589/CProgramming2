#include "/workspaces/CProgramming2/programs/beyblade-x/deck-randomizer-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/match-beyblade-x.h"
char battleChoice;
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
        for(int a=0;a<1;){
            userSelect1();
            userSelect2();
            makeTheCombos(2);
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
    return 0;
}