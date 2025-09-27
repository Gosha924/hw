#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* array = NULL;
    int lenArray, countZero = 0;
    printf("Input array`s len\n");
    scanf("%d", &lenArray);
    array = (int*)malloc(lenArray * sizeof(int));
    printf("Input array`s elems\n");
    for (int i = 0; i < lenArray; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < lenArray; i++) {
        if (array[i] == 0) {
            countZero++;
        }
    }
    printf("%d\n", countZero);
    free(array);
    return 0;
}