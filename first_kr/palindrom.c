#include <stdio.h>
#include <string.h>

int toTwo(int qwerty)
{
    int num[100];
    int i = 0;
    int n = qwerty;
    while (n > 0) {
        num[i] = n % 2;
        n /= 2;
        i++;
    }
    int len = sizeof(num) / sizeof(num[0]);
    int res = pal(num, len);
    if (res == 1) {
        return 1;
    }
    return 0;
}

int pal(int bin[], int len)
{
    int diff = 0;
    int asa = len - 1;
    while (diff <= asa) {
        if (bin[diff] == bin[asa]) {
            diff++;
            asa--;
        } else {
            return 0;
        }
    }
    return 1;
}

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void appendStr(char* str, char c)
{
    int len = strlen(str);
    str[len] = c;
    str[len + 1] = '\0';
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int b = toTwo(i);
        if (b == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}