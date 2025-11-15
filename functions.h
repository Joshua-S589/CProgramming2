#include <stdlib.h>
#include <time.h>
void dieRoll4(int *die);
void dieRoll6(int *die);
void dieRoll8(int *die);
void dieRoll10(int *die);
void dieRoll12(int *die);
void dieRoll20(int *die);
typedef struct{int hours; int minutes; int seconds;} Time; Time t;
void makeTime(int a);
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
void makeTime(int a){
    t.seconds=a;
    t.minutes=t.seconds/60;
    t.seconds-=t.minutes*60;
    t.hours=t.minutes/60;
    t.minutes-=t.hours*60;
}