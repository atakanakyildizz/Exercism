#include "sum_of_multiples.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit){
    int sum=0;
    if (number_of_factors == 0){
        return 0;
    }


    for (unsigned int i = 0; i < limit; i++){
        for (size_t j = 0; j < number_of_factors; j++){
            if (factors[j] != 0 && i % factors[j] == 0){
                sum += i;
                break;
            }         
        }  
    }
    return sum;


}
