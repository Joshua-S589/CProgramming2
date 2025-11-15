#include <stdio.h>
#include <stdbool.h>

bool isDivisibleBoth(int first, int second);
bool isCorrectInput(int first, int second);

int main(void) {
    printf("Enter the values of x and y\n");
    int x = 0;
    scanf("%d", &x);
    int y = 0;
    scanf("%d", &y);
    if (isCorrectInput(x, y)) {
    printf("%d\n", isDivisibleBoth(x, y));
    }
    else {
        puts("Incorrect input");
    }
    return 0;
}

bool isDivisibleBoth(int first, int second) {
    return first % second == 0 && first % (second - 3) == 0;
}

bool isCorrectInput(int first, int second) {
    return !(second == 0 || second == 3);
}