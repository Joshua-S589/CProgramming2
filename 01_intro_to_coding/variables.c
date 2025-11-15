#include <stdio.h>

int main(void){
    // create a variable
    int first_number;
    // assign a value
    first_number = 5;
    // creat and initialize
    int second_number = 78;
    // print the value
    printf("The first number is %d\n", first_number);
    printf("The second number is %d\n", second_number);
    // calculate the sum
    int sum = first_number + second_number;
    printf("%d + %d = %d\n", first_number, second_number, sum);
    return 0;
}