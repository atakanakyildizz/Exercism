#include "grains.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

uint64_t square(uint8_t index){
    uint64_t result;
    result = pow(2,index-1);
    if (index>64){
        return 0;
    }
    return result;
}

uint64_t total(void){
    return pow(2,64);
}



