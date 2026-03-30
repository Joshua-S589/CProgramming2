/* 

program converts seconds to HMS

*/

#include <stdio.h>
int main(void) {
    int sec = 0;

    // getting seconds
    puts("Enter the number of seconds");
    scanf("%d", &sec);
    
    // selection statement
    if (sec < 0) {
        puts("seconds cannot be negative");
        return 0;
    }
    else {
    // calculates minutes
    int min = sec / 60;
    int sec_rem = sec % 60;

    // calculates hours
    int hour = min / 60;
    int min_rem = min % 60;

    // prints results
    printf("%d seconds is equivalent to %d hours, %d minutes, and %d seconds\n", sec, hour, min_rem, sec_rem);
    }

    return 0;
}