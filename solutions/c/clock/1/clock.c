#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

clock_t clock_create(int hour, int minute) {
    clock_t time;
    
    int total_minutes = (hour * 60) + minute;
    
    total_minutes = (total_minutes % 1440 + 1440) % 1440;
    
    int final_hour = total_minutes / 60;
    int final_minute = total_minutes % 60;
    
    sprintf(time.text, "%02d:%02d", final_hour, final_minute);
    return time;
}


clock_t clock_add(clock_t clock, int minute_add) {
    int current_hour, current_minute;
    
    sscanf(clock.text, "%d:%d", &current_hour, &current_minute);
    
    int total_minutes = (current_hour * 60) + current_minute;
    
    total_minutes += minute_add;
    total_minutes = (total_minutes % 1440 + 1440) % 1440;
    
    int final_hour = total_minutes / 60;
    int final_minute = total_minutes % 60;
    
    sprintf(clock.text, "%02d:%02d", final_hour, final_minute);
    
    return clock;
}


clock_t clock_subtract(clock_t clock, int minute_subtract){
    int current_hour, current_minute;
    
    sscanf(clock.text, "%d:%d", &current_hour, &current_minute);
    
    int total_minutes = (current_hour * 60) + current_minute;
    
    total_minutes -= minute_subtract;
    total_minutes = (total_minutes % 1440 + 1440) % 1440;
    
    int final_hour = total_minutes / 60;
    int final_minute = total_minutes % 60;
    
    sprintf(clock.text, "%02d:%02d", final_hour, final_minute);
    
    return clock;
}

bool clock_is_equal(clock_t a, clock_t b){
    if (strcmp(a.text, b.text))
    {
        return false;
    }
      return true;
}

