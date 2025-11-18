#include "dnd_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


#include "dnd_character.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>   

int ability(void) {
    
    int sum = 0;
    int min = 7; 

    for (int i = 0; i < 4; i++) {
        int roll = (rand() % 6) + 1;
        sum += roll;
        if (roll < min) {
            min = roll;
        }
    }
    return sum - min; 
}

int modifier(int score) {
    return (int)floor((score - 10) / 2.0);
}

dnd_character_t make_dnd_character(void) {
    dnd_character_t character;

    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();

    character.hitpoints = 10 + modifier(character.constitution);

    return character;
}




