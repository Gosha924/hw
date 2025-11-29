#include <stdio.h>
#include <string.h>
#include "5_hw_c_stack/stack.h"

int main(void)
{
    char string[100];
    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);
    OBJ* brackets = NULL;
    for (int i = 0; string[i] != '\n'; i++) {
        if (strchr("(){}[]", string[i]) != NULL)
            brackets = push(brackets, string[i]);

        if (lenStack(brackets) > 1) {
            for (int j = 0; j < lenStack(brackets) - 1; j++) {
                int a = showElem(brackets, j);
                int b = showElem(brackets, j + 1);
                // узнаю номера символов в таблице кодировок, у открывающих и закрывающих скобкок одного вида номера стоят рядом
                // разность больше нуля так как я проверяю, что сначала идет открывающая, а потом уже закрывающая
                if (a - b < 3 && a - b > 0) {
                    brackets = pop(brackets);
                    brackets = pop(brackets);
                }
            }
        }
    }
    if (lenStack(brackets) == 0) {
        printf("Корректная скобочная последовательность\n");
    } else {
        printf("Некорректная скобочная последовательность\n");
    }
    while (brackets != NULL) {
        brackets = pop(brackets);
    }
    return 0;
}
