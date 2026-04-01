#include "sublist.h"
#include <stdlib.h>
#include <stdio.h>

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count){
    size_t lenA = list_to_compare_element_count;
    size_t lenB = base_list_element_count;
    
    if (lenA == 0 && lenB == 0) return 0;
    if (lenA == 0) return 2;
    if (lenB == 0) return 3;

    if (lenA <= lenB) {
        for (size_t i = 0; i <= lenB - lenA; i++) {
            size_t j = 0;
            while (j < lenA && list_to_compare[j] == base_list[i + j]) j++;
            
            if (j == lenA) { 
                return (lenA == lenB) ? EQUAL : 2;
            }
        }
    } else {
        for (size_t i = 0; i <= lenA - lenB; i++) {
            size_t j = 0;
            while (j < lenB && base_list[j] == list_to_compare[i + j]) j++;
            
            if (j == lenB) return SUPERLIST;
        }
    }

    return UNEQUAL;
}
