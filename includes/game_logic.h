#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void start_game(void);
void update_board(void);
void show_board(void);
void player_move(void);
int check_board_availability(int row_selection, int column_selection);
void deconstruct_board_states();
void convert_symbol_in_board_to_number(char symbol, int nums_array[3][3]);

#endif