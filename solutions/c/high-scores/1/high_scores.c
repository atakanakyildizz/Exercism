#include "high_scores.h"
#include <stdio.h>
#include <stdlib.h>

int32_t latest(const int32_t *scores, size_t scores_len){
    int32_t last=0;
    for (size_t i = 0; i < scores_len; i++){
        last = scores[i];
    }
    return last;
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t best=0;
    for (size_t i = 0; i < scores_len; i++){
        if (scores[i]>best){
            best = scores[i];
        }
        
    }
    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    int32_t copy_array[scores_len], key;
    size_t i;
    int j;
    for (i = 0; i < scores_len; i++) {
        copy_array[i] = scores[i];
    }
    for (i = 1; i < scores_len; i++) {
        key = copy_array[i];
        j = (int)i - 1; 

        while (j >= 0 && copy_array[j] < key) {
            copy_array[j + 1] = copy_array[j];
            j = j - 1;
        }
        copy_array[j + 1] = key;
    }

    size_t count = 0;
    for (i = 0; i < 3 && i < scores_len; i++) {
        output[i] = copy_array[i];
        count++;
    }
    return count;
}



