#include "space_age.h"
#include <stdio.h>
#include <stdlib.h>


float age(planet_t planet, int64_t seconds){
    float earth_year = seconds / 31557600;
    float year;

    switch (planet)
    {
    case MERCURY:
        year = earth_year / 0.2408467;
        break;
    case VENUS:
        year = earth_year / 0.61519726;
        break;
    case EARTH:
        year = earth_year;
        break;
    case MARS:
        year = earth_year / 1.8808158;
        break;
    case JUPITER:
        year = earth_year / 11.862615;
        break;
    case SATURN:
        year = earth_year / 29.447498;
        break;
    case URANUS:
        year = earth_year / 84.016846;
        break;
    case NEPTUNE:
        year = earth_year / 164.79132;
        break;
    default:
        year = -1;
        break;        
    }

    return year; 
}

