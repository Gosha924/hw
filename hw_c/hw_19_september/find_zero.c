#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int *array = NULL;
    int len_array, count_zero = 0;
    printf("Input array`s len\n");
    scanf("%d", &len_array);
    array = (int*)malloc(len_array * sizeof(int));
    printf("Input array`s elems\n");
    for (int i = 0; i < len_array; i++) {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < len_array; i++) {
        if (array[i] == 0) {
            count_zero++;
        }
    }
    printf("%d\n", count_zero);
    free(array);
    return 0;
}