#include <iostream>
#include "arrays.h"

int main() {
    std::string first_player, play_again;
    do {
        TicTacToe game;

        do {
            std::cout << "Enter first player (X or O): ";
            std::cin >> first_player;
        } while (first_player != "X" && first_player != "O");

        game.start_game(first_player);

        while (!game.game_over()) {
            int position;
            game.display_board();
            std::cout << "Player " << game.get_player() << ", enter a position (1-9): ";
            std::cin >> position;

            if (position < 1 || position > 9) {
                std::cout << "Invalid position! Try again.\n";
                continue;
            }

            game.mark_board(position);
        }

        game.display_board();
        std::cout << "Game over! Winner: " << game.get_winner() << "\n";

        std::cout << "Play again? (yes/no): ";
        std::cin >> play_again;
    } while (play_again == "yes");

    return 0;
}