#include "all_your_base.h"
#include <stdio.h>
#include <stdlib.h>

size_t rebase(int8_t digits[DIGITS_ARRAY_SIZE], int16_t input_base, int16_t output_base, size_t input_length) {
    
    if (input_base < 2 || output_base < 2) return 0;

    unsigned long long total = 0;

    for (size_t i = 0; i < input_length; i++) {
        if (digits[i] < 0 || digits[i] >= input_base) return 0;
        total = total * input_base + digits[i];
    }

    if (input_length <= 0) return 0;
    if (total <= 0) return 1;

    int8_t temp_digits[DIGITS_ARRAY_SIZE];
    size_t index = 0;

    while (total > 0) {
        temp_digits[index] = total % output_base; 
        total = total / output_base;
        index++;
    }

    for (size_t i = 0; i < index; i++) {
        digits[i] = temp_digits[index - 1 - i];
    }

    return index; 
}
