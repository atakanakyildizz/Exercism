#include "rna_transcription.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna){
    if (dna == NULL){
        return NULL;
    }
    int lenght = strlen(dna);
    char *rna = malloc(sizeof(char) * (lenght+1));

    if (rna == NULL){
        return NULL;
    }

    for (int i = 0; i < lenght; i++) {
        if (dna[i] == 'G') {
            rna[i] = 'C';
        } else if (dna[i] == 'C') {
            rna[i] = 'G';
        } else if (dna[i] == 'T') {
            rna[i] = 'A';
        } else if (dna[i] == 'A') {
            rna[i] = 'U';
        } else {
            free(rna);
            return NULL; 
        }
    }
        rna[lenght] = '\0';
        return rna;
        
    }
