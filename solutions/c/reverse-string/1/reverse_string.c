#include "reverse_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *reverse(const char *value){
    if (value == NULL) return NULL;
    int len = strlen(value);
    char *my_str = (char *)malloc((len+1) * sizeof(char));
    if (my_str == NULL) {return NULL; }
    for (int i = 0; i < len; i++){
        my_str[i]= value[len-1-i];
    }
    my_str[len]='\0';
    return my_str;
}

