//h
#ifndef TICTACTOE4_H
#define TICTACTOE4_H

#include "tic_tac_toe.h"

class TicTacToe4 : public TicTacToe {
public:
    TicTacToe4(); // Конструктор для игры 4x4

private:
    bool check_column_win() override;   // Проверка победы по столбцам
    bool check_row_win() override;     // Проверка победы по строкам
    bool check_diagonal_win() override; // Проверка победы по диагоналям
};

#endif