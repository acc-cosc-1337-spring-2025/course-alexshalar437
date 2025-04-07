//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
public:
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    void display_board() const;
    std::string get_player() const;
    std::string get_winner() const;

    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

private:
    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner(std::string winner);
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();

    std::string player;
    std::string winner;
    std::vector<std::string> pegs{9, " "};
};

#endif