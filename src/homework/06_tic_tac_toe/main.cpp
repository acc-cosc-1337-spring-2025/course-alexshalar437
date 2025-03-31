#include "tic_tac_toe.h"
#include <iostream>

int main() {
    TicTacToe game;
    std::string first_player;
    char choice;

    do {
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;

        game.start_game(first_player);
        int position;

        while (!game.game_over()) {
            game.display_board();
            std::cout << "Player " << game.get_player() << ", enter position (1-9): ";
            std::cin >> position;
            game.mark_board(position);
        }

        game.display_board();
        std::cout << "Game over! Play again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}