#ifndef AI_H
#define AI_H

extern int ai_state;

void ai_move(void);
void ai_choose_board_coordinates(void);
void convert_symbol_in_board_to_number(char symbol, int nums_array[3][3]);


#endif