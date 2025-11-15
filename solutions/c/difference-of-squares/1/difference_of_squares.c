#include "difference_of_squares.h"
#include <stdio.h>
#include <math.h>


unsigned int sum_of_squares(unsigned int number){
    int sum=0;
    for (unsigned int i = 0; i <= number; i++){
        sum = sum + pow(i,2);
    }
    return sum;
}

unsigned int square_of_sum(unsigned int number){
    int sum=0;
    int sumof_squares;
    for (unsigned int i = 0; i <= number; i++){
        sum = sum + i;
    }
    sumof_squares = pow(sum,2);
    return sumof_squares;
}

unsigned int difference_of_squares(unsigned int number){
    int difference = square_of_sum(number) - sum_of_squares(number);
    return difference;
}

