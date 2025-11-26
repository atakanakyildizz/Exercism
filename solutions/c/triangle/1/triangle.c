#include "triangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool is_equilateral(triangle_t sides){

    if ((sides.a + sides.b < sides.c) || 
        (sides.a + sides.c < sides.b) || 
        (sides.b + sides.c < sides.a) ||
        (sides.a == 0 || sides.b == 0 || sides.c == 0)
        ) {return false;}

    if ((sides.a==sides.b) && (sides.b==sides.c)){
        return true;
    }
    return false;
}

bool is_isosceles(triangle_t sides){
    int check = 0;
    if ((sides.a + sides.b < sides.c) || 
        (sides.a + sides.c < sides.b) || 
        (sides.b + sides.c < sides.a) ||
        (sides.a == 0 || sides.b == 0 || sides.c == 0)
        ) {return false;}

    if (sides.a == sides.b){check++;}
    if (sides.a == sides.c){check++;}
    if (sides.b == sides.c){check++;}
    if (check >= 1){
        return true;
    }
    return false;
}

bool is_scalene(triangle_t sides){
        int check = 0;
    if ((sides.a + sides.b < sides.c) || 
        (sides.a + sides.c < sides.b) || 
        (sides.b + sides.c < sides.a) ||
        (sides.a == 0 || sides.b == 0 || sides.c == 0)
        ) {return false;}

    if (sides.a == sides.b){check++;}
    if (sides.a == sides.c){check++;}
    if (sides.b == sides.c){check++;}
    if (check == 0){
        return true;
    }
    return false;
}




