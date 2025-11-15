// Collatz Conjecture
#include <stdio.h>
#include <unistd.h>
int even(void);
int odd(void);
int stepCounter(void);
int collatzSequence(void);
int collatzFind(void);
int collatzRange(void);
int collatz;
int steps=0;
int pauseDuration=0;
int numTestMax=0;
int numTestMin=0;
int stepTest=0;
int stepTestMin=0;
int stepTestMax=0;
int i=1;
int stepSuccess=0;
int testType;
int main(void){
    printf("\n\nWelcome to the Collatz Sequence!\n");
    printf("This program will allow you to see the results of running this sequnce on various numbers.\n");
    printf("You may be wondering; what is the Collatz sequence?\n");
    printf("The Collatz sequence is a mathematical formula where from a starting positive integer, if ever it is even divide the number by 2, and if odd multiply by 3 and add 1.\n");
    printf("The sequence also states that every positive integer will enter the 4-2-1 loop endlessly, though it can only be disproven.\n");
    printf("Since its creation in 1937, over 1 duovigintillion, or 10^69, numbers have been tested all of which have been seen tp enter this loop.\n\n");
    printf("If you choose to test a single number, you will get a readout of each step taken until 1 is reached, with the amount of steps taken.\n");
    printf("If you choose 2, you select a range of numbers from 1 and a target step number and you will see how many and which numbers take that many steps on that range.\n");
    printf("If you choose 3, you select a range of numbers and of target steps, and you will see how many numbers on that range take a number of steps within the specified range to reach 1\n\n");
    puts("Would you like to test a single number (1), or test for numbers that fulfill specified steps taken (2), or for a range of numbers that fulfills a range of steps (3)?");
    scanf("%d", &testType);
    printf("\n\n");
    if(testType==1){
        collatzSequence();
    }
    else if(testType==2){
        collatzFind();
    }
    else if(testType==3){
        collatzRange();
    }
}
int collatzSequence(void){
    puts("How many microseconds would you like to pause at each step for?");
    scanf("%d", &pauseDuration);
    puts("Enter the starting number:");
    scanf("%d", &collatz);
    while(!(collatz<=1)){
        if(collatz%2==0){
            even();
        }
        else if(!(collatz%2==0)){
            odd();
        }
    }
    stepCounter();
}
int collatzFind(void){
    puts("Up to what number do you want to test the amount of steps taken? It is recomended to do a high number, as otherwise not much will be done.");
    scanf("%d", &numTestMax);
    printf("What is the amount of steps taken you want to find out on this range of 1-%d?\n", numTestMax);
    scanf("%d", &stepTest);
    printf("\nHere are the numbers from 1-%d that take %d many steps to reach a loop:\n\n", numTestMax, stepTest);
    while(i<=numTestMax){
        int collatz=i;
        while(!(collatz<=1)){
            if(collatz%2==0){
                collatz=collatz/2;
                steps++;
            }
            else if(!(collatz%2==0)){
                collatz=(collatz*3)+1;
                steps++;
            }
        }
        if(steps==stepTest){
            printf("%d, ", i);
            stepSuccess++;
        }
        steps=0;
        i++;
    }
    printf("There are %d starting numbers that take %d steps to reach a loop\n", stepSuccess, stepTest);
}
int collatzRange(void){
    puts("What is the minimum number you'd like to test from? It is recomended to do a wide range, as otherwise not much will be done.");
    scanf("%d", &numTestMin);
    i=numTestMin;
    puts("The maximum?");
    scanf("%d", &numTestMax);
    puts("What is the minimum on the range of steps to test?");
    scanf("%d", &stepTestMin);
    puts("The maximum?");
    scanf("%d", &stepTestMax);
    printf("\nHere are the amount of numbers from %d-%d that take %d-%d steps to reach a loop:\n\n", numTestMin, numTestMax, stepTestMin, stepTestMax);
    while(i<=numTestMax){
        int collatz=i;
        while(!(collatz<=1)){
            if(collatz%2==0){
                collatz=collatz/2;
                steps++;
            }
            else if(!(collatz%2==0)){
                collatz=(collatz*3)+1;
                steps++;
            }
        }
        if(steps>=stepTestMin&&steps<=stepTestMax){
            stepSuccess++;
        }
        steps=0;
        i++;
    }
    printf("There are %d starting numbers on the range of %d-%d that take %d-%d steps to reach a loop\n", stepSuccess, numTestMin, numTestMax, stepTestMin, stepTestMax);
}
int even(void){
    collatz=collatz/2;
    printf("%d\n", collatz);
    steps=steps+1;
    usleep(pauseDuration);
    return collatz;
}
int odd(void){
    collatz=(collatz*3)+1;
    printf("%d\n", collatz);
    steps=steps+1;
    usleep(pauseDuration);
    return collatz;
}
int stepCounter(void){
    printf("It took %d steps for you to reach a loop.\n", steps);
}