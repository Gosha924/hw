#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void)
{
    int numbers[] = { 4, 2, 1, 5, 3 };
    int len = sizeof(numbers) / sizeof(numbers[0]);
    int buff;
    char res;
    while (res != 'y') {
        int a = rand() % len;
        int b = rand() % len;
        buff = numbers[a];
        numbers[a] = numbers[b];
        numbers[b] = buff;
        printArray(numbers, len);
        printf("Input y if array sort if not input enter\n");
        scanf("%c", &res);
    }
    return 0;
}