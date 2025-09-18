#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num;
    int result = 0;
    printf("Input sum of three numbers\n");
    scanf("%d", &num);
    if (num < 0 || num > 27) {
        printf("NO lusky tickets\n");
    } else {
        int digit1, digit2, digit3;
        int digit4, digit5, digit6;
        for (int i = 100000; i < 1000000; i++) {
            digit1 = i / 100000;
            digit2 = (i / 10000) % 10;
            digit3 = (i / 1000) % 10;
            digit4 = (i / 100) % 10;
            digit5 = (i / 10) % 10;
            digit6 = i % 10;
            int sum1 = digit1 + digit2 + digit3;
            int sum2 = digit4 + digit5 + digit6;
            if (sum1 == sum2 && sum1 == num) {
                result++;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}
