#include <stdlib.h>
#include <time.h>
typedef struct{int hours; int minutes; int seconds;} Time; Time t;
void makeTime(int a);
void makeTime(int a){
    t.seconds=a;
    t.minutes=t.seconds/60;
    t.seconds-=t.minutes*60;
    t.hours=t.minutes/60;
    t.minutes-=t.hours*60;
}