#include "gigasecond.h"
 #include <stdio.h>
 #include <stdlib.h>
 
#define GIGASECOND_VAL 1000000000

void gigasecond(time_t input, char *output, size_t size) {
    time_t future_time = input + GIGASECOND_VAL;

    struct tm *tm_info = gmtime(&future_time);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", tm_info);
}


