#include <stdio.h>
#include <string.h>
#include "/workspaces/CProgramming2/programs/beyblade-x/parts-list-beyblade-x.h"
const char* str1;
const char* str2;
void main(void){
    str1=blade[bladeBxcnt+2];
    str2="Clock Mirage";
    printf("%d\n", strcmp(str1,str2));
    printf("%s\n%s\n", str1, str2);
}