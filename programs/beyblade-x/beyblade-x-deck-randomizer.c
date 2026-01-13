#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/parts-list-beyblade-x.h"
int choiceBlade;
int choiceMainBlade;
int choiceRatchet;
int choiceRatchetIntegratedBit;
int choiceBit;
int choiceLockChip;
int choiceAssistBlade;
int nomlc;
int deckSize;
void comboRandomizer(void);
void partGetter(void);
char decision;
void main(void){
    srand(time(0));
    partGetter();
    for(int i=0;i<1000;i++){
        printf("How many combos would you like your deck to contain?\n");
        scanf(" %d", &deckSize);
        for(int i=0;i<deckSize;i++){
            comboRandomizer();
        }
        for(int i=0;i<(bladecnt+mainBladecnt);i++){
            bladeCollectionClone[i]=bladeCollection[i];
        }
        for(int i=0;i<assistBladecnt;i++){
            assistBladeCollectionClone[i]=assistBladeCollection[i];
        }
        // for(int i=0;i<2;i++){
        //     ratchetIntegratedBitCollectionClone[i]=ratchetIntegratedBitCollection[i];
        // }
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
}
void comboRandomizer(void){
    choiceBlade=rand()%(bladecnt+mainBladecnt);
    while(bladeCollectionClone[choiceBlade]==0){
        choiceBlade=rand()%(bladecnt+mainBladecnt);
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
    if(choiceRatchet<ratchetIntegratedBitcnt){
        rand()%2;
    }
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
    bitCollectionClone[choiceBit]-=1;
    puts("");
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