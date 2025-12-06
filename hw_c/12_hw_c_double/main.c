#include "double.h"
#include <stdio.h>

int main(void)
{
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);
    printf("Result: ");
    printNumber(number);
    return 0;
}