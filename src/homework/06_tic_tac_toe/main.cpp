#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<TicTacToe> game;
    TicTacToeManager manager;

    int choice;
    std::cout << "Play TicTacToe 3 (1) or 4 (2)? ";
    std::cin >> choice;

    if (choice == 1)
        game = std::make_unique<TicTacToe3>();
    else
        game = std::make_unique<TicTacToe4>();

    std::string first_player;
    char cont;

    do {
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;
        while (first_player != "X" && first_player != "O") {
            std::cout << "Invalid. Enter X or O: ";
            std::cin >> first_player;
        }

        game->start_game(first_player);

        int position;
        while (!game->game_over()) {
            game->display_board();
            std::cout << "Enter position: ";
            std::cin >> position;
            game->mark_board(position);
        }

        game->display_board();
        std::cout << "Game Over! Winner: " << game->get_winner() << "\n";

        manager.save_game(*game);

        int x, o, t;
        manager.get_winner_total(o, x, t);
        std::cout << "Scores - X: " << x << " O: " << o << " Ties: " << t << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> cont;

        if (cont == 'y' || cont == 'Y') {
            std::cout << "Play TicTacToe 3 (1) or 4 (2)? ";
            std::cin >> choice;

            if (choice == 1)
                game = std::make_unique<TicTacToe3>();
            else
                game = std::make_unique<TicTacToe4>();
        }

    } while (cont == 'y' || cont == 'Y');

    // Uncomment the following line if the display_games method is implemented in TicTacToeManager
    // manager.display_games();

    return 0;
}