#include "eliuds_eggs.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int egg_count(int egg_number){
    int start = sqrt(egg_number);
    int i_counter=0;
    while (egg_number>0)
    {
        if (egg_number-pow(2,start) >= 0){
            egg_number=egg_number-pow(2,start);
            i_counter++;
        }
        start--;
    }
    return i_counter;
}
