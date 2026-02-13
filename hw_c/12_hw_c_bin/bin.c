#include <stdio.h>

#define BIN 16

void toBinary(int num, char* binary)
{
    for (int i = BIN - 1; i >= 0; i--) {
        binary[BIN - 1 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[BIN] = '\0';
}

void printBinNum(char* binary)
{
    for (int i = 0; i < BIN; i++) {
        if (i % 4 == 0 && i > 0) {
            printf(" ");
        }
        printf("%c", binary[i]);
    }
    printf("\n");
}

void binarySum(char* bin1, char* bin2, char* binSum)
{
    printf("\n Вывод суммы\n");
    printBinNum(bin1);
    printBinNum(bin2);
    printf("++++++++++++++++++++\n");
    int buff = 0;
    for (int i = BIN - 1; i >= 0; i--) {
        int bit1 = bin1[i] - '0';
        int bit2 = bin2[i] - '0';
        int sum = bit1 + bit2 + buff;
        binSum[i] = (sum % 2) + '0';
        buff = sum / 2;
    }
    binSum[BIN] = '\0';
    printBinNum(binSum);
}

int toDecimal(char* binary)
{
    int result = 0;
    if (binary[0] == '1') {
        // если число отрицательное
        char temp[BIN + 1];
        int buff = 1;
        for (int i = BIN - 1; i >= 0; i--) {
            int bit = (binary[i] == '0') ? 1 : 0;
            int sum = bit + buff;
            temp[i] = (sum % 2) + '0';
            buff = sum / 2;
        }
        temp[BIN] = '\0';
        for (int i = 0; i < BIN; i++) {
            result = result * 2 + (temp[i] - '0');
        }
        result = -result;
    } else {
        // Положительное число
        for (int i = 0; i < BIN; i++) {
            result = result * 2 + (binary[i] - '0');
        }
    }
    return result;
}
int main(void)
{
    int num1, num2;
    printf("Введите два числа\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    char bin1[BIN + 1], bin2[BIN + 1];
    toBinary(num1, bin1);
    toBinary(num2, bin2);
    printBinNum(bin1);
    printBinNum(bin2);
    char sum[BIN + 1];
    binarySum(bin1, bin2, sum);
    int res = toDecimal(sum);
    printf("%d\n", res);
    return 0;
}