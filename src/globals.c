#include "globals.h"

char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
int board_converted[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
int block_collection_array[6][3];

int game_status = 0; // If != 0 program teminates
int board_coordinates[2];

int game_state = 0; 
// Phase 0: Game hasn't started
// Phase 1: (Player 1's Move)
// Phase 2: (AI's Move) 
// Phase 3: Results????

char global_input[10];
int current_input_validity = 0;