/*

    Progra calculates the roots of quadratic equation.

    ax^2 + bx + c = 0

    Steps:
        1. Print the prompt
        2. Get coefficients
        3. Calculate the discriminants
        4. Print roots
*/

#include <stdio.h>
#include <math.h>

// function prototypes
void printPrompt(char coeff);
int getCeofficient(void);
int calculateDiscriminant(int a, int b, int c);
void printRoots(int a, int b, int c);
int xval
int main(void){
    printPrompt('a');
    int a = getCeofficient();
     printPrompt('b');
    int b = getCeofficient();
    printPrompt('c');
    int c = getCeofficient();
    return 0;
}

void printPrompt(char coeff) {
    printf("Enter the coefficient %c: ", coeff);
}

int getCeofficient(void) {
    int coeff;
    scanf("%d", &coeff);
}

int calculateDiscriminant(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

void printRoots(int a, int b, int c) {
    int discrim = calculateDiscriminant(a, b, c);
    if (discrim < 0) {
        puts("No real roots");
    }
    else if (discrim == 0) {
        xval = double (-b / (2 * a))
        printf("x = %f\n", xval);
    }
    else if (discrim > 0) {
        double x1 = (-b + sqrt(discrim)) / (2 * a);
        double x2 = (-b + sqrt(discrim)) / (2 * a);
        printf("x1 = %lf; x2 = %lf\n", x1, x2);
    }
}