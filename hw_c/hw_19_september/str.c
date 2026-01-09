#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Введите 2 строки, учтите максимальная длина строк 100 символов\n");
    char string[100];
    char substring[100];
    int count = 0;
    scanf("%s", string);
    scanf("%s", substring);
    if (strlen(substring) > strlen(string)) {
        printf("0\n");
        return 0;
    } else {
        char* inditorStr = string;
        int len = strlen(substring);
        do {
            inditorStr = strstr(inditorStr, substring);
            if (inditorStr != NULL) {
                count++;
                inditorStr += 1;
            }
        } while (inditorStr != NULL);
    }
    printf("%d\n", count);
    return 0;
}