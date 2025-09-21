#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Введите 2 строки, учтите максимальная длина строк 100 символов и строки разделяются по пробелу\n");
    char string[100];
    char string1[100];
    int count = 0;
    scanf("%s", string);
    scanf("%s", string1);
    if (strlen(string1) > strlen(string)) {
        printf("%d\n", 0);
    } else {
        char *inditor_str = string;
        int len = strlen(string1);
        inditor_str = strstr(inditor_str, string1);
        while (inditor_str != NULL) {
            count++;
            inditor_str += 1;
            inditor_str = strstr(inditor_str, string1);
        }
    }
    printf("%d\n", count);
    return 0;
}