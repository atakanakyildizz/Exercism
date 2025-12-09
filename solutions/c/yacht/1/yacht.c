#include "yacht.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int score(dice_t dice, category_t category){
    int result = 0;
    if(category == 11){
        if(dice.faces[0] == dice.faces[1] && dice.faces[1] == dice.faces[2] && dice.faces[2] == dice.faces[3] && dice.faces[3] == dice.faces[4]){
        result = 50;
    }
}
else if(category == 0){
    int number_of_ones=0;
    for (int i = 0; i < 5; i++){if(dice.faces[i]==1){number_of_ones++;}}
    result = 1 * number_of_ones;
}
else if(category==1){
    int number_of_twos=0;
    for (int i = 0; i < 5; i++){if(dice.faces[i]==2){number_of_twos++;}}
    result = 2 * number_of_twos;
}
else if(category==2){
    int number_of_threes=0;
    for (int i = 0; i < 5; i++){if(dice.faces[i]==3){number_of_threes++;}}
    result = 3 * number_of_threes;
}
else if(category==3){
    int number_of_fours=0;
    for (int i = 0; i < 5; i++){if(dice.faces[i]==4){number_of_fours++;}}
    result = 4 * number_of_fours;
}
else if(category==4){
    int number_of_fives=0;
    for (int i = 0; i < 5; i++){if(dice.faces[i]==5){number_of_fives++;}}
    result = 5 * number_of_fives;
}
else if(category==5){
    int number_of_sixes=0;
    for (int i = 0; i < 5; i++){if(dice.faces[i]==6){number_of_sixes++;}}
    result = 6 * number_of_sixes;
}
else if (category == 6) { 
    int counts[7] = {0}; 
    
    for (int i = 0; i < 5; i++) {
        counts[dice.faces[i]]++;
    }
    bool three_of_a_kind = false;
    bool two_of_a_kind = false;

    for (int i = 1; i <= 6; i++) {
        if (counts[i] == 3) {
            three_of_a_kind = true;
        }
        else if (counts[i] == 2) {
            two_of_a_kind = true;
        }
    }

    if ((three_of_a_kind && two_of_a_kind)) {
        for (int i = 0; i < 5; i++) {
            result += dice.faces[i];
        }
    }
}   
else if (category == 7) { 
    int counts[7] = {0}; 

    for (int i = 0; i < 5; i++) {
        counts[dice.faces[i]]++;
    }
    for (int i = 1; i <= 6; i++) {
        if (counts[i] >= 4){
            result=4*i;
        }
    }
}
else if (category == 8) { 
    int check[7] = {0};
    int counter = 0;

    for (int i = 0; i < 5; i++){
        check[dice.faces[i]]=1;
    }

    for (int i = 1; i <= 5; i++){
        if(check[i]==1){counter++;}
    }
    if (counter==5){result=30;}
}
else if (category == 9) { 
    int check[7] = {0};
    int counter=0;

    for (int i = 0; i < 5; i++){
        check[dice.faces[i]]=1;
    }
    for (int i = 2; i <= 6; i++){
        if(check[i]==1){counter++;}
    }
    
    if (counter >=5){result=30;}
}
else if (category == 10) { 
    int sum=0;
    for (int i = 0; i < 5; i++){
        sum = dice.faces[i]+sum;
    }
    result = sum;
    

}

    return result;
}

