#include "ai.h"
#include "globals.h"
#include "game_logic.h"
#include "utility.h"
#include "visual_spice.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
}

void ai_choose_board_coordinates() {

    int new_row_coords = generate_rand_num_in_range(1, 3);
    int new_column_coords = generate_rand_num_in_range(1, 3);

    while (new_row_coords == board_coordinates[0]) {
        printf("Current ROW coordinate is %d. Trying again...\n", new_row_coords);
        new_row_coords = generate_rand_num_in_range(1, 3);
    }

    while (new_column_coords == board_coordinates[1]) {
        printf("Current COLUMN coordinate is %d. Trying again...\n", new_row_coords);
        new_column_coords = generate_rand_num_in_range(1, 3);
    }

    board_coordinates[0] = new_row_coords;
    board_coordinates[1] = new_column_coords;
}