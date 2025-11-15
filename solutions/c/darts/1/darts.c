#include "darts.h"
#include <stdio.h>
#include <math.h>

int score(coordinate_t landing_position){
    int score=0;
    float x = landing_position.x;
    float y = landing_position.y;

    float distance = sqrt(pow(x,2) + pow(y,2));
    if (distance <=1){
        score = score+10;
    }
    else if(distance <= 5){
        score = score+5;
    }
    else if (distance <= 10)
    {
        score = score+1;
    }

    return score;
}



