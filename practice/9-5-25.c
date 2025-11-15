/*
    practice with a non-void function
*/

#include <stdio.h>

// function prototypes
// function takes nothing and returns an integer

int GetFive(void);

// function that converts the given number of kilometers into miles and
// returns the result

double miles_to_kilometers (int miles){
    double kms = miles * 1.609;

    return kms;
}

// function print weather condition based on the given temperature
void DescribeWeather (int temp){
    if (temp >= 80) {
        puts("HOT");
    }
    else{
        puts("COLD");
    }
}

int GetTempurature(void) {
    puts("Enter the temperature");
    int temp;
    scanf("%d", &temp);
    return temp;
}

int main(void){
    // call GetFive function
    int n = GetFive();
    printf("%d\n", n);

    // convert miles
    int miles = 100;
    printf("%d miles is %lf\n", miles, miles_to_kilometers(miles));

    // call described weather function
    int temp = GetTempurature();
    DescribeWeather(temp);
    
    return 0;
}
