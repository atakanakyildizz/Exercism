#include "scrabble_score.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned int score(const char *word){
    int len = strlen(word);
    char my_word[len];
    int point = 0;

    for (int i = 0; i < len; i++){
        my_word[i] = tolower(word[i]);
        if (my_word[i] == 'a' || my_word[i] == 'e' || my_word[i] == 'i' || my_word[i] == 'o' || 
            my_word[i] == 'u' || my_word[i] == 'l' || my_word[i] == 'n' || my_word[i] == 'r' || 
            my_word[i] == 's' || my_word[i] == 't'){
            point = point + 1;
        }
        else if(my_word[i] == 'd' || my_word[i] == 'g' ){point = point + 2;}
        else if(my_word[i] == 'b' || my_word[i] == 'c' || my_word[i] == 'm' || my_word[i] == 'p' ){point = point + 3;}
        else if(my_word[i] == 'f' || my_word[i] == 'h' || my_word[i] == 'v' || my_word[i] == 'w' || my_word[i] == 'y' ){point = point + 4;}
        else if(my_word[i] == 'k'  ){point = point + 5;}
        else if(my_word[i] == 'j' || my_word[i] == 'x' ){point = point + 8;}
        else if(my_word[i] == 'q' || my_word[i] == 'z' ){point = point + 10;}
    }

    return point;

}




