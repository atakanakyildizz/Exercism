#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool is_armstrong_number(int candidate){
    int step = 0;
    int sum = 0;
    int copy_candiate = candidate;

    while (candidate>0){
        candidate = candidate/10;
        step++;
    }
    candidate = copy_candiate;
    while (candidate>0){
        sum = sum + pow(candidate%10, step);
        candidate = candidate/10;
    }

    if (copy_candiate == sum){
        return true;
    }
    return false;

}

