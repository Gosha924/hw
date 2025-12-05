#include "list.h"
#include <stdio.h>


int palindrom(LinkedList* numbers, int len)
{
    int j = len - 1;
    int isPalindrom = 1;
    for (int i = 0; i <= len / 2; i++) {
        int start = getValue(numbers, i);
        int finish = getValue(numbers, j);
        if (start != finish) {
            // printf("NOT palindrom\n");
            isPalindrom--;
            return 0;
        }
        j--;
    }
    if (isPalindrom) {
        //printf("Palindrom\n");
    }
    return 1;
}

void testsForPalindrom(void){
    // first test
    LinkedList* numbers = createNewList();
    insertNum(numbers, 1);
    insertNum(numbers, 1);
    insertNum(numbers, 1);
    int func = palindrom(numbers, 3);
    if (func) {
        printf("test with equal numbers PASSED\n");
    } else {
        printf("test with equal numbers FAILED\n");
    }
    deleteList(numbers);
    // second test
    LinkedList* numbers2 = createNewList();
    insertNum(numbers2, 1);
    insertNum(numbers2, 2);
    insertNum(numbers2, 3);
    insertNum(numbers2, 4);
    insertNum(numbers2, 5);
    insertNum(numbers2, 6);
    int func2 = palindrom(numbers2, 6);
    if (func2 == 0) {
        printf("test with [1: 6] numbers PASSED\n");
    } else {
        printf("test with [1: 6] numbers FAILED\n");
    }
    deleteList(numbers2);
    // third test
    LinkedList* numbers3 = createNewList();
    insertNum(numbers3, 1);
    insertNum(numbers, 2);
    insertNum(numbers3, -1);
    insertNum(numbers3, -2);
    insertNum(numbers3, 1);
    insertNum(numbers3, -2);
    int func3 = palindrom(numbers3, 6);
    if (func3 == 0) {
        printf("test with negative numbers PASSED\n");
    } else {
        printf("test with negative numbers FAILED\n");
    }
    deleteList(numbers3);
}

int main(void)
{
    LinkedList* numbers = createNewList();
    int len, value;
    printf("Введите длину списка\n");
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        printf("Введите число\n");
        scanf("%d", &value);
        insertNum(numbers, value);
    }
    int result = palindrom(numbers, len);
    if (result) {
        printf("palindrom\n");
    } else {
        printf("NOT palindrom\n");
    }
    deleteList(numbers);
    testsForPalindrom();
    return 0;
}
