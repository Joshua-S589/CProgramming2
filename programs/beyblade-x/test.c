#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/parts-list-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/user-parts-lists-beyblade-x.h"
void comboRandomizer(void);
void partGetter(void);
void cloneReset(void);
void userSelect(void);
void partsCheck(void);
int choiceBlade;
int choiceMainBlade;
int choiceRatchet;
int choiceRatchetIntegratedBit;
int choiceBit;
int choiceLockChip;
int choiceAssistBlade;
int nomlc;
int deckSize=0;
int userChoice;
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
    for(int i=0;i<(plccnt+mlccnt);i++){
        printf("%d", lockChipCollection[i]);
    }
    for(int a=0;a<1000;a++){
        printf("How many combos would you like your deck to contain?\n");
        scanf(" %d", &deckSize);
        for(int b=0;b<deckSize;b++){
            comboRandomizer();
        }
        cloneReset();
        deckSize=0;
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
    partsCheck();
    choiceBlade=rand()%(bladecnt+mainBladecnt);
    while(bladeCollectionClone[choiceBlade]==0){
        choiceBlade=rand()%(bladecnt+mainBladecnt);
    }
    if(choiceBlade<bladecnt){
        printf("%s", blade[choiceBlade]);
        printf(" ");
    }
    else{
        choiceLockChip=rand()%(mlccnt+plccnt);
        while(lockChipCollectionClone[choiceLockChip]==0){
            choiceLockChip=rand()%(mlccnt+plccnt);
        }
        printf("%s", lock_chip[choiceLockChip]);
        printf(" ");
        printf("%s", blade[choiceBlade]);
        printf(" ");
        choiceAssistBlade=rand()%assistBladecnt;
        while(assistBladeCollectionClone[choiceAssistBlade]==0){
            choiceAssistBlade=rand()%assistBladecnt;
        }
        printf("%s", assist_blade[choiceAssistBlade]);
    }
    choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    while(ratchetCollectionClone[choiceRatchet]==0){
        choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    }
    printf("%s", ratchet[choiceRatchet]);
    printf(" ");
    if(choiceRatchet<ratchetIntegratedBitcnt){}
    else{
        choiceBit=rand()%bitcnt;
        while(bitCollectionClone[choiceBit]==0){
            choiceBit=rand()%bitcnt;
        }
        printf("%s", bit[choiceBit]);
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
        printf("%s", blade[i]);
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
        printf("%s", blade[i]);
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
        printf("%s", assist_blade[i]);
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
        printf("%s", ratchet[i]);
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
        printf("%s", bit[i]);
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
        printf("%s", lock_chip[i]);
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
        if(userChoice==1){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_bx_bladecnt;j++){
                    if(!strcmp(user_blade_bx[j],blade[i])){
                        bladeCollection[i]=1;
                        bladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_bx_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_bx[j],assist_blade[i])){
                        assistBladeCollection[i]=1;
                        assistBladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_bx_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_bx[j],ratchet[i])){
                        ratchetCollection[i]=1;
                        ratchetCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_bx_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_bx[j],lock_chip[i])){
                        lockChipCollection[i]=1;
                        lockChipCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_bx_bitcnt);j++){
                    if(!strcmp(user_bit_bx[j],bit[i])){
                        bitCollection[i]=1;
                        bitCollectionClone[i]=1;
                    }
                }
            }
        }
        if(userChoice==2){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_ux_bladecnt;j++){
                    if(!strcmp(user_blade_ux[j],blade[i])){
                        bladeCollection[i]=1;
                        bladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_ux_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_ux[j],assist_blade[i])){
                        assistBladeCollection[i]=1;
                        assistBladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_ux_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_ux[j],ratchet[i])){
                        ratchetCollection[i]=1;
                        ratchetCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_ux_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_ux[j],lock_chip[i])){
                        lockChipCollection[i]=1;
                        lockChipCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_ux_bitcnt);j++){
                    if(!strcmp(user_bit_ux[j],bit[i])){
                        bitCollection[i]=1;
                        bitCollectionClone[i]=1;
                    }
                }
            }
        }
        if(userChoice==3){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_cx_bladecnt;j++){
                    if(!strcmp(user_blade_cx[j],blade[i])){
                        bladeCollection[i]=1;
                        bladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_cx_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_cx[j],assist_blade[i])){
                        assistBladeCollection[i]=1;
                        assistBladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_cx_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_cx[j],ratchet[i])){
                        ratchetCollection[i]=1;
                        ratchetCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_cx_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_cx[j],lock_chip[i])){
                        lockChipCollection[i]=1;
                        lockChipCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_cx_bitcnt);j++){
                    if(!strcmp(user_bit_cx[j],bit[i])){
                        bitCollection[i]=1;
                        bitCollectionClone[i]=1;
                    }
                }
            }
        }
        if(userChoice==4){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_Snek_Blades_bladecnt;j++){
                    if(!strcmp(user_blade_Snek_Blades[j],blade[i])){
                        bladeCollection[i]=1;
                        bladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_Snek_Blades_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_Snek_Blades[j],assist_blade[i])){
                        assistBladeCollection[i]=1;
                        assistBladeCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_Snek_Blades_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_Snek_Blades[j],ratchet[i])){
                        ratchetCollection[i]=1;
                        ratchetCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_Snek_Blades_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_Snek_Blades[j],lock_chip[i])){
                        lockChipCollection[i]=1;
                        lockChipCollectionClone[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_Snek_Blades_bitcnt);j++){
                    if(!strcmp(user_bit_Snek_Blades[j],bit[i])){
                        bitCollection[i]=1;
                        bitCollectionClone[i]=1;
                    }
                }
            }
        }
    }
    else if(userDecision=='N'){
        partGetter();
    }
}
void partsCheck(void){
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
}