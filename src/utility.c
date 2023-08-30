// Includes all functions for exiting, pausing, etc.

#include "utility.h"
#include "globals.h"

#include <stdlib.h>
#include <stdio.h>

void exit_game() {

    printf("\nmaybe you won?");
    printf("\n \n");
    game_status = 1;
    exit(0);

}

int generate_rand_num_in_range(int min, int max) {

    int random_number = (rand() % (max - min + 1)) + min;

    return random_number;

}