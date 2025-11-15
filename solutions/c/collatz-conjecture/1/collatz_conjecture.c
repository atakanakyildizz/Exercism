#include "collatz_conjecture.h"
#include <stdio.h>
#include <stdlib.h>

int steps(int start){

    int iteration = 0;
    if (start<1){return -1;}

    while(start>1){
        if(start%2==0){start = start/2;}
        else{start = start*3+1;}
        iteration++;
    }
    return iteration;
}

