#include <stdio.h>

int sumNum(int number) 
{
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(void) 
{
    int nums[] = {1, 1, 1, 1};
    int len = sizeof(nums) / sizeof(nums[0]);
    int max = -123445;
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sumNum(nums[i]);
        if (sum > max) {
            max = sum;
        }
    }
    for (int i = 0; i < len; i++) {
        sum = sumNum(nums[i]);
        if (max == sum) {
            printf("%d ", nums[i]);
        }
    }
    printf("\n");
    return 0;
}