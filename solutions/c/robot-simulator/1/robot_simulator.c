#include "robot_simulator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t yon;
    yon.direction = direction;
    yon.position.x = x;
    yon.position.y = y;

    return yon;
}

void robot_move(robot_status_t *robot, const char *commands){

    while (*commands != '\0') {
    
    char komut = *commands; 

    if ('R' == komut) {
        robot->direction = (robot->direction+1) % DIRECTION_MAX;
    } else if ('L' == komut) {
        robot->direction = (robot->direction-1) % DIRECTION_MAX;
    } else if('A' == komut){
        switch (robot->direction) {
            case DIRECTION_NORTH:
                robot->position.y++;
                break;
            case DIRECTION_EAST:
                robot->position.x++;
                break;
            case DIRECTION_SOUTH:
                robot->position.y--;
                break;
            case DIRECTION_WEST:
                robot->position.x--;
                break;            
            case DIRECTION_MAX:
                break;
        }
    }
    
    commands++; 
}
}



