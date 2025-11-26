#include "resistor_color_trio.h"
#include <stdio.h>
#include <math.h>

resistor_value_t color_code(resistor_band_t bands[]) {
    resistor_value_t result;
    unsigned long long main_value = (bands[0] * 10 + bands[1]);
    
    int zeros = bands[2];
    if (main_value != 0 && main_value % 10 == 0) {
        main_value /= 10;
        zeros++;
    }

    result.unit = OHMS;

    if (zeros >= 9) {
        result.unit = GIGAOHMS;
        zeros -= 9;
    } else if (zeros >= 6) {
        result.unit = MEGAOHMS;
        zeros -= 6;
    } else if (zeros >= 3) {
        result.unit = KILOOHMS;
        zeros -= 3;
    }
    while (zeros > 0) {
        main_value *= 10;
        zeros--;
    }

    result.value = (int)main_value;
    return result;
}
