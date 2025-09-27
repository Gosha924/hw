#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Введите делимое и делитель: ");
    scanf("%d", &a);
    scanf("%d", &b);
    if (b == 0) {
        printf("Ошибка: деление на ноль!\n");
        return 0;
    }
    int quotient = 0;
    int sign = 1;
    if (a < 0) {
        a = -a;
        sign = -sign;
    }
    if (b < 0) {
        b = -b;
        sign = -sign;
    }
    while (a >= b) {
        a = a - b;
        quotient = quotient + 1;
    }
    quotient = quotient * sign;
    printf("Неполное частное: %d\n", quotient);
    return 0;
}