#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void printfArray(int numbers[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void)
{
    int numbers[100];
    int count = 0;
    char ch;
    printf("Введите числа через пробел (не более 100): ");
    while (scanf("%d", &numbers[count]) == 1 && count < 100) {
        count++;
        ch = getchar();
        if (ch == '\n') {
            break;
        }
    }

    printf("Исходный массив: ");
    printfArray(numbers, count);

    int changes = bubbleSort(numbers, count);
    printf("Отсортированный массив: ");
    printfArray(numbers, count);
    printf("Количество элементов, изменивших позицию: %d\n", changes);
    return changes;
}