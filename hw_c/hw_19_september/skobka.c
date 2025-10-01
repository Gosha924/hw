#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    char str[100];
    printf("Введите строку для проверки баланса скобок: ");
    fgets(str, sizeof(str), stdin);
    int balance = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            balance++;
        } else if (str[i] == ')') {
            balance--;
        }
        if (balance < 0) {
            printf("Скобки не сбалансированы\n");
            return 0;
        }
    }
    if (balance == 0) {
        printf("Скобки сбалансированы\n");
    } else {
        printf("Скобки не сбалансированы\n");
    }
    return 0;
}