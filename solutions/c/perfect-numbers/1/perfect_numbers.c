#include "perfect_numbers.h"
#include <stdio.h>
#include <stdlib.h>

int classify_number(int number){
    int sum=0;
    if (number<=0){return -1;}
    for (int i = 0; i <= number/2; i++){if (number%i==0){sum=sum+i;}}
    if (sum == number){return 1;}
    else if(sum > number) {return 2;}
    else{return 3;}
}
