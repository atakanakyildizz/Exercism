#include "binary_search.h"
#include <stdio.h>
#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length){
    int i=0;
    int error=0;
    if (length==0){
        return NULL;
    }


    while (value != arr[i]){
        if (value>arr[(i+length)/2]){
            i=(i+length)/2;
            error++;
        }
        else{
        i++;
        error++;
    }
    if(error==(int)(length)){return NULL;}
    }
    return &arr[i];
}
