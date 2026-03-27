#include "resistor_color_duo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int color_code(resistor_band_t color[]){

    int result=0;
    resistor_band_t deneme = color[0];
    resistor_band_t deneme2 = color[1];

    result = 10*deneme + deneme2;
    
    return result;

}


