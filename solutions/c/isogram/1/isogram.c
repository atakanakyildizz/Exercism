#include "isogram.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool is_isogram(const char phrase[]){

    if (phrase == NULL){
        return false;
    }
    
    int length_word = strlen(phrase);
    char copy[length_word];
    memcpy(copy, phrase, sizeof(char) * length_word);


    for (int i = 0; i < length_word; i++){
        copy[i] = tolower(copy[i]);
        if(ispunct(copy[i]) == 1 || isalpha(copy[i] != 0)){
            copy[i] = ' ';
        }
    }
    

    for (int i = 0; i < length_word; i++){
        for (int j = 0; j < length_word; j++){
            if (i!=j && copy[i] == copy[j] && copy[i]!= ' '){
                return false;
            }
        }
    }
    return true;
}
