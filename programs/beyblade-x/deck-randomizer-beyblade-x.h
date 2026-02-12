#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/parts-list-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/user-parts-lists-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/match-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/var-and-fun/deck-ran.h"
void makeTheCombos(int n){
    srand(time(0));
    if(n==1){
        printf("How many combos would you like your deck to contain?\n");
        scanf(" %d", &deckSize);
        for(int b=0;b<deckSize;b++){
            numOfDeck=b;
            comboRandomizer1();
            avbCombo1[b]=1;
            if(contgen==1){
                finalDeckSize=b+1;
                b+=deckSize;
                contgen=0;
            }
            finalDeckSize=b+1;
        }
        cloneReset();
        puts("");
        deckSize=0;
    }
    if(n==2){
        printf("How many combos would you like your decks to contain?\n");
        scanf(" %d", &deckSize);
        for(int b=0;b<deckSize;b++){
            numOfDeck=b;
            comboRandomizer1();
            avbCombo1[b]=1;
            if(contgen==1){
                finalDeckSize=b+1;
                b+=deckSize;
                contgen=0;
            }
            finalDeckSize=b+1;
        }
        for(int b=0;b<deckSize;b++){
            numOfDeck=b;
            comboRandomizer2();
            avbCombo2[b]=1;
            if(contgen==1){
                if(b+1<finalDeckSize){
                    finalDeckSize=b+1;
                }
                b+=deckSize;
                contgen=0;
            }
        }
        cloneReset();
        deckSize=0;
    }
}
void comboRandomizer1(void){
    nocxtest=0;
    nononcxtest=0;
    bladetest=0;
    ratchettest=0;
    bittest=0;
    choiceBlade=0;
    choiceLockChip=0;
    choiceAssistBlade=0;
    choiceRatchet=0;
    choiceBit=0;
    partsCheck1();
    if(contgen==1){
        return;
    }
    if(simpleratchettest==0){
        bladeCollectionClone1[bladeBxcnt+clockMiragenum]=0;
    }
    do{
        choiceBlade=rand()%(bladecnt+mainBladecnt);
    }while(bladeCollectionClone1[choiceBlade]==0);
    str1=blade[choiceBlade];
    if(choiceBlade<bladecnt){
        blade_final[0]='\n';
        sprintf(blade_final, "%s", blade[choiceBlade]);
    }
    else{
        do{
            choiceLockChip=rand()%(mlccnt+plccnt);
        }while(lockChipCollectionClone1[choiceLockChip]==0);
        do{
            choiceAssistBlade=rand()%assistBladecnt;
        }while(assistBladeCollectionClone1[choiceAssistBlade]==0);
        blade_final[0]='\n';
        sprintf(blade_final, "%s %s %s", lock_chip[choiceLockChip], blade[choiceBlade], assist_blade[choiceAssistBlade]);
    }
    if(strcmp(blade[choiceBlade],simple_blade[0])==0){
        do{
            choiceRatchet=rand()%simpleRatchetcnt;
        }while(simpleRatchetCollectionClone1[choiceRatchet]==0);
    }
    else{
        do{
            choiceRatchet=rand()%(ratchetcnt+ratchetIntegratedBitcnt);
        }while(ratchetCollectionClone1[choiceRatchet]==0);
    }
    if(choiceRatchet<simpleRatchetcnt||choiceRatchet>=(simpleRatchetcnt+ratchetIntegratedBitcnt)){
        do{
            choiceBit=rand()%bitcnt;
        }while(bitCollectionClone1[choiceBit]==0);
    }
    bladeCollectionClone1[choiceBlade]-=1;
    if(choiceLockChip<mlccnt){
        lockChipCollectionClone1[choiceLockChip]-=1;
    }
    if(choiceBlade>=bladecnt){
        assistBladeCollectionClone1[choiceAssistBlade]-=1;
    }
    ratchetCollectionClone1[choiceRatchet]-=1;
    if(choiceRatchet<simpleRatchetcnt||choiceRatchet>=(simpleRatchetcnt+ratchetIntegratedBitcnt)){
        bitCollectionClone1[choiceBit]-=1;
        if(choiceBlade>=bladecnt){
            combo_list_player_1[numOfDeck][0]='\n';
            sprintf(combo_list_player_1[numOfDeck], "%s%s %s", blade_final, ratchet[choiceRatchet], bit[choiceBit]);
        }
        else{
            combo_list_player_1[numOfDeck][0]='\n';
            sprintf(combo_list_player_1[numOfDeck], "%s %s %s", blade_final, ratchet[choiceRatchet], bit[choiceBit]);
        }
    }
    else{
        if(choiceBlade>=bladecnt){
            combo_list_player_1[numOfDeck][0]='\n';
            sprintf(combo_list_player_1[numOfDeck], "%s%s", blade_final, ratchet[choiceRatchet]);
        }
        else{
            combo_list_player_1[numOfDeck][0]='\n';
            sprintf(combo_list_player_1[numOfDeck], "%s %s", blade_final, ratchet[choiceRatchet]);
        }
    }
    return;
}
void partGetter1(void){
    for(int i=0;i<bladecnt;i++){
        printf("Do you have the blade ");
        printf("%s", blade[i]);
        printf("? Y/N\n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bladeCollection1[i]=1;
            bladeCollectionClone1[i]=1;
        }
        else if(decision=='N'){
            bladeCollection1[i]=0;
            bladeCollectionClone1[i]=0;
        }
    }
    for(int i=bladecnt;i<(bladecnt+mainBladecnt);i++){
        printf("Do you have the main blade ");
        printf("%s", blade[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bladeCollection1[i]=1;
            bladeCollectionClone1[i]=1;
        }
        else if(decision=='N'){
            bladeCollection1[i]=0;
            bladeCollectionClone1[i]=0;
        }
    }
    for(int i=0;i<assistBladecnt;i++){
        printf("Do you have the assist blade ");
        printf("%s", assist_blade[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            assistBladeCollection1[i]=1;
            assistBladeCollectionClone1[i]=1;
        }
        else if(decision=='N'){
            assistBladeCollection1[i]=0;
            assistBladeCollectionClone1[i]=0;
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        str2=ratchet[i];
        printf("Do you have the ratchet ");
        printf("%s", ratchet[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            ratchetCollection1[i]=1;
            ratchetCollectionClone1[i]=1;
            for(int j=0;j<simpleRatchetcnt;j++){
                str3=simple_ratchet[j];
                if(strcmp(str2,str3)==0){
                    simpleRatchetCollection1[j]=1;
                    simpleRatchetCollectionClone1[j]=1;
                }
            }
        }
        else if(decision=='N'){
            ratchetCollection1[i]=0;
            ratchetCollectionClone1[i]=0;
        }
    }
    for(int i=0;i<bitcnt;i++){
        printf("Do you have the bit ");
        printf("%s", bit[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bitCollection1[i]=1;
            bitCollectionClone1[i]=1;
        }
        else if(decision=='N'){
            bitCollection1[i]=0;
            bitCollectionClone1[i]=0;
        }
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        printf("Do you have the lock chip ");
        printf("%s", lock_chip[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            lockChipCollection1[i]=1;
            lockChipCollectionClone1[i]=1;
        }
        else if(decision=='N'){
            lockChipCollection1[i]=0;
            lockChipCollectionClone1[i]=0;
        }
    }
}
void comboRandomizer2(void){
    nocxtest=0;
    nononcxtest=0;
    bladetest=0;
    ratchettest=0;
    bittest=0;
    choiceBlade=0;
    choiceLockChip=0;
    choiceAssistBlade=0;
    choiceRatchet=0;
    choiceBit=0;
    partsCheck2();
    if(contgen==1){
        return;
    }
    if(simpleratchettest==0){
        bladeCollectionClone2[bladeBxcnt+clockMiragenum]=0;
    }
    do{
        choiceBlade=rand()%(bladecnt+mainBladecnt);
    }while(bladeCollectionClone2[choiceBlade]==0);
    str1=blade[choiceBlade];
    if(choiceBlade<bladecnt){
        blade_final[0]='\n';
        sprintf(blade_final, "%s", blade[choiceBlade]);
    }
    else{
        do{
            choiceLockChip=rand()%(mlccnt+plccnt);
        }while(lockChipCollectionClone2[choiceLockChip]==0);
        do{
            choiceAssistBlade=rand()%assistBladecnt;
        }while(assistBladeCollectionClone2[choiceAssistBlade]==0);
        blade_final[0]='\n';
        sprintf(blade_final, "%s %s %s", lock_chip[choiceLockChip], blade[choiceBlade], assist_blade[choiceAssistBlade]);
    }
    if(strcmp(blade[choiceBlade],simple_blade[0])==0){
        do{
            choiceRatchet=rand()%simpleRatchetcnt;
        }while(simpleRatchetCollectionClone2[choiceRatchet]==0);
    }
    else{
        do{
            choiceRatchet=rand()%(ratchetcnt+ratchetIntegratedBitcnt);
        }while(ratchetCollectionClone2[choiceRatchet]==0);
    }
    if(choiceRatchet<simpleRatchetcnt||choiceRatchet>=(simpleRatchetcnt+ratchetIntegratedBitcnt)){
        do{
            choiceBit=rand()%bitcnt;
        }while(bitCollectionClone2[choiceBit]==0);
    }
    bladeCollectionClone2[choiceBlade]-=1;
    if(choiceLockChip<mlccnt){
        lockChipCollectionClone2[choiceLockChip]-=1;
    }
    if(choiceBlade>=bladecnt){
        assistBladeCollectionClone2[choiceAssistBlade]-=1;
    }
    ratchetCollectionClone2[choiceRatchet]-=1;
    if(choiceRatchet<simpleRatchetcnt||choiceRatchet>=(simpleRatchetcnt+ratchetIntegratedBitcnt)){
        bitCollectionClone2[choiceBit]-=1;
        if(choiceBlade>=bladecnt){
            combo_list_player_2[numOfDeck][0]='\n';
            sprintf(combo_list_player_2[numOfDeck], "%s%s %s", blade_final, ratchet[choiceRatchet], bit[choiceBit]);
        }
        else{
            combo_list_player_2[numOfDeck][0]='\n';
            sprintf(combo_list_player_2[numOfDeck], "%s %s %s", blade_final, ratchet[choiceRatchet], bit[choiceBit]);
        }
    }
    else{
        if(choiceBlade>=bladecnt){
            combo_list_player_2[numOfDeck][0]='\n';
            sprintf(combo_list_player_2[numOfDeck], "%s%s", blade_final, ratchet[choiceRatchet]);
        }
        else{
            combo_list_player_2[numOfDeck][0]='\n';
            sprintf(combo_list_player_2[numOfDeck], "%s %s", blade_final, ratchet[choiceRatchet]);
        }
    }
    return;
}
void partGetter2(void){
    for(int i=0;i<bladecnt;i++){
        printf("Do you have the blade ");
        printf("%s", blade[i]);
        printf("? Y/N\n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bladeCollection2[i]=1;
            bladeCollectionClone2[i]=1;
        }
        else if(decision=='N'){
            bladeCollection2[i]=0;
            bladeCollectionClone2[i]=0;
        }
    }
    for(int i=bladecnt;i<(bladecnt+mainBladecnt);i++){
        printf("Do you have the main blade ");
        printf("%s", blade[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bladeCollection2[i]=1;
            bladeCollectionClone2[i]=1;
        }
        else if(decision=='N'){
            bladeCollection2[i]=0;
            bladeCollectionClone2[i]=0;
        }
    }
    for(int i=0;i<assistBladecnt;i++){
        printf("Do you have the assist blade ");
        printf("%s", assist_blade[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            assistBladeCollection2[i]=1;
            assistBladeCollectionClone2[i]=1;
        }
        else if(decision=='N'){
            assistBladeCollection2[i]=0;
            assistBladeCollectionClone2[i]=0;
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        str2=ratchet[i];
        printf("Do you have the ratchet ");
        printf("%s", ratchet[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            ratchetCollection2[i]=1;
            ratchetCollectionClone2[i]=1;
            for(int j=0;j<simpleRatchetcnt;j++){
                str3=simple_ratchet[j];
                if(strcmp(str2,str3)==0){
                    simpleRatchetCollection2[j]=1;
                    simpleRatchetCollectionClone2[j]=1;
                }
            }
        }
        else if(decision=='N'){
            ratchetCollection2[i]=0;
            ratchetCollectionClone2[i]=0;
        }
    }
    for(int i=0;i<bitcnt;i++){
        printf("Do you have the bit ");
        printf("%s", bit[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bitCollection2[i]=1;
            bitCollectionClone2[i]=1;
        }
        else if(decision=='N'){
            bitCollection2[i]=0;
            bitCollectionClone2[i]=0;
        }
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        printf("Do you have the lock chip ");
        printf("%s", lock_chip[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            lockChipCollection2[i]=1;
            lockChipCollectionClone2[i]=1;
        }
        else if(decision=='N'){
            lockChipCollection2[i]=0;
            lockChipCollectionClone2[i]=0;
        }
    }
}
void cloneReset(void){
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        bladeCollectionClone1[i]=bladeCollection1[i];
    }
    for(int i=0;i<assistBladecnt;i++){
        assistBladeCollectionClone1[i]=assistBladeCollection1[i];
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        ratchetCollectionClone1[i]=ratchetCollection1[i];
    }
    for(int i=0;i<bitcnt;i++){
        bitCollectionClone1[i]=bitCollection1[i];
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        lockChipCollectionClone1[i]=lockChipCollection1[i];
    }
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        bladeCollectionClone2[i]=bladeCollection2[i];
    }
    for(int i=0;i<assistBladecnt;i++){
        assistBladeCollectionClone2[i]=assistBladeCollection2[i];
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        ratchetCollectionClone2[i]=ratchetCollection2[i];
    }
    for(int i=0;i<bitcnt;i++){
        bitCollectionClone2[i]=bitCollection2[i];
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        lockChipCollectionClone2[i]=lockChipCollection2[i];
    }
    for(int i=0;i<simpleRatchetcnt;i++){
        simpleRatchetCollectionClone1[i]=simpleRatchetCollection1[i];
    }
    for(int i=0;i<simpleRatchetcnt;i++){
        simpleRatchetCollectionClone2[i]=simpleRatchetCollection2[i];
    }
}
void userSelect1(void){
    if(playercnt>1){
        printf("Would you like to select a prerecorded set of parts for Player 1? Y/N\n");
    }
    else{
        printf("Would you like to select a prerecorded set of parts? Y/N\n");
    }
    scanf(" %c", &userDecision);
    while(!(userDecision=='Y'||userDecision=='N')){
        puts("Sorry, that is an invalid response, please reenter");
        printf("Would you like to select a prerecorded set of parts? Y/N\n");
        scanf(" %c", &userDecision);
    }
    if(userDecision=='Y'){
        printf("Which user would you like to load?\n");
        printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4), Yako(5), Ben(6)\n");
        scanf(" %d", &userChoice);
        while(userChoice<1||userChoice>6){
            puts("Sorry, that is an invalid response, please reenter");
            printf("Which user would you like to load?\n");
            printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4), Yako(5), Ben(6)\n");
            scanf(" %d", &userChoice);
        }
        if(userChoice==1){
            userChoiceAlign1(bx);
        }
        if(userChoice==2){
            userChoiceAlign1(ux);
        }
        if(userChoice==3){
            userChoiceAlign1(cx);
        }
        if(userChoice==4){
            userChoiceAlign1(Snek_blades);
        }
        if(userChoice==5){
            userChoiceAlign1(Yako);
        }
        if(userChoice==6){
            userChoiceAlign1(Ben);
        }
    }
    else if(userDecision=='N'){
        partGetter1();
    }
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        avbladecnt+=bladeCollection1[i];
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        avratchetcnt+=ratchetCollection1[i];
    }
    for(int i=0;i<bitcnt;i++){
        avbitcnt+=bitCollection1[i];
    }
}
void partsCheck1(void){
    simpleratchettest=0;
    for(int i=0;i<simpleRatchetcnt;i++){
        if(ratchetCollectionClone1[i]==1){
            simpleratchettest=1;
        }
    }
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        if(bladeCollectionClone1[i]==1){
            bladetest=1;
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        if(ratchetCollectionClone1[i]==1){
            ratchettest=1;

        }
    }
    for(int i=0;i<bitcnt;i++){
        if(bitCollectionClone1[i]==1){
            bittest=1;
        }
    }
    if(bladetest==0||ratchettest==0||bittest==0){
        printf("Sorry, there are not enough remaining parts to generate a combo\n");
        contgen=1;
        return;
    }
    else{
        contgen=0;
    }
}
void userSelect2(void){
    printf("Would you like to select a prerecorded set of parts for Player 2? Y/N\n");
    scanf(" %c", &userDecision);
    while(!(userDecision=='Y'||userDecision=='N')){
        puts("Sorry, that is an invalid response, please reenter");
        printf("Would you like to select a prerecorded set of parts for Player 2? Y/N\n");
        scanf(" %c", &userDecision);
    }
    if(userDecision=='Y'){
        printf("Which user would you like to load?\n");
        printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4), Yako(5), Ben(6)\n");
        scanf(" %d", &userChoice);
        while(userChoice<1||userChoice>6){
            puts("Sorry, that is an invalid response, please reenter");
            printf("Which user would you like to load?\n");
            printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4), Yako(5), Ben(6)\n");
            scanf(" %d", &userChoice);
        }
        if(userChoice==1){
            userChoiceAlign2(bx);
        }
        if(userChoice==2){
            userChoiceAlign2(ux);
        }
        if(userChoice==3){
            userChoiceAlign2(cx);
        }
        if(userChoice==4){
            userChoiceAlign2(Snek_blades);
        }
        if(userChoice==5){
            userChoiceAlign2(Yako);
        }
        if(userChoice==6){
            userChoiceAlign2(Ben);
        }
    }
    else if(userDecision=='N'){
        partGetter2();
    }
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        avbladecnt+=bladeCollection2[i];
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        avratchetcnt+=ratchetCollection2[i];
    }
    for(int i=0;i<bitcnt;i++){
        avbitcnt+=bitCollection2[i];
    }
}
void partsCheck2(void){
    simpleratchettest=0;
    for(int i=0;i<simpleRatchetcnt;i++){
        if(ratchetCollectionClone2[i]==1){
            simpleratchettest=1;
        }
    }
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        if(bladeCollectionClone2[i]==1){
            bladetest=1;
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        if(ratchetCollectionClone2[i]==1){
            ratchettest=1;

        }
    }
    for(int i=0;i<bitcnt;i++){
        if(bitCollectionClone2[i]==1){
            bittest=1;
        }
    }
    if(bladetest==0||ratchettest==0||bittest==0){
        printf("Sorry, there are not enough remaining parts to generate a combo\n");
        contgen=1;
        return;
    }
    else{
        contgen=0;
    }
}
int playerCount(void){
    printf("Would you like to generate decks for 1 or 2 players? ");
    scanf(" %d", &playercnt);
    while(!(playercnt==1||playercnt==2)){
        puts("Sorry, that is an invalid count, please try again");
        printf("Would you like to generate decks for 1 or 2 players? ");
        scanf(" %d", &playercnt);
    }
    return playercnt;
}
void userChoiceAlign1(struct User user_choice){
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        for(int j=0;j<user_choice.blade_cnt;j++){
            if(strcmp(user_choice.blade[j],blade[i])==0){
                bladeCollection1[i]=1;
                bladeCollectionClone1[i]=1;
            }
        }
    }
    for(int i=0;i<(assistBladecnt);i++){
        for(int j=0;j<(user_choice.assist_blade_cnt);j++){
            if(strcmp(user_choice.assist_blade[j],assist_blade[i])==0){
                assistBladeCollection1[i]=1;
                assistBladeCollectionClone1[i]=1;
            }
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        for(int j=0;j<(user_choice.ratchet_cnt);j++){
            if(strcmp(user_choice.ratchet[j],ratchet[i])==0){
                ratchetCollection1[i]=1;
                ratchetCollectionClone1[i]=1;
                for(int k=0;k<simpleRatchetcnt;k++){
                    if(strcmp(ratchet[i],simple_ratchet[k])==0){
                        simpleRatchetCollection1[k]=1;
                        simpleRatchetCollectionClone1[k]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        for(int j=0;j<(user_choice.lock_chip_cnt);j++){
            if(strcmp(user_choice.lock_chip[j],lock_chip[i])==0){
                lockChipCollection1[i]=1;
                lockChipCollectionClone1[i]=1;
            }
        }
    }
    for(int i=0;i<(bitcnt);i++){
        for(int j=0;j<(user_choice.bit_cnt);j++){
            if(strcmp(user_choice.bit[j],bit[i])==0){
                bitCollection1[i]=1;
                bitCollectionClone1[i]=1;
            }
        }
    }
}
void userChoiceAlign2(struct User user_choice){
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        for(int j=0;j<user_choice.blade_cnt;j++){
            if(strcmp(user_choice.blade[j],blade[i])==0){
                bladeCollection2[i]=1;
                bladeCollectionClone2[i]=1;
            }
        }
    }
    for(int i=0;i<(assistBladecnt);i++){
        for(int j=0;j<(user_choice.assist_blade_cnt);j++){
            if(strcmp(user_choice.assist_blade[j],assist_blade[i])==0){
                assistBladeCollection2[i]=1;
                assistBladeCollectionClone2[i]=1;
            }
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        for(int j=0;j<(user_choice.ratchet_cnt);j++){
            if(strcmp(user_choice.ratchet[j],ratchet[i])==0){
                ratchetCollection2[i]=1;
                ratchetCollectionClone2[i]=1;
                for(int k=0;k<simpleRatchetcnt;k++){
                    if(strcmp(ratchet[i],simple_ratchet[k])==0){
                        simpleRatchetCollection2[k]=1;
                        simpleRatchetCollectionClone2[k]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        for(int j=0;j<(user_choice.lock_chip_cnt);j++){
            if(strcmp(user_choice.lock_chip[j],lock_chip[i])==0){
                lockChipCollection2[i]=1;
                lockChipCollectionClone2[i]=1;
            }
        }
    }
    for(int i=0;i<(bitcnt);i++){
        for(int j=0;j<(user_choice.bit_cnt);j++){
            if(strcmp(user_choice.bit[j],bit[i])==0){
                bitCollection2[i]=1;
                bitCollectionClone2[i]=1;
            }
        }
    }
}