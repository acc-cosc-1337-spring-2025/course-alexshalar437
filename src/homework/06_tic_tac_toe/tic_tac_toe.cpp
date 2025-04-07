//cpp
#include "tic_tac_toe.h"
#include <iostream>

// implement functions like start_game, mark_board, game_over etc.

// Check if the board is full (Game Over)
bool TicTacToe::game_over() {
    return check_board_full();
}

// Start a new game by setting the first player and clearing the board
void TicTacToe::start_game(std::string first_player) {
    if (first_player == "X" || first_player == "O") {
        player = first_player;
        clear_board();
    }
}

// Mark the board at the given position
void TicTacToe::mark_board(int position) {
    if (position >= 1 && position <= 9 && pegs[position - 1] == " ") {
        pegs[position - 1] = player;
        set_next_player();
    }
}

// Return the current player
std::string TicTacToe::get_player() const {
    return player;
}

// Display the board
void TicTacToe::display_board() const {
    for (int i = 0; i < 9; i++) {
        std::cout << pegs[i] << " ";
        if ((i + 1) % 3 == 0) std::cout << "\n";
    }
}

// Toggle player turns
void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

// Check if the board is full
bool TicTacToe::check_board_full() {
    for (const auto &peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

// Clear the board for a new game
void TicTacToe::clear_board() {
    pegs.assign(9, " ");
}
std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    for (size_t i = 0; i < game.pegs.size(); i++) {
        out << game.pegs[i];
        if ((i + 1) % 3 == 0) out << "\n";
        else out << " | ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
    int position;
    std::cout << "Player " << game.get_player() << ", enter position (1-9): ";
    in >> position;
    game.mark_board(position);
    return in;
    
}