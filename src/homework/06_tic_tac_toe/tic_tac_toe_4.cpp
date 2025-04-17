#include "tic_tac_toe_4.h"

// Конструктор для игры 4x4
TicTacToe4::TicTacToe4() : TicTacToe(4) {}

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 4,  8, 12
1, 5,  9, 13
2, 6, 10, 14
3, 7, 11, 15
*/
bool TicTacToe4::check_column_win() {
    for (int col = 0; col < 4; ++col) {
        int i = col;
        if (pegs[i] != " " &&
            pegs[i] == pegs[i + 4] &&
            pegs[i + 4] == pegs[i + 8] &&
            pegs[i + 8] == pegs[i + 12]) {
            return true;
        }
    }
    return false;
}

/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win() {
    for (int row = 0; row <= 12; row += 4) {
        if (pegs[row] != " " &&
            pegs[row] == pegs[row + 1] &&
            pegs[row + 1] == pegs[row + 2] &&
            pegs[row + 2] == pegs[row + 3]) {
            return true;
        }
    }
    return false;
}

/*
class function check_diagonal_win
Win diagonally
Top-left to bottom-right: 0, 5, 10, 15
Top-right to bottom-left: 3, 6, 9, 12
*/
bool TicTacToe4::check_diagonal_win() {
    if (pegs[0] != " " &&
        pegs[0] == pegs[5] &&
        pegs[5] == pegs[10] &&
        pegs[10] == pegs[15]) {
        return true;
    }

    if (pegs[3] != " " &&
        pegs[3] == pegs[6] &&
        pegs[6] == pegs[9] &&
        pegs[9] == pegs[12]) {
        return true;
    }

    return false;
}