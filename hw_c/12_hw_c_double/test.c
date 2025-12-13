#include "double.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Вспомогательные функции для тестирования
typedef struct {
    double input;
    bool expected_sign;
    int expected_exponent;
    const char* expected_mantissa_prefix; // Первые 10 цифр мантиссы для проверки
} TestCase;

bool test1PositiveNumber()
{
    double num = 2.5;
    DoubleParts parts = parseDouble(num);
    double mantissa = calcMantissa(parts);
    return (!parts.sign && parts.exponent == 1 && fabs(mantissa - 1.25) < 1e-10);
}

bool test2NegativeNumber()
{
    double num = -2.5;
    DoubleParts parts = parseDouble(num);
    double mantissa = calcMantissa(parts);
    return (parts.sign && parts.exponent == 1 && fabs(mantissa - 1.25) < 1e-10);
}

bool test3Zero()
{
    double num = 0.0;
    DoubleParts parts = parseDouble(num);
    return (!parts.sign && parts.exponent == -1022);
}

bool test4LargeNumber()
{
    double num = 12312.323;
    DoubleParts parts = parseDouble(num);
    double mantissa = calcMantissa(parts);

    return (parts.exponent == 13 && mantissa > 1.502969 && mantissa < 1.502970);
}

bool test5SmallNumber()
{
    double num = 1e-10;
    DoubleParts parts = parseDouble(num);

    // Проверяем что это нормализованное число
    return (!parts.sign && parts.exponent < 0);
}

bool runTests(void)
{
    printf("Tests\n");

    int passed = 0;
    int total = 5;
    if (test1PositiveNumber()) {
        printf("Test 1 PASSED\n");
        passed++;
    } else {
        printf("Test 1 FAILED\n");
    }
    if (test2NegativeNumber) {
        printf("Test 2 PASSED\n");
        passed++;
    } else {
        printf("Test 2 FAILED\n");
    }

    if (test3Zero()) {
        printf("Test 3 PASSED\n");
        passed++;
    } else {
        printf("Test 3 FAILED\n");
    }

    if (test4LargeNumber()) {
        printf("Test 5 PASSED\n");
        passed++;
    } else {
        printf("Test 5 FAILED\n");
    }

    if (test5SmallNumber()) {
        printf("Test 5 PASSED\n");
        passed++;
    } else {
        printf("Test 5 FAILED\n");
    }

    printf("Tests passed: %d/%d\n", passed, total);
    return (passed == total);
}

int main(void)
{
    return runTests();
}
