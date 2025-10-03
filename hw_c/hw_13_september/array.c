#include <stdio.h>

void FirstSecondPerevarotArray(int array[], int lenn)
{
    for (int i = 0; i < lenn / 2; i++) {
        int elem = array[i];
        array[i] = array[lenn - 1 - i];
        array[lenn - 1 - i] = elem;
    }
}

void ThreePerevarotArray(int array[], int n, int m)
{
    for (int j = 0; j < n / 2; j++) {
        int elem = array[j + m];
        array[j + m] = array[10 - 1 - j];
        array[10 - 1 - j] = elem;
    }
}

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
    FirstSecondPerevarotArray(array, 10);
    FirstSecondPerevarotArray(array, m);
    ThreePerevarotArray(array, n, m);
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}