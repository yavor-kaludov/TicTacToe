#include "user_input.h"
#include "globals.h"
#include "utility.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void collect_user_input() { // just collects user keyboard input

    scanf("%s", global_input);

}

void evaluate_user_input() { // ! refactor to accept only desired input specified in function that calls it

    if (strcmp(global_input, "exit") == 0) {
        game_status = 1;
        exit_game();
    } else if ((strcmp(global_input, "1") == 0) || 
               (strcmp(global_input, "2") == 0) || 
               (strcmp(global_input, "3") == 0)) { 
        current_input_validity = 0; //valid
    } else if (game_state == 0 && strcmp(global_input, "c") == 0) {
        current_input_validity = 0;
    } else {
        current_input_validity = 1;
    }
}
