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