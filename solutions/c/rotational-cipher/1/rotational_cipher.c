#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *rotate(const char *text, int shift_key) {
    int len = strlen(text);
    
    char *rotated = (char *)malloc((len + 1) * sizeof(char));
    if (rotated == NULL) return NULL;

    int basit_shift = shift_key % 26;

    for (int i = 0; i < len; i++) {
        char harf = text[i];

        if (harf >= 'a' && harf <= 'z') {
            int yeni_harf = harf + basit_shift;
            
            if (yeni_harf > 'z') {
                yeni_harf = yeni_harf - 26;
            }
            rotated[i] = (char)yeni_harf;
        }
        
        else if (harf >= 'A' && harf <= 'Z') {
            int yeni_harf = harf + basit_shift;
            
            if (yeni_harf > 'Z') {
                yeni_harf = yeni_harf - 26;
            }
            rotated[i] = (char)yeni_harf;
        }
        
        else {
            rotated[i] = harf; 
        }
    }

    rotated[len] = '\0';

    return rotated;
}
