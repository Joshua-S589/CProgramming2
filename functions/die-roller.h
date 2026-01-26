#include <stdlib.h>
#include <time.h>
void dieRollN(int *die, int a);
void dieRoll4(int *die);
void dieRoll6(int *die);
void dieRoll8(int *die);
void dieRoll10(int *die);
void dieRoll12(int *die);
void dieRoll20(int *die);
void dieRoll4(int *die){
    *die=(rand()%4)+1;
}
void dieRoll6(int *die){
    *die=(rand()%6)+1;
}
void dieRoll8(int *die){
    *die=(rand()%8)+1;
}
void dieRoll10(int *die){
    *die=(rand()%10)+1;
}
void dieRoll12(int *die){
    *die=(rand()%12)+1;
}
void dieRoll20(int *die){
    *die=(rand()%20)+1;
}
void dieRollN(int *die, int a){
    *die=(rand()%a)+1;
}