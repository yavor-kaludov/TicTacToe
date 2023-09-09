#include "game_logic.h"
#include "globals.h"
#include "user_input.h"
#include "utility.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void start_game() { // presents the welcome message, asks the player if they're ready

   while (game_state == 0) {
        printf("\nWelcome! Let's plays some Tic Tac Toe! Type 'c' to start or 'exit' to leave.\n");

        do {
            collect_user_input();
            evaluate_user_input(1, "c");
        } while (current_input_validity != 0);
        game_state = 1;
    }

    

}

void update_board () {  //Updates the board according to the last player input. 
                        //Automatically filters out of bounds input
// 1. checks game state
// 2. if game state is 1, runs the function to add X
// 3. if game state is 2, runs the function to add O
// 4. if game state is else, do nothing and print (call to update board)


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board_coordinates[0] == i + 1 && board_coordinates[1] == j + 1) {
                if (game_state == 1) {
                    board[i][j] = 'X';
                }

                if (game_state == 2) {
                board[i][j] = 'O';
                }
            }
        }
    }
}

void show_board() {  // Display board in terminal

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    
    }
}

void player_move() { // Player place down X

        //show_board();

    current_input_validity = 0; // resets validity to 0

    while (current_input_validity == 0 && game_state == 1) {
        
        printf("\n"); // padding 

        printf("Pick a row (1-3): \n");
        
        collect_user_input();
        evaluate_user_input(3, "1", "2", "3");

        // function to change coords goes here <<<
        board_coordinates[0] = atoi(global_input);

        printf("\n"); // padding 

        printf("Pick a column (1-3): \n");
        
        collect_user_input();
        evaluate_user_input(3, "1", "2", "3");

        // function to change coords goes here <<<
        board_coordinates[1] = atoi(global_input);

        printf("\n"); // padding 

        printf("You placed an X at row %d, column %d!\n", board_coordinates[0], board_coordinates[1]);

        //we need a function to update the board here
        update_board();

        printf("\n"); // padding

        game_state = 2; //When done, hand the game over to the AI
    }
}

int check_board_availability(int row_selection, int column_selection) {
    // possibly flip the availability and check
    int availability = 0;
    printf("Debug: AI has chosen row %d, column %d\n", row_selection, column_selection);
    printf("Debug: Checking Board availability.\n");
    printf("Currently on this position is %c\n\n", board[row_selection - 1][column_selection - 1]);
    
    if (board[row_selection - 1][column_selection - 1] == 'X' || board[row_selection - 1][column_selection - 1] == 'O') {
        availability = 1;
    }

    return availability;
}

void convert_symbol_in_board_to_number(char symbol, int nums_array[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == symbol) {
                nums_array[i][j] = 1;
            } else {
                nums_array[i][j] = 0;
            }
        }
    }

    // this part prints the array

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", nums_array[i][j]);
        }

        printf("\n");
    
    }
}

void deconstruct_board_states() {

    int row1[3];
    int row2[3];
    int row3[3];
    int column1[3];
    int column2[3];
    int column3[3];
    // int diagonal1[3];
    // int diagonal2[3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0) {
                row1[j] = board_converted[i][j];
            }
            if (i == 1) {
                row2[j] = board_converted[i][j];
            }
            if (i == 2) {
                row3[j] = board_converted[i][j];
            }
            if (j == 0) {
                column1[i] = board_converted[i][j];
            }
            if (j == 1) {
                column2[i] = board_converted[i][j];
            }
            if (j == 2) {
                column3[i] = board_converted[i][j];
            }
        }
    }

    for (int b = 0; b < 3; b++) {
        printf("%d", row1[b]);
    }
    for (int b = 0; b < 3; b++) {
        printf("%d", row2[b]);
    }
    for (int b = 0; b < 3; b++) {
        printf("%d", row3[b]);
    }
    for (int b = 0; b < 3; b++) {
        printf("%d", column1[b]);
    }
    for (int b = 0; b < 3; b++) {
        printf("%d", column2[b]);
    }
    for (int b = 0; b < 3; b++) {
        printf("%d", column3[b]);
    }

    memcpy(block_collection_array[0], row1, sizeof(row1));
    memcpy(block_collection_array[1], row2, sizeof(row2));
    memcpy(block_collection_array[2], row3, sizeof(row3));
    memcpy(block_collection_array[3], column1, sizeof(column1));
    memcpy(block_collection_array[4], column2, sizeof(column2));
    memcpy(block_collection_array[5], column3, sizeof(column3));
}

// maybe a function takes the returns from this one as options.. 