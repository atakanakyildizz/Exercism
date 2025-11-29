#include "nucleotide_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char *count(const char *dna_strand){
    int len = strlen(dna_strand);
    
    int g_counter=0, c_counter=0, a_counter=0, t_counter=0;

    for (int i = 0; i < len; i++){
        char mychar = tolower(dna_strand[i]);
        if ((mychar!='a')&&(mychar!='t')&&(mychar!='g')&&(mychar!='c')){
            char *empty_buffer = (char *)calloc(1, sizeof(char));
            return empty_buffer;
        }
        else if (mychar=='a'){a_counter++;}
        else if (mychar=='t'){t_counter++;}
        else if (mychar=='g'){g_counter++;}
        else if (mychar=='c'){c_counter++;}
    }
    
    char *result_buffer = (char *)malloc(50 * sizeof(char));    
    if (result_buffer == NULL) return NULL;
    snprintf(result_buffer , 20*sizeof(char) ,"A:%d C:%d G:%d T:%d", a_counter, c_counter, g_counter, t_counter);    
    return result_buffer;
}
