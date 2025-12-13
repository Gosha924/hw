#include <stdbool.h>
#include <stdint.h>

// структура для доступа к битовому представлению double
typedef union {
    double value;
    uint64_t bits;
} DoubleUnion;

// Структура для хранения результата разбора double
typedef struct {
    bool sign;
    int exponent; // порядок
    uint64_t mantissa; // мантисса
    int expBias; // экспонента со смещением
} DoubleParts;

bool getBit(uint64_t bits, int i);
DoubleParts parseDouble(double num);
double calcMantissa(DoubleParts parts);
void printNumber(double num);