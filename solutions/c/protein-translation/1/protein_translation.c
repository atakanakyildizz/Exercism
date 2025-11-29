#include "protein_translation.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    const char *str;
    amino_acid_t acid;
    bool stop;
} codon_map_t;

static const codon_map_t MAP[] = {
    {"AUG", Methionine,    false},
    {"UUU", Phenylalanine, false}, {"UUC", Phenylalanine, false},
    {"UUA", Leucine,       false}, {"UUG", Leucine,       false},
    {"UCU", Serine,        false}, {"UCC", Serine,        false},
    {"UCA", Serine,        false}, {"UCG", Serine,        false},
    {"UAU", Tyrosine,      false}, {"UAC", Tyrosine,      false},
    {"UGU", Cysteine,      false}, {"UGC", Cysteine,      false},
    {"UGG", Tryptophan,    false},
    {"UAA", 0, true}, {"UAG", 0, true}, {"UGA", 0, true}, 
    {NULL,  0, false} 
};

protein_t protein(const char *const rna) {
    protein_t result = { .valid = true, .count = 0 };
    int len = strlen(rna);

    for (int i = 0; i < len; i += 3) {
        if (i + 3 > len) {
            result.valid = false;
            return result;
        }

        char current_codon[4] = { rna[i], rna[i+1], rna[i+2], '\0' };
        bool found = false;
        
        for (const codon_map_t *p = MAP; p->str != NULL; p++) {
            if (strcmp(current_codon, p->str) == 0) {
                if (p->stop) {
                    return result; 
                }
                
                if (result.count < MAX_AMINO_ACIDS) {
                    result.amino_acids[result.count++] = p->acid;
                }
                found = true;
                break; 
            }
        }

        if (!found) {
            result.valid = false;
            return result;
        }
    }

    return result;
}
