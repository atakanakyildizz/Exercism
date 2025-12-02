#include "prime_factors.h"
#include <stdlib.h>
#include <stdio.h>


size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
    size_t loc=0;

    for (uint64_t i = 2; i <= n; i++){
        if(loc>=MAXFACTORS){break;}
        if (n%i==0){
            factors[loc]=i;
            n=n/i;
            loc++;
            i=1;
    }
}
    return loc;
}
