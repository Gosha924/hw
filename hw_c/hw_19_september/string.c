#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Введите 2 строки, учтите максимальная длина строк 100 символов и строки разделяются по пробелу\n");
    char string[100];
    char string1[100];
    int count = 0;
    scanf("%s", string);
    scanf("%s", string1);
    if (strlen(string1) > strlen(string)) {
        printf("%d\n", 0);
    } else {
        char* inditorStr = string;
        int len = strlen(string1);
        inditorStr = strstr(inditorStr, string1);
        while (inditorStr != NULL) {
            count++;
            inditorStr += 1;
            inditorStr = strstr(inditorStr, string1);
        }
    }
    printf("%d\n", count);
    return 0;
}