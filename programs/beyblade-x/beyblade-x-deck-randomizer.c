#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/parts-list-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/user-parts-lists-beyblade-x.h"
void comboRandomizer(void);
void partGetter(void);
void cloneReset(void);
void userSelect(void);
int choiceBlade;
int choiceMainBlade;
int choiceRatchet;
int choiceRatchetIntegratedBit;
int choiceBit;
int choiceLockChip;
int choiceAssistBlade;
int nomlc;
int deckSize;
int userChoice;
int testFlag=0;
int testFlagRef=0;
int nocxtest=0;
int nononcxtest=0;
int bladetest=0;
int ratchettest=0;
int bittest=0;
char decision;
char userDecision;
void main(void){
    srand(time(0));
    userSelect();
    for(int a=0;a<1000;a++){
        printf("How many combos would you like your deck to contain?\n");
        scanf(" %d", &deckSize);
        for(int b=0;b<deckSize;b++){
            comboRandomizer();
        }
        cloneReset();
    }
}
void comboRandomizer(void){
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
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        if(bladeCollectionClone[i]==1){
            bladetest=1;
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        if(ratchetCollectionClone[i]==1){
            ratchettest=1;
        }
    }
    for(int i=0;i<bitcnt;i++){
        if(bitCollectionClone[i]==1){
            bittest=1;
        }
    }
    if(bladetest==0||ratchettest==0||bittest==0){
        printf("Sorry, there are not enough remaining parts to generate a combo\n");
        return;
    }
    for(int i=bladecnt;i<(bladecnt+mainBladecnt);i++){
        if(bladeCollectionClone[i]==1){
            nononcxtest=1;
        }
    }
    for(int i=0;i<bladecnt;i++){
        if(bladeCollectionClone[i]==1){
            nocxtest=1;
        }
    }
    if(nocxtest==0){
        choiceBlade=rand()%bladecnt;
        while(bladeCollectionClone[choiceBlade]==0){
            choiceBlade=rand()%bladecnt;
        }
    }
    else if(nononcxtest==0){
        choiceBlade=(rand()%mainBladecnt)+bladecnt;
        while(bladeCollectionClone[choiceBlade]==0){
            choiceBlade=(rand()%mainBladecnt)+bladecnt;
        }
    }
    else{
        choiceBlade=rand()%(bladecnt+mainBladecnt);
        while(bladeCollectionClone[choiceBlade]==0){
            choiceBlade=rand()%(bladecnt+mainBladecnt);
        }
    }
    if(choiceBlade<bladecnt){
        for(int i=0;i<50;i++){
            printf("%c", blade[choiceBlade][i]);
        }
        printf(" ");
    }
    else{
        choiceLockChip=rand()%(mlccnt+plccnt);
        while(lockChipCollectionClone[choiceLockChip]==0){
            choiceLockChip=rand()%(mlccnt+plccnt);
        }
        for(int i=0;i<50;i++){
            printf("%c", lock_chip[choiceLockChip][i]);
        }
        printf(" ");
        for(int i=0;i<50;i++){
            printf("%c", blade[choiceBlade][i]);
        }
        printf(" ");
        choiceAssistBlade=rand()%assistBladecnt;
        while(assistBladeCollectionClone[choiceAssistBlade]==0){
            choiceAssistBlade=rand()%assistBladecnt;
        }
        for(int i=0;i<50;i++){
            printf("%c", assist_blade[choiceAssistBlade][i]);
        }
    }
    choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    while(ratchetCollectionClone[choiceRatchet]==0){
        choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    }
    for(int i=0;i<50;i++){
        printf("%c", ratchet[choiceRatchet][i]);
    }
    printf(" ");
    if(choiceRatchet<ratchetIntegratedBitcnt){}
    else{
        choiceBit=rand()%bitcnt;
        while(bitCollectionClone[choiceBit]==0){
            choiceBit=rand()%bitcnt;
        }
        for(int i=0;i<50;i++){
            printf("%c", bit[choiceBit][i]);
        }
    }
    bladeCollectionClone[choiceBlade]-=1;
    if(choiceLockChip<mlccnt){
        lockChipCollectionClone[choiceLockChip]-=1;
    }
    assistBladeCollectionClone[choiceAssistBlade]-=1;
    ratchetCollectionClone[choiceRatchet]-=1;
    if(choiceRatchet>=ratchetIntegratedBitcnt){
        bitCollectionClone[choiceBit]-=1;
    }
    puts("");
    return;
}
void partGetter(void){
    for(int i=0;i<bladecnt;i++){
        printf("Do you have the blade ");
        for(int j=0;j<50;j++){
            printf("%c", blade[i][j]);
        }
        printf("? Y/N\n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bladeCollection[i]=1;
            bladeCollectionClone[i]=1;
        }
        else if(decision=='N'){
            bladeCollection[i]=0;
            bladeCollectionClone[i]=0;
        }
    }
    for(int i=bladecnt;i<(bladecnt+mainBladecnt);i++){
        printf("Do you have the main blade ");
        for(int j=0;j<50;j++){
            printf("%c", blade[i][j]);
        }
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bladeCollection[i]=1;
            bladeCollectionClone[i]=1;
        }
        else if(decision=='N'){
            bladeCollection[i]=0;
            bladeCollectionClone[i]=0;
        }
    }
    for(int i=0;i<assistBladecnt;i++){
        printf("Do you have the assist blade ");
        for(int j=0;j<50;j++){
            printf("%c", assist_blade[i][j]);
        }
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            assistBladeCollection[i]=1;
            assistBladeCollectionClone[i]=1;
        }
        else if(decision=='N'){
            assistBladeCollection[i]=0;
            assistBladeCollectionClone[i]=0;
        }
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        printf("Do you have the ratchet ");
        for(int j=0;j<50;j++){
            printf("%c", ratchet[i][j]);
        }
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            ratchetCollection[i]=1;
            ratchetCollectionClone[i]=1;
        }
        else if(decision=='N'){
            ratchetCollection[i]=0;
            ratchetCollectionClone[i]=0;
        }
    }
    for(int i=0;i<bitcnt;i++){
        printf("Do you have the bit ");
        for(int j=0;j<50;j++){
            printf("%c", bit[i][j]);
        }
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            bitCollection[i]=1;
            bitCollectionClone[i]=1;
        }
        else if(decision=='N'){
            bitCollection[i]=0;
            bitCollectionClone[i]=0;
        }
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        printf("Do you have the lock chip ");
        for(int j=0;j<50;j++){
            printf("%c", lock_chip[i][j]);
        }
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            lockChipCollection[i]=1;
            lockChipCollectionClone[i]=1;
        }
        else if(decision=='N'){
            lockChipCollection[i]=0;
            lockChipCollectionClone[i]=0;
        }
    }
}
void cloneReset(void){
    for(int i=0;i<(bladecnt+mainBladecnt);i++){
        bladeCollectionClone[i]=bladeCollection[i];
    }
    for(int i=0;i<assistBladecnt;i++){
        assistBladeCollectionClone[i]=assistBladeCollection[i];
    }
    for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
        ratchetCollectionClone[i]=ratchetCollection[i];
    }
    for(int i=0;i<bitcnt;i++){
        bitCollectionClone[i]=bitCollection[i];
    }
    for(int i=0;i<(mlccnt+plccnt);i++){
        lockChipCollectionClone[i]=lockChipCollection[i];
    }
}
void userSelect(void){
    printf("Would you like to select a prerecorded set of parts? Y/N\n");
    scanf(" %c", &userDecision);
    if(userDecision=='Y'){
        printf("Which user would you like to load?\n");
        printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4)\n");
        scanf(" %d", &userChoice);
        if(userChoice=1){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<(user_bx_bladecnt);j++){
                    for(int k=0;k<50;k++){
                        if(user_blade_bx[j][k]==blade[i][k]){
                            testFlagRef+=1;
                        }
                        testFlag+=1;
                    }
                    if(testFlagRef==testFlag){
                        bladeCollection[i]=1;
                        bladeCollectionClone[i]=1;
                    }
                    testFlag=0;
                    testFlagRef=0;
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_bx_assistbladecnt);j++){
                    for(int k=0;k<50;k++){
                        if(user_assist_blade_bx[j][k]==assist_blade[i][k]){
                            testFlagRef+=1;
                        }
                        testFlag+=1;
                    }
                    if(testFlagRef==testFlag){
                        assistBladeCollection[i]=1;
                        assistBladeCollectionClone[i]=1;
                    }
                    testFlag=0;
                    testFlagRef=0;
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_bx_ratchetcnt);j++){
                    for(int k=0;k<50;k++){
                        if(user_ratchet_bx[j][k]==ratchet[i][k]){
                            testFlagRef+=1;
                        }
                        testFlag+=1;
                    }
                    if(testFlagRef==testFlag){
                        ratchetCollection[i]=1;
                        ratchetCollectionClone[i]=1;
                    }
                    testFlag=0;
                    testFlagRef=0;
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_bx_lockchipcnt);j++){
                    for(int k=0;k<50;k++){
                        if(user_lock_chip_bx[j][k]==lock_chip[i][k]){
                            testFlagRef+=1;
                        }
                        testFlag+=1;
                    }
                    if(testFlagRef==testFlag){
                        lockChipCollection[i]=1;
                        lockChipCollectionClone[i]=1;
                    }
                    testFlag=0;
                    testFlagRef=0;
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_bx_bitcnt);j++){
                    for(int k=0;k<50;k++){
                        if(user_bit_bx[j][k]==bit[i][k]){
                            testFlagRef+=1;
                        }
                        testFlag+=1;
                    }
                    if(testFlagRef==testFlag){
                        bitCollection[i]=1;
                        bitCollectionClone[i]=1;
                    }
                    testFlag=0;
                    testFlagRef=0;
                }
            }
        }
    }
    else if(userDecision=='N'){
        partGetter();
    }
}