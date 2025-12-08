#include "hamming.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute(const char *lhs, const char *rhs){
    int length1 = strlen(lhs);
    int length2 = strlen(rhs);
    int difference=0;
    if ((length1!=length2) || (length1<0)){
        return -1;
    }
    for (int i = 0; i < length1; i++){
        if(lhs[i] != rhs[i]){
        difference++;
    }
}
    return difference;
}

