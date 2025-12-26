#include "sort.h"
#include <stdio.h>

// Функция сортировки пузырьком
int bubbleSort(int numbers[], int len)
{
    int original_positions[len];
    for (int i = 0; i < len; i++) {
        original_positions[i] = numbers[i];
    }
    int temp;
    int changes = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (original_positions[i] != numbers[i]) {
            changes++;
        }
    }
    return changes;
}