#include "beer_song.h"
#include <stdio.h>
#include <stdlib.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    
    int song_index = 0;
    uint8_t current_bottles = start_bottles;


    while (take_down > 0) {
        song[song_index] = malloc(100 * sizeof(char));
        if (song[song_index] == NULL) return; 

        switch (current_bottles) {
            case 0:
                sprintf(song[song_index], "No more bottles of beer on the wall, no more bottles of beer.");
                break;
            case 1:
                sprintf(song[song_index], "1 bottle of beer on the wall, 1 bottle of beer.");
                break;
            default:
                sprintf(song[song_index], "%d bottles of beer on the wall, %d bottles of beer.", current_bottles, current_bottles);
                break;
        }
        song_index++; 
        
        song[song_index] = malloc(100 * sizeof(char));
        if (song[song_index] == NULL) return; 

        switch (current_bottles) {
            case 0: 
                sprintf(song[song_index], "Go to the store and buy some more, 99 bottles of beer on the wall.");
                break;
            case 1: 
                sprintf(song[song_index], "Take it down and pass it around, no more bottles of beer on the wall.");
                break;
            case 2: 
                sprintf(song[song_index], "Take one down and pass it around, 1 bottle of beer on the wall.");
                break;
            default: 
                sprintf(song[song_index], "Take one down and pass it around, %d bottles of beer on the wall.", current_bottles - 1);
                break;
        }
        song_index++;
        current_bottles--; 
        take_down--; 
    

if (take_down > 0) {
            song[song_index] = malloc(2 * sizeof(char)); 
            if (song[song_index] == NULL) return;
            sprintf(song[song_index], "");
            song_index++; 
        }
}
}
