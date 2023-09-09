#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

void start_game(void);
void update_board(void);
void show_board(void);
void player_move(void);
int check_board_availability(int row_selection, int column_selection);
void deconstruct_board_states();

#endif