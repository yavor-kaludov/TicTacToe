#include "user_input.h"
#include "globals.h"
#include "utility.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

void collect_user_input() { // just collects user keyboard input

    scanf("%s", global_input);
    printf("DEBUG: Global input is: %s\n", global_input);

}

// this is a variadic function

void evaluate_user_input(int num_desired_inputs, ...) { // ! refactor to accept only desired input specified in function that calls it

    // checks if desired input is as stated.
    // if not, prompts user to try again. 

    va_list possible_inputs; //creates variable "possible_inputs" of type va_list
    va_start(possible_inputs, num_desired_inputs);

    if (strcmp(global_input, "exit") == 0) {
        game_status = 1;
        exit_game();
    }

    current_input_validity = 1; // resets any to-be-evaluated user input as invalid by default before testing

    for (int i = 0; i < num_desired_inputs; i++) {
        char* next_input = va_arg(possible_inputs, char*);

        if (strcmp(global_input, next_input) == 0) {
            current_input_validity = 0; // input is valid
            break;
        }
    }
    
    if (current_input_validity == 1) {
        printf("ERROR: Invalid Input!\n");
    }
    
    
    va_end(possible_inputs);
}  
    
