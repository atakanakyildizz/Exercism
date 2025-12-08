
#include "nth_prime.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 
#include <string.h> 

uint32_t nth(uint32_t n) {
    if (n == 0) return 0;
    if (n == 1) return 2; 

    uint32_t limit;
    if (n < 6) {
        limit = 15; 
    } else {
        double ln_n = log(n);
        limit = (uint32_t)(n * (ln_n + log(ln_n))) + 5;
    }

    bool *is_prime = (bool*)malloc((limit + 1) * sizeof(bool));
    
    memset(is_prime, true, (limit + 1) * sizeof(bool));
    is_prime[0] = false;
    is_prime[1] = false;

    // ADIM 3: Eratosthenes Kalburu Algoritması
    for (uint32_t p = 2; p * p <= limit; p++) {
        // Eğer p değişmediyse (hala true ise), asaldır.
        if (is_prime[p] == true) {
            // p'nin tüm katlarını asal değil (false) olarak işaretle
            for (uint32_t i = p * p; i <= limit; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // ADIM 4: n. asalı bulmak için diziyi tara
    uint32_t count = 0;
    uint32_t result = 0;

    for (uint32_t i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            count++;
            if (count == n) {
                result = i;
                break;
            }
        }
    }

    free(is_prime);

    return result;
}
