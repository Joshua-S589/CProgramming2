#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/parts-list-beyblade-x.h"
#include "/workspaces/CProgramming2/programs/beyblade-x/user-parts-lists-beyblade-x.h"
void comboRandomizer1(void);
void partGetter1(void);
void comboRandomizer2(void);
void partGetter2(void);
void cloneReset(void);
void userSelect1(void);
void partsCheck1(void);
void userSelect2(void);
void partsCheck2(void);
void playerCnt(void);
int avbitcnt;
int avbladecnt;
int avmainbladecnt;
int avratchetcnt;
int bittest=0;
int bladetest=0;
int choiceAssistBlade;
int choiceBit;
int choiceBlade;
int choiceLockChip;
int choiceMainBlade;
int choiceRatchet;
int choiceRatchetIntegratedBit;
int deckSize=0;
int nocxtest=0;
int nononcxtest=0;
int nomlc;
int playercnt;
int ratchettest=0;
int userChoice;
char decision;
char userDecision;
void main(void){
    srand(time(0));
    playerCnt();
    userSelect1();
    if(playercnt==2){
        userSelect2();
    }
    if(playercnt==1){
        for(int a=0;a<1000;a++){
            printf("How many combos would you like your deck to contain?\n");
            scanf(" %d", &deckSize);
            for(int b=0;b<deckSize;b++){
                comboRandomizer1();
            }
            cloneReset();
            deckSize=0;
        }
    }
    if(playercnt==2){
        for(int a=0;a<1000;a++){
            printf("How many combos would you like your decks to contain?\n");
            scanf(" %d", &deckSize);
            puts("Player 1 deck:");
            for(int b=0;b<deckSize;b++){
                comboRandomizer1();
            }
            puts("");
            puts("Player 2 deck:");
            for(int b=0;b<deckSize;b++){
                comboRandomizer2();
            }
            puts("");
            cloneReset();
            deckSize=0;
        }
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
    choiceBlade=rand()%(bladecnt+mainBladecnt);
    while(bladeCollectionClone1[choiceBlade]==0){
        choiceBlade=rand()%(bladecnt+mainBladecnt);
    }
    if(choiceBlade<bladecnt){
        printf("%s", blade[choiceBlade]);
        printf(" ");
    }
    else{
        choiceLockChip=rand()%(mlccnt+plccnt);
        while(lockChipCollectionClone1[choiceLockChip]==0){
            choiceLockChip=rand()%(mlccnt+plccnt);
        }
        printf("%s", lock_chip[choiceLockChip]);
        printf(" ");
        printf("%s", blade[choiceBlade]);
        printf(" ");
        choiceAssistBlade=rand()%assistBladecnt;
        while(assistBladeCollectionClone1[choiceAssistBlade]==0){
            choiceAssistBlade=rand()%assistBladecnt;
        }
        printf("%s", assist_blade[choiceAssistBlade]);
    }
    choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    while(ratchetCollectionClone1[choiceRatchet]==0){
        choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    }
    printf("%s", ratchet[choiceRatchet]);
    printf(" ");
    if(choiceRatchet<ratchetIntegratedBitcnt){}
    else{
        choiceBit=rand()%bitcnt;
        while(bitCollectionClone1[choiceBit]==0){
            choiceBit=rand()%bitcnt;
        }
        printf("%s", bit[choiceBit]);
    }
    bladeCollectionClone1[choiceBlade]-=1;
    if(choiceLockChip<mlccnt){
        lockChipCollectionClone1[choiceLockChip]-=1;
    }
    assistBladeCollectionClone1[choiceAssistBlade]-=1;
    ratchetCollectionClone1[choiceRatchet]-=1;
    if(choiceRatchet>=ratchetIntegratedBitcnt){
        bitCollectionClone1[choiceBit]-=1;
    }
    puts("");
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
        printf("Do you have the ratchet ");
        printf("%s", ratchet[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            ratchetCollection1[i]=1;
            ratchetCollectionClone1[i]=1;
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
    choiceBlade=rand()%(bladecnt+mainBladecnt);
    while(bladeCollectionClone2[choiceBlade]==0){
        choiceBlade=rand()%(bladecnt+mainBladecnt);
    }
    if(choiceBlade<bladecnt){
        printf("%s", blade[choiceBlade]);
        printf(" ");
    }
    else{
        choiceLockChip=rand()%(mlccnt+plccnt);
        while(lockChipCollectionClone2[choiceLockChip]==0){
            choiceLockChip=rand()%(mlccnt+plccnt);
        }
        printf("%s", lock_chip[choiceLockChip]);
        printf(" ");
        printf("%s", blade[choiceBlade]);
        printf(" ");
        choiceAssistBlade=rand()%assistBladecnt;
        while(assistBladeCollectionClone2[choiceAssistBlade]==0){
            choiceAssistBlade=rand()%assistBladecnt;
        }
        printf("%s", assist_blade[choiceAssistBlade]);
    }
    choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    while(ratchetCollectionClone2[choiceRatchet]==0){
        choiceRatchet=rand()%(ratchetIntegratedBitcnt+ratchetcnt);
    }
    printf("%s", ratchet[choiceRatchet]);
    printf(" ");
    if(choiceRatchet<ratchetIntegratedBitcnt){}
    else{
        choiceBit=rand()%bitcnt;
        while(bitCollectionClone2[choiceBit]==0){
            choiceBit=rand()%bitcnt;
        }
        printf("%s", bit[choiceBit]);
    }
    bladeCollectionClone2[choiceBlade]-=1;
    if(choiceLockChip<mlccnt){
        lockChipCollectionClone2[choiceLockChip]-=1;
    }
    assistBladeCollectionClone2[choiceAssistBlade]-=1;
    ratchetCollectionClone2[choiceRatchet]-=1;
    if(choiceRatchet>=ratchetIntegratedBitcnt){
        bitCollectionClone2[choiceBit]-=1;
    }
    puts("");
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
        printf("Do you have the ratchet ");
        printf("%s", ratchet[i]);
        printf("? Y/N \n");
        scanf(" %c", &decision);
        if(decision=='Y'){
            ratchetCollection2[i]=1;
            ratchetCollectionClone2[i]=1;
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
}
void userSelect1(void){
    printf("Would you like to select a prerecorded set of parts? Y/N\n");
    scanf(" %c", &userDecision);
    if(userDecision=='Y'){
        printf("Which user would you like to load?\n");
        printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4), Yako(5)\n");
        scanf(" %d", &userChoice);
        if(userChoice==1){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_bx_bladecnt;j++){
                    if(!strcmp(user_blade_bx[j],blade[i])){
                        bladeCollection1[i]=1;
                        bladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_bx_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_bx[j],assist_blade[i])){
                        assistBladeCollection1[i]=1;
                        assistBladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_bx_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_bx[j],ratchet[i])){
                        ratchetCollection1[i]=1;
                        ratchetCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_bx_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_bx[j],lock_chip[i])){
                        lockChipCollection1[i]=1;
                        lockChipCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_bx_bitcnt);j++){
                    if(!strcmp(user_bit_bx[j],bit[i])){
                        bitCollection1[i]=1;
                        bitCollectionClone1[i]=1;
                    }
                }
            }
        }
        if(userChoice==2){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_ux_bladecnt;j++){
                    if(!strcmp(user_blade_ux[j],blade[i])){
                        bladeCollection1[i]=1;
                        bladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_ux_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_ux[j],assist_blade[i])){
                        assistBladeCollection1[i]=1;
                        assistBladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_ux_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_ux[j],ratchet[i])){
                        ratchetCollection1[i]=1;
                        ratchetCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_ux_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_ux[j],lock_chip[i])){
                        lockChipCollection1[i]=1;
                        lockChipCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_ux_bitcnt);j++){
                    if(!strcmp(user_bit_ux[j],bit[i])){
                        bitCollection1[i]=1;
                        bitCollectionClone1[i]=1;
                    }
                }
            }
        }
        if(userChoice==3){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_cx_bladecnt;j++){
                    if(!strcmp(user_blade_cx[j],blade[i])){
                        bladeCollection1[i]=1;
                        bladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_cx_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_cx[j],assist_blade[i])){
                        assistBladeCollection1[i]=1;
                        assistBladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_cx_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_cx[j],ratchet[i])){
                        ratchetCollection1[i]=1;
                        ratchetCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_cx_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_cx[j],lock_chip[i])){
                        lockChipCollection1[i]=1;
                        lockChipCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_cx_bitcnt);j++){
                    if(!strcmp(user_bit_cx[j],bit[i])){
                        bitCollection1[i]=1;
                        bitCollectionClone1[i]=1;
                    }
                }
            }
        }
        if(userChoice==4){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_Snek_Blades_bladecnt;j++){
                    if(!strcmp(user_blade_Snek_Blades[j],blade[i])){
                        bladeCollection1[i]=1;
                        bladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_Snek_Blades_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_Snek_Blades[j],assist_blade[i])){
                        assistBladeCollection1[i]=1;
                        assistBladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_Snek_Blades_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_Snek_Blades[j],ratchet[i])){
                        ratchetCollection1[i]=1;
                        ratchetCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_Snek_Blades_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_Snek_Blades[j],lock_chip[i])){
                        lockChipCollection1[i]=1;
                        lockChipCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_Snek_Blades_bitcnt);j++){
                    if(!strcmp(user_bit_Snek_Blades[j],bit[i])){
                        bitCollection1[i]=1;
                        bitCollectionClone1[i]=1;
                    }
                }
            }
        }
        if(userChoice==5){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_Yako_bladecnt;j++){
                    if(!strcmp(user_blade_Yako[j],blade[i])){
                        bladeCollection1[i]=1;
                        bladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_Yako_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_Yako[j],assist_blade[i])){
                        assistBladeCollection1[i]=1;
                        assistBladeCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_Yako_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_Yako[j],ratchet[i])){
                        ratchetCollection1[i]=1;
                        ratchetCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_Yako_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_Yako[j],lock_chip[i])){
                        lockChipCollection1[i]=1;
                        lockChipCollectionClone1[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_Yako_bitcnt);j++){
                    if(!strcmp(user_bit_Yako[j],bit[i])){
                        bitCollection1[i]=1;
                        bitCollectionClone1[i]=1;
                    }
                }
            }
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
        return;
    }
}
void userSelect2(void){
    printf("Would you like to select a prerecorded set of parts for Player 2? Y/N\n");
    scanf(" %c", &userDecision);
    if(userDecision=='Y'){
        printf("Which user would you like to load?\n");
        printf("BX parts (1), UX parts (2), CX parts(3), Snek Blades(4), Yako(5)\n");
        scanf(" %d", &userChoice);
        if(userChoice==1){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_bx_bladecnt;j++){
                    if(!strcmp(user_blade_bx[j],blade[i])){
                        bladeCollection2[i]=1;
                        bladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_bx_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_bx[j],assist_blade[i])){
                        assistBladeCollection2[i]=1;
                        assistBladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_bx_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_bx[j],ratchet[i])){
                        ratchetCollection2[i]=1;
                        ratchetCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_bx_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_bx[j],lock_chip[i])){
                        lockChipCollection2[i]=1;
                        lockChipCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_bx_bitcnt);j++){
                    if(!strcmp(user_bit_bx[j],bit[i])){
                        bitCollection2[i]=1;
                        bitCollectionClone2[i]=1;
                    }
                }
            }
        }
        if(userChoice==2){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_ux_bladecnt;j++){
                    if(!strcmp(user_blade_ux[j],blade[i])){
                        bladeCollection2[i]=1;
                        bladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_ux_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_ux[j],assist_blade[i])){
                        assistBladeCollection2[i]=1;
                        assistBladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_ux_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_ux[j],ratchet[i])){
                        ratchetCollection2[i]=1;
                        ratchetCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_ux_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_ux[j],lock_chip[i])){
                        lockChipCollection2[i]=1;
                        lockChipCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_ux_bitcnt);j++){
                    if(!strcmp(user_bit_ux[j],bit[i])){
                        bitCollection2[i]=1;
                        bitCollectionClone2[i]=1;
                    }
                }
            }
        }
        if(userChoice==3){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_cx_bladecnt;j++){
                    if(!strcmp(user_blade_cx[j],blade[i])){
                        bladeCollection2[i]=1;
                        bladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_cx_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_cx[j],assist_blade[i])){
                        assistBladeCollection2[i]=1;
                        assistBladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_cx_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_cx[j],ratchet[i])){
                        ratchetCollection2[i]=1;
                        ratchetCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_cx_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_cx[j],lock_chip[i])){
                        lockChipCollection2[i]=1;
                        lockChipCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_cx_bitcnt);j++){
                    if(!strcmp(user_bit_cx[j],bit[i])){
                        bitCollection2[i]=1;
                        bitCollectionClone2[i]=1;
                    }
                }
            }
        }
        if(userChoice==4){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_Snek_Blades_bladecnt;j++){
                    if(!strcmp(user_blade_Snek_Blades[j],blade[i])){
                        bladeCollection2[i]=1;
                        bladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_Snek_Blades_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_Snek_Blades[j],assist_blade[i])){
                        assistBladeCollection2[i]=1;
                        assistBladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_Snek_Blades_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_Snek_Blades[j],ratchet[i])){
                        ratchetCollection2[i]=1;
                        ratchetCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_Snek_Blades_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_Snek_Blades[j],lock_chip[i])){
                        lockChipCollection2[i]=1;
                        lockChipCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_Snek_Blades_bitcnt);j++){
                    if(!strcmp(user_bit_Snek_Blades[j],bit[i])){
                        bitCollection2[i]=1;
                        bitCollectionClone2[i]=1;
                    }
                }
            }
        }
        if(userChoice==5){
            for(int i=0;i<(bladecnt+mainBladecnt);i++){
                for(int j=0;j<user_Yako_bladecnt;j++){
                    if(!strcmp(user_blade_Yako[j],blade[i])){
                        bladeCollection2[i]=1;
                        bladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(assistBladecnt);i++){
                for(int j=0;j<(user_Yako_assistbladecnt);j++){
                    if(!strcmp(user_assist_blade_Yako[j],assist_blade[i])){
                        assistBladeCollection2[i]=1;
                        assistBladeCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(ratchetIntegratedBitcnt+ratchetcnt);i++){
                for(int j=0;j<(user_Yako_ratchetcnt);j++){
                    if(!strcmp(user_ratchet_Yako[j],ratchet[i])){
                        ratchetCollection2[i]=1;
                        ratchetCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(mlccnt+plccnt);i++){
                for(int j=0;j<(user_Yako_lockchipcnt);j++){
                    if(!strcmp(user_lock_chip_Yako[j],lock_chip[i])){
                        lockChipCollection2[i]=1;
                        lockChipCollectionClone2[i]=1;
                    }
                }
            }
            for(int i=0;i<(bitcnt);i++){
                for(int j=0;j<(user_Yako_bitcnt);j++){
                    if(!strcmp(user_bit_Yako[j],bit[i])){
                        bitCollection2[i]=1;
                        bitCollectionClone2[i]=1;
                    }
                }
            }
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
        return;
    }
}
void playerCnt(void){
    printf("Would you like to generate decks for 1 or 2 players? ");
    scanf(" %d", &playercnt);
    while(!(playercnt==1||playercnt==2)){
        puts("Sorry, that is an invalid count, please try again");
        printf("Would you like to generate decks for 1 or 2 players? ");
        scanf(" %d", &playercnt);
    }

}