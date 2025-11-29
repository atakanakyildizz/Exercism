#include "square_root.h"
#include <stdlib.h>
#include <stdio.h>

int square_root(int number){
    if (number<=0){return 0;}
    int l = 0, r = number+1;

    while(l != r-1){
        int m = ((l+r)/2);
        if (m*m <= number){l=m;}
        else{r=m;}
    }
    return l;
}


