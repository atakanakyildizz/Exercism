#include "pangram.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL) return false;
    bool alphabet_found[26] = {false};
    
    int i = 0;
    while(sentence[i] != '\0') {
        char c = sentence[i];
        if (isalpha(c)) {
            c = tolower(c);
            int index = c - 'a'; 
            alphabet_found[index] = true;
        }
        i++;
    }

    for (int k = 0; k < 26; k++) {
        if (alphabet_found[k] == false) {
            return false; 
        }
    }

    return true;
}
