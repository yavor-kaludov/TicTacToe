#include "ai.h"
#include "globals.h"
#include "game_logic.h"
#include "utility.h"
#include "visual_spice.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ai_state = 0;
// ai_state 0 is defencive play
// ai_state 1 is offensive play
// ai_state 2 is strategic play

void ai_move() {  // Computer place down X
    // check where there are player pieces and create a range
    // place a piece on a random number in the range

    printf("\n"); // padding 

    printf("AI's turn.\n \n");
    sleep(1);

    print_processing_animation();


    // main func goes here 
    // (check for player placements)
    // (update board coords first using rand numbers)

    ai_choose_board_coordinates();
    sleep(1);
    
    update_board();
    sleep(1);

    game_state = 1; // hands over turn back to player

    printf("AI has placed an O at row %d, column %d!\n", board_coordinates[0], board_coordinates[1]);

    convert_symbol_in_board_to_number('X', board_converted);

    deconstruct_board_states();
    printf("\n"); // padding 

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d, ", block_collection_array[i][j]);
        }
    }

    set_ai_state();
    printf("AI state is %d \n", ai_state);
    printf("Target block is at index %d \n", set_ai_state());

}

void ai_choose_board_coordinates() {

    // this will be replaced by a function that calculates the optimal move for the AI.
    // This may be in a separete file called AI_logic.. perhaps
    int new_row_coords = generate_rand_num_in_range(1, 3);
    int new_column_coords = generate_rand_num_in_range(1, 3);

    // here goes a function to check if board column is available it will return a 0 if true
    // then while not true (0) the loop will run

    while (check_board_availability(new_row_coords, new_column_coords) != 0) {
        printf("random coords %d and %d overlap with existing positions. Trying again...\n", new_row_coords, new_column_coords);
        new_row_coords = generate_rand_num_in_range(1, 3);
        new_column_coords = generate_rand_num_in_range(1, 3);
    }

    board_coordinates[0] = new_row_coords;
    board_coordinates[1] = new_column_coords;
}

int set_ai_state() { // inclomplete funciton

    // Check each block by 
    // 1. there are sum of 2
    int biggest_counter = 0;
    int index_of_block_checked;


    for (int i = 0; i < 8; i++) {
        int counter = 0;
        for (int j = 0; j < 3; j++) {
            if (block_collection_array[i][j] == 1) {
                counter++;
            }
        }
        
        

        if (biggest_counter < counter) {
            biggest_counter = counter;
            index_of_block_checked = i;
        }
    }

    if (biggest_counter == 2) {
        ai_state = 0;
        return index_of_block_checked;
    } else if (biggest_counter == 1) {
        ai_state = 1;
        return index_of_block_checked;
    } else if (biggest_counter == 0) {
        ai_state = 2;
        return index_of_block_checked;
    } else {
        return 100;
    }
    
}

