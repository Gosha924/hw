#include <stdio.h>

int main(void) {
    int num;
    printf("Input number, please\n");
    scanf("%d", &num);
    int num_row = num * num;
    int result = (num_row + 1) * (num_row + num) + 1;
    printf("%d\n", result);
    return 0;
}
