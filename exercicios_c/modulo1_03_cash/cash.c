#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_valid_float(void);

int main(void)
{
    float cents = get_valid_float();
    cents = cents - ((int) cents);
    int result = round(cents * 100);

    int count25 = 0;
    while( result >= 25 )
    {
        result = result - 25;
        count25++;
    }
    // printf("0.25: %i | %i \n", count25, result);
    int count10 = 0;
    while( result >= 10 )
    {
        result = result - 10;
        count10++;
    }
    // printf("0.10: %i | %i \n", count10, result);
    int count05 = 0;
    while( result >= 5 )
    {
        result = result - 5;
        count05++;
    }
    // printf("0.05: %i | %i \n", count05, result);
    int count01 = 0;
    while( result >= 1 )
    {
        result = result - 1;
        count01++;
    }
    // printf("0.01: %i | %i \n", count01, result);
    int count = count25 + count10 + count05 + count01;
    printf("%i \n", count);
}

float get_valid_float(void)
{
    float n;
    do
    {
         n = get_float("Change owed: ");
	}
    while( n <= 0 );
    return n;
}
