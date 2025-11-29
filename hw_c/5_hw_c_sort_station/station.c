#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "5_hw_c_stack/stack.h"

void appendStr(char* str, char c)
{
    int len = strlen(str);
    str[len] = c; 
    str[len + 1] = '\0';
}

int isOperator(char c) {
    return c == '(' || c == '+' || c == '-' || c == '*' || c == '/' || c == ')';
}

// Функция для определения приоритета операторов
int prioritet(char c)
{
    if (c == '+' || c == '-'){
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

int main(void)
{
    char string[100];
    char result[100];
    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);
    OBJ* top = NULL;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isdigit(string[i])) {
            appendStr(result, string[i]);
            appendStr(result, ' ');
            continue;
        }
        if (isOperator(string[i]) == 1) {
            if (isOperator(string[i])) {
                while (top != NULL && showElem(top, 0) != '(' && prioritet(showElem(top, 0)) >= prioritet(string[i])) {
                    appendStr(result, showElem(top, 0));
                    appendStr(result, ' ');
                    top = pop(top);
                }
                top = push(top, string[i]);
            }
        }
        if (string[i] == ')') {
            char a = showElem(top, 0);
            while (a) {
                top = pop(top);
                a = showElem(top, 0);
                if (a == '(') {
                    break;
                }
                appendStr(result, a);
                appendStr(result, ' ');
            }
            top = pop(top);
        }
    }
    while (lenStack(top) > 0) {
        char buff = showElem(top, 0);
        appendStr(result, buff);
        appendStr(result, ' ');
        top = pop(top);
    }
    printf("%s\n", result);
    while (top != NULL) {
        top = pop(top);
    }
    return 0;
}