#include "allergies.h"
#include <stdio.h>
#include <stdlib.h>


bool is_allergic_to(allergen_t allergen, int score) {
    for (int i = 0; i < (int)allergen; i++) {
        score = score / 2; 
    }
    if (score % 2 == 1) {
        return true;
    } else {
        return false;
    }
}


allergen_list_t get_allergens(int score) {
    allergen_list_t list;
    list.count = 0;

    for (int i = 0; i < ALLERGEN_COUNT; i++) {
        if (is_allergic_to(i, score)) {
            list.allergens[i] = true;
            list.count++;
        } else {
            list.allergens[i] = false;
        }
    }

    return list;
}


