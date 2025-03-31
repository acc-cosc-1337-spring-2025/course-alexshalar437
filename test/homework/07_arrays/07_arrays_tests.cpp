#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "arrays.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected (Tie Game)") {
    TicTacToe game;
    game.start_game("X");

    std::vector<int> moves = {1, 2, 3, 4, 5, 7, 6, 9, 8}; 
    for (int move : moves) {
        game.mark_board(move);
        if (move != 8) REQUIRE(game.game_over() == false);
    }

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column") {
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    game.mark_board(2);
    game.mark_board(4);
    game.mark_board(3);
    game.mark_board(7);

    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}
