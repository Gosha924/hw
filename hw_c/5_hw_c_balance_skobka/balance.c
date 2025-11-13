#include "5_hw_c_stack/stack.h"
#include <stdio.h>
#include <string.h>


int main(void)
{
    char string[100];
    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);
    OBJ* top = NULL;
    for (int i = 0; string[i] != '\n'; i++) {
        if (string[i] == '(' || string[i] == ')') {
            top = push(top, string[i]);
        }
        if (string[i] == '[' || string[i] == ']') {
            top = push(top, string[i]);
        }
        if (string[i] == '{' || string[i] == '}') {
            top = push(top, string[i]);
        }
        if (lenStack(top) > 1) {
            for (int j = 0; j < lenStack(top) - 1; j++) {
                int a = showElem(top, j);
                int b = showElem(top, j + 1);
                if (a - b < 3 && a - b > 0) {
                    top = pop(top);
                    top = pop(top);
                }
            }
        }
    }
    if (lenStack(top) > 0) {
        printf("Некорректная скобочная последовательность\n");
    } else {
        printf("Корректная скобочная последовательность\n");
    }
    while (top != NULL) {
        top = pop(top);
    }
    return 0;
}