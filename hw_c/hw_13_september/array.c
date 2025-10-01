#include <stdio.h>

int main(void)
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("Введите длины отрезков n и m, учтите их общая длина должна быть 10\n");
    unsigned int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    if (n + m != 10) {
        printf("Некорректный ввод\n");
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        int elem = array[i];
        array[i] = array[10 - 1 - i];
        array[10 - 1 - i] = elem;
    }
    for (int i = 0; i < m / 2; i++) {
        int elem = array[i];
        array[i] = array[m - 1 - i];
        array[m - 1 - i] = elem;
    }
    for (int j = 0; j < n / 2; j++) {
        int elem = array[j + m];
        array[j + m] = array[10 - 1 - j];
        array[10 - 1 - j] = elem;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}