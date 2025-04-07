#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

int main() {
    TicTacToe game;
    TicTacToeManager manager;

    std::string first_player;
    char cont;

    do {
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;
        while (first_player != "X" && first_player != "O") {
            std::cout << "Invalid. Enter X or O: ";
            std::cin >> first_player;
        }

        game.start_game(first_player);

        int position;
        while (!game.game_over()) {
            std::cout << game;
            std::cout << "Enter position (1-9): ";
            std::cin >> position;
            game.mark_board(position);
        }

        std::cout << game;
        std::cout << "Game Over! Winner: " << game.get_winner() << "\n";

        manager.save_game(game);

        int x, o, t;
        manager.get_winner_total(o, x, t);
        std::cout << "Scores - X: " << x << " O: " << o << " Ties: " << t << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    return 0;
}