#include "binary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convert(const char *input){
    int result=0, length=strlen(input);
    for (int i = 0; i < length; i++){
        if( (input[i]!= '1') && ((input[i]!= '0'))){return -1;}
        if (input[i]== '1'){result = result+pow(2,length-i-1);}
    } 
    return result;
}
