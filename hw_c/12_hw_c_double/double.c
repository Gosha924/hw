#include "double.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool getBit(uint64_t bits, int i)
{
    return (bits >> i) & 1ULL;
}

// Функция для разбора double
DoubleParts parseDouble(double num)
{
    DoubleUnion du;
    du.value = num;
    DoubleParts parts;
    // Извлекаем знак
    parts.sign = getBit(du.bits, 63);
    // Извлекаем экспоненту
    parts.expBias = 0;
    for (int i = 52; i <= 62; i++) {
        if (getBit(du.bits, i)) {
            parts.expBias |= (1 << (i - 52));
        }
    }
    // Извлекаем мантиссу
    parts.mantissa = 0;
    for (int i = 0; i <= 51; i++) {
        if (getBit(du.bits, i)) {
            parts.mantissa |= (1ULL << i);
        }
    }
    // Вычисляем реальную экспоненту со смещением -1023
    if (parts.expBias == 0) {
        parts.exponent = -1022;
    } else if (parts.expBias == 0x7FF) {
        parts.exponent = parts.expBias - 1023;
    } else {
        // Нормализованное число
        parts.exponent = parts.expBias - 1023;
    }
    return parts;
}

// Функция для вычисления мантиссы
double calcMantissa(DoubleParts parts)
{
    double mantissa = 1.0;
    if (parts.expBias == 0) {
        // Денормализованное число
        mantissa = 0.0;
    }
    // Добавляем биты мантиссы
    for (int i = 51; i >= 0; i--) {
        if (parts.mantissa & (1ULL << i)) {
            double bit_value = 1.0 / (1ULL << (52 - i));
            mantissa += bit_value;
        }
    }
    return mantissa;
}

void printNumber(double num)
{
    DoubleParts parts = parseDouble(num);
    double mantissa = calcMantissa(parts);

    printf(parts.sign ? "-" : "+");
    // Выводим мантиссу
    printf("%.20f*2^%d\n", mantissa, parts.exponent);
}