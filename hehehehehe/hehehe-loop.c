#include <stdio.h>
#include <unistd.h>
void hehehe(int a);
void main(void){
    hehehe(1);
    return;
}
void hehehe(int a){
    printf("%d", a);
    usleep(a);
    hehehe(a+1);
}