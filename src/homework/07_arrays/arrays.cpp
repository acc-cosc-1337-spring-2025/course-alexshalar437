//add function(s) code here
#include "arrays.h"

void TicTacToe::start_game(std::string first_player) {
    if (first_player == "X" || first_player == "O") {
        player = first_player;
        clear_board();
    }
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const {
    for (int i = 0; i < 9; i++) {
        std::cout << pegs[i] << " ";
        if ((i + 1) % 3 == 0) std::cout << "\n";
    }
}

bool TicTacToe::game_over() {
    if (check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    if (check_board_full()) {
        winner = "C"; // Tie game
        return true;
    }
    return false;
}

std::string TicTacToe::get_winner() const {
    return winner;
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

bool TicTacToe::check_column_win() {
    for (int i = 0; i < 3; i++) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 3] && pegs[i] == pegs[i + 6]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win() {
    for (int i = 0; i < 9; i += 3) {
        if (pegs[i] != " " && pegs[i] == pegs[i + 1] && pegs[i] == pegs[i + 2]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win() {
    return (pegs[0] != " " && pegs[0] == pegs[4] && pegs[0] == pegs[8]) ||
           (pegs[2] != " " && pegs[2] == pegs[4] && pegs[2] == pegs[6]);
}

void TicTacToe::clear_board() {
    pegs.assign(9, " ");
}