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

// void update_board () {  //Updates the board according to the last player input. 
//                         //Automatically filters out of bounds input

//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (board_coordinates[0] == i + 1 && board_coordinates[1] == j + 1) {
//                 board[i][j] = 'X'; 
//             }
//         }
//     }
// }

void update_board () {  //Updates the board according to the last player input. 
                        //Automatically filters out of bounds input
// 1. checks game state
// 2. if game state is 1, runs the function to add X
// 3. if game state is 2, runs the function to add O
// 4. if game state is else, do nothing and print (call to update board)


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board_coordinates[0] == i + 1 && board_coordinates[1] == j + 1) {
                board[i][j] = 'X'; 
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

int check_board_row_availability(int row_selection, int column_selection) {

    int availability;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            if (strcmp(board[i][j], "X") == 0 || strcmp(board[i][j], "O") == 0) {
                availability = 0;
            }
        }
    }
    return availability;
}