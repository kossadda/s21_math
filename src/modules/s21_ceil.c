/**
 * @file s21_ceil.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Implementation of function ceil from math.h library
 * @version 1.0
 * @date 2024-01-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "./include/s21_ceil.h"

/**
 * @brief Returns the nearest integer not less than the given value.
 * 
 * @param x number whose value needs to be rounded.
 * @return long double - result of calculation.
 */
long double s21_ceil(double x)
{
    long double result = x;
    union double_int bits = {x};

    int sign = bits.ulong >> DOUBLE_SHIFT;
    int exponent = ((bits.ulong & EXP_MASK) >> MANTISS_SIZE) - EXP_SHIFT;
    uint64_t mantissa = bits.ulong & MANTISS_MASK;

    if (exponent < 0) {
        if(!x && sign) {
            bits.dbl = NEGATIVE_ZERO;
        } else if (!x) {
            bits.dbl = ZERO;
        } else {
            bits.dbl = 1.0;
        }
    } else {
        uint64_t mask = MANTISS_MASK >> exponent;

        if ((mantissa & mask) == BIT_NOT_SET) {
            bits.dbl = x;
        } else {
            if (sign == BIT_NOT_SET) {
                mantissa += (uint64_t)1 << (MANTISS_SIZE - exponent);
                if (mantissa & OVERFLOW_MASK) {
                    mantissa = 0;
                    exponent++;
                }
            }
            mantissa &= ~mask;
            if(!S21_IS_NAN(result)) {
                bits.ulong = ((uint64_t)sign << DOUBLE_SHIFT) | ((uint64_t)(exponent + EXP_SHIFT) << MANTISS_SIZE) | mantissa;
            }
        }
    }

    result = bits.dbl;

    return result;
}
