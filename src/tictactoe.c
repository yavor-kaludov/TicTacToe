#include "game_logic.h"
#include "utility.h"
#include "user_input.h"
#include "ai.h"

#include "globals.h" // all global variables

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


// Main Game Loop

int main () {

    srand(time(NULL)); // seeding random num generator

    while (game_status == 0) {

        if (game_state == 0) {

            printf("\tIN: Game State 0!\n");
        
            start_game();

            printf("\n"); // padding above

            show_board();

            printf("\n"); // padding below

            printf("\tOUT: Game State 0!\n");
        
        } else if (game_state == 1) {
            printf("\tIN: Game State 1!\n");

            player_move();

            printf("\n"); // padding above

            show_board();

            printf("\n"); // padding below

            printf("\tOUT: Game State 1!\n");

        } else if (game_state == 2) {
            printf("\tIN: Game State 2!\n");

            ai_move();
            sleep(1);

            printf("\n"); // padding above

            show_board();
            
            printf("\n"); // padding below

            printf("\tOUT: Game State 2!\n");

            // game_status = 1;

        } else if (game_status != 0) {
            printf("\nmaybe you won?");
            printf("\n \n");
            
            exit(0);
        }
    }

    exit_game();
}


// Tasks: 

// 1. Fix handling invlaid input. 
// 2. Fix inputting the same position
// 3. Change user input validity evaluation to accept an example. Use provide examples in each func. 
// 4. Asses inifinity loop
// 5. Implement turn swithcing. Use player one, player two.. or some other mechanic
// 6. 


// 1. In player_move() implement invalid input conditions