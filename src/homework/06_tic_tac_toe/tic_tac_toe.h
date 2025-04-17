//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
public:
    explicit TicTacToe(int size); // Конструктор с указанием размера доски
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    void display_board() const;
    std::string get_player() const { return player; }
    std::string get_winner() const;

    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

protected:
    std::vector<std::string> pegs;
    std::string player;
    std::string winner;
    int board_size; // Размер доски

    virtual bool check_column_win();
    virtual bool check_row_win();
    virtual bool check_diagonal_win();
    void set_winner();
    bool check_board_full() const;
    void clear_board();
    void set_next_player();
};
#endif