//add function(s) prototype
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
public:
    void start_game(std::string first_player);
    void mark_board(int position);
    void display_board() const;
    bool game_over();
    std::string get_winner() const;
    std::string get_player() const;

private:
    std::string player;
    std::vector<std::string> pegs{9, " "};
    std::string winner;

    void set_next_player();
    void set_winner();
    bool check_board_full();
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void clear_board();
};

#endif