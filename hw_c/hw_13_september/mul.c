#include <stdio.h>

int main(void) {
    int num;
    printf("Input number, please\n");
    scanf("%d", &num);
    int numRow = num * num;
    int result = (numRow + 1) * (numRow + num) + 1;
    printf("%d\n", result);
    return 0;
}
