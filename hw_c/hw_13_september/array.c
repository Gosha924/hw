#include <stdio.h>

int main(void)
{
    /*
    Моя программа переставляет массив чисел от 1 до 5 в массив 3 4 5 1 2
    */
    int array[] = {1, 2, 3, 4, 5 };
    int zeroElem = array[0];
    int firstElem = array[1];
    int len = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < len; i++) {
        if (i < 3) {
            array[i] = array[i + 2];
        } else if (i == 3) {
            array[i] = zeroElem;
        } else {
            array[i] = firstElem;
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}