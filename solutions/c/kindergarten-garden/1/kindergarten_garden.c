#include "kindergarten_garden.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

plants_t plants(const char *diagram, const char *student) {
    plants_t result;
    
    int student_idx = student[0] - 'A';
    int col = student_idx * 2;

    const char *row2 = strchr(diagram, '\n') + 1;
    char current_chars[4] = { diagram[col], diagram[col+1], row2[col], row2[col+1] };

    for (int i = 0; i < 4; i++) {
        switch (current_chars[i]) {
            case 'C': result.plants[i] = CLOVER;   break;
            case 'G': result.plants[i] = GRASS;    break;
            case 'R': result.plants[i] = RADISHES; break;
            case 'V': result.plants[i] = VIOLETS;  break;
        }
    }

    return result;
}

