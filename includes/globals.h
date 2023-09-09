#ifndef GLOBALS
#define GLOBALS

extern char board[3][3];
extern int board_converted[3][3];
extern int block_collection_array[8][3];

extern int game_status; // If != 0 program teminates
extern int board_coordinates[2];

extern int game_state; 

extern char global_input[10];
extern int current_input_validity;

#endif
