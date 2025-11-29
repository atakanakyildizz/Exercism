#include "sieve.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit < 2) return 0;

    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    if (!is_prime) return 0;

    memset(is_prime, 1, (limit + 1) * sizeof(bool)); 
    is_prime[0] = false;
    is_prime[1] = false;

    // 2. Eratosthenes Algorithm
    for (uint32_t p = 2; p * p <= limit; p++) {
        if (is_prime[p] == true) {
            for (uint32_t i = p * p; i <= limit; i += p)
                is_prime[i] = false;
        }
    }

    uint32_t count = 0;
    for (uint32_t p = 2; p <= limit; p++) {
        if (is_prime[p]) {
            if (count < max_primes) {
                primes[count] = p;
                count++;
            } else {
                break; 
            }
        }
    }
    free(is_prime);
    return count;
}
