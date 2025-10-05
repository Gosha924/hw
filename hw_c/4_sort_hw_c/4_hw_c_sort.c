#include <stdio.h>

#define MAX_SIZE 100

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lomitoSort(int array[], int left, int right)
{
    if (left >= right) {
        return;
    }
    int oporElem = array[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (array[j] <= oporElem) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[right]);
    lomitoSort(array, left, i - 1);
    lomitoSort(array, i + 1, right);
}

int elemsThatChangePosition(int OldArr[], int NewArr[], int len) {
    int countChange = 0;
    for (int i = 0; i < len; i++) {
        if (OldArr[i] == NewArr[i]) {
            countChange++;
        }
    }
    return countChange;
}

int main(void)
{
    int numbers[MAX_SIZE];
    int len = 0;
    printf("Введите числа:\n");
    while(len < MAX_SIZE && scanf("%d", &numbers[len]) == 1) {
        len++;
    }
    int oldNumbers[len];
    for (int i = 0; i < len; i++) {
        oldNumbers[i] = numbers[i];
    }
    // printf("Массив до сортировки\n");
    // printArray(oldNumbers, len);
    lomitoSort(numbers, 0, len - 1);
    // printf("Массив после сортировки\n");
    //printArray(numbers, len);
    int count = elemsThatChangePosition(oldNumbers, numbers, len);
    printf("%d\n", count);
    return 0;
}