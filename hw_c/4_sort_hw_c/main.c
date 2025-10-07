#include <stdio.h>
#include <stdlib.h>

// Объявление функции сортировки из второго файла
extern int bubleSort(int arr[], int len);

#define MAX_NUMBERS 100

void printfArray(int numbers[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}


int main(void)
{
    int numbers[MAX_NUMBERS];
    int count = 0;
    char ch;
    printf("Введите числа через пробел (не более 100): ");
    while (scanf("%d", &numbers[count]) == 1 && count < MAX_NUMBERS) {
        count++;
        ch = getchar();
        if (ch == '\n') {
            break;
        }
    }

    printf("Исходный массив: ");
    printfArray(numbers, count);

    int changes = bubleSort(numbers, count);
    printf("Отсортированный массив: ");
    printfArray(numbers, count);
    printf("Количество элементов, изменивших позицию: %d\n", changes);
    return changes;
}